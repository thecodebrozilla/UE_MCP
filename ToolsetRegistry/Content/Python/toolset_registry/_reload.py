# Copyright Epic Games, Inc. All Rights Reserved.
"""Reload modules and reregister reloaded toolsets with the registry."""

from graphlib import CycleError, TopologicalSorter
import importlib
from typing import Any
from types import ModuleType
import sys

from ._unreal import get_unreal_module
from ._registry_interface import (
    find_toolset_classes, register_toolset_classes, unregister_toolset_classes
)


def _find_modules(top_module: ModuleType) -> list[ModuleType]:
    """Find the specified module / package and all modules under it.

    Args:
        top_module: Module to search from.
    """
    package_name = top_module.__name__
    modules: list[ModuleType] = []
    for module_name, module in sys.modules.items():
        is_in_or_is_package_module = (
            module_name == package_name or
            module_name.startswith(f'{package_name}.')
        )
        loaded_from_a_file = (
            hasattr(module, '__file__') and module.__file__ is not None
        )
        if is_in_or_is_package_module and loaded_from_a_file:
            modules.append(module)
    return modules


def _get_module_or_container_module_name(obj: Any) -> str:
    """Determine whether an object is a module or get the container module.

    Args:
        obj: Object to query.

    Returns:
        A module name if the object is a module, the container module name
        if object isn't a module and has a __module__ attribute, an empty
        string otherwise.
    """
    unreal = get_unreal_module()
    module_name = ''
    if isinstance(obj, ModuleType):
        module_name = obj.__name__
    elif isinstance(getattr(obj, '__module__', None), str):
        try:
            # Make sure the referenced module is loaded.
            # If a module is loaded manually (i.e outside of the import
            # mechanism) the module will not be installed in sys.modules.
            imported_module = sys.modules[obj.__module__]
            module_name = imported_module.__name__
        except Exception:  # pylint: disable=broad-exception-caught
            unreal.log_error(
                f'Module {obj.__module__} referenced by {obj} not '
                'found.'
            )
    return module_name


def _sort_by_import_order(modules: list[ModuleType]) -> list[ModuleType]:
    """Topologically sort modules by reverse import order.

    Args:
        modules: Module to sort.

    Returns:
        Modules sorted by reverse import order.
    """
    modules_by_name: dict[str, ModuleType] = {
        module.__name__: module for module in modules
    }
    module_graph: dict[str, set[str]] = {
        module.__name__: set() for module in modules
    }
    for module in modules:
        referenced_module_names = module_graph[module.__name__]
        for attr_name in dir(module):
            referenced_module_name = _get_module_or_container_module_name(
                getattr(module, attr_name, None)
            )
            if (
                referenced_module_name in modules_by_name and
                referenced_module_name != module.__name__
            ):
                referenced_module_names.add(referenced_module_name)

    sorted_modules: list[ModuleType] = []
    while True:
        sorter = TopologicalSorter(module_graph)
        try:
            sorted_modules = [
                modules_by_name[module_name]
                for module_name in sorter.static_order()
            ]
            break
        except CycleError as error:
            # Attempt to break the cycle.
            # pylint: disable-next=unbalanced-tuple-unpacking
            _, module_cycle = error.args[:2]
            importer_name = module_cycle[-1]
            imported_name = module_cycle[-2]
            module_graph[importer_name].remove(imported_name)
    return sorted_modules


def _reload_modules(modules: list[ModuleType]) -> list[str]:
    """Reload modules capturing any exceptions.

    Args:
        modules: Modules to reload.

    Returns:
        List of errors that occurred while reloading modules.
    """
    errors: list[str]  = []
    sorted_modules = _sort_by_import_order(modules)
    for module in sorted_modules:
        try:
            importlib.reload(module)
        # Can't just catch ImportError because PythonScriptPlugin raises
        # Exception on failure to generate class. Must catch in order to not
        # leave modules in broken state.
        except Exception as e:  # pylint: disable=broad-exception-caught
            errors.append(f'Failed to reload {module}: {str(e)}')
    return errors


def _get_class_name(cls: type) -> str:
    """Get the name of a class within its source module.

    Args:
        cls: Class to query.

    Returns:
        Name of the class within a module.
    """
    return f'{cls.__module__}.{cls.__name__}'


def _find_class(name: str) -> type | None:
    """Find a class.

    Args:
        name: Class name within a module.

    Returns:
        Class within the module or None if it's not found.
    """
    module_name, class_name = name.rsplit('.', maxsplit=1)
    try:
        module = sys.modules[module_name]
        return getattr(module, class_name, None)
    except KeyError:
        return None


def reload_module(top_module: ModuleType) -> None:
    """Reload a module and all its submodules, managing toolset registration.

    For any toolset classes found in the modules being reloaded that are
    currently registered, they are unregistered before reload and re-registered
    after.

    Args:
        top_module: The top-level module to reload. All submodules are also reloaded.
    """
    unreal = get_unreal_module()
    modules_to_reload = _find_modules(top_module)

    unregistered_toolset_class_names = [
        _get_class_name(toolset_class)
        for toolset_class in  unregister_toolset_classes(
            find_toolset_classes(modules_to_reload)
        )
    ]

    errors = _reload_modules(modules_to_reload)

    toolset_classes_to_reregister: list[type] = []
    for toolset_class_name in unregistered_toolset_class_names:
        toolset_class = _find_class(toolset_class_name)
        if toolset_class is None:
            errors.append(
                f'Cannot register {toolset_class_name} as it is not found'
            )
            continue
        toolset_classes_to_reregister.append(toolset_class)

    errors.extend(register_toolset_classes(toolset_classes_to_reregister))

    if errors:
        unreal.log_error(f'Errors reloading {top_module.__name__}:')
        for error in errors:
            unreal.log_error(error)
