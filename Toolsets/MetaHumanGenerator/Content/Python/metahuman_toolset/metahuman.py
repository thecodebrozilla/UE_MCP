# Copyright Epic Games, Inc. All Rights Reserved.

"""MetaHuman Generator toolset for AI-driven character creation and editing.

Provides tools for modifying MetaHuman character through a simplified API optimized for AI agents.
"""

from __future__ import annotations

import unreal
import toolset_registry

from metahuman_toolset.session import get_or_create_session, MetaHumanEditSession


_METAHUMAN_SUBSYSTEM = unreal.get_editor_subsystem(unreal.MetaHumanCharacterEditorSubsystem)

_METAHUMAN_WRAPPER = unreal.MetaHumanGeneratorSubsystemWrapper

_BODY_PARAM_MASCULINE_FEMININE = "Masculine/Feminine"
_BODY_PARAM_FAT = "Fat"
_BODY_PARAM_MUSCULARITY = "Muscularity"
_BODY_PARAM_HEIGHT = "Height"

_BODY_PARAM_NAMES = {_BODY_PARAM_MASCULINE_FEMININE, _BODY_PARAM_FAT, _BODY_PARAM_MUSCULARITY, _BODY_PARAM_HEIGHT}


def _get_body_constraints_and_ranges(character: unreal.Object) -> tuple[list, dict[str, tuple[float, float]]]:
    """Get body constraints and extract parameter ranges."""
    body_constraints = _METAHUMAN_SUBSYSTEM.get_body_constraints(
        character=character,
        scale_measurement_ranges_with_height=False
    )
    if not body_constraints:
        raise RuntimeError("Failed to get body constraints from character")

    param_ranges = {}
    for constraint in body_constraints:
        constraint_name = str(constraint.name)
        if constraint_name in _BODY_PARAM_NAMES:
            param_ranges[constraint_name] = (float(constraint.min_measurement), float(constraint.max_measurement))

    if not param_ranges:
        raise RuntimeError("No body parameters found in character constraints")

    return body_constraints, param_ranges


@unreal.ustruct()
class EyeColor(unreal.StructBase):
    """
    MetaHuman eye color parameters.

    EXAMPLES
    - light blue: (0.1, 0.9)
    - dark brown: (0.9, 0.1)
    - medium hazel: (0.7, 0.4)
    - greenish gray: (0.3, 0.6)
    - amber: (0.8, 0.7)
    - dark gray-blue: (0.2, 0.2)
    """

    temperature = unreal.uproperty(
        float, meta={'ClampMin': 0.0, 'ClampMax': 1.0, 'ToolTip': 'Temperature: 0.0=cool (blue, gray, green), 1.0=warm (brown, amber, hazel)'}
    )
    brightness = unreal.uproperty(
        float, meta={'ClampMin': 0.0, 'ClampMax': 1.0, 'ToolTip': 'Brightness: 0.0=dark, 1.0=light'}
    )


@unreal.ustruct()
class SkinTone(unreal.StructBase):
    """
    MetaHuman skin tone parameters.

    EXAMPLES
    - very pale cool: [0.06, 0.12]
    - pale: [0.10, 0.45]
    - light rosy: [0.18, 0.88]
    - light warm: [0.18, 0.75]
    - medium neutral: [0.50, 0.45]
    - tan golden: [0.60, 0.65]
    - olive: [0.50, 0.30]
    - medium-dark cool: [0.72, 0.12]
    - dark neutral: [0.85, 0.45]
    - very dark warm: [0.93, 0.75]
    - very dark cool: [0.93, 0.12]
    - darkest reddish brown: [0.98, 0.88]
    """

    lightness = unreal.uproperty(
        float, meta={'ClampMin': 0.0, 'ClampMax': 1.0, 'ToolTip': 'Lightness (0..1). 0=light, 1=dark'}
    )
    redness = unreal.uproperty(
        float, meta={'ClampMin': 0.0, 'ClampMax': 1.0, 'ToolTip': 'Redness (0..1). 0=cool, 1=red'}
    )


@unreal.ustruct()
class BodyShape(unreal.StructBase):
    """
    MetaHuman body parameters.

    RULES
    - Unset fields mean 'do not change'
    - Keep proportions realistic; avoid extremes unless clearly requested.
    - Avoid fat < 0.25 AND muscularity < 0.25 unless user explicitly asks for gaunt/emaciated.

    EXAMPLES (approximate targets)
    - athletic woman: masculine_feminine=0.80, fat=0.25, muscularity=0.70, height_cm=168
    - muscular man: masculine_feminine=0.20, fat=0.25, muscularity=0.80, height_cm=178
    - petite girl: masculine_feminine=0.90, fat=0.30, muscularity=0.35, height_cm=155
    - stocky middle-aged man: masculine_feminine=0.20, fat=0.70, muscularity=0.50, height_cm=175
    """

    # [5.7 port] uproperty type was the optional tuple (float, None); UE 5.7's
    # reflection cannot build an optional-scalar struct property ("Failed to
    # create property ... (tuple)"). Use a plain float and treat any negative
    # value as "unset / do not change" (all valid ranges are >= 0). Defaults to
    # -1.0 below so a freshly constructed BodyShape leaves every field unchanged.
    masculine_feminine = unreal.uproperty(
        float, meta={'ClampMin': -1.0, 'ClampMax': 1.0, 'ToolTip': 'Masculine/feminine (0..1). 0=masculine, 1=feminine. Negative = leave unchanged'}
    )
    fat = unreal.uproperty(
        float, meta={'ClampMin': -1.0, 'ClampMax': 1.0, 'ToolTip': 'Body fat (0..1). 0=lean, 1=overweight. Negative = leave unchanged'}
    )
    muscularity = unreal.uproperty(
        float, meta={'ClampMin': -1.0, 'ClampMax': 1.0, 'ToolTip': 'Muscle definition (0..1). 0=no muscle, 1=extreme muscle. Negative = leave unchanged'}
    )
    height_cm = unreal.uproperty(
        float, meta={'ClampMin': -1.0, 'ClampMax': 220.0, 'ToolTip': 'Height in centimeters (135..220). Negative = leave unchanged'}
    )


@unreal.uclass()
class MetaHumanToolset(unreal.ToolsetDefinition):
    """Tools for creating and editing MetaHuman characters"""

    @toolset_registry.tool_call
    def begin_edit(object_path: str) -> MetaHumanEditSession:
        """Begin editing a MetaHuman character. Call this FIRST before any other MetaHuman tools.

        Args:
            object_path: Asset path

        Returns:
            Session to pass to other tools

        IMPORTANT: Always call end_edit() when done to commit changes.
        """
        return get_or_create_session(object_path, cache=True)

    @toolset_registry.tool_call
    def end_edit(session: MetaHumanEditSession) -> None:
        """End editing a MetaHuman character. Call this LAST after all modifications.

        Args:
            session: Session from begin_edit()
        """
        session.finalize()

    @toolset_registry.tool_call
    def get_body_shape(session: MetaHumanEditSession) -> BodyShape:
        """Get MetaHuman body shape parameters.

        Args:
            session: Session from begin_edit()

        Returns:
            Current body shape parameters
        """
        body_constraints, param_ranges = _get_body_constraints_and_ranges(session.character)
        params_scaled = {}
        for constraint in body_constraints:
            name = str(constraint.name)
            if name not in _BODY_PARAM_NAMES:
                continue

            raw_value = constraint.target_measurement
            if name == _BODY_PARAM_HEIGHT:
                scaled_value = unreal.MathLibrary.f_clamp(raw_value, param_ranges[name][0], param_ranges[name][1])
            else:
                normalized = unreal.MathLibrary.normalize_to_range(raw_value, param_ranges[name][0], param_ranges[name][1])
                scaled_value = unreal.MathLibrary.f_clamp(normalized, 0.0, 1.0)
            params_scaled[name] = scaled_value

        # [5.7 port] Fields are plain floats now (no optional); use -1.0 to mean
        # "not constrained / unchanged" for params that have no active constraint.
        body_shape = BodyShape()
        body_shape.masculine_feminine = params_scaled.get(_BODY_PARAM_MASCULINE_FEMININE, -1.0)
        body_shape.fat = params_scaled.get(_BODY_PARAM_FAT, -1.0)
        body_shape.muscularity = params_scaled.get(_BODY_PARAM_MUSCULARITY, -1.0)
        body_shape.height_cm = params_scaled.get(_BODY_PARAM_HEIGHT, -1.0)
        return body_shape

    @toolset_registry.tool_call
    def set_body_shape(session: MetaHumanEditSession, body_shape: BodyShape) -> None:
        """Set MetaHuman body shape.

        Args:
            session: Session from begin_edit()
            body_shape: Body shape parameters to apply
        """
        # [5.7 port] Fields are plain floats now; a negative value means "leave
        # this parameter unchanged" (was None in the original optional form).
        if all(v < 0.0 for v in [body_shape.masculine_feminine, body_shape.fat, body_shape.muscularity, body_shape.height_cm]):
            unreal.log_warning(f"[MetaHumanGenerator] set_body_shape called with no parameters for {session.object_path}")
            return

        body_constraints, param_ranges = _get_body_constraints_and_ranges(session.character)
        constraints_dict = {str(c.name): c for c in body_constraints}

        updates = []
        if body_shape.masculine_feminine >= 0.0:
            updates.append((_BODY_PARAM_MASCULINE_FEMININE, body_shape.masculine_feminine))
        if body_shape.fat >= 0.0:
            updates.append((_BODY_PARAM_FAT, body_shape.fat))
        if body_shape.muscularity >= 0.0:
            updates.append((_BODY_PARAM_MUSCULARITY, body_shape.muscularity))
        if body_shape.height_cm >= 0.0:
            updates.append((_BODY_PARAM_HEIGHT, body_shape.height_cm))

        for name, value in updates:
            if name not in constraints_dict:
                continue
            constraint = constraints_dict[name]
            constraint.is_active = True
            if name == _BODY_PARAM_HEIGHT:
                constraint.target_measurement = unreal.MathLibrary.f_clamp(value, param_ranges[name][0], param_ranges[name][1])
            else:
                clamped = unreal.MathLibrary.f_clamp(value, 0.0, 1.0)
                constraint.target_measurement = unreal.MathLibrary.lerp(param_ranges[name][0], param_ranges[name][1], clamped)

        _METAHUMAN_SUBSYSTEM.set_body_constraints(
            character=session.character,
            body_constraints=list(constraints_dict.values())
        )
        _METAHUMAN_SUBSYSTEM.commit_body_state(character=session.character)
        _METAHUMAN_WRAPPER.reset_neck_to_body(session.character)
        unreal.log(f"[MetaHumanGenerator] Body shape applied to {session.object_path}")

    @toolset_registry.tool_call
    def get_skin_tone(session: MetaHumanEditSession) -> SkinTone:
        """Get MetaHuman skin tone.

        Args:
            session: Session from begin_edit()

        Returns:
            Current skin tone parameters
        """
        skin_settings = session.character.skin_settings
        skin_tone = SkinTone()
        skin_tone.lightness = skin_settings.skin.u
        skin_tone.redness = skin_settings.skin.v
        return skin_tone

    @toolset_registry.tool_call
    def set_skin_tone(session: MetaHumanEditSession, skin_tone: SkinTone) -> None:
        """Set MetaHuman skin tone.

        Args:
            session: Session from begin_edit()
            skin_tone: Skin tone parameters to apply
        """
        skin_settings = session.character.skin_settings
        skin_settings.skin.u = skin_tone.lightness
        skin_settings.skin.v = skin_tone.redness

        _METAHUMAN_SUBSYSTEM.commit_skin_settings(character=session.character, skin_settings=skin_settings)
        unreal.log(f"[MetaHumanGenerator] Skin tone applied to {session.object_path}")

    @toolset_registry.tool_call
    def get_eye_color(session: MetaHumanEditSession) -> EyeColor:
        """Get MetaHuman eye color.

        Args:
            session: Session from begin_edit()

        Returns:
            Current eye color parameters
        """
        eyes_settings = session.character.eyes_settings
        eye_color = EyeColor()
        eye_color.temperature = eyes_settings.eye_right.iris.primary_color_u
        eye_color.brightness = eyes_settings.eye_right.iris.primary_color_v
        return eye_color

    @toolset_registry.tool_call
    def set_eye_color(session: MetaHumanEditSession, eye_color: EyeColor) -> None:
        """Set MetaHuman eye color.

        Args:
            session: Session from begin_edit()
            eye_color: Eye color parameters to apply
        """
        eyes_settings = session.character.eyes_settings

        eyes_settings.eye_right.iris.primary_color_u = eye_color.temperature
        eyes_settings.eye_right.iris.primary_color_v = eye_color.brightness
        eyes_settings.eye_right.iris.secondary_color_u = eye_color.temperature
        eyes_settings.eye_right.iris.secondary_color_v = eye_color.brightness

        eyes_settings.eye_left.iris.primary_color_u = eye_color.temperature
        eyes_settings.eye_left.iris.primary_color_v = eye_color.brightness
        eyes_settings.eye_left.iris.secondary_color_u = eye_color.temperature
        eyes_settings.eye_left.iris.secondary_color_v = eye_color.brightness

        _METAHUMAN_SUBSYSTEM.commit_eyes_settings(
            character=session.character,
            eyes_settings=eyes_settings
        )
        unreal.log(f"[MetaHumanGenerator] Eye color applied to {session.object_path}")

    @toolset_registry.tool_call
    def create(asset_path: str) -> unreal.MetaHumanCharacter:
        """Create a new MetaHuman character asset.

        Args:
            asset_path: Asset path where the MetaHuman will be created

        Returns:
            Created MetaHuman character asset
        """
        asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
        asset_pkg = unreal.Paths.get_path(asset_path)
        asset_name = unreal.Paths.get_base_filename(asset_path)

        factory = unreal.new_object(type=unreal.MetaHumanCharacterFactoryNew)
        asset = asset_tools.create_asset(
            asset_name=asset_name,
            package_path=asset_pkg,
            asset_class=unreal.MetaHumanCharacter,
            factory=factory
        )

        if not asset:
            raise RuntimeError(f"Failed to create MetaHuman asset at {asset_path}")
        unreal.log(f"[MetaHumanGenerator] Created MetaHuman asset at {asset_path}")
        return asset
