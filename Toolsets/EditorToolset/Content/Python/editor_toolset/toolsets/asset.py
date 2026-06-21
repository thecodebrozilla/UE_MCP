# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import json
import os

import unreal

import toolset_registry
from toolset_registry.helpers import asset_exists, create_asset


def require_factory_supports(source_file: str, factory: unreal.Factory) -> None:
    """Asserts source_file's extension is one factory declares in its Formats list."""
    ext = os.path.splitext(source_file)[1].lower().lstrip('.')
    allowed = {entry.split(';', 1)[0].lower() for entry in factory.formats}
    if ext not in allowed:
        raise ValueError(
            f'{type(factory).__name__} does not support ".{ext}" files. '
            f'Allowed: {sorted(allowed)}.')


def import_asset(
        folder_path: str, asset_name: str, source_file: str,
        factory: unreal.Factory | None = None,
        options: unreal.Object | None = None) -> list[unreal.Object]:
    """Imports a file from disk as one or more Unreal assets.

    Args:
        folder_path: The content-browser folder to import into (e.g. '/Game/Foo').
        asset_name: The name to give the imported asset. When the import produces
            multiple assets, additional names are derived from this base name.
        source_file: The absolute path to the file on disk to import.
        factory: Optional factory to drive the import. Pin this when the
            extension is ambiguous (e.g. .csv -> DataTable vs CurveTable) or
            when factory-specific options must be honored. Leave None to let
            the engine pick (which preserves the Interchange path).
        options: Optional factory-specific options object (e.g. unreal.FbxImportUI).

    Returns:
        Every asset produced by the import, in import order.
    """
    if not os.path.isfile(source_file):
        raise FileNotFoundError(f'Source file not found: {source_file}')
    if factory is not None:
        require_factory_supports(source_file, factory)
    if asset_exists(f'{folder_path}/{asset_name}'):
        raise RuntimeError(f'import_asset: {asset_name} at {folder_path} already exists')
    task = unreal.AssetImportTask()
    task.filename = source_file
    task.destination_path = folder_path
    task.destination_name = asset_name
    task.replace_existing = False
    task.automated = True
    task.save = False
    if factory is not None:
        task.factory = factory
    if options is not None:
        task.options = options
    unreal.AssetToolsHelpers.get_asset_tools().import_asset_tasks([task])
    paths = list(task.get_editor_property('imported_object_paths'))
    if not paths:
        raise RuntimeError(
            f'Import of "{source_file}" produced no assets. The file format may '
            f'not be supported or the file may be invalid.')
    return [unreal.load_asset(p) for p in paths]

@unreal.uclass()
class AssetTools(unreal.ToolsetDefinition):
    """Provides tools for interacting with assets in the Unreal project and files on disk."""

    @toolset_registry.tool_call
    @staticmethod
    def create_folder(path: str) -> bool:
        """Creates a folder at the specified path.

        Args:
            path: The project relative path at which to create the folder.

        Returns:
            True if the folder could be created or already exists.
        """
        eas = AssetTools._eas()
        return eas.does_directory_exist(path) or eas.make_directory(path)

    @toolset_registry.tool_call
    @staticmethod
    def list_folders(root_path: str, recursive: bool = True) -> list[str]:
        """Lists the folders contained within a folder.

        Args:
            root: The project relative path to the folder to search from.
            recursive: Subfolders will be searched when this is set to true.

        Returns:
            A list of paths to folders
        """
        eas = AssetTools._eas()
        found_items = eas.list_assets(root_path, recursive, True)
        folders: list[str] = []
        for item in found_items:
            assert isinstance(item, str)
            if eas.does_directory_exist(item):
                folders.append(item)
        return folders

    @toolset_registry.tool_call
    @staticmethod
    def exists(path: str) -> bool:
        """Determines if a folder or asset exists.

        Args:
            path: The path at which an asset or folder might exist.

        Returns:
            True if an asset or folder exists at the path. False otherwise.
        """
        return asset_exists(path)

    @toolset_registry.tool_call
    @staticmethod
    def duplicate(path: str, new_path: str) -> bool:
        """Makes a copy of a folder or asset.

        Args:
            path: The current location of folder or asset.
            new_path: The location of the copy.

        Returns:
            True if the copy happened successfully. False otherwise.
        """
        eas = AssetTools._eas()
        if eas.does_directory_exist(path):
            return eas.duplicate_directory(path, new_path)
        elif eas.does_asset_exist(path):
            return eas.duplicate_asset(path, new_path) is not None
        return False

    @toolset_registry.tool_call
    @staticmethod
    def move(path: str, new_path: str) -> bool:
        """Moves or renames an asset or folder.

        Args:
            path: The current location of the folder or asset.
            new_path: The new location and/or name.

        Returns:
            True if the rename happened successfully. False otherwise.
        """
        eas = AssetTools._eas()
        if eas.does_directory_exist(path):
            return eas.rename_directory(path, new_path)
        elif eas.does_asset_exist(path):
            return eas.rename_asset(path, new_path)
        return False

    @toolset_registry.tool_call
    @staticmethod
    def delete(path: str) -> bool:
        """Deletes an asset or folder.

        Args:
            path: The current location of the folder or asset.

        Returns:
            True if the delete happened successfully. False otherwise.
        """
        eas = AssetTools._eas()
        if eas.does_directory_exist(path):
            return eas.delete_directory(path)
        elif eas.does_asset_exist(path):
            return eas.delete_asset(path)
        return False

    @toolset_registry.tool_call
    @staticmethod
    def find_assets(
        folder_path: str, name: str = '', asset_type: unreal.Class | None = None,
        recursive: bool = True, tags: dict[str, str] | None = None) -> list[str]:
        """Searches the project for assets that match specific criteria.

        Args:
            folder_path: The folder to search within. Pass an empty string to search
                         the entire project (/Game/ and all plugin content folders including
                         project plugins and engine plugins).
            name: If set, will only return assets whose name contains this string
                  (case-insensitive).
            asset_type: If set, will only return assets that are of this type.
            recursive: Whether to search subfolders or not.
            tags: If set, will only return assets whose asset registry tags contain
                  all specified key-value pairs with exact value matches.

        Returns:
            A list of asset paths that match the criteria.
        """
        search_roots = (
            [folder_path] if folder_path else
            ['/Game/'] + list(AssetTools.get_plugin_content_paths(include_engine=True)))
        ar = unreal.AssetRegistryHelpers.get_asset_registry()
        ar_filter = unreal.ARFilter(
            package_paths=search_roots,
            recursive_paths=recursive,
            class_paths=[asset_type.get_class_path_name()] if asset_type else [],
            recursive_classes=bool(asset_type),
        )
        # get_assets covers native disk-indexed assets; get_in_memory_assets covers
        # newly created assets not yet saved; get_blueprint_assets covers Blueprint
        # assets whose parent class (at any inheritance depth) matches asset_type.
        asset_data_list = (
            list(ar.get_assets(ar_filter) or []) +
            list(ar.get_in_memory_assets(ar_filter) or []) +
            (list(unreal.AssetRegistryHelpers.get_blueprint_assets(ar_filter) or [])
             if asset_type else [])
        )

        seen: set[str] = set()
        name_lower = name.lower()
        found_assets: list[str] = []
        for ad in asset_data_list:
            package_name = str(ad.package_name)
            parts = package_name.split('/')
            if (package_name in seen or
                (name and name_lower not in str(ad.asset_name).lower()) or
                # Skip per-actor level assets (legacy Actors/ and WP __ExternalActors__);
                # these are scene actors and should be used via the actor interface.
                'Actors' in parts or '__ExternalActors__' in parts):
                continue
            if tags and any(
                    ad.get_tag_value(k) is None or str(ad.get_tag_value(k)) != v
                    for k, v in tags.items()):
                continue
            seen.add(package_name)
            found_assets.append(package_name)
        return found_assets

    @toolset_registry.tool_call
    @staticmethod
    def get_asset_tags(asset_path: str) -> dict[str, str]:
        """Gets the asset registry tags for an asset.

        Args:
            asset_path: Content path to the asset.

        Returns:
            A dict mapping tag names to their string values.
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        raw = AssetTools._eas().get_tag_values(package_path)
        return {str(k): str(raw[k]) for k in raw}

    @toolset_registry.tool_call
    @staticmethod
    def get_asset_class(asset_path: str) -> str:
        """Gets the class of an asset.

        Args:
            asset_path: Content path to the asset.

        Returns:
            The class name of the asset (e.g. 'StaticMesh', 'Material', 'HeroCharacter_C').
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        ar = unreal.AssetRegistryHelpers.get_asset_registry()
        asset_data_list = ar.get_assets_by_package_name(package_path)
        assert asset_data_list, f'Unexpected: asset exists but not in registry: {package_path}'
        ad = asset_data_list[0]
        blueprint_class_path = unreal.Blueprint.static_class().get_class_path_name()
        derived_blueprint_classes = ar.get_derived_class_names([blueprint_class_path], set())
        if (ad.asset_class_path == blueprint_class_path or
                ad.asset_class_path in derived_blueprint_classes):
            return f'{str(ad.asset_name)}_C'
        return str(ad.asset_class_path.asset_name)

    @toolset_registry.tool_call
    @staticmethod
    def get_metadata_tags(asset_path: str) -> dict[str, str]:
        """Gets the metadata tags for an asset.

        Args:
            asset_path: Content path to the asset.

        Returns:
            A dict mapping tag names to their string values.
        """
        asset = AssetTools.load_asset(asset_path)
        return dict(AssetTools._eas().get_metadata_tag_values(asset))

    @toolset_registry.tool_call
    @staticmethod
    def update_metadata_tags(
            asset_path: str,
            set_tags: dict[str, str] | None = None,
            remove_tags: list[str] | None = None) -> None:
        """Sets or removes metadata tags on an asset.

        Args:
            asset_path: Content path to the asset.
            set_tags: Tag names mapped to the values to set.
            remove_tags: Tag names to remove. Removing a tag that does not
                         exist is a no-op.
        """
        asset = AssetTools.load_asset(asset_path)
        eas = AssetTools._eas()
        for tag, value in (set_tags or {}).items():
            eas.set_metadata_tag(asset, tag, value)
        for tag in (remove_tags or []):
            eas.remove_metadata_tag(asset, tag)

    @toolset_registry.tool_call
    @staticmethod
    def load_asset(asset_path: str) -> unreal.Object:
        """Loads an asset from the project.

        Args:
            asset_path: The path to the asset to load.

        Returns:
            The loaded asset.
        """
        asset = unreal.load_asset(asset_path)
        assert isinstance(asset, unreal.Object), f'Unable to load {asset_path}'
        return asset

    @toolset_registry.tool_call
    @staticmethod
    def save_assets(asset_paths: list[str]) -> bool:
        """Saves assets to disk.

        Args:
            asset_paths: The paths to the assets to save. Pass an empty list to save
                         all dirty assets.

        Returns:
            True if all assets were saved successfully.
        """
        if not asset_paths:
            unreal.EditorLoadingAndSavingUtils.save_dirty_packages(True, True)
            return True
        eas = AssetTools._eas()
        results = []
        for path in asset_paths:
            if not AssetTools.exists(path):
                raise ValueError(f'Asset does not exist: {path}')
            results.append(eas.save_asset(path))
        return all(results)

    @toolset_registry.tool_call
    @staticmethod
    def is_dirty(asset_path: str) -> bool:
        """Checks whether an asset has unsaved changes.

        Args:
            asset_path: The path to the asset to check.

        Returns:
            True if the asset has unsaved changes, False if it is saved.
        """
        if not AssetTools.exists(asset_path):
            raise ValueError(f'Asset does not exist: {asset_path}')
        dirty_packages = (
            list(unreal.EditorLoadingAndSavingUtils.get_dirty_content_packages()) +
            list(unreal.EditorLoadingAndSavingUtils.get_dirty_map_packages()))
        return (any(pkg.get_path_name() == asset_path for pkg in dirty_packages) or
           not AssetTools._is_on_disk(asset_path))

    @toolset_registry.tool_call
    @staticmethod
    def can_edit_asset(asset_path: str) -> bool:
        """Checks whether an asset can be edited.

        Args:
            asset_path: Content path to the asset.

        Returns:
            True if the asset can be edited, False if it is checked out
            or locked by another user in source control. Always True
            when source control is not enabled.
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        state = AssetTools._sc_state(package_path)
        return True if state is None else not state.is_checked_out_other

    @toolset_registry.tool_call
    @staticmethod
    def is_checked_out(asset_path: str) -> bool:
        """Checks whether an asset is checked out by the current user.

        Args:
            asset_path: Content path to the asset.

        Returns:
            True if the asset is currently checked out by the current user.
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        state = AssetTools._sc_state(package_path)
        return False if state is None else state.is_checked_out

    @toolset_registry.tool_call
    @staticmethod
    def get_referencers(asset_path: str) -> list[str]:
        """Lists assets that reference the specified asset.

        Args:
            asset_path: Content path to the asset.

        Returns:
            A list of content paths for assets that reference the given asset.
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        options = unreal.AssetRegistryDependencyOptions()
        referencers = registry.get_referencers(package_path, options)
        return [str(r) for r in referencers]

    @toolset_registry.tool_call
    @staticmethod
    def get_dependencies(asset_path: str) -> list[str]:
        """Lists assets that the specified asset depends on.

        Args:
            asset_path: Content path to the asset.

        Returns:
            A list of content paths for assets that the given asset depends on.
        """
        package_path = AssetTools._to_package_path(asset_path)
        if not AssetTools._eas().does_asset_exist(package_path):
            raise ValueError(f'Asset does not exist: {package_path}')
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        options = unreal.AssetRegistryDependencyOptions()
        dependencies = registry.get_dependencies(package_path, options)
        return [str(dep) for dep in dependencies]

    @toolset_registry.tool_call
    @staticmethod
    def get_plugin_content_paths(include_engine: bool = False) -> list[str]:
        """Returns the root content paths for plugins that have content.

        Args:
            include_engine: When True, also includes content plugins under the Engine directory.

        Returns:
            A list of virtual content root paths (e.g. ['/PluginName/']) for each
            in-scope plugin that has a content directory.
        """
        paths: list[str] = []
        for _, name in AssetTools._iter_content_plugin_base_dirs(include_engine):
            path = unreal.PluginBlueprintLibrary.get_plugin_mounted_asset_path(name)
            if path:
                paths.append(path)
        return paths

    @staticmethod
    def _iter_content_plugin_base_dirs(include_engine: bool):
        """Yields (full_base_dir, name) for each enabled plugin whose descriptor
        declares CanContainContent and that lives under <project>/Plugins/ (and,
        if include_engine, <engine>/Plugins/).
        """
        # Trailing '/' is load-bearing: prevents <root>/Plugins matching <root>/PluginsX/...
        def _full(p: str) -> str:
            return unreal.Paths.normalize_directory_name(
                unreal.Paths.convert_relative_path_to_full(p)) + '/'
        allowed_dirs = [_full(unreal.Paths.project_plugins_dir())]
        if include_engine:
            allowed_dirs.append(_full(unreal.Paths.engine_plugins_dir()))
        for name in unreal.PluginBlueprintLibrary.get_enabled_plugin_names():
            base_dir = unreal.PluginBlueprintLibrary.get_plugin_base_dir(name)
            if not base_dir:
                continue
            full_base = unreal.Paths.convert_relative_path_to_full(base_dir)
            if not any(full_base.startswith(d) for d in allowed_dirs):
                continue
            if not AssetTools._plugin_can_contain_content(name):
                continue
            yield full_base, name

    _MAX_READ_FILE_BYTES = 80 * 1024

    @toolset_registry.tool_call
    @staticmethod
    def read_file(file_path: str) -> str:
        """Reads a text file from disk and returns its contents.

        Only files under /Game/, an enabled plugin's Content/ directory, or
        the project Saved/ directory may be read. Only plain text formats are
        supported.

        Args:
            file_path: The path to the file to read.

        Returns:
            The text content of the file.
        """
        full_path = AssetTools._require_allowed_path(file_path)
        _, ext = os.path.splitext(full_path)
        if ext.lower() not in AssetTools._WRITABLE_EXTENSIONS:
            raise ValueError(
                f'Unsupported file extension "{ext}". '
                f'Allowed: {sorted(AssetTools._WRITABLE_EXTENSIONS)}')
        if not os.path.isfile(full_path):
            raise FileNotFoundError(f'File not found: {full_path}')
        size = os.path.getsize(full_path)
        if size > AssetTools._MAX_READ_FILE_BYTES:
            raise ValueError(
                f'File is too large to read ({size:,} bytes). '
                f'Maximum allowed size is {AssetTools._MAX_READ_FILE_BYTES:,} bytes. '
                'Use a Python script tool call to extract only the relevant '
                'data from the file programmatically.')
        with open(full_path, encoding='utf-8') as f:
            return f.read()

    _WRITABLE_EXTENSIONS = {'.txt', '.json', '.csv', '.html', '.py', '.md'}

    @toolset_registry.tool_call
    @staticmethod
    def write_file(file_path: str, content: str) -> None:
        """Writes text content to a file on disk.

        Only files under /Game/, an enabled plugin's Content/ directory, or
        the project Saved/ directory may be written. Only plain text formats
        are supported. Overwrites the file if it already exists.

        Args:
            file_path: The path to the file to write.
            content: The text content to write.
        """
        full_path = AssetTools._require_allowed_path(file_path)
        _, ext = os.path.splitext(full_path)
        if ext.lower() not in AssetTools._WRITABLE_EXTENSIONS:
            raise ValueError(
                f'Unsupported file extension "{ext}". '
                f'Allowed: {sorted(AssetTools._WRITABLE_EXTENSIONS)}')
        if os.path.exists(full_path) and not os.access(full_path, os.W_OK):
            if not AssetTools._check_out_file(full_path):
                raise RuntimeError(f'File is not writable and could not be checked out: {full_path}')
        os.makedirs(os.path.dirname(full_path), exist_ok=True)
        with open(full_path, 'w', encoding='utf-8') as f:
            f.write(content)

    @staticmethod
    def _require_allowed_path(file_path: str) -> str:
        """Resolves file_path and asserts it is under an allowed root."""
        def _under(root: str, path: str) -> bool:
            return path == root or path.startswith(root + os.sep)

        full_path = AssetTools._normalize_fs_path(file_path)
        roots = AssetTools._get_allowed_file_roots()
        if not any(_under(r, full_path) for r in roots):
            raise ValueError(
                f'Path "{full_path}" is not within an allowed root. '
                f'Allowed roots: {roots}')
        return full_path

    @staticmethod
    def _get_allowed_file_roots() -> list[str]:
        """Returns the filesystem roots read_file/write_file may access."""
        roots = [AssetTools._normalize_fs_path(unreal.Paths.project_content_dir()),
                 AssetTools._normalize_fs_path(unreal.Paths.project_saved_dir())]
        for full_base, _ in AssetTools._iter_content_plugin_base_dirs(include_engine=True):
            roots.append(AssetTools._normalize_fs_path(os.path.join(full_base, 'Content')))
        return roots

    @staticmethod
    def _normalize_fs_path(p: str) -> str:
        """Resolves a path to an absolute, symlink-resolved, case-normalized form."""
        return os.path.normcase(os.path.realpath(
            unreal.Paths.convert_relative_path_to_full(p)))

    @staticmethod
    def _plugin_can_contain_content(name: str) -> bool:
        """Returns True if the plugin descriptor has CanContainContent set to True."""
        descriptor = unreal.PluginBlueprintLibrary.get_plugin_descriptor_file_path(name)
        if not descriptor:
            return False
        try:
            full_path = unreal.Paths.convert_relative_path_to_full(descriptor)
            with open(full_path) as f:
                data = json.load(f)
            return bool(data.get('CanContainContent', False))
        except json.JSONDecodeError:
            return False

    @staticmethod
    def _sc_state(package_path: str) -> unreal.SourceControlState | None:
        """Returns the source control state for a package, or None if SC is not enabled."""
        if not unreal.SourceControl.is_enabled():
            return None
        return unreal.SourceControl.query_file_state(package_path, True)

    @staticmethod
    def _to_package_path(path: str) -> str:
        """Normalize full object paths to package paths.

        Tools like find_assets return full object paths
        (e.g. "/Game/Foo/Bar.Bar"), but the AssetRegistry APIs
        expect package paths ("/Game/Foo/Bar").
        """
        dot_index = path.find('.')
        return path[:dot_index] if dot_index >= 0 else path

    @staticmethod
    def _is_on_disk(asset_path: str) -> bool:
        """Determines if an asset has a backing file on disk.

        An asset can exist in memory without a corresponding file on disk —
        for example, a newly duplicated asset that has not yet been saved.
        Use this to distinguish between in-memory-only assets and assets that
        are backed by a saved file.

        Args:
            asset_path: The path to the asset to check.

        Returns:
            True if a file exists on disk for this asset. False if the asset
            only exists in memory.
        """
        registry = unreal.AssetRegistryHelpers.get_asset_registry()
        return bool(registry.get_assets_by_package_name(
            asset_path, include_only_on_disk_assets=True))

    @staticmethod
    def _check_out_file(full_path: str) -> bool:
        return unreal.SourceControl.check_out_file(full_path, silent=True)

    @staticmethod
    def _eas() -> unreal.EditorAssetSubsystem:
        eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
        assert eas
        return eas
