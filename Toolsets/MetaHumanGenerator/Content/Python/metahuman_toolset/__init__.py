# Copyright Epic Games, Inc. All Rights Reserved.

def _reload():
    """Reload metahuman_toolset package modules.

    Use during development to reload modules that have changed.

    Usage:
        import metahuman_toolset
        metahuman_toolset._reload()
    """
    import importlib
    import sys
    import unreal

    package_name = 'metahuman_toolset'
    modules_to_reload = []
    package_to_reload = None

    for module_name, module in sys.modules.items():
        if module_name == package_name:
            package_to_reload = module
        elif module_name.startswith(package_name + '.'):
            if hasattr(module, '__file__') and module.__file__ is not None:
                modules_to_reload.append(module)

    for module in modules_to_reload:
        importlib.reload(module)
        unreal.log(f"[MetaHumanGenerator] Reloaded {module}")

    if package_to_reload:
        importlib.reload(package_to_reload)
        unreal.log(f"[MetaHumanGenerator] Reloaded {package_to_reload}")
