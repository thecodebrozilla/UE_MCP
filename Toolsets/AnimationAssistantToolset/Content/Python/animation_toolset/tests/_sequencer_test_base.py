# Copyright Epic Games, Inc. All Rights Reserved.

"""Shared base class for Sequencer test cases.

Provides a common setUp/tearDown that creates a temp LevelSequence, spawns a
SkeletalMeshActor with the UEFN Mannequin mesh, and binds it to the sequence.
"""

from contextlib import ExitStack
import unittest

import unreal

from toolset_registry.tests.automation import create_temp_folder
from animation_toolset.toolsets.sequencer import SequencerTools


def first_loadable_asset(candidates):
    """Return the first candidate path that resolves to an asset, else None.

    unreal.load_asset may raise if the path's content root isn't mounted
    (e.g. '/InternalDev/' in a stock test environment), so each call is
    guarded. Useful for tests that want to work across multiple projects
    with different content layouts.

    Call this lazily from setUp/setUpClass rather than caching the result
    at module import time: Python test modules can be imported before
    the asset registry has finished scanning every content root, so a
    path that is unresolved at import may resolve later.
    """
    for path in candidates:
        try:
            if unreal.load_asset(path) is not None:
                return path
        except Exception:
            continue
    return None


# Candidate skeletal mesh paths in preference order. Tests resolve to
# the first one that loads in the current environment. EngineTest ships
# the Metahuman mannequin; AnimSandbox ships the UEFN mannequin;
# MoverExamples (when enabled) ships the stock Mannequin.
MANNEQUIN_MESH_CANDIDATES = (
    '/Game/Animation/ControlRig/Metahuman/SK_Mannequin_MH',
    '/Game/Characters/UEFN_Mannequin/Meshes/SKM_UEFN_Mannequin',
    '/MoverExamples/Characters/Mannequins/Meshes/SK_Mannequin',
)


def resolve_mannequin_mesh_path():
    """Return the first mannequin mesh path that loads, else None.

    Resolved lazily so it is safe to call even before the asset registry
    has fully scanned all content roots.
    """
    return first_loadable_asset(MANNEQUIN_MESH_CANDIDATES)


def _release_viewport_actor_lock():
    """Clear any viewport pilot or camera-cut lock.

    A spawnable created by a sibling test (e.g. test_create_camera) can
    pilot the viewport. When the spawnable is then destroyed by
    close_level_sequence, the viewport's FTypedElementHandle is left
    dangling, and the next FLevelEditorViewportClient::Tick asserts in
    UTypedElementRegistry.
    """
    try:
        level_editor = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
        if level_editor is not None:
            level_editor.eject_pilot_level_actor()
    except Exception:
        pass
    try:
        unreal.LevelSequenceEditorBlueprintLibrary.set_lock_camera_cut_to_viewport(
            False
        )
    except Exception:
        pass


class SequencerTestBase(unittest.TestCase):
    """Base class that creates a fresh sequence + actor + binding per test."""

    def setUp(self):
        super().setUp()
        # Initialize attrs first so tearDown is safe even if we skip below.
        self._stack = None
        self._test_folder = None
        self.sequence = None
        self.actor = None
        self.binding = None

        # Resolve the mannequin mesh lazily - the asset registry may not
        # have fully scanned all content roots at module import time.
        mesh_path = resolve_mannequin_mesh_path()
        if mesh_path is None:
            self.skipTest(
                'No skeletal mesh available from candidates: '
                + ', '.join(MANNEQUIN_MESH_CANDIDATES)
            )
        mesh = unreal.load_asset(mesh_path)
        if mesh is None:
            self.skipTest(f'Mannequin mesh failed to load at {mesh_path}')

        self._stack = ExitStack()
        self._test_folder = self._stack.enter_context(create_temp_folder())

        self.sequence = SequencerTools.create_level_sequence(
            self._test_folder, 'TestSequence'
        )
        unreal.LevelSequenceEditorBlueprintLibrary.open_level_sequence(
            self.sequence
        )
        SequencerTools.set_playback_range(self.sequence, 0, 120)

        self.actor = unreal.EditorLevelLibrary.spawn_actor_from_class(
            unreal.SkeletalMeshActor,
            unreal.Vector(0, 0, 0),
            unreal.Rotator(0, 0, 0),
        )
        skel_comp = self.actor.get_editor_property('skeletal_mesh_component')
        skel_comp.set_skeletal_mesh_asset(mesh)

        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        bindings = subsystem.add_actors([self.actor])
        self.binding = bindings[0]

    def tearDown(self) -> None:
        # Must run before close_level_sequence destroys any spawnable the
        # viewport is piloting; eject is a no-op once the lock is stale.
        _release_viewport_actor_lock()
        # Deselect everything before closing/destroying to avoid dangling
        # references in the editor selection system.
        try:
            unreal.LevelSequenceEditorBlueprintLibrary.empty_selection()
        except Exception:
            pass
        try:
            editor_actor_sub = unreal.get_editor_subsystem(
                unreal.EditorActorSubsystem
            )
            editor_actor_sub.clear_actor_selection_set()
        except Exception:
            pass
        try:
            unreal.LevelSequenceEditorBlueprintLibrary.close_level_sequence()
        except Exception:
            pass
        if self.actor:
            self.actor.destroy_actor()
        self.sequence = None
        self.binding = None
        self.actor = None
        if self._stack is not None:
            self._stack.close()
        super().tearDown()

    def _make_track_and_section(self):
        """Helper: add a visibility track with one section and return both."""
        track = SequencerTools.add_track_to_binding(
            self.binding, unreal.MovieSceneVisibilityTrack.static_class()
        )
        section = SequencerTools.add_section(track)
        return track, section

    def _make_transform_section(self):
        """Helper: get (or create) a 3D transform track with one section.

        ``add_actors`` automatically creates a transform track on the
        binding, so we reuse it instead of adding a duplicate (a second
        transform track on the same binding cannot accept keys because
        the property binding is already claimed by the first track).
        """
        existing = SequencerTools.find_tracks_by_type(
            self.binding, unreal.MovieScene3DTransformTrack.static_class()
        )
        if existing:
            track = existing[0]
            sections = SequencerTools.get_sections(track)
            if sections:
                section = sections[0]
            else:
                section = SequencerTools.add_section(track)
        else:
            track = SequencerTools.add_track_to_binding(
                self.binding, unreal.MovieScene3DTransformTrack.static_class()
            )
            section = SequencerTools.add_section(track)
        SequencerTools.set_section_range(section, 0, 120)
        return track, section

    def _get_outliner_root_and_children(self):
        """Helper: get outliner root node and its children."""
        subsystem = unreal.get_editor_subsystem(
            unreal.LevelSequenceEditorSubsystem
        )
        scripting_layer = subsystem.get_scripting_layer()
        outliner = scripting_layer.get_outliner()
        root = outliner.get_root_node()
        if not root:
            self.skipTest('No outliner root node available')
        children = list(outliner.get_children(root))
        return root, children, outliner
