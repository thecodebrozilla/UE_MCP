# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import unreal

import toolset_registry
from toolset_registry.helpers import require_editable

@unreal.uclass()
class ObjectTools(unreal.ToolsetDefinition):
    """Provides tools for inspecting and modifying the properties of
    Unreal Objects and Unreal Classes, including those in Blueprints.
    Also use this toolset to discover available classes and subclasses."""

    @toolset_registry.tool_call
    @staticmethod
    def search_subclasses(base_class: unreal.Class, class_name: str = '') -> list[unreal.SoftClassPath]:
        """Finds all subclasses of a given class.

        Args:
            base_class: The class to search subclasses of.
            class_name: Optional case-insensitive substring filter on the class path.

        Returns:
            A list of subclasses matching the filter.
        """
        derived = unreal.ToolsetLibrary.get_derived_classes(base_class)
        if not class_name:
            return derived
        return [c for c in derived if class_name.lower() in c.export_text().lower()]

    @toolset_registry.tool_call
    @staticmethod
    def get_class(instance: unreal.Object) -> unreal.Class:
        """Returns the class of an Unreal object.

        Args:
            instance: The object instance to query.

        Returns:
            The class of the object.
        """
        if isinstance(instance, unreal.Blueprint):
            return instance.generated_class()
        elif isinstance(instance, unreal.Class):
            return instance
        else:
            return instance.get_class()

    @toolset_registry.tool_call
    @staticmethod
    def list_properties(instance: unreal.Object) -> str:
        """Returns a list of properties that are on the specified object.

        Args:
            instance: The object to query.

        Returns:
            A list of properties on the object.
        """
        struct: unreal.Struct = (instance if isinstance(instance, unreal.Struct)
                                 else ObjectTools.get_class(instance))
        return unreal.ToolsetLibrary.list_struct_properties(struct)

    @toolset_registry.tool_call
    @staticmethod
    def get_properties(instance: unreal.Object, properties: list[str]) -> str:
        """Returns the values of one or more properties on an object.

        Args:
            instance: The the object to query.
            properties: The names of the properties to query.

        Returns:
            A JSON formatted string of the properties and their values.
        """
        return unreal.ToolsetLibrary.get_object_properties(
            ObjectTools._get_instance_object(instance), properties) # type: ignore

    @toolset_registry.tool_call
    @staticmethod
    def set_properties(instance: unreal.Object, values: str) -> bool:
        """Sets the values of properties on an object.

        Args:
            instance: The object with the property.
            values: A JSON formatted string of the properties to set and their values.
                For instanced sub-object properties, pass a class path as the instance member.

        Returns:
            True if the property was set. False otherwise.
        """
        obj = ObjectTools._get_instance_object(instance)
        require_editable(obj)
        return unreal.ToolsetLibrary.set_object_properties(obj, values)

    @toolset_registry.tool_call
    @staticmethod
    def reset_properties(instance: unreal.Object, properties: list[str]) -> bool:
        """Resets one or more properties on an object to their default values,
        removing any per-instance overrides.

        Args:
            instance: The object with the properties to reset.
            properties: The names of the properties to reset to their defaults.

        Returns:
            True if all properties were reset. False otherwise.
        """
        obj = ObjectTools._get_instance_object(instance)
        require_editable(obj)
        if isinstance(instance, unreal.Blueprint):
            archetype = unreal.get_default_object(instance.generated_class().get_super_class())
        else:
            archetype = unreal.get_default_object(obj.get_class())
        default_values = unreal.ToolsetLibrary.get_object_properties(archetype, properties)
        return unreal.ToolsetLibrary.set_object_properties(obj, default_values)

    @staticmethod
    def _get_instance_object(instance: unreal.Object) -> unreal.Object:
        """Returns the CDO when instance is a Blueprint, otherwise returns the instance."""
        return (unreal.get_default_object(instance.generated_class())
                if isinstance(instance, unreal.Blueprint) else instance)
