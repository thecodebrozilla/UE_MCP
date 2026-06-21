# Copyright Epic Games, Inc. All Rights Reserved.

from __future__ import annotations

import os

import unreal

import toolset_registry
from toolset_registry.helpers import asset_exists
from editor_toolset.toolsets.asset import AssetTools

# [5.7 port] unreal.StringTable (UStringTable) is not exposed to Python on UE 5.7
# (UCLASS without BlueprintType and not referenced by any reflected signature), and
# the 5.8 StringTableLibrary helpers get_table_id / import_table_from_csv_* do not
# exist on 5.7. The bundled BlueprintGraphEditorPort plugin provides
# unreal.EditorToolsetCompatLibrary, a thin C++ shim that performs each StringTable
# operation directly on the asset (passed as a plain unreal.Object). All tool
# signatures therefore annotate the asset as unreal.Object so the tools register and
# function on 5.7; the shim Cast<UStringTable>s internally.
#
# Note: the shim is referenced inside method bodies (not at module scope) so this
# module still imports even if BlueprintGraphEditorPort is absent; the tools then
# fail at call time rather than aborting the whole editor_toolset package import.


@unreal.uclass()
class StringTableTools(unreal.ToolsetDefinition):
    """Provides tools for creating and editing StringTable assets."""

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str,
            source_file: str) -> list[unreal.Object]:
        """Imports a file from disk as a StringTable asset.

        The file must have a header row with at least 'Key' and 'SourceString'
        columns. Additional meta-data columns are imported but the namespace
        is not - the StringTable's namespace is derived from its asset path.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source file on disk.

        Returns:
            The assets produced by the import (a single StringTable).
        """
        if not os.path.isfile(source_file):
            raise FileNotFoundError(f'Source file not found: {source_file}')
        ext = os.path.splitext(source_file)[1].lower().lstrip('.')
        if ext != 'csv':
            raise ValueError(
                f'StringTable import only supports ".csv" files, got ".{ext}".')
        asset_path = f'{folder_path}/{asset_name}'
        string_table = StringTableTools.create(folder_path, asset_name)
        try:
            if not unreal.EditorToolsetCompatLibrary.string_table_import_csv_file(string_table, source_file):
                raise RuntimeError(
                    f'Failed to import "{source_file}" into StringTable "{asset_path}".')
        except Exception:
            # Best-effort cleanup of the empty asset; never let a delete failure
            # replace the original import exception.
            try:
                AssetTools.delete(asset_path)
            except Exception:
                pass
            raise
        return [string_table]

    @toolset_registry.tool_call
    @staticmethod
    def create(folder_path: str, asset_name: str) -> unreal.Object:
        """Creates a new StringTable asset.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset.

        Returns:
            The created StringTable.
        """
        # [5.7 port] unreal.StringTable.static_class() / unreal.StringTableFactory
        # are not exposed on 5.7; create the asset natively via the compat shim.
        if asset_exists(f'{folder_path}/{asset_name}'):
            raise RuntimeError(
                f'create_asset: {asset_name} at {folder_path} already exists')
        asset = unreal.EditorToolsetCompatLibrary.create_string_table_asset(folder_path, asset_name)
        if asset is None:
            raise ValueError(f'Unable to create StringTable in {folder_path}/{asset_name}')
        return asset

    @toolset_registry.tool_call
    @staticmethod
    def get_table_id(string_table: unreal.Object) -> str:
        """Returns the table ID for a StringTable asset.

        The table ID is derived from the asset's package path and is used
        to reference the string table in text properties and localisation.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            The table ID as a string.
        """
        return str(unreal.EditorToolsetCompatLibrary.string_table_get_id(string_table))

    @toolset_registry.tool_call
    @staticmethod
    def get_namespace(string_table: unreal.Object) -> str:
        """Returns the namespace of a StringTable asset.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            The namespace string.
        """
        return unreal.EditorToolsetCompatLibrary.string_table_get_namespace(string_table)

    @toolset_registry.tool_call
    @staticmethod
    def list_keys(string_table: unreal.Object) -> list[str]:
        """Lists all keys in the string table.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            A list of key strings.
        """
        return list(unreal.EditorToolsetCompatLibrary.string_table_list_keys(string_table))

    @toolset_registry.tool_call
    @staticmethod
    def get_entry(string_table: unreal.Object, key: str) -> str:
        """Returns the source string for a specific key.

        Args:
            string_table: The StringTable asset to query.
            key: The key whose string value to retrieve.

        Returns:
            The source string for the key.
        """
        StringTableTools._ensure_key_exists(string_table, key)
        return unreal.EditorToolsetCompatLibrary.string_table_get_entry(string_table, key)

    @toolset_registry.tool_call
    @staticmethod
    def set_entry(string_table: unreal.Object, key: str, value: str) -> None:
        """Adds or updates an entry in the string table.

        If the key already exists its value is replaced; otherwise a new entry
        is created.

        Args:
            string_table: The StringTable asset to modify.
            key: The key for the entry.
            value: The source string value for the entry.
        """
        if not unreal.EditorToolsetCompatLibrary.string_table_set_entry(string_table, key, value):
            raise RuntimeError(f'Failed to set entry "{key}" on the string table.')

    @toolset_registry.tool_call
    @staticmethod
    def remove_entry(string_table: unreal.Object, key: str) -> None:
        """Removes an entry from the string table.

        Args:
            string_table: The StringTable asset to modify.
            key: The key of the entry to remove.
        """
        StringTableTools._ensure_key_exists(string_table, key)
        if len(StringTableTools.list_keys(string_table)) <= 1:
            raise RuntimeError(
                f'Cannot remove the last entry "{key}" from a StringTable. '
                'The API does not support clearing all entries programmatically.')
        if not unreal.EditorToolsetCompatLibrary.string_table_remove_entry(string_table, key):
            raise RuntimeError(f'Failed to remove entry "{key}" from the string table.')

    @staticmethod
    def _ensure_key_exists(string_table: unreal.Object, key: str) -> None:
        if key not in StringTableTools.list_keys(string_table):
            raise ValueError(f'Key "{key}" does not exist in the string table.')
