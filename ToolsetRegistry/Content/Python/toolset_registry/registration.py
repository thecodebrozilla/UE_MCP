# Copyright Epic Games, Inc. All Rights Reserved.
"""Manages the registration of a set of toolsets."""

from typing import Sequence

import unreal

from ._registry_interface import get_toolset_registry, ToolsetRegistryProtocol


class Registration:
    """Manages the registration of a set of toolsets."""

    def __init__(self, toolset_classes: Sequence[unreal.ToolsetDefinition]):
        """Associate toolsets with a registration.

        Args:
            toolset_classes: Toolsets to associated with this registration.
        """
        self._toolset_classes: Sequence[type] = tuple(toolset_classes)

    @property
    def _registry(self) -> ToolsetRegistryProtocol:
        """Toolset registry."""
        return get_toolset_registry()

    def register(self) -> bool:
        """Register toolsets with the registry."""
        if not self._registry.is_available():
            return False

        for toolset_class in self._toolset_classes:
            self._registry.register_toolset_class(toolset_class)
        return True

    def unregister(self) -> None:
        """Unregister toolsets from the registry."""
        if not self._registry.is_available():
            return

        for toolset_class in self._toolset_classes:
            self._registry.unregister_toolset_class(toolset_class)
