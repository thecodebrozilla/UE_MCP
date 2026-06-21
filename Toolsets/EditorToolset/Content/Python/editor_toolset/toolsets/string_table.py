# Copyright Epic Games, Inc. All Rights Reserved.

import csv
import io
import os

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset
from editor_toolset.toolsets.asset import AssetTools


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
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        try:
            if not unreal.StringTableLibrary.import_table_from_csv_file(
                    table_id, source_file):
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
    def create(folder_path: str, asset_name: str) -> unreal.StringTable:
        """Creates a new StringTable asset.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset.

        Returns:
            The created StringTable.
        """
        asset = create_asset(
            folder_path, asset_name,
            unreal.StringTable.static_class(), unreal.StringTableFactory())
        if not isinstance(asset, unreal.StringTable):
            raise ValueError(f'Unable to create StringTable in {folder_path}/{asset_name}')
        return asset

    @toolset_registry.tool_call
    @staticmethod
    def get_table_id(string_table: unreal.StringTable) -> str:
        """Returns the table ID for a StringTable asset.

        The table ID is derived from the asset's package path and is used
        to reference the string table in text properties and localisation.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            The table ID as a string.
        """
        return str(unreal.StringTableLibrary.get_table_id(string_table))

    @toolset_registry.tool_call
    @staticmethod
    def get_namespace(string_table: unreal.StringTable) -> str:
        """Returns the namespace of a StringTable asset.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            The namespace string.
        """
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        return unreal.StringTableLibrary.get_table_namespace(table_id)

    @toolset_registry.tool_call
    @staticmethod
    def list_keys(string_table: unreal.StringTable) -> list[str]:
        """Lists all keys in the string table.

        Args:
            string_table: The StringTable asset to query.

        Returns:
            A list of key strings.
        """
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        return list(unreal.StringTableLibrary.get_keys_from_string_table(table_id))

    @toolset_registry.tool_call
    @staticmethod
    def get_entry(string_table: unreal.StringTable, key: str) -> str:
        """Returns the source string for a specific key.

        Args:
            string_table: The StringTable asset to query.
            key: The key whose string value to retrieve.

        Returns:
            The source string for the key.
        """
        StringTableTools._ensure_key_exists(string_table, key)
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        return unreal.StringTableLibrary.get_table_entry_source_string(table_id, key)

    @toolset_registry.tool_call
    @staticmethod
    def set_entry(string_table: unreal.StringTable, key: str, value: str) -> None:
        """Adds or updates an entry in the string table.

        If the key already exists its value is replaced; otherwise a new entry
        is created.

        Args:
            string_table: The StringTable asset to modify.
            key: The key for the entry.
            value: The source string value for the entry.
        """
        entries = StringTableTools._get_all_entries(string_table)
        entries[key] = value
        StringTableTools._import_entries(string_table, entries)

    @toolset_registry.tool_call
    @staticmethod
    def remove_entry(string_table: unreal.StringTable, key: str) -> None:
        """Removes an entry from the string table.

        Args:
            string_table: The StringTable asset to modify.
            key: The key of the entry to remove.
        """
        StringTableTools._ensure_key_exists(string_table, key)
        entries = StringTableTools._get_all_entries(string_table)
        del entries[key]
        if not entries:
            raise RuntimeError(
                f'Cannot remove the last entry "{key}" from a StringTable. '
                'The API does not support clearing all entries programmatically.')
        StringTableTools._import_entries(string_table, entries)

    @staticmethod
    def _ensure_key_exists(string_table: unreal.StringTable, key: str) -> None:
        if key not in StringTableTools.list_keys(string_table):
            raise ValueError(f'Key "{key}" does not exist in the string table.')

    @staticmethod
    def _get_all_entries(string_table: unreal.StringTable) -> dict[str, str]:
        """Returns all entries as a dict of key -> source string."""
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        keys = unreal.StringTableLibrary.get_keys_from_string_table(table_id)
        return {k: unreal.StringTableLibrary.get_table_entry_source_string(table_id, k)
                for k in keys}

    @staticmethod
    def _import_entries(string_table: unreal.StringTable, entries: dict[str, str]) -> None:
        """Replaces all entries in the string table via CSV import."""
        output = io.StringIO()
        writer = csv.writer(output)
        writer.writerow(['Key', 'SourceString'])
        for key, value in entries.items():
            writer.writerow([key, value])
        table_id = unreal.StringTableLibrary.get_table_id(string_table)
        unreal.StringTableLibrary.import_table_from_csv_string(table_id, output.getvalue())
