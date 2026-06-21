# Copyright Epic Games, Inc. All Rights Reserved.

import fnmatch
import json

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset
from editor_toolset.toolsets.asset import import_asset

_NAME_COLUMN = 'Name'

@unreal.uclass()
class DataTableTools(unreal.ToolsetDefinition):
    """Provides tools for creating and editing DataTable assets."""

    @toolset_registry.tool_call
    @staticmethod
    def search_row_structs(struct_name: str = '*') -> list[unreal.ScriptStruct]:
        """Finds structs that can be used as a DataTable schema.

        Args:
            struct_name: If set, will filter structs by name using wildcard match.

        Returns:
            A list of structs derived from TableRowBase that match the criteria.
        """
        derived = unreal.ToolsetLibrary.get_derived_structs(unreal.TableRowBase.static_struct())
        return [s for s in derived if fnmatch.fnmatch(s.get_name(), struct_name)]

    @toolset_registry.tool_call
    @staticmethod
    def import_file(
            folder_path: str, asset_name: str, source_file: str,
            schema: unreal.ScriptStruct) -> list[unreal.Object]:
        """Imports a file from disk as a DataTable asset.

        The file's columns must match the property names in schema. Use
        search_row_structs to discover usable schema structs.

        Args:
            folder_path: The content-browser folder to create the asset in.
            asset_name: The name of the new asset.
            source_file: The absolute path to the source file on disk.
            schema: The struct that defines the columns of the table. Must be a
                subclass of TableRowBase.

        Returns:
            The assets produced by the import (typically a single DataTable).
        """
        factory = unreal.CSVImportFactory()
        factory.automated_import_settings.import_type = unreal.CSVImportType.ECSV_DATA_TABLE
        factory.automated_import_settings.import_row_struct = schema
        return import_asset(folder_path, asset_name, source_file, factory=factory)

    @toolset_registry.tool_call
    @staticmethod
    def create(
            folder_path: str, asset_name: str,
            schema: unreal.ScriptStruct) -> unreal.DataTable:
        """Creates a new DataTable asset with the specified column schema.

        Args:
            folder_path: The path to the folder that will contain the asset.
            asset_name: The name of the asset.
            schema: The struct that defines the columns of the table.
                    Must be a subclass of TableRowBase.

        Returns:
            The created DataTable.
        """
        factory = unreal.DataTableFactory()
        factory.struct = schema
        asset = create_asset(
            folder_path, asset_name, unreal.DataTable.static_class(), factory)
        if not isinstance(asset, unreal.DataTable):
            raise ValueError(f'Unable to create CurveTable in {folder_path}/{asset_name}')
        return asset

    @toolset_registry.tool_call
    @staticmethod
    def get_schema(data_table: unreal.DataTable) -> str:
        """Returns the column schema of the data table as a JSON string.

        Args:
            data_table: The DataTable to query.

        Returns:
            A JSON formatted string mapping column names to their type info.
        """
        # DataTable row structs expose all fields as columns regardless of Blueprint visibility,
        # so we pass False to include properties that may lack CPF_BlueprintVisible.
        return unreal.ToolsetLibrary.list_struct_properties(data_table.get_row_struct(), False)

    @toolset_registry.tool_call
    @staticmethod
    def list_rows(data_table: unreal.DataTable) -> list[str]:
        """Lists the names of all rows in the data table.

        Args:
            data_table: The DataTable to query.

        Returns:
            A list of row names.
        """
        return [name for name in data_table.get_row_names()]

    @toolset_registry.tool_call
    @staticmethod
    def add_rows(data_table: unreal.DataTable, row_names: list[str]) -> None:
        """Adds new rows with default values to the data table.

        Args:
            data_table: The DataTable to modify.
            row_names: The names for the new rows.
        """
        DataTableTools._check_no_duplicate_names(row_names, 'add')
        DataTableTools._check_rows_dont_exist(data_table, row_names)
        rows = DataTableTools._read_table(data_table)
        for row_name in row_names:
            rows.append({_NAME_COLUMN: row_name})
        if not DataTableTools._write_table(data_table, rows):
            raise RuntimeError(f'Error adding rows to data table.')

    @toolset_registry.tool_call
    @staticmethod
    def remove_rows(data_table: unreal.DataTable, row_names: list[str]) -> None:
        """Removes rows from the data table.

        Args:
            data_table: The DataTable to modify.
            row_names: The names of the rows to remove.
        """
        DataTableTools._check_no_duplicate_names(row_names, 'remove')
        DataTableTools._check_rows_exist(data_table, row_names)
        for row_name in row_names:
            unreal.DataTableFunctionLibrary.remove_data_table_row(data_table, row_name)
            if data_table.does_row_exist(row_name):
                raise RuntimeError(f'Error removing row {row_name!r} from data table.')

    @toolset_registry.tool_call
    @staticmethod
    def rename_rows(data_table: unreal.DataTable, renames: dict[str, str]) -> None:
        """Renames one or more rows in the data table.

        Args:
            data_table: The DataTable to modify.
            renames: A mapping of existing row names to their new names.
        """
        old_names = list(renames.keys())
        new_names = list(renames.values())
        DataTableTools._check_no_duplicate_names(new_names, 'rename to')
        DataTableTools._check_rows_exist(data_table, old_names)
        conflicts = [n for n in new_names
                     if n not in old_names and data_table.does_row_exist(n)]
        if conflicts:
            raise ValueError(f'New row names already exist in the data table: {conflicts}.')
        rows = DataTableTools._read_table(data_table)
        for row in rows:
            old_name = row.get(_NAME_COLUMN)
            new_name = renames.get(old_name)
            if new_name:
                row[_NAME_COLUMN] = new_name
        if not DataTableTools._write_table(data_table, rows):
            raise RuntimeError('Error renaming rows in data table.')

    @toolset_registry.tool_call
    @staticmethod
    def get_rows(data_table: unreal.DataTable, row_names: list[str]) -> str:
        """Returns the column values for one or more rows as a JSON string.

        Args:
            data_table: The DataTable to query.
            row_names: The names of the rows to retrieve.

        Returns:
            A JSON object mapping each row name to an object of property names and values.
        """
        DataTableTools._check_rows_exist(data_table, row_names)
        # Build a case-insensitive map from lowercased key to schema-canonical key so
        # the returned keys always match what get_schema reports. Deprecated columns are
        # excluded from the schema and are omitted from the result to keep the two
        # consistent.
        lower_to_schema = DataTableTools._get_schema_keys(data_table)
        requested = set(row_names)
        rows = DataTableTools._read_table(data_table)
        result = {}
        for row in rows:
            name = row.get(_NAME_COLUMN)
            if name not in requested:
                continue
            result[name] = {lower_to_schema[k.lower()]: v
                            for k, v in row.items()
                            if k != _NAME_COLUMN and k.lower() in lower_to_schema}
        return json.dumps(result)

    @toolset_registry.tool_call
    @staticmethod
    def set_rows(data_table: unreal.DataTable, values: str) -> None:
        """Sets column values for one or more rows.

        Args:
            data_table: The DataTable to modify.
            values: A JSON object mapping row names to objects of camelCase property
                    names and values to update. Only specified properties are updated;
                    others remain unchanged.
        """
        try:
            rows_data = json.loads(values)
        except json.JSONDecodeError as e:
            raise ValueError(f'values is not valid JSON: {e}') from e
        if not isinstance(rows_data, dict):
            raise ValueError(f'values must be a JSON object, got {type(rows_data).__name__}.')
        for row_name, row_values in rows_data.items():
            if not isinstance(row_values, dict):
                raise ValueError(f'Values for row {row_name!r} must be a JSON object.')
        DataTableTools._check_rows_exist(data_table, list(rows_data.keys()))
        # Validate user-supplied keys against the schema. Deprecated columns are excluded
        # from the schema and cannot be set. Case-insensitive to match get_schema behaviour.
        valid_lower = DataTableTools._get_schema_keys(data_table)
        for row_name, row_values in rows_data.items():
            invalid = [k for k in row_values if k.lower() not in valid_lower]
            if invalid:
                raise ValueError(f'Properties not found in schema: {invalid}')
        rows = DataTableTools._read_table(data_table)
        # Case-insensitive lookup from schema key to the export-format key actually
        # present in the row, since export_to_json_string and get_schema may differ in
        # casing for the same property (e.g. 'aIDelayMin' vs 'aIdelayMin').
        schema_lower_to_export = {k.lower(): k
                                  for row in rows for k in row if k != _NAME_COLUMN
                                  if k.lower() in valid_lower}
        for row in rows:
            row_values = rows_data.get(row.get(_NAME_COLUMN))
            if row_values is None:
                continue
            for key, value in row_values.items():
                export_key = schema_lower_to_export[key.lower()]
                row[export_key] = value
        if not DataTableTools._write_table(data_table, rows):
            raise RuntimeError(f'Error writing rows to data table.')

    @staticmethod
    def _check_no_duplicate_names(row_names: list[str], action: str) -> None:
        seen = set()
        duplicates = list(dict.fromkeys(n for n in row_names if n in seen or seen.add(n)))
        if duplicates:
            raise ValueError(f'Cannot {action} rows with the same name: {duplicates}.')

    @staticmethod
    def _check_rows_exist(data_table: unreal.DataTable, row_names: list[str]) -> None:
        missing = [name for name in row_names if not data_table.does_row_exist(name)]
        if missing:
            raise ValueError(f'Rows do not exist in the data table: {missing}.')

    @staticmethod
    def _check_rows_dont_exist(data_table: unreal.DataTable, row_names: list[str]) -> None:
        existing = [name for name in row_names if data_table.does_row_exist(name)]
        if existing:
            raise ValueError(f'Rows already exist in the data table: {existing}.')

    @staticmethod
    def _get_schema_keys(data_table: unreal.DataTable) -> dict[str, str]:
        """Returns a map of lowercase schema key to actual schema key."""
        schema_props = json.loads(DataTableTools.get_schema(data_table))
        return {k.lower(): k for k in schema_props.keys()}

    @staticmethod
    def _read_table(data_table: unreal.DataTable) -> list[dict]:
        """Exports the DataTable as a list of row dicts.

        Each dict has a 'Name' key with the row name and one key per schema column
        using the casing from export_to_json_string.
        """
        json_str = data_table.export_to_json_string()
        if not json_str:
            raise RuntimeError(f'{data_table} cannot be read.')
        json_data = json.loads(json_str)
        if not isinstance(json_data, list):
            raise RuntimeError(f'{data_table} returned an invalid format.')
        return json_data

    @staticmethod
    def _write_table(data_table: unreal.DataTable, rows: list[dict]) -> bool:
        """Writes row dicts to the DataTable via JSON round-trip.

        Rows are expected to use export-format keys (as returned by _read_table).
        Deprecated columns present in the export are preserved as-is; callers are
        responsible for validating any user-supplied keys before calling this method.
        """
        return data_table.fill_from_json_string(json.dumps(rows), data_table.get_row_struct())
