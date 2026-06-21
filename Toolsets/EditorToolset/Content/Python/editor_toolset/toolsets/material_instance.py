# Copyright Epic Games, Inc. All Rights Reserved.
"""Material instance toolset."""

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset


@unreal.uenum()
class MaterialParameterType(unreal.EnumBase): # pylint: disable=too-few-public-methods
    """The type of a material parameter."""
    Scalar = unreal.uvalue(0)
    Vector = unreal.uvalue(1)
    Texture = unreal.uvalue(2)
    StaticSwitch = unreal.uvalue(3)


@unreal.ustruct()
class MaterialParameter(unreal.StructBase): # pylint: disable=too-few-public-methods
    """Describes a single parameter exposed by a material or material instance.

    Attributes:
        name: The parameter name as defined in the material graph.
        type: The parameter type.
    """
    name = unreal.uproperty(str)
    type = unreal.uproperty(MaterialParameterType)


_PARAMETER_NAME_SETTERS = {
    MaterialParameterType.Scalar:
        unreal.MaterialEditingLibrary.set_material_instance_scalar_parameter_value,
    MaterialParameterType.Vector:
        unreal.MaterialEditingLibrary.set_material_instance_vector_parameter_value,
    MaterialParameterType.Texture:
        unreal.MaterialEditingLibrary.set_material_instance_texture_parameter_value,
    MaterialParameterType.StaticSwitch:
        unreal.MaterialEditingLibrary.set_material_instance_static_switch_parameter_value,
}

_PARAMETER_NAME_GETTERS = {
    MaterialParameterType.Scalar: (
        unreal.MaterialEditingLibrary.get_scalar_parameter_names
    ),
    MaterialParameterType.Vector: (
        unreal.MaterialEditingLibrary.get_vector_parameter_names
    ),
    MaterialParameterType.Texture: (
        unreal.MaterialEditingLibrary.get_texture_parameter_names
    ),
    MaterialParameterType.StaticSwitch: (
        unreal.MaterialEditingLibrary.get_static_switch_parameter_names
    ),
}

_PARAMETER_VALUE_GETTERS = {
    MaterialParameterType.Scalar:
        unreal.MaterialEditingLibrary.get_material_instance_scalar_parameter_value,
    MaterialParameterType.Vector:
        unreal.MaterialEditingLibrary.get_material_instance_vector_parameter_value,
    MaterialParameterType.Texture:
        unreal.MaterialEditingLibrary.get_material_instance_texture_parameter_value,
    MaterialParameterType.StaticSwitch:
        unreal.MaterialEditingLibrary.get_material_instance_static_switch_parameter_value,
}


@unreal.uclass()
class MaterialInstanceTools(unreal.ToolsetDefinition):
    """Provides tools for creating and modifying MaterialInstanceConstant assets."""

    # -------------------------------------------------------------------------
    # Asset creation
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def create(
            folder_path: str,
            asset_name: str,
            parent: unreal.MaterialInterface) -> unreal.MaterialInstanceConstant:
        """Creates a new MaterialInstanceConstant asset derived from a parent material.

        Material instances expose the parent's parameters without triggering a full
        shader recompile when parameter values change.

        Args:
            folder_path: The content-browser path to the folder for the new asset.
            asset_name: The name of the new asset.
            parent: The parent Material or MaterialInstance to derive from.

        Returns:
            The newly created MaterialInstanceConstant.
        """
        instance = create_asset(
            folder_path, asset_name,
            unreal.MaterialInstanceConstant.static_class(),
            unreal.MaterialInstanceConstantFactoryNew())
        assert isinstance(instance, unreal.MaterialInstanceConstant)
        unreal.MaterialEditingLibrary.set_material_instance_parent(instance, parent)
        return instance

    # -------------------------------------------------------------------------
    # Parameter discovery
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def list_parameters(material: unreal.MaterialInterface) -> list[MaterialParameter]:
        """Returns all parameters exposed by a material or instance, with their names and types.

        Args:
            material: The Material or MaterialInstance to query.

        Returns:
            A list of MaterialParameter entries, each with a name and a type.
        """
        params = []
        for type_val, getter in _PARAMETER_NAME_GETTERS.items():
            for n in getter(material):
                p = MaterialParameter()
                p.name = str(n)
                p.type = type_val
                params.append(p)
        return params

    # -------------------------------------------------------------------------
    # Parameter access
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def get_scalar_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str) -> float:
        """Gets the current value of a scalar parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to query.
            name: The parameter name.

        Returns:
            The effective scalar (float) value, inheriting from the parent if not overridden.
        """
        return MaterialInstanceTools._get_parameter(instance, name, MaterialParameterType.Scalar)

    @toolset_registry.tool_call
    @staticmethod
    def set_scalar_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            value: float) -> None:
        """Sets the value of a scalar parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to modify.
            name: The parameter name.
            value: The new scalar (float) value.
        """
        MaterialInstanceTools._set_parameter(instance, name, MaterialParameterType.Scalar, value)

    @toolset_registry.tool_call
    @staticmethod
    def get_vector_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str) -> unreal.LinearColor:
        """Gets the current value of a vector parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to query.
            name: The parameter name.

        Returns:
            The effective value as a LinearColor (RGBA), inheriting from the parent if
            not overridden.
        """
        return MaterialInstanceTools._get_parameter(instance, name, MaterialParameterType.Vector)

    @toolset_registry.tool_call
    @staticmethod
    def set_vector_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            value: unreal.LinearColor) -> None:
        """Sets the value of a vector parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to modify.
            name: The parameter name.
            value: The new value as a LinearColor (RGBA). Use values in the range 0–1
                for standard colors; values above 1 are valid for HDR and emissive.
        """
        MaterialInstanceTools._set_parameter(instance, name, MaterialParameterType.Vector, value)

    @toolset_registry.tool_call
    @staticmethod
    def get_texture_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str) -> unreal.Texture | None:
        """Gets the texture assigned to a texture parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to query.
            name: The parameter name.

        Returns:
            The assigned Texture, or None if the parameter is not overridden on this instance.
        """
        return MaterialInstanceTools._get_parameter(instance, name, MaterialParameterType.Texture)

    @toolset_registry.tool_call
    @staticmethod
    def set_texture_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            value: unreal.Texture) -> None:
        """Assigns a texture to a texture parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to modify.
            name: The parameter name.
            value: The Texture asset to assign.
        """
        MaterialInstanceTools._set_parameter(instance, name, MaterialParameterType.Texture, value)

    @toolset_registry.tool_call
    @staticmethod
    def get_static_switch_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str) -> bool:
        """Gets the value of a static switch parameter on a material instance.

        Note: Overriding static switch parameters triggers a shader recompile.

        Args:
            instance: The MaterialInstanceConstant to query.
            name: The parameter name.

        Returns:
            The effective boolean value, inheriting from the parent if not overridden.
        """
        return bool(MaterialInstanceTools._get_parameter(
            instance, name, MaterialParameterType.StaticSwitch))

    @toolset_registry.tool_call
    @staticmethod
    def set_static_switch_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            value: bool) -> None:
        """Sets the value of a static switch parameter on a material instance.

        Args:
            instance: The MaterialInstanceConstant to modify.
            name: The parameter name.
            value: The new boolean value.
        """
        MaterialInstanceTools._set_parameter(
            instance, name, MaterialParameterType.StaticSwitch, value)

    # -------------------------------------------------------------------------
    # Instance management
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def set_parent(
            instance: unreal.MaterialInstanceConstant,
            parent: unreal.MaterialInterface) -> None:
        """Changes the parent of a material instance.

        Args:
            instance: The MaterialInstanceConstant to modify.
            parent: The new parent Material or MaterialInstance.
        """
        unreal.MaterialEditingLibrary.set_material_instance_parent(instance, parent)
        MaterialInstanceTools._refresh_editor(instance)

    @toolset_registry.tool_call
    @staticmethod
    def clear_parameters(instance: unreal.MaterialInstanceConstant) -> None:
        """Clears all parameter overrides on a material instance, reverting to parent defaults.

        Args:
            instance: The MaterialInstanceConstant to clear.
        """
        unreal.MaterialEditingLibrary.clear_all_material_instance_parameters(instance)
        unreal.MaterialEditingLibrary.update_material_instance(instance)
        MaterialInstanceTools._refresh_editor(instance)

    @toolset_registry.tool_call
    @staticmethod
    def set_parameter_override(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            override: bool) -> None:
        """Enables or disables a parameter override on a material instance.

        Enabling sets the override to the current effective value. Disabling reverts
        to the parent. For non-static parameter types, disabling also discards the
        prior override value; re-enabling later restores the parent value, not the
        prior override. Static switches and static component masks preserve their
        value across toggle.

        Args:
            instance: The MaterialInstanceConstant to modify.
            name: The parameter name.
            override: True to enable the override, False to clear it.
        """
        # SetMaterialInstanceParameterOverride internally runs UpdateMaterialInstance + RebuildMaterialInstanceEditor;
        # _refresh_editor on top of that adds the Refresh() (viewport + property window) that the C++ path omits.
        success = unreal.MaterialEditingLibrary.set_material_instance_parameter_override(
            instance, name, override)
        if not success:
            raise ValueError(
                f'Parameter "{name}" not found in this material instance\'s hierarchy.')
        MaterialInstanceTools._refresh_editor(instance)

    # -------------------------------------------------------------------------
    # Private helpers
    # -------------------------------------------------------------------------

    @staticmethod
    def _get_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            expected_type: MaterialParameterType
        ) -> float | unreal.LinearColor | unreal.Texture | bool:
        if not isinstance(instance, unreal.MaterialInstanceConstant):
            raise AssertionError(f'{instance} is not a MaterialInstanceConstant.')
        names = [str(n) for n in _PARAMETER_NAME_GETTERS[expected_type](instance)]
        if name not in names:
            raise ValueError(
                f'Parameter "{name}" is not a {expected_type} parameter on the material.')
        return _PARAMETER_VALUE_GETTERS[expected_type](instance, name)

    @staticmethod
    def _set_parameter(
            instance: unreal.MaterialInstanceConstant,
            name: str,
            expected_type: MaterialParameterType,
            value: float | unreal.LinearColor | unreal.Texture | bool) -> None:
        if not isinstance(instance, unreal.MaterialInstanceConstant):
            raise AssertionError(f'{instance} is not a MaterialInstanceConstant.')
        names = [str(n) for n in _PARAMETER_NAME_GETTERS[expected_type](instance)]
        if name not in names:
            raise ValueError(
                f'Parameter "{name}" is not a {expected_type} parameter on the material.')
        _PARAMETER_NAME_SETTERS[expected_type](instance, name, value)
        unreal.MaterialEditingLibrary.update_material_instance(instance)
        # Unlike scalar/vector/texture, static switches always trigger a full
        # shader recompile which occurs asynchronously; flush it synchronously
        # to avoid a potential crash resulting from a data race that may occur
        # during object destruction in the case that the recompile hasn't
        # completed before the instance is garbage collected.
        if expected_type == MaterialParameterType.StaticSwitch:
            unreal.MaterialEditingLibrary.recompile_material(instance.get_base_material())
        MaterialInstanceTools._refresh_editor(instance)

    @staticmethod
    def _refresh_editor(instance: unreal.MaterialInstanceConstant) -> None:
        unreal.MaterialEditingLibrary.refresh_material_instance_editor(instance)
