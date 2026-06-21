# Copyright Epic Games, Inc. All Rights Reserved.

from contextlib import ExitStack

import unreal

from toolset_registry.tests.toolset_testcase import ToolCallTestCase
from toolset_registry.tests.automation import create_temp_folder
from editor_toolset.toolsets.material import MaterialTools


def create_material_with_params(folder: str, name: str) -> unreal.Material:
    """Creates a material with a scalar and vector parameter wired to material outputs.

    Exported for use by test_material_instance.py.
    """
    mat = MaterialTools.create_material(folder, name)

    scalar = MaterialTools.add_expression(
        mat, unreal.MaterialExpressionScalarParameter.static_class(), x=-400, y=0)
    scalar.set_editor_property('parameter_name', 'TestScalar')
    scalar.set_editor_property('default_value', 0.5)

    vector = MaterialTools.add_expression(
        mat, unreal.MaterialExpressionVectorParameter.static_class(), x=-400, y=100)
    vector.set_editor_property('parameter_name', 'TestVector')
    vector.set_editor_property('default_value', unreal.LinearColor(r=1.0, g=1.0, b=1.0, a=1.0))

    MaterialTools.connect_to_output(scalar, '', unreal.MaterialProperty.MP_ROUGHNESS)
    MaterialTools.connect_to_output(vector, 'RGB', unreal.MaterialProperty.MP_BASE_COLOR)
    MaterialTools.recompile(mat)
    return mat


class MaterialToolsTestCase(ToolCallTestCase):
    """Test MaterialTools toolset."""

    def setUp(self):
        super().setUp()
        # We need to enter the temp_folder context in test setup because these tests create
        # Python objects that reference Material UObjects and those Python objects need
        # to be out of scope before we delete the Material asset.
        self._stack = ExitStack()
        self.folder = self._stack.enter_context(create_temp_folder())
        self.mat = MaterialTools.create_material(self.folder, 'Mat')

    def tearDown(self):
        self.mat = None
        self._stack.close()
        super().tearDown()

    def test_create(self):
        """Ensures that we can create a Material asset."""
        self.assertIsInstance(self.mat, unreal.Material)

    def test_create_parameter_collection(self):
        """Ensures that we can create a MaterialParameterCollection asset."""
        mpc = MaterialTools.create_parameter_collection(self.folder, 'MPC')
        self.assertIsInstance(mpc, unreal.MaterialParameterCollection)
        self.assertEqual(len(mpc.get_editor_property('scalar_parameters')), 0)
        self.assertEqual(len(mpc.get_editor_property('vector_parameters')), 0)

    def test_list_expression_classes(self):
        """Ensures that list_expression_classes returns a non-empty list of class paths."""
        classes = MaterialTools.list_expression_classes(self.mat)
        self.assertGreater(len(classes), 0)

    def test_list_expression_classes_search(self):
        """Ensures that the search filter narrows results to matching class names."""
        all_classes = MaterialTools.list_expression_classes(self.mat)
        filtered = MaterialTools.list_expression_classes(self.mat, search='Multiply')
        self.assertGreater(len(all_classes), len(filtered))
        self.assertTrue(all('multiply' in c.export_text().lower() for c in filtered))

    def test_list_expression_classes_excludes_function_only_for_material(self):
        """Ensures that FunctionInput/Output are excluded when context is a Material."""
        classes = MaterialTools.list_expression_classes(self.mat)
        names = [c.export_text() for c in classes]
        self.assertFalse(any('FunctionInput' in n for n in names))
        self.assertFalse(any('FunctionOutput' in n for n in names))

    def test_list_expression_classes_wrong_type_raises(self):
        """Ensures that passing a non-Material/MaterialFunction raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.list_expression_classes(unreal.Actor())

    def test_add_expression(self):
        """Ensures that we can add an expression node to a material."""
        expr = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        self.assertIsInstance(expr, unreal.MaterialExpressionConstant)

    def test_add_expression_position(self):
        """Ensures that the x/y position is applied to the created expression node."""
        expr = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class(), x=-300, y=150)
        self.assertEqual(expr.get_editor_property('material_expression_editor_x'), -300)
        self.assertEqual(expr.get_editor_property('material_expression_editor_y'), 150)

    def test_add_expression_invalid_class(self):
        """Ensures that passing a non-MaterialExpression class raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.add_expression(self.mat, unreal.Actor.static_class())

    def test_add_expression_function_only_class_raises_on_material(self):
        """Ensures that adding a function-only expression to a Material raises an error."""
        for cls in (unreal.MaterialExpressionFunctionInput,
                    unreal.MaterialExpressionFunctionOutput):
            with self.subTest(cls=cls), self.assertToolRaisesRuntimeError():
                MaterialTools.add_expression(self.mat, cls.static_class())

    def test_get_expressions(self):
        """Ensures that get_expressions returns all added nodes."""
        MaterialTools.add_expression(self.mat, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.add_expression(self.mat, unreal.MaterialExpressionConstant.static_class())
        exprs = MaterialTools.get_expressions(self.mat)
        self.assertGreaterEqual(len(exprs), 2)

    def test_get_expressions_wrong_type_raises(self):
        """Ensures that passing a non-Material/MaterialFunction raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.get_expressions(unreal.Actor())

    def test_delete_expression(self):
        """Ensures that deleting an expression removes it from the graph."""
        expr = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        count_before = len(MaterialTools.get_expressions(self.mat))
        MaterialTools.delete_expression(self.mat, expr)
        self.assertEqual(len(MaterialTools.get_expressions(self.mat)), count_before - 1)

    def test_list_parameter_groups(self):
        """Ensures that list_parameter_groups returns the unique groups from parameter nodes."""
        scalar = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        vector = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionVectorParameter.static_class())
        vector.set_editor_property('group', 'Details')
        scalar2 = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        scalar2.set_editor_property('group', 'Surface')
        groups = MaterialTools.list_parameter_groups(self.mat)
        self.assertEqual(groups, ['Details', 'Surface'])

    def test_list_parameter_groups_excludes_ungrouped(self):
        """Ensures that parameters whose group is NAME_None are not included in the results."""
        MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        # Default group is NAME_None; no group assignment is made.
        groups = MaterialTools.list_parameter_groups(self.mat)
        self.assertNotIn('None', groups)

    def test_list_parameter_groups_excludes_non_parameters(self):
        """Ensures that non-parameter expressions do not contribute group names."""
        MaterialTools.add_expression(self.mat, unreal.MaterialExpressionAdd.static_class())
        groups = MaterialTools.list_parameter_groups(self.mat)
        self.assertEqual(groups, [])

    def test_recompile_compile_error(self):
        """Ensures that recompile raises an error when the material fails to compile."""
        custom = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionCustom.static_class())
        custom.set_editor_property('code', 'this is not valid hlsl')
        MaterialTools.connect_to_output(custom, '', unreal.MaterialProperty.MP_BASE_COLOR)
        with self.assertToolRaisesRuntimeError():
            MaterialTools.recompile(self.mat)

    def test_rename_parameter_group(self):
        """Ensures that rename_parameter_group reassigns all parameters in the group."""
        scalar = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        MaterialTools.rename_parameter_group(self.mat, 'Surface', 'Appearance')
        groups = MaterialTools.list_parameter_groups(self.mat)
        self.assertIn('Appearance', groups)
        self.assertNotIn('Surface', groups)

    def test_rename_parameter_group_invalid(self):
        """Ensures that renaming a nonexistent group raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.rename_parameter_group(self.mat, 'DoesNotExist', 'NewName')

    def test_rename_parameter_group_invalid_new_name(self):
        """Ensures that renaming a group to "None" or an empty string raises an error."""
        for name in ('None', ''):
            with self.subTest(name=name), self.assertToolRaisesRuntimeError():
                MaterialTools.rename_parameter_group(self.mat, 'Surface', name)

    def test_delete_parameter_group(self):
        """Ensures that delete_parameter_group removes the group from all parameters."""
        scalar = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        MaterialTools.delete_parameter_group(self.mat, 'Surface')
        groups = MaterialTools.list_parameter_groups(self.mat)
        self.assertNotIn('Surface', groups)

    def test_delete_parameter_group_invalid(self):
        """Ensures that deleting a nonexistent group raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.delete_parameter_group(self.mat, 'DoesNotExist')

    def test_get_expression_input_names(self):
        """Ensures that input pin names are returned for an expression node."""
        add_expr = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        names = MaterialTools.get_expression_input_names(add_expr)
        self.assertIn('A', names)
        self.assertIn('B', names)

    def test_get_expression_output_names(self):
        """Ensures that named outputs and per-channel mask outputs are both returned."""
        vector = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionVectorParameter.static_class())
        names = MaterialTools.get_expression_output_names(vector)
        for expected in ('RGB', 'R', 'G', 'B', 'A'):
            self.assertIn(expected, names)

    def test_get_expression_output_names_default_output(self):
        """Ensures that the default unnamed output is returned as an empty string,
        matching the empty-string convention used by connect_expressions."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        self.assertEqual(MaterialTools.get_expression_output_names(const), [''])

    def test_get_expression_inputs_reports_wired_source(self):
        """Ensures that a wired input pin reports its source expression."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        MaterialTools.connect_expressions(const, '', add, 'A')
        wiring = {w.input_name: w for w in MaterialTools.get_expression_inputs(self.mat, add)}
        self.assertEqual(wiring['A'].expression, const)
        self.assertEqual(wiring['A'].output_name, '')

    def test_get_expression_inputs_reports_unwired_as_none(self):
        """Ensures that an unwired input pin reports expression as None."""
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        wiring = {w.input_name: w for w in MaterialTools.get_expression_inputs(self.mat, add)}
        self.assertIsNone(wiring['A'].expression)
        self.assertIsNone(wiring['B'].expression)
        self.assertEqual(wiring['A'].output_name, '')
        self.assertEqual(wiring['B'].output_name, '')

    def test_get_expression_inputs_reports_named_output(self):
        """Ensures that output_name carries the source's named output pin."""
        vector = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionVectorParameter.static_class())
        mask = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionComponentMask.static_class())
        MaterialTools.connect_expressions(vector, 'RGB', mask, '')
        wiring = MaterialTools.get_expression_inputs(self.mat, mask)
        self.assertEqual(len(wiring), 1)
        self.assertEqual(wiring[0].expression, vector)
        self.assertEqual(wiring[0].output_name, 'RGB')

    def test_get_property_input_reports_connected_node(self):
        """Ensures that get_property_input returns the node feeding an output property."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.connect_to_output(const, '', unreal.MaterialProperty.MP_ROUGHNESS)
        source = MaterialTools.get_property_input(
            self.mat, unreal.MaterialProperty.MP_ROUGHNESS)
        self.assertEqual(source.expression, const)
        self.assertEqual(source.output_name, '')

    def test_get_property_input_reports_disconnected_as_none(self):
        """Ensures that a disconnected output property reports expression as None."""
        source = MaterialTools.get_property_input(
            self.mat, unreal.MaterialProperty.MP_ROUGHNESS)
        self.assertIsNone(source.expression)
        self.assertEqual(source.output_name, '')

    def test_get_property_input_reports_named_output(self):
        """Ensures that output_name carries the source's named output pin."""
        vector = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionVectorParameter.static_class())
        MaterialTools.connect_to_output(vector, 'RGB', unreal.MaterialProperty.MP_BASE_COLOR)
        source = MaterialTools.get_property_input(
            self.mat, unreal.MaterialProperty.MP_BASE_COLOR)
        self.assertEqual(source.expression, vector)
        self.assertEqual(source.output_name, 'RGB')

    def test_connect_expressions(self):
        """Ensures that two expression nodes are actually wired together."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        MaterialTools.connect_expressions(const, '', add, 'A')
        inputs = unreal.MaterialEditingLibrary.get_inputs_for_material_expression(self.mat, add)
        self.assertIn(const, inputs)

    def test_connect_expressions_invalid_input(self):
        """Ensures that connecting to a nonexistent input pin name raises an error."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        with self.assertToolRaisesRuntimeError():
            MaterialTools.connect_expressions(const, '', add, 'DoesNotExist')

    def test_connect_to_output(self):
        """Ensures that an expression is actually connected to a material output property."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.connect_to_output(const, '', unreal.MaterialProperty.MP_ROUGHNESS)
        connected = unreal.MaterialEditingLibrary.get_material_property_input_node(
            self.mat, unreal.MaterialProperty.MP_ROUGHNESS)
        self.assertEqual(connected, const)

    def test_connect_to_output_invalid_output_name(self):
        """Ensures that connecting with a nonexistent output pin name raises an error."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        with self.assertToolRaisesRuntimeError():
            MaterialTools.connect_to_output(const, 'DoesNotExist', unreal.MaterialProperty.MP_ROUGHNESS)

    def test_disconnect_expressions(self):
        """Ensures that disconnect_expressions breaks a connection between two nodes."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        MaterialTools.connect_expressions(const, '', add, 'A')
        MaterialTools.disconnect_expressions(add, 'A')
        inputs = unreal.MaterialEditingLibrary.get_inputs_for_material_expression(self.mat, add)
        self.assertNotIn(const, inputs)

    def test_disconnect_expressions_already_disconnected(self):
        """Ensures that disconnecting an already-disconnected pin raises an error."""
        add = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        with self.assertToolRaisesRuntimeError():
            MaterialTools.disconnect_expressions(add, 'A')

    def test_disconnect_from_output(self):
        """Ensures that disconnect_from_output removes the connection to a material property."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.connect_to_output(const, '', unreal.MaterialProperty.MP_ROUGHNESS)
        MaterialTools.disconnect_from_output(self.mat, unreal.MaterialProperty.MP_ROUGHNESS)
        connected = unreal.MaterialEditingLibrary.get_material_property_input_node(
            self.mat, unreal.MaterialProperty.MP_ROUGHNESS)
        self.assertIsNone(connected)

    def test_disconnect_from_output_already_disconnected(self):
        """Ensures that disconnecting an already-disconnected property raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.disconnect_from_output(self.mat, unreal.MaterialProperty.MP_ROUGHNESS)

    def test_layout_expressions(self):
        """Ensures that layout_expressions repositions expression nodes."""
        const = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class(), x=0, y=0)
        MaterialTools.connect_to_output(const, '', unreal.MaterialProperty.MP_ROUGHNESS)
        MaterialTools.layout_expressions(self.mat)
        x = const.get_editor_property('material_expression_editor_x')
        y = const.get_editor_property('material_expression_editor_y')
        self.assertNotEqual((x, y), (0, 0))

    def test_delete_unused_expressions_removes_unconnected(self):
        """Ensures that expressions with no path to a material output are removed."""
        unused = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        connected = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.connect_to_output(connected, '', unreal.MaterialProperty.MP_ROUGHNESS)
        MaterialTools.delete_unused_expressions(self.mat)
        exprs = MaterialTools.get_expressions(self.mat)
        self.assertNotIn(unused, exprs)
        self.assertIn(connected, exprs)

    def test_delete_unused_expressions_preserves_transitively_connected(self):
        """Ensures that expressions reachable only via another expression are kept."""
        upstream = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionConstant.static_class())
        downstream = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionAdd.static_class())
        MaterialTools.connect_expressions(upstream, '', downstream, 'A')
        MaterialTools.connect_to_output(downstream, '', unreal.MaterialProperty.MP_ROUGHNESS)
        MaterialTools.delete_unused_expressions(self.mat)
        exprs = MaterialTools.get_expressions(self.mat)
        self.assertIn(upstream, exprs)
        self.assertIn(downstream, exprs)

    def test_delete_unused_expressions_empty_graph(self):
        """Ensures that calling on an empty graph does not raise."""
        MaterialTools.delete_unused_expressions(self.mat)
        self.assertEqual(MaterialTools.get_expressions(self.mat), [])

    def test_recompile(self):
        """Ensures that recompile flushes expression property changes into the material's cache."""
        scalar = MaterialTools.add_expression(
            self.mat, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('parameter_name', 'RecompileTest')
        scalar.set_editor_property('default_value', 0.42)
        MaterialTools.connect_to_output(scalar, '', unreal.MaterialProperty.MP_ROUGHNESS)
        # Change the default value without altering graph connections, then recompile.
        scalar.set_editor_property('default_value', 0.99)
        MaterialTools.recompile(self.mat)
        value = unreal.MaterialEditingLibrary.get_material_default_scalar_parameter_value(
            self.mat, 'RecompileTest')
        self.assertAlmostEqual(value, 0.99, places=3)


class MaterialFunctionTestCase(ToolCallTestCase):
    """Tests MaterialTools methods when operating on MaterialFunction assets."""

    def setUp(self):
        super().setUp()
        self._stack = ExitStack()
        self.folder = self._stack.enter_context(create_temp_folder())
        self.func = MaterialTools.create_function(self.folder, 'Func')

    def tearDown(self):
        self.func = None
        self._stack.close()
        super().tearDown()

    def test_create_function(self):
        """Ensures that we can create a MaterialFunction asset."""
        self.assertIsInstance(self.func, unreal.MaterialFunction)

    def test_list_expression_classes_includes_function_only_for_function(self):
        """Ensures that FunctionInput/Output are included when context is a MaterialFunction."""
        classes = MaterialTools.list_expression_classes(self.func)
        names = [c.export_text() for c in classes]
        self.assertTrue(any('FunctionInput' in n for n in names))
        self.assertTrue(any('FunctionOutput' in n for n in names))

    def test_add_expression(self):
        """Ensures that we can add an expression node to a material function."""
        expr = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionConstant.static_class())
        self.assertIsInstance(expr, unreal.MaterialExpressionConstant)

    def test_add_expression_position(self):
        """Ensures that the x/y position is applied to the created expression node."""
        expr = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionConstant.static_class(), x=-300, y=150)
        self.assertEqual(expr.get_editor_property('material_expression_editor_x'), -300)
        self.assertEqual(expr.get_editor_property('material_expression_editor_y'), 150)

    def test_add_expression_invalid_class(self):
        """Ensures that passing a non-MaterialExpression class raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.add_expression(self.func, unreal.Actor.static_class())

    def test_add_function_input(self):
        """Ensures that a FunctionInput expression can be added and named."""
        expr = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionFunctionInput.static_class())
        expr.set_editor_property('input_name', 'BaseColor')
        self.assertIsInstance(expr, unreal.MaterialExpressionFunctionInput)
        self.assertEqual(str(expr.get_editor_property('input_name')), 'BaseColor')

    def test_add_function_output(self):
        """Ensures that a FunctionOutput expression can be added and named."""
        expr = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionFunctionOutput.static_class())
        expr.set_editor_property('output_name', 'Result')
        self.assertIsInstance(expr, unreal.MaterialExpressionFunctionOutput)
        self.assertEqual(str(expr.get_editor_property('output_name')), 'Result')

    def test_get_expressions(self):
        """Ensures that get_expressions returns all added nodes."""
        MaterialTools.add_expression(self.func, unreal.MaterialExpressionConstant.static_class())
        MaterialTools.add_expression(self.func, unreal.MaterialExpressionConstant.static_class())
        exprs = MaterialTools.get_expressions(self.func)
        self.assertGreaterEqual(len(exprs), 2)

    def test_delete_expression(self):
        """Ensures that deleting an expression removes it from the graph."""
        expr = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionConstant.static_class())
        count_before = len(MaterialTools.get_expressions(self.func))
        MaterialTools.delete_expression(self.func, expr)
        self.assertEqual(len(MaterialTools.get_expressions(self.func)), count_before - 1)

    def test_list_parameter_groups(self):
        """Ensures that list_parameter_groups returns the unique groups from parameter nodes."""
        scalar = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        vector = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionVectorParameter.static_class())
        vector.set_editor_property('group', 'Details')
        scalar2 = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionScalarParameter.static_class())
        scalar2.set_editor_property('group', 'Surface')
        groups = MaterialTools.list_parameter_groups(self.func)
        self.assertEqual(groups, ['Details', 'Surface'])

    def test_list_parameter_groups_excludes_ungrouped(self):
        """Ensures that parameters without a group are not included in the results."""
        MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionScalarParameter.static_class())
        groups = MaterialTools.list_parameter_groups(self.func)
        self.assertNotIn('None', groups)

    def test_list_parameter_groups_excludes_non_parameters(self):
        """Ensures that non-parameter expressions do not contribute group names."""
        MaterialTools.add_expression(self.func, unreal.MaterialExpressionAdd.static_class())
        groups = MaterialTools.list_parameter_groups(self.func)
        self.assertEqual(groups, [])

    def test_rename_parameter_group(self):
        """Ensures that rename_parameter_group reassigns all parameters in the group."""
        scalar = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        MaterialTools.rename_parameter_group(self.func, 'Surface', 'Appearance')
        groups = MaterialTools.list_parameter_groups(self.func)
        self.assertIn('Appearance', groups)
        self.assertNotIn('Surface', groups)

    def test_rename_parameter_group_invalid(self):
        """Ensures that renaming a nonexistent group raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.rename_parameter_group(self.func, 'DoesNotExist', 'NewName')

    def test_rename_parameter_group_invalid_new_name(self):
        """Ensures that renaming a group to 'None' or an empty string raises an error."""
        for name in ('None', ''):
            with self.subTest(name=name), self.assertToolRaisesRuntimeError():
                MaterialTools.rename_parameter_group(self.func, 'Surface', name)

    def test_delete_parameter_group(self):
        """Ensures that delete_parameter_group removes the group from all parameters."""
        scalar = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionScalarParameter.static_class())
        scalar.set_editor_property('group', 'Surface')
        MaterialTools.delete_parameter_group(self.func, 'Surface')
        groups = MaterialTools.list_parameter_groups(self.func)
        self.assertNotIn('Surface', groups)

    def test_delete_parameter_group_invalid(self):
        """Ensures that deleting a nonexistent group raises an error."""
        with self.assertToolRaisesRuntimeError():
            MaterialTools.delete_parameter_group(self.func, 'DoesNotExist')

    def test_layout_expressions(self):
        """Ensures that layout_expressions does not raise on a function graph."""
        MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionConstant.static_class(), x=0, y=0)
        MaterialTools.layout_expressions(self.func)

    def test_recompile(self):
        """Ensures that recompile completes without error on a MaterialFunction."""
        MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionFunctionInput.static_class())
        MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionFunctionOutput.static_class())
        MaterialTools.recompile(self.func)

    def test_get_expression_inputs_inside_function_graph(self):
        """Ensures that get_expression_inputs reports wiring inside a MaterialFunction graph."""
        const = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionConstant.static_class())
        output = MaterialTools.add_expression(
            self.func, unreal.MaterialExpressionFunctionOutput.static_class())
        MaterialTools.connect_expressions(const, '', output, '')
        wiring = MaterialTools.get_expression_inputs(self.func, output)
        self.assertEqual(len(wiring), 1)
        self.assertEqual(wiring[0].expression, const)
        self.assertEqual(wiring[0].output_name, '')

    def test_get_referencing_materials(self):
        """Ensures that get_referencing_materials returns materials that use the function."""
        mat = MaterialTools.create_material(self.folder, 'RefMat')
        expr = MaterialTools.add_expression(
            mat, unreal.MaterialExpressionMaterialFunctionCall.static_class())
        expr.set_editor_property('material_function', self.func)
        MaterialTools.recompile(mat)
        eas = unreal.get_editor_subsystem(unreal.EditorAssetSubsystem)
        eas.save_asset(self.func.get_path_name().split('.')[0])
        eas.save_asset(mat.get_path_name().split('.')[0])
        ar = unreal.AssetRegistryHelpers.get_asset_registry()
        ar.scan_paths_synchronous([self.folder], force_rescan=True)
        result = MaterialTools.get_referencing_materials(self.func)
        self.assertEqual([str(ad.asset_name) for ad in result], ['RefMat'])
