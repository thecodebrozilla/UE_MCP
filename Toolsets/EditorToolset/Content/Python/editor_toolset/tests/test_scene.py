# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import contextmanager, ExitStack
from typing import Iterator
import unittest
from unittest.mock import MagicMock, patch
import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.demo_toolset import ToolsetTestActor
from editor_toolset.toolsets.actor import ActorTools
from editor_toolset.toolsets.asset import AssetTools
from editor_toolset.toolsets.blueprint import BlueprintTools
from editor_toolset.toolsets.object import ObjectTools
from editor_toolset.toolsets.scene import ALL_COLLISION_CHANNELS, SceneTools
from toolset_registry.tests.automation import create_temp_folder


@contextmanager
def create_actor(
    name: str = 'test_actor', actor_type: unreal.Class = unreal.Actor.static_class(),
    transform: unreal.Transform = unreal.Transform(), parent: unreal.Actor | None = None,
    snap_to_ground: bool = False) -> Iterator[unreal.Actor]:
    with unreal.ScopedEditorTransaction('create_actor_test'):
        test_actor: unreal.Actor | None = None
        try:
            test_actor = SceneTools.add_to_scene_from_class(
                actor_type, name, transform, parent, snap_to_ground)
            yield test_actor
        finally:
            if test_actor:
                SceneTools.remove_from_scene(test_actor)

class SceneToolsTestCase(ToolCallTestCase):
    """Test SceneTools toolset."""

    def test_can_edit_returns_true_for_scene_actor(self):
        """An actor in the current level should be editable when source control is not enabled."""
        with create_actor() as test_actor:
            self.assertTrue(SceneTools.can_edit(test_actor))

    def test_can_edit_false_when_checked_out_by_other(self):
        """can_edit returns False when the actor's package is checked out by another user."""
        mock_state = MagicMock()
        mock_state.is_checked_out_other = True
        with create_actor() as test_actor:
            with patch.object(SceneTools, '_sc_state', return_value=mock_state):
                self.assertFalse(SceneTools.can_edit(test_actor))

    def test_is_checked_out_false_for_scene_actor(self):
        """An actor in the current level should not be checked out when source control is not enabled."""
        with create_actor() as test_actor:
            self.assertFalse(SceneTools.is_checked_out(test_actor))

    def test_is_checked_out_true_when_checked_out_by_me(self):
        """is_checked_out returns True when the actor's package is checked out by the current user."""
        mock_state = MagicMock()
        mock_state.is_checked_out = True
        with create_actor() as test_actor:
            with patch.object(SceneTools, '_sc_state', return_value=mock_state):
                self.assertTrue(SceneTools.is_checked_out(test_actor))

    def test_create_actor(self):
        """Ensures we can set and get actor labels"""
        name = 'create_test'
        transform = unreal.Transform(unreal.Vector(1, 2, 3))
        with create_actor(name=name, transform=transform) as test_actor:
            self.assertEqual(test_actor.get_actor_label(), name)
            self.assertEqual(test_actor.get_actor_location(), transform.translation)

    def test_add_to_scene_from_asset(self):
        """Ensures we can add an actor to the scene using an asset path."""
        name = 'asset_path_test'
        with create_temp_folder() as test_folder:
            blueprint = BlueprintTools.create(test_folder, 'test_bp', unreal.Actor.static_class())
            bp_path = blueprint.get_path_name()
            with unreal.ScopedEditorTransaction('test_create_actor_from_asset_path'):
                test_actor: unreal.Actor | None = None
                try:
                    test_actor = SceneTools.add_to_scene_from_asset(bp_path, name, unreal.Transform())
                    self.assertIsNotNone(test_actor)
                    self.assertEqual(test_actor.get_actor_label(), name)
                finally:
                    if test_actor:
                        SceneTools.remove_from_scene(test_actor)

    def test_find_actor_name(self):
        """Ensures we can find actors by name"""
        name = 'create_test'
        with create_actor(name=name) as test_actor:
            found = SceneTools.find_actors(name=name)
            self.assertEqual(len(found), 1)
            self.assertEqual(found[0], test_actor)
        self.assertEqual(len(SceneTools.find_actors(name=name)), 0)

    def test_find_actor_tag(self):
        """Ensures we can find actors by tag"""
        tag = 'test_tag'
        with create_actor(name='tagged_actor') as tagged, create_actor(name='untagged_actor') as untagged:
            tagged.tags = [unreal.Name(tag)]
            found = SceneTools.find_actors(tag=tag)
            self.assertIn(tagged, found)
            self.assertNotIn(untagged, found)

    def test_find_actor_class(self):
        """Ensures we can find actors by class"""
        with create_actor(actor_type=ToolsetTestActor.static_class()) as test_actor:
            found = SceneTools.find_actors(actor_type=ToolsetTestActor.static_class())
            self.assertEqual(len(found), 1)
            self.assertEqual(found[0], test_actor)
        self.assertEqual(len(SceneTools.find_actors(actor_type=ToolsetTestActor.static_class())), 0)

    def test_create_actor_with_parent(self):
        """Ensures a child actor's world position reflects its transform relative to the parent."""
        parent_pos = unreal.Vector(100, 200, 300)
        child_offset = unreal.Vector(10, 0, 0)
        with create_actor(transform=unreal.Transform(parent_pos)) as parent:
            with create_actor(transform=unreal.Transform(child_offset), parent=parent) as child:
                expected = parent_pos.add(child_offset)
                actual = child.get_actor_location()
                self.assertAlmostEqual(actual.x, expected.x, delta=0.1)
                self.assertAlmostEqual(actual.y, expected.y, delta=0.1)
                self.assertAlmostEqual(actual.z, expected.z, delta=0.1)

    def test_create_actor_with_parent_rotation(self):
        """Ensures a child's world transform accounts for the parent's rotation.

        With the parent rotated 90° yaw, a child offset along local +X should end
        up displaced along world +Y, and the child should inherit the parent's rotation.
        """
        parent_pos = unreal.Vector(100, 200, 300)
        parent_rot = unreal.Rotator(0, 0, 90)  # roll=0, pitch=0, yaw=90
        child_offset = unreal.Vector(10, 0, 0)  # 10 units along parent's local +X
        with create_actor(transform=unreal.Transform(parent_pos, parent_rot)) as parent:
            with create_actor(transform=unreal.Transform(child_offset), parent=parent) as child:
                # Local +X (10, 0, 0) rotated 90° yaw becomes world +Y offset (0, 10, 0).
                expected_pos = parent_pos.add(unreal.Vector(0, 10, 0))
                actual_pos = child.get_actor_location()
                self.assertAlmostEqual(actual_pos.x, expected_pos.x, delta=0.1)
                self.assertAlmostEqual(actual_pos.y, expected_pos.y, delta=0.1)
                self.assertAlmostEqual(actual_pos.z, expected_pos.z, delta=0.1)
                # Child with identity local rotation should inherit the parent's world rotation.
                actual_rot = child.get_actor_rotation()
                self.assertAlmostEqual(actual_rot.yaw, parent_rot.yaw, delta=0.1)
                self.assertAlmostEqual(actual_rot.pitch, parent_rot.pitch, delta=0.1)
                self.assertAlmostEqual(actual_rot.roll, parent_rot.roll, delta=0.1)

    def test_find_actor_parent(self):
        """Ensures we can find actors by parent"""
        with (create_actor() as parent_actor, create_actor(parent=parent_actor) as test_actor):
            found = SceneTools.find_actors(root=parent_actor)
            self.assertCountEqual(found, [test_actor, parent_actor])

    def test_find_actor_parent_and_class(self):
        """Ensures actor_type filter is applied when searching by parent.

        Tests two cases: actor_type=Actor (base class, matches all children) and
        actor_type=StaticMeshActor (no children of that type, so the result excludes them).
        """
        with (create_actor() as parent,
              create_actor(parent=parent) as child):
            # With the base Actor class, both parent and child should be returned.
            found = SceneTools.find_actors(
                root=parent, actor_type=unreal.Actor.static_class())
            self.assertIn(parent, found)
            self.assertIn(child, found)
            # With StaticMeshActor, neither plain-Actor child nor parent should match.
            found_sm = SceneTools.find_actors(
                root=parent, actor_type=unreal.StaticMeshActor.static_class())
            self.assertNotIn(parent, found_sm)
            self.assertNotIn(child, found_sm)

    def test_find_actor_parent_class_and_bounds(self):
        """Ensures actor_type filter is applied to candidates when root and bounds are both set."""
        pos = unreal.Vector(0, 0, 100000)
        bounds = unreal.Box(
            min=unreal.Vector(-1000, -1000, 99000),
            max=unreal.Vector(1000, 1000, 101000))
        with create_actor(transform=unreal.Transform(pos)) as parent:
            with create_actor(parent=parent) as child:
                # With Actor class, both actors should be found within bounds.
                found = SceneTools.find_actors(
                    root=parent, bounds=bounds,
                    actor_type=unreal.Actor.static_class())
                self.assertIn(parent, found)
                self.assertIn(child, found)
                # With StaticMeshActor, no plain Actors should match.
                found_sm = SceneTools.find_actors(
                    root=parent, bounds=bounds,
                    actor_type=unreal.StaticMeshActor.static_class())
                self.assertNotIn(parent, found_sm)
                self.assertNotIn(child, found_sm)

    def test_get_collision_channels(self):
        """Ensures get_collision_channels returns correctly."""
        self.assertEqual(SceneTools.get_collision_channels(), ALL_COLLISION_CHANNELS)

    def test_find_actors_in_bounds(self):
        """Ensures find_actors returns actors whose bounds overlap the bounding box."""
        cube = unreal.load_asset('/Engine/BasicShapes/Cube')
        if cube is None:
            self.skipTest('Basic cube mesh not found')
        inside_pos = unreal.Vector(0, 0, 100000)
        outside_pos = unreal.Vector(0, 0, 200000)
        inside_actor = SceneTools._eas().spawn_actor_from_object(cube, inside_pos)
        outside_actor = SceneTools._eas().spawn_actor_from_object(cube, outside_pos)
        if inside_actor is None or outside_actor is None:
            self.skipTest('Could not spawn test cube actors')
        try:
            bounds = unreal.Box(
                min=unreal.Vector(-1000, -1000, 99000),
                max=unreal.Vector(1000, 1000, 101000))
            found = SceneTools.find_actors(bounds=bounds)
            self.assertIn(inside_actor, found)
            self.assertNotIn(outside_actor, found)
        finally:
            SceneTools._eas().destroy_actor(inside_actor)
            SceneTools._eas().destroy_actor(outside_actor)

    def test_find_actors_in_bounds_with_collision_channels(self):
        """Ensures collision_channels triggers a physics query, excluding actors without collision."""
        cube = unreal.load_asset('/Engine/BasicShapes/Cube')
        if cube is None:
            self.skipTest('Basic cube mesh not found')
        pos = unreal.Vector(0, 0, 100000)
        bounds = unreal.Box(
            min=unreal.Vector(-1000, -1000, 99000),
            max=unreal.Vector(1000, 1000, 101000))
        physics_actor = SceneTools._eas().spawn_actor_from_object(cube, pos)
        if physics_actor is None:
            self.skipTest('Could not spawn test cube actor')
        try:
            with create_actor(transform=unreal.Transform(pos)) as no_collision_actor:
                # Default: bounds overlap check finds both actors.
                found_default = SceneTools.find_actors(bounds=bounds)
                self.assertIn(physics_actor, found_default)
                self.assertIn(no_collision_actor, found_default)
                # Physics query (all channels): cube found, plain Actor not.
                found_physics = SceneTools.find_actors(
                    bounds=bounds, collision_channels=ALL_COLLISION_CHANNELS)
                self.assertIn(physics_actor, found_physics)
                self.assertNotIn(no_collision_actor, found_physics)
        finally:
            SceneTools._eas().destroy_actor(physics_actor)

    def test_load_get_level(self):
        """Ensure we can change levels and query the current level."""
        with create_temp_folder() as temp_folder:
            try:
                original_level = SceneTools.get_current_level()
                test_level_path = f'{temp_folder}TestLevel'
                self.assertTrue(SceneTools._les().new_level(test_level_path))
                test_level = SceneTools.get_current_level()
                self.assertEqual(test_level, test_level_path)
            finally:
                SceneTools._les().load_level(original_level)

    def test_load_level(self):
        """Ensure we can load a level."""
        with create_temp_folder() as temp_folder:
            original_level = SceneTools.get_current_level()
            try:
                # Create a test level and switch to it.
                test_level_path1 = f'{temp_folder}TestLevel1'
                self.assertTrue(SceneTools._les().new_level(test_level_path1))
                test_level = SceneTools.get_current_level()
                self.assertEqual(test_level, test_level_path1)

                # Create another test level and switch to it.
                test_level_path2 = f'{temp_folder}TestLevel2'
                self.assertTrue(SceneTools._les().new_level(test_level_path2))
                test_level = SceneTools.get_current_level()
                self.assertEqual(test_level, test_level_path2)

                # Finally, load the first test level with scene tools.
                SceneTools.load_level(test_level_path1)
                test_level = SceneTools.get_current_level()
                self.assertEqual(test_level, test_level_path1)
            finally:
                SceneTools._les().load_level(original_level)

    def test_load_level_bad_input(self):
        """Ensure load_level fails when given invalid level input."""
        with create_temp_folder() as temp_folder:
            original_level = SceneTools.get_current_level()
            try:
                # Create a test level and then switch back.
                test_level_path = f'{temp_folder}TestLevel'
                self.assertTrue(SceneTools._les().new_level(test_level_path))
                test_level = SceneTools.get_current_level()
                self.assertEqual(test_level, test_level_path)

                # Attempt to load nonexistent level (nonsensical path)
                unreal.AutomationLibrary.add_expected_plain_log_error(
                    "Can't convert the path 'nonsense' because it does not map to a root",
                    2)
                with self.assertToolRaisesRuntimeError():
                    SceneTools.load_level('nonsense')
                # Attempt to load nonexistent level (plausible but incorrect path)
                with self.assertToolRaisesRuntimeError():
                    SceneTools.load_level(test_level_path + 'foo')
                # Attempt to load empty level path
                unreal.AutomationLibrary.add_expected_plain_log_error(
                    'DoesDirectoryExist failed')
                unreal.AutomationLibrary.add_expected_plain_log_error(
                    'DoesAssetExist failed')
                with self.assertToolRaisesRuntimeError():
                    SceneTools.load_level('')
            finally:
                SceneTools._les().load_level(original_level)

    def test_load_level_raises_if_never_saved(self):
        """Ensures load_level raises RuntimeError for a level that has never
        been saved to disk."""
        original_level = SceneTools.get_current_level()
        if not original_level:
            self.skipTest('No level currently open to duplicate.')
        with create_temp_folder() as temp_folder:
            test_level_path = f'{temp_folder}UnsavedLevel'
            # Duplicate the current level to produce an in-memory asset with no
            # backing file.
            self.assertTrue(AssetTools.duplicate(original_level, test_level_path))
            self.assertTrue(AssetTools.is_dirty(test_level_path))
            with self.assertToolRaisesRuntimeError():
                SceneTools.load_level(test_level_path)

    def test_load_level_raises_if_dirty(self):
        """Ensures load_level raises RuntimeError when the current level has
        unsaved changes."""
        with create_temp_folder() as temp_folder:
            original_level = SceneTools.get_current_level()
            test_level_path = f'{temp_folder}DirtyLevel'
            try:
                # new_level saves automatically, so the level is already on disk.
                SceneTools._les().new_level(test_level_path)
                # Spawning an actor makes the level dirty.
                SceneTools.add_to_scene_from_class(
                    unreal.Actor.static_class(), 'DirtyActor', unreal.Transform())
                self.assertTrue(AssetTools.is_dirty(test_level_path))
                # Attempting to reload the current dirty level should raise.
                with self.assertToolRaisesRuntimeError():
                    SceneTools.load_level(test_level_path)
            finally:
                SceneTools._les().load_level(original_level)

    def test_set_actor_folder(self):
        """Ensures we can assign an actor to a folder and retrieve its folder."""
        with create_actor(name='outliner_set_test') as actor:
            SceneTools.set_actor_folder(actor, 'TestFolder')
            self.assertIn(actor, SceneTools.get_actors_in_folder('TestFolder'))
            self.assertEqual(SceneTools._get_actor_folder(actor), 'TestFolder')
            SceneTools.delete_folder('TestFolder')

    def test_set_actor_folder_root(self):
        """Ensures passing an empty string moves the actor to the root."""
        with create_actor(name='outliner_root_test') as actor:
            SceneTools.set_actor_folder(actor, 'SomeFolder')
            SceneTools.delete_folder('SomeFolder')
            self.assertEqual(SceneTools._get_actor_folder(actor), '')
            self.assertNotIn('SomeFolder', SceneTools.get_folders())

    def test_get_folders_includes_parents(self):
        """Ensures get_folders includes all intermediate parent paths."""
        with create_actor(name='outliner_nested_test') as actor:
            SceneTools.set_actor_folder(actor, 'A/B/C')
            folders = SceneTools.get_folders()
            self.assertIn('A', folders)
            self.assertIn('A/B', folders)
            self.assertIn('A/B/C', folders)
            SceneTools.delete_folder('A/B/C')
            SceneTools.delete_folder('A/B')
            SceneTools.delete_folder('A')

    def test_get_actors_in_folder_non_recursive(self):
        """Ensures non-recursive get_actors_in_folder returns only direct members."""
        with (create_actor(name='outliner_direct') as actor_direct,
              create_actor(name='outliner_sub') as actor_sub):
            SceneTools.set_actor_folder(actor_direct, 'Parent')
            SceneTools.set_actor_folder(actor_sub, 'Parent/Sub')
            direct = SceneTools.get_actors_in_folder('Parent', recursive=False)
            self.assertIn(actor_direct, direct)
            self.assertNotIn(actor_sub, direct)
            SceneTools.delete_folder('Parent/Sub')
            SceneTools.delete_folder('Parent')

    def test_get_actors_in_folder_actors_recursive(self):
        """Ensures recursive get_actors_in_folder includes sub-folder actors."""
        with (create_actor(name='outliner_rec_direct') as actor_direct,
              create_actor(name='outliner_rec_sub') as actor_sub):
            SceneTools.set_actor_folder(actor_direct, 'RecParent')
            SceneTools.set_actor_folder(actor_sub, 'RecParent/Sub')
            recursive = SceneTools.get_actors_in_folder('RecParent', recursive=True)
            self.assertIn(actor_direct, recursive)
            self.assertIn(actor_sub, recursive)
            SceneTools.delete_folder('RecParent/Sub')
            SceneTools.delete_folder('RecParent')

    def test_rename_folder(self):
        """Ensures rename_folder updates paths for actors in the folder and sub-folders."""
        with (create_actor(name='rename_root') as actor_root,
              create_actor(name='rename_child') as actor_child):
            SceneTools.set_actor_folder(actor_root, 'OldFolder')
            SceneTools.set_actor_folder(actor_child, 'OldFolder/Sub')
            count = SceneTools.rename_folder('OldFolder', 'NewFolder')
            self.assertEqual(count, 2)
            self.assertEqual(SceneTools._get_actor_folder(actor_root), 'NewFolder')
            self.assertEqual(SceneTools._get_actor_folder(actor_child), 'NewFolder/Sub')
            SceneTools.delete_folder('NewFolder/Sub')
            SceneTools.delete_folder('NewFolder')

    def test_rename_folder_does_not_affect_sibling(self):
        """Ensures rename_folder does not alter actors in sibling folders."""
        with (create_actor(name='rename_target') as actor_target,
              create_actor(name='rename_sibling') as actor_sibling):
            SceneTools.set_actor_folder(actor_target, 'Rename/Target')
            SceneTools.set_actor_folder(actor_sibling, 'Rename/Sibling')
            SceneTools.rename_folder('Rename/Target', 'Rename/Renamed')
            self.assertEqual(SceneTools._get_actor_folder(actor_target), 'Rename/Renamed')
            self.assertEqual(SceneTools._get_actor_folder(actor_sibling), 'Rename/Sibling')
            SceneTools.delete_folder('Rename/Renamed')
            SceneTools.delete_folder('Rename/Sibling')
            SceneTools.delete_folder('Rename')

    def test_delete_folder_moves_to_parent(self):
        """Ensures delete_folder moves direct actors to the parent and preserves sub-folders."""
        with (create_actor(name='delete_direct') as actor_direct,
              create_actor(name='delete_sub') as actor_sub):
            SceneTools.set_actor_folder(actor_direct, 'Parent/ToDelete')
            SceneTools.set_actor_folder(actor_sub, 'Parent/ToDelete/Sub')
            count = SceneTools.delete_folder('Parent/ToDelete')
            self.assertEqual(count, 2)
            self.assertEqual(SceneTools._get_actor_folder(actor_direct), 'Parent')
            self.assertEqual(SceneTools._get_actor_folder(actor_sub), 'Parent/Sub')
            SceneTools.delete_folder('Parent/Sub')
            SceneTools.delete_folder('Parent')

    def test_delete_top_level_folder_moves_to_root(self):
        """Ensures deleting a top-level folder moves actors to the outliner root."""
        with create_actor(name='delete_top') as actor:
            SceneTools.set_actor_folder(actor, 'TopLevel')
            count = SceneTools.delete_folder('TopLevel')
            self.assertEqual(count, 1)
            self.assertEqual(SceneTools._get_actor_folder(actor), '')

    def test_require_folder_raises_for_missing_folder(self):
        """Ensures _require_folder raises ValueError when the folder does not exist."""
        self.assertRaises(ValueError, SceneTools._require_folder, 'DoesNotExist')

    def test_require_folder_passes_for_existing_folder(self):
        """Ensures _require_folder does not raise for a folder that exists."""
        with create_actor(name='require_folder_test') as actor:
            SceneTools.set_actor_folder(actor, 'ExistingFolder')
            SceneTools._require_folder('ExistingFolder')  # should not raise
            SceneTools.delete_folder('ExistingFolder')

    def test_find_actors_in_pie(self):
        """Ensures find_actors queries the game world when PIE is active."""
        name = 'pie_find_test'
        editor_world = SceneTools._ues().get_editor_world()
        mock_ues = MagicMock()
        mock_ues.get_game_world.return_value = editor_world
        with create_actor(name=name) as test_actor:
            with patch.object(SceneTools, '_ues', return_value=mock_ues):
                found = SceneTools.find_actors(name=name)
                self.assertEqual(len(found), 1)
                self.assertEqual(found[0], test_actor)

    def test_add_to_scene_from_class_raises_in_pie(self):
        """Ensures add_to_scene_from_class raises RuntimeError when PIE is active."""
        with patch.object(SceneTools, '_is_pie', return_value=True):
            with self.assertToolRaisesRuntimeError():
                SceneTools.add_to_scene_from_class(
                    unreal.Actor.static_class(), 'pie_test', unreal.Transform())

    def test_add_to_scene_from_asset_raises_in_pie(self):
        """Ensures add_to_scene_from_asset raises RuntimeError when PIE is active."""
        with patch.object(SceneTools, '_is_pie', return_value=True):
            with self.assertToolRaisesRuntimeError():
                SceneTools.add_to_scene_from_asset(
                    '/Game/SomeAsset', 'pie_test', unreal.Transform())

    def test_trace_world_miss(self):
        """Ensures trace_world returns None when nothing is in the path."""
        start = unreal.Vector(0, 0, 100000)
        end = unreal.Vector(0, 0, 200000)
        self.assertIsNone(SceneTools.trace_world(start, end))

    def test_trace_world_hit(self):
        """Ensures trace_world returns a positive distance when an object is hit."""
        cube = unreal.load_asset('/Engine/BasicShapes/Cube')
        if cube is None:
            self.skipTest('Basic cube mesh not found')
        pos = unreal.Vector(0, 0, 100000)
        with unreal.ScopedEditorTransaction('test_trace_world_hit'):
            actor = SceneTools._eas().spawn_actor_from_object(cube, pos)
            if actor is None:
                self.skipTest('Could not spawn test cube actor')
            try:
                distance = SceneTools.trace_world(
                    unreal.Vector(0, 0, 101000), unreal.Vector(0, 0, 99000))
                self.assertIsNotNone(distance)
                assert distance is not None
                self.assertGreater(distance, 0)
                self.assertLess(distance, 2000)
            finally:
                SceneTools._eas().destroy_actor(actor)

    def test_remove_from_scene_raises_in_pie(self):
        """Ensures remove_from_scene raises RuntimeError when PIE is active."""
        with create_actor(name='pie_remove_test') as actor:
            with patch.object(SceneTools, '_is_pie', return_value=True):
                with self.assertToolRaisesRuntimeError():
                    SceneTools.remove_from_scene(actor)

    def test_merge_actors_raises_in_pie(self):
        """Ensures merge_actors raises when PIE is active."""
        with patch.object(SceneTools, '_is_pie', return_value=True):
            with self.assertToolRaisesRuntimeError():
                SceneTools.merge_actors([], '/Game/Merged')

    def test_merge_actors(self):
        """Ensures merge_actors combines static mesh actors into a single merged actor."""
        cube = unreal.load_asset('/Engine/BasicShapes/Cube')
        if cube is None:
            self.skipTest('Basic cube mesh not found')
        with create_temp_folder() as temp_folder:
            actor1 = SceneTools._eas().spawn_actor_from_object(cube, unreal.Vector(0, 0, 100000))
            actor2 = SceneTools._eas().spawn_actor_from_object(cube, unreal.Vector(100, 0, 100000))
            if actor1 is None or actor2 is None:
                self.skipTest('Could not spawn test cube actors')
            merged = None
            try:
                merged = SceneTools.merge_actors(
                    [actor1, actor2], f'{temp_folder}MergedMesh')
                self.assertIsInstance(merged, unreal.StaticMeshActor)
                origin, extent = merged.get_actor_bounds(False)
                self.assertAlmostEqual(origin.x, 50, delta=1)
                self.assertAlmostEqual(origin.y, 0, delta=1)
                self.assertAlmostEqual(origin.z, 100000, delta=1)
                self.assertAlmostEqual(extent.x, 100, delta=1)
                self.assertAlmostEqual(extent.y, 50, delta=1)
                self.assertAlmostEqual(extent.z, 50, delta=1)
            finally:
                SceneTools._eas().destroy_actor(actor1)
                SceneTools._eas().destroy_actor(actor2)
                if merged:
                    SceneTools._eas().destroy_actor(merged)

    def test_create_level_instance(self):
        """Ensures we can create a level instance actor referencing an existing level."""
        with create_temp_folder() as temp_folder:
            original_level = SceneTools.get_current_level()
            sub_level_path = f'{temp_folder}SubLevel'
            working_level_path = f'{temp_folder}WorkingLevel'
            try:
                SceneTools._les().new_level(sub_level_path)
                SceneTools._les().new_level(working_level_path)
                li: unreal.LevelInstance | None = None
                try:
                    li = SceneTools.create_level_instance(
                        sub_level_path, 'test_li', unreal.Transform())
                    self.assertIsInstance(li, unreal.LevelInstance)
                    self.assertEqual(li.get_actor_label(), 'test_li')
                finally:
                    if li:
                        SceneTools._eas().destroy_actor(li)
            finally:
                if original_level:
                    SceneTools._les().load_level(original_level)

    def test_create_level_instance_raises_for_missing_level(self):
        """Ensures create_level_instance raises when the level path does not exist."""
        with self.assertToolRaisesRuntimeError():
            SceneTools.create_level_instance('/Game/DoesNotExist', 'test', unreal.Transform())

    def test_create_level_instance_raises_in_pie(self):
        """Ensures create_level_instance raises when PIE is active."""
        with patch.object(SceneTools, '_is_pie', return_value=True):
            with self.assertToolRaisesRuntimeError():
                SceneTools.create_level_instance('/Game/SomeLevel', 'test', unreal.Transform())

    def test_save_actor_raises_for_non_external_actor(self):
        """Ensures save_actor raises for a standard level actor that has no individual package."""
        with create_actor(name='save_actor_test') as actor:
            with self.assertToolRaisesRuntimeError():
                SceneTools.save_actor(actor)

    def test_save_actor_saves_external_actor(self):
        """Ensures save_actor calls save_assets with the actor's package path."""
        with create_actor(name='save_actor_external_test') as actor:
            expected_path = actor.get_package().get_path_name()
            with patch.object(SceneTools, '_is_external_actor', return_value=True):
                with patch.object(AssetTools, 'save_assets', return_value=True) as mock_save:
                    SceneTools.save_actor(actor)
                    mock_save.assert_called_once_with([expected_path])


class LevelInstanceTestCase(ToolCallTestCase):
    """Tests find_actors behavior with level instances.

    Uses setUp/tearDown to manage the level instance lifecycle so that Python
    references to UE actor objects are explicitly cleared before UE-side cleanup,
    preventing GC assertions from stale Python wrappers.
    """

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        self.temp_folder = self._stack.enter_context(create_temp_folder())
        self.li_actor = None
        self.inner_actor_name = 'inner_li_test_actor'
        self.original_level = SceneTools.get_current_level()
        if not self.original_level:
            return

        lib = unreal.InterchangeEditorScriptLibrary
        sub_level_path = f'{self.temp_folder}LISubLevel'

        # Create an empty sub-level for the level instance to reference.
        SceneTools._les().new_level(sub_level_path)

        # Create a blank working level to host the level instance actor.
        # Using a dedicated working level means tearDown can switch back to the
        # original level, which causes UE to unload both the working level and the
        # sub-level — cleanly releasing all World references without needing explicit
        # actor destruction or forced GC.
        SceneTools._les().new_level(f'{self.temp_folder}WorkingLevel')

        # Place a LevelInstance actor referencing the sub-level.
        with unreal.ScopedEditorTransaction('test_li_setup'):
            self.li_actor = SceneTools._eas().spawn_actor_from_class(
                unreal.LevelInstance.static_class(), unreal.Vector())
            sub_level_world = unreal.load_asset(sub_level_path)
            self.li_actor.set_world_asset(sub_level_world)
        SceneTools._les().save_current_level()

        # Enter edit mode — this synchronously loads the sub-level.
        self.assertTrue(lib.level_instance_enter_edit_mode(self.li_actor))

        # Spawn an actor inside the level instance while in edit mode.
        with unreal.ScopedEditorTransaction('test_li_inner'):
            SceneTools.add_to_scene_from_class(
                unreal.Actor.static_class(), self.inner_actor_name, unreal.Transform())

    def tearDown(self) -> None:
        lib = unreal.InterchangeEditorScriptLibrary
        li_actor = self.li_actor
        self.li_actor = None
        if li_actor:
            lib.level_instance_commit(li_actor, True)  # discard edit-mode changes
            li_actor = None
        # Save so the working level is clean, then switch back to the original level.
        # The level switch causes UE to unload the working level and its streaming
        # sub-level, so delete_directory can remove the temp folder without fighting
        # loaded World object references.
        SceneTools._les().save_current_level()
        if self.original_level:
            SceneTools._les().load_level(self.original_level)
        self._stack.close()
        super().tearDown()

    def test_find_actors_in_level_instance(self):
        """Ensures find_actors returns actors inside a level instance in edit mode."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        found = SceneTools.find_actors(name=self.inner_actor_name)
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0].get_actor_label(), self.inner_actor_name)

    def test_find_actors_in_non_editing_level_instance(self):
        """Ensures find_actors returns actors inside a level instance that is not in edit mode."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        actor = self._save_and_find_inner_actor()
        self.assertIsNotNone(actor)
        self.assertEqual(actor.get_actor_label(), self.inner_actor_name)

    def test_edit_level_instance(self):
        """Ensures edit_level_instance enters edit mode successfully."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        lib = unreal.InterchangeEditorScriptLibrary
        # Save the inner actor so it persists in the sub-level, then exit edit mode.
        lib.level_instance_commit(self.li_actor, False)
        SceneTools.edit_level_instance(self.li_actor)
        # Verify we are in edit mode — the saved inner actor should be editable.
        editable = lib.level_instance_get_editable_actors(self.li_actor)
        labels = [a.get_actor_label() for a in editable]
        self.assertIn(self.inner_actor_name, labels)

    def test_commit_level_instance(self):
        """Ensures commit_level_instance saves changes and exits edit mode."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        lib = unreal.InterchangeEditorScriptLibrary
        SceneTools.commit_level_instance(self.li_actor)
        # Verify edit mode has been exited.
        editable = lib.level_instance_get_editable_actors(self.li_actor)
        self.assertEqual(len(editable), 0)
        # Verify changes were saved — the inner actor should still be findable.
        found = SceneTools.find_actors(name=self.inner_actor_name)
        self.assertEqual(len(found), 1)

    def test_commit_level_instance_discard(self):
        """Ensures commit_level_instance with discard=True exits without saving."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        lib = unreal.InterchangeEditorScriptLibrary
        SceneTools.commit_level_instance(self.li_actor, discard=True)
        # Verify edit mode has been exited.
        editable = lib.level_instance_get_editable_actors(self.li_actor)
        self.assertEqual(len(editable), 0)
        # Verify changes were discarded — the inner actor should not be findable.
        found = SceneTools.find_actors(name=self.inner_actor_name)
        self.assertEqual(len(found), 0)

    def _save_and_find_inner_actor(self) -> unreal.Actor | None:
        """Commits (saves) the current edit to persist the inner actor, then returns it."""
        SceneTools.commit_level_instance(self.li_actor)
        actors = SceneTools.find_actors(name=self.inner_actor_name)
        return actors[0] if actors else None

    def test_edit_raises_in_locked_level_instance(self):
        """Ensures require_editable raises when modifying an actor in a non-editing level instance."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        actor = self._save_and_find_inner_actor()
        self.assertIsNotNone(actor)
        with self.assertToolRaisesRuntimeError():
            ActorTools.set_label(actor, 'new_label')

    def test_object_tools_raises_in_locked_level_instance(self):
        """Ensures ObjectTools raises when setting properties on an actor in a non-editing level instance."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        actor = self._save_and_find_inner_actor()
        self.assertIsNotNone(actor)
        with self.assertToolRaisesRuntimeError():
            ObjectTools.set_properties(actor, '{"ActorLabel": "new_label"}')

    def test_remove_from_scene_raises_in_locked_level_instance(self):
        """Ensures remove_from_scene raises when the actor is in a non-editing level instance."""
        if not self.original_level:
            self.skipTest('No level currently open.')
        actor = self._save_and_find_inner_actor()
        self.assertIsNotNone(actor)
        with self.assertToolRaisesRuntimeError():
            SceneTools.remove_from_scene(actor)
