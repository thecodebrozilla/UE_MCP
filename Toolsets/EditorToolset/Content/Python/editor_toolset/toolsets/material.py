# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

import toolset_registry
from toolset_registry.helpers import create_asset


@unreal.ustruct()
class MaterialInputSource(unreal.StructBase):
    """Describes the source feeding either an expression input pin or a material output property.

    input_name carries the pin name when the destination is an expression input,
    and is empty when the destination is a fixed material output property.
    """
    input_name = unreal.uproperty(str)
    expression = unreal.uproperty(unreal.MaterialExpression)
    output_name = unreal.uproperty(str)


@unreal.uclass()
class MaterialTools(unreal.ToolsetDefinition):
    """Provides tools for creating and editing Material and MaterialFunction assets."""

    # -------------------------------------------------------------------------
    # Asset creation
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def create_material(folder_path: str, asset_name: str) -> unreal.Material:
        """Creates a new empty Material asset.

        Warning: Each new Material increases shader compile times. Prefer creating
        a MaterialInstance from an existing Material where possible.

        Args:
            folder_path: The content-browser path to the folder for the new asset.
            asset_name: The name of the new asset.

        Returns:
            The newly created Material.
        """
        return create_asset(
            folder_path, asset_name,
            unreal.Material.static_class(), unreal.MaterialFactoryNew())

    @toolset_registry.tool_call
    @staticmethod
    def create_function(folder_path: str, asset_name: str) -> unreal.MaterialFunction:
        """Creates a new empty MaterialFunction asset.

        Args:
            folder_path: The content-browser path to the folder for the new asset.
            asset_name: The name of the new asset.

        Returns:
            The newly created MaterialFunction.
        """
        return create_asset(
            folder_path, asset_name,
            unreal.MaterialFunction.static_class(), unreal.MaterialFunctionFactoryNew())

    @toolset_registry.tool_call
    @staticmethod
    def create_parameter_collection(
            folder_path: str,
            asset_name: str) -> unreal.MaterialParameterCollection:
        """Creates a new empty MaterialParameterCollection (MPC) asset.

        An MPC holds named Scalar and Vector parameters with default values
        that materials can reference at runtime without recompiling shaders.

        Args:
            folder_path: The content-browser path to the folder for the new asset.
            asset_name: The name of the new asset.

        Returns:
            The newly created MaterialParameterCollection.
        """
        return create_asset(
            folder_path, asset_name,
            unreal.MaterialParameterCollection.static_class(),
            unreal.MaterialParameterCollectionFactoryNew())

    # -------------------------------------------------------------------------
    # Graph editing (Material or MaterialFunction)
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def list_expression_classes(
            material_or_function: unreal.Object,
            search: str = '') -> list[unreal.SoftClassPath]:
        """Returns MaterialExpression subclasses valid for the given context.

        Use the results with add_expression. Pass a search string to filter by name,
        e.g. 'Multiply' or 'Parameter'.

        Args:
            material_or_function: The Material or MaterialFunction to filter by context.
            search: Optional case-insensitive substring filter on the class path.

        Returns:
            Matching MaterialExpression subclass paths.
        """
        all_derived = unreal.ToolsetLibrary.get_derived_classes(
            unreal.MaterialExpression.static_class())
        # FunctionInput and FunctionOutput are only valid inside a MaterialFunction;
        # adding them to a Material causes a compile error.
        derived = MaterialTools._dispatch(
            material_or_function,
            lambda _: [c for c in all_derived
                       if not MaterialTools._is_function_only_expression(
                           unreal.load_class(None, c.export_text()))],
            lambda _: all_derived)
        if not search:
            return derived
        return [c for c in derived if search.lower() in c.export_text().lower()]

    @toolset_registry.tool_call
    @staticmethod
    def add_expression(
            material_or_function: unreal.Object,
            expression_class: unreal.Class,
            x: int = 0,
            y: int = 0) -> unreal.MaterialExpression:
        """Adds a new expression node to a Material or MaterialFunction graph.

        Use list_expression_classes to discover available types.

        Args:
            material_or_function: The Material or MaterialFunction to add the expression to.
            expression_class: The type of expression node to create.
            x: Horizontal position in the graph editor.
            y: Vertical position in the graph editor.

        Returns:
            The newly created MaterialExpression node.
        """
        if (isinstance(material_or_function, unreal.Material) and
                MaterialTools._is_function_only_expression(expression_class)):
            raise ValueError(
                f'{expression_class} can only be added to a MaterialFunction.')
        expression = MaterialTools._dispatch(
            material_or_function,
            lambda m: unreal.MaterialEditingLibrary.create_material_expression(
                m, expression_class, node_pos_x=x, node_pos_y=y),
            lambda f: unreal.MaterialEditingLibrary.create_material_expression_in_function(
                f, expression_class, node_pos_x=x, node_pos_y=y))
        if not expression:
            raise RuntimeError(f'Failed to create expression of type {expression_class}.')
        MaterialTools._refresh_editor(material_or_function)
        return expression

    @toolset_registry.tool_call
    @staticmethod
    def delete_expression(
            material_or_function: unreal.Object,
            expression: unreal.MaterialExpression) -> None:
        """Removes an expression node from a Material or MaterialFunction graph.

        Args:
            material_or_function: The Material or MaterialFunction that owns the expression.
            expression: The expression node to remove.
        """
        MaterialTools._dispatch(
            material_or_function,
            lambda m: unreal.MaterialEditingLibrary.delete_material_expression(m, expression),
            lambda f: unreal.MaterialEditingLibrary.delete_material_expression_in_function(
                f, expression))
        MaterialTools._refresh_editor(material_or_function)

    @toolset_registry.tool_call
    @staticmethod
    def get_expressions(
            material_or_function: unreal.Object) -> list[unreal.MaterialExpression]:
        """Returns all expression nodes in a Material or MaterialFunction graph.

        Args:
            material_or_function: The Material or MaterialFunction to query.

        Returns:
            All MaterialExpression nodes in the graph.
        """
        return MaterialTools._get_expressions(material_or_function)

    @toolset_registry.tool_call
    @staticmethod
    def layout_expressions(material_or_function: unreal.Object) -> None:
        """Automatically arranges all expression nodes in a Material or MaterialFunction graph.

        Args:
            material_or_function: The Material or MaterialFunction whose graph should be tidied.
        """
        MaterialTools._dispatch(
            material_or_function,
            unreal.MaterialEditingLibrary.layout_material_expressions,
            unreal.MaterialEditingLibrary.layout_material_function_expressions)
        MaterialTools._refresh_editor(material_or_function)

    # -------------------------------------------------------------------------
    # Parameter groups (Material or MaterialFunction)
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def list_parameter_groups(material_or_function: unreal.Object) -> list[str]:
        """Returns the unique parameter group names defined in a Material or MaterialFunction.

        Parameters are organised into groups in the Material Instance editor. This returns
        the distinct set of group names found across all parameter expressions in the graph.
        The empty string represents parameters that have not been assigned to a named group.

        Args:
            material_or_function: The Material or MaterialFunction to query.

        Returns:
            A sorted list of unique group names.
        """
        groups = set()
        for expr in MaterialTools._get_expressions(material_or_function):
            if isinstance(expr, unreal.MaterialExpressionParameter):
                group = expr.get_editor_property('group')
                if not group.is_none():
                    groups.add(str(group))
        return sorted(groups)

    @toolset_registry.tool_call
    @staticmethod
    def rename_parameter_group(
            material_or_function: unreal.Object,
            old_name: str,
            new_name: str) -> None:
        """Renames a parameter group across all parameter expressions in a Material or
        MaterialFunction.

        All parameters currently in old_name will be moved to new_name. If new_name
        already exists, the parameters are merged into it.

        Note: triggers an internal recompile; no separate call to recompile/update is needed.

        Args:
            material_or_function: The Material or MaterialFunction to modify.
            old_name: The current name of the group to rename.
            new_name: The new name for the group.
        """
        if not new_name or new_name == 'None':
            raise ValueError(f'"{new_name}" is not a valid parameter group name.')
        if not MaterialTools._rename_group(material_or_function, old_name, new_name):
            raise ValueError(f'Parameter group "{old_name}" not found.')
        MaterialTools._refresh_editor(material_or_function)

    @toolset_registry.tool_call
    @staticmethod
    def delete_parameter_group(
            material_or_function: unreal.Object,
            group_name: str) -> None:
        """Removes a parameter group, ungrouping all parameters that belong to it.

        The parameter expressions themselves are not deleted - only their group assignment
        is cleared.

        Note: triggers an internal recompile; no separate call to recompile/update is needed.

        Args:
            material_or_function: The Material or MaterialFunction to modify.
            group_name: The name of the group to delete.
        """
        if not MaterialTools._rename_group(material_or_function, group_name, 'None'):
            raise ValueError(f'Parameter group "{group_name}" not found.')
        MaterialTools._refresh_editor(material_or_function)

    @toolset_registry.tool_call
    @staticmethod
    def get_expression_input_names(
            expression: unreal.MaterialExpression) -> list[str]:
        """Returns the names of all input pins on a material expression node.

        Use these names as to_input_name when calling connect_expressions.

        Args:
            expression: The expression node to query.

        Returns:
            The input pin names available on the expression.
        """
        return list(unreal.MaterialEditingLibrary.get_material_expression_input_names(expression))

    @toolset_registry.tool_call
    @staticmethod
    def get_expression_output_names(
            expression: unreal.MaterialExpression) -> list[str]:
        """Returns the names of all output pins on a material expression node.

        Use these names as from_output_name when calling connect_expressions or
        connect_to_output. The empty string represents the default (first) output
        of nodes that expose only an unnamed output.

        Args:
            expression: The expression node to query.

        Returns:
            The output pin names available on the expression.
        """
        return list(unreal.MaterialEditingLibrary.get_material_expression_output_names(expression))

    @toolset_registry.tool_call
    @staticmethod
    def connect_expressions(
            from_expression: unreal.MaterialExpression,
            from_output_name: str,
            to_expression: unreal.MaterialExpression,
            to_input_name: str) -> None:
        """Connects an expression node's output pin to another expression node's input pin.

        Args:
            from_expression: The expression providing the output value.
            from_output_name: The output pin name. Pass an empty string to use the
                default (first) output.
            to_expression: The expression receiving the input.
            to_input_name: The input pin name to connect to. Use get_expression_input_names
                to discover valid names.
        """
        success = unreal.MaterialEditingLibrary.connect_material_expressions(
            from_expression, from_output_name, to_expression, to_input_name)
        if not success:
            raise ValueError(
                f'Failed to connect output "{from_output_name}" on {from_expression} '
                f'to input "{to_input_name}" on {to_expression}.')
        MaterialTools._refresh_editor(to_expression.get_outer())

    @toolset_registry.tool_call
    @staticmethod
    def disconnect_expressions(
            to_expression: unreal.MaterialExpression,
            to_input_name: str) -> None:
        """Disconnects the input pin of an expression node, removing whatever is connected to it.

        Args:
            to_expression: The expression whose input pin should be disconnected.
            to_input_name: The input pin name to disconnect. Use get_expression_input_names
                to discover valid names. Pass an empty string to disconnect the first input.
        """
        result = unreal.MaterialEditingLibrary.disconnect_material_expressions(
            to_expression, to_input_name)
        if not result:
            raise ValueError(
                f'Failed to disconnect input "{to_input_name}" on {to_expression}. '
                f'The pin may not exist or may already be disconnected.')
        MaterialTools._refresh_editor(to_expression.get_outer())

    # -------------------------------------------------------------------------
    # Graph reading
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def get_expression_inputs(
            material_or_function: unreal.Object,
            expression: unreal.MaterialExpression) -> list[MaterialInputSource]:
        """Returns the current wiring of each input pin on a material expression.

        Use after building or modifying a graph to verify the wiring matches
        expectations.

        Args:
            material_or_function: The Material or MaterialFunction that owns the expression.
            expression: The expression whose input wiring to read.

        Returns:
            One entry per input pin, in declaration order matching
            get_expression_input_names. The expression field is None for
            unwired pins.
        """
        input_names = list(
            unreal.MaterialEditingLibrary.get_material_expression_input_names(expression))
        # Parallel to input_names; unwired pins come back as None.
        sources = list(MaterialTools._dispatch(
            material_or_function,
            lambda m: unreal.MaterialEditingLibrary.get_inputs_for_material_expression(
                m, expression),
            lambda f: unreal.MaterialEditingLibrary.get_inputs_for_material_function_expression(
                f, expression)))
        result = []
        for i, name in enumerate(input_names):
            src = sources[i] if i < len(sources) else None
            entry = MaterialInputSource()
            entry.input_name = name
            entry.expression = src
            output_name = unreal.MaterialEditingLibrary.get_input_node_output_name_for_material_expression(
                expression, src) if src else None
            entry.output_name = output_name if output_name is not None else ''
            result.append(entry)
        return result

    @toolset_registry.tool_call
    @staticmethod
    def get_property_input(
            material: unreal.Material,
            material_property: unreal.MaterialProperty) -> MaterialInputSource:
        """Returns the expression and output pin feeding a material output property.

        Use to inspect what drives MP_EmissiveColor, MP_Opacity, MP_BaseColor, etc.

        Args:
            material: The Material to query.
            material_property: The material output property.

        Returns:
            A MaterialInputSource with input_name empty. Its expression field is
            None when the output property is disconnected.
        """
        node = unreal.MaterialEditingLibrary.get_material_property_input_node(
            material, material_property)
        result = MaterialInputSource()
        result.input_name = ''
        result.expression = node
        result.output_name = (
            unreal.MaterialEditingLibrary.get_material_property_input_node_output_name(
                material, material_property)
            if node else '')
        return result

    # -------------------------------------------------------------------------
    # Material-only operations
    # -------------------------------------------------------------------------

    @toolset_registry.tool_call
    @staticmethod
    def connect_to_output(
            expression: unreal.MaterialExpression,
            output_name: str,
            material_property: unreal.MaterialProperty) -> None:
        """Connects an expression node's output to one of the material's output properties.

        Args:
            expression: The expression whose output will drive the property.
            output_name: The output pin name. Pass an empty string to use the
                default (first) output.
            material_property: The material output property to connect to.
        """
        success = unreal.MaterialEditingLibrary.connect_material_property(
            expression, output_name, material_property)
        if not success:
            raise ValueError(f'Failed to connect to material property {material_property}.')
        MaterialTools._refresh_editor(expression.get_outer())

    @toolset_registry.tool_call
    @staticmethod
    def disconnect_from_output(
            material: unreal.Material,
            material_property: unreal.MaterialProperty) -> None:
        """Disconnects the expression currently connected to a material output property.

        Args:
            material: The Material to modify.
            material_property: The material output property to disconnect.
        """
        result = unreal.MaterialEditingLibrary.disconnect_material_property(
            material, material_property)
        if not result:
            raise ValueError(
                f'Failed to disconnect material property {material_property}. '
                f'The property may already be disconnected.')
        MaterialTools._refresh_editor(material)

    @toolset_registry.tool_call
    @staticmethod
    def delete_unused_expressions(material: unreal.Material) -> None:
        """Deletes all expression nodes not connected to any material output.

        Useful for cleaning up a material graph after reorganising or after the AI
        has added experimental nodes that were later abandoned.

        Note: triggers no recompile - call recompile() afterwards if needed.

        Args:
            material: The Material to clean up.
        """
        unreal.MaterialEditingLibrary.delete_unused_expressions(material)
        MaterialTools._refresh_editor(material)

    @toolset_registry.tool_call
    @staticmethod
    def recompile(material_or_function: unreal.Object) -> None:
        """Recompiles a Material or MaterialFunction after edits.

        For Materials, raises if the shader fails to compile. For MaterialFunctions,
        also recompiles any Materials that reference the function.

        Call this once after a set of graph modifications is complete - after adding or
        deleting expressions, making connections, or changing expression properties such as
        parameter names or default values.

        Args:
            material_or_function: The Material or MaterialFunction to recompile.
        """
        def _recompile_material(m):
            errors = unreal.MaterialEditingLibrary.recompile_material(m)
            if errors:
                raise RuntimeError('Material failed to compile:\n' + '\n'.join(errors))

        try:
            MaterialTools._dispatch(
                material_or_function,
                _recompile_material,
                unreal.MaterialEditingLibrary.update_material_function)
        finally:
            # recompile_material mutates compilation state before reporting errors,
            # so refresh the editor view even on the compile-error path. The refresh
            # node cascades to any open dependent editors on the C++ side.
            MaterialTools._refresh_editor(material_or_function)

    @toolset_registry.tool_call
    @staticmethod
    def get_referencing_materials(
            material_function: unreal.MaterialFunction) -> list[unreal.AssetData]:
        """Returns asset data for all Materials that reference this MaterialFunction.

        Args:
            material_function: The MaterialFunction to query.

        Returns:
            Asset data for each Material that uses this function.
        """
        return unreal.MaterialEditingLibrary.get_materials_referencing_function(
            material_function)

    # -------------------------------------------------------------------------
    # Private helpers
    # -------------------------------------------------------------------------

    @staticmethod
    def _get_expressions(
            material_or_function: unreal.Object) -> list[unreal.MaterialExpression]:
        return list(MaterialTools._dispatch(
            material_or_function,
            unreal.MaterialEditingLibrary.get_material_expressions,
            unreal.MaterialEditingLibrary.get_material_function_expressions))

    @staticmethod
    def _rename_group(
            material_or_function: unreal.Object,
            old_name: str,
            new_name: str) -> bool:
        return MaterialTools._dispatch(
            material_or_function,
            lambda m: unreal.MaterialEditingLibrary.rename_material_parameter_group(
                m, old_name, new_name),
            lambda f: unreal.MaterialEditingLibrary.rename_material_function_parameter_group(
                f, old_name, new_name))

    @staticmethod
    def _is_function_only_expression(expression_class: unreal.Class) -> bool:
        return expression_class in (
            unreal.MaterialExpressionFunctionInput.static_class(),
            unreal.MaterialExpressionFunctionOutput.static_class())

    @staticmethod
    def _dispatch(material_or_function: unreal.Object, on_material, on_function):
        if isinstance(material_or_function, unreal.Material):
            return on_material(material_or_function)
        elif isinstance(material_or_function, unreal.MaterialFunction):
            return on_function(material_or_function)
        else:
            raise ValueError(
                f'Expected a Material or MaterialFunction, '
                f'got {type(material_or_function).__name__}.')

    @staticmethod
    def _refresh_editor(material_or_function: unreal.Object) -> None:
        if isinstance(material_or_function, unreal.Material):
            unreal.MaterialEditingLibrary.refresh_material_editor(material_or_function)
        elif isinstance(material_or_function, unreal.MaterialFunction):
            unreal.MaterialEditingLibrary.refresh_material_function_editor(material_or_function)
        else:
            unreal.log_warning(
                f'_refresh_editor: expected Material or MaterialFunction, got '
                f'{type(material_or_function).__name__}; editor will not be refreshed.')

