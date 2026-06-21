# Copyright Epic Games, Inc. All Rights Reserved.

import json
import unittest
import unreal

from toolset_registry.tool_call_impl import (
    ToolCallMissingAnnotation, _python_to_unreal_type, _get_signature,
    _get_default_value_for_type, tool_call, tool_raising_exceptions)
from toolset_registry.tests.demo_toolset import ErrorProneToolset

class TestToolCallDecoratorHelpers(unittest.TestCase):
    """Tests for the tool_call decorator helper methods."""

    def test_python_to_unreal_type_none(self):
        """Test that _python_to_unreal_type returns correct type for None."""
        self.assertEqual(_python_to_unreal_type(None), None)

    def test_python_to_unreal_type_basic(self):
        """Test that _python_to_unreal_type returns correct type for basic types."""
        self.assertEqual(_python_to_unreal_type(int), int)
        self.assertEqual(_python_to_unreal_type(str), str)
        self.assertEqual(_python_to_unreal_type(float), float)
        self.assertEqual(_python_to_unreal_type(bool), bool)

    def test_python_to_unreal_type_list(self):
        """Test that _python_to_unreal_type converts lists to unreal.Array."""
        self.assertEqual(_python_to_unreal_type(list[int]), unreal.Array(int))
        self.assertEqual(_python_to_unreal_type(list[str]), unreal.Array(str))

    def test_python_to_unreal_type_list_no_type(self):
        """Test _python_to_unreal_type on lists without contained type. """
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _python_to_unreal_type(list)

    def test_python_to_unreal_type_set(self):
        """Test that _python_to_unreal_type converts sets to unreal.Set."""
        self.assertEqual(_python_to_unreal_type(set[int]), unreal.Set(int))
        self.assertEqual(_python_to_unreal_type(set[str]), unreal.Set(str))

    def test_python_to_unreal_type_set_no_type(self):
        """Test _python_to_unreal_type on sets without contained type."""
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _python_to_unreal_type(set)

    def test_python_to_unreal_type_dict(self):
        """Test that _python_to_unreal_type converts dicts to unreal.Map."""
        self.assertEqual(_python_to_unreal_type(dict[str, int]), unreal.Map(str, int))
        self.assertEqual(_python_to_unreal_type(dict[str, str]), unreal.Map(str, str))

    def test_python_to_unreal_type_dict_unsupported_key_type(self):
        """Test that _python_to_unreal_type raises on dicts with non-string keys."""
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _python_to_unreal_type(dict[int, str])

    def test_python_to_unreal_type_dict_no_type(self):
        """Test that _python_to_unreal_type raises on dicts without type."""
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _python_to_unreal_type(dict)

    def test_python_to_unreal_type_dict_missing_type(self):
        """Test that _python_to_unreal_type raises on dicts with missing types."""
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _python_to_unreal_type(dict[str])

    def test_python_to_unreal_type_optional_list(self):
        """Test that Optional list converts to (Array, None)."""
        self.assertEqual(_python_to_unreal_type(list[int] | None),
                         (unreal.Array(int), None))

    def test_python_to_unreal_type_optional_dict(self):
        """Test that Optional dict converts to (Map, None)."""
        self.assertEqual(_python_to_unreal_type(dict[str, str] | None),
                         (unreal.Map(str, str), None))

    def test_python_to_unreal_type_optional_set(self):
        """Test that Optional set converts to (Set, None)."""
        self.assertEqual(_python_to_unreal_type(set[int] | None),
                         (unreal.Set(int), None))

    def test_python_to_unreal_type_enum(self):
        """Test that _python_to_unreal_type handles UEnum properly."""
        @unreal.uenum()
        class ATestEnum(unreal.EnumBase):
            """A test Enum with values."""
            One = unreal.uvalue(0)
            Two = unreal.uvalue(1)
            Three = unreal.uvalue(2)

        self.assertEqual(_python_to_unreal_type(ATestEnum), ATestEnum)

    def test_python_to_unreal_type_struct(self):
        """Test that _python_to_unreal_type handles UStruct properly."""
        @unreal.ustruct()
        class ATestStruct(unreal.StructBase):
            """A test Struct with values."""
            One = unreal.uproperty(int)
            Two = unreal.uproperty(str)
            Three = unreal.uproperty(bool)

        self.assertEqual(_python_to_unreal_type(ATestStruct), ATestStruct)

    def test_get_signature_unannotated_raises(self):
        """Test that calling _get_signature on unannotated function raises
        properly."""
        def a_func(a, b):
            """Has unannotated params."""
        with self.assertRaises(ToolCallMissingAnnotation):
            _ = _get_signature(a_func)

    def test_get_signature_return_none(self):
        """Test that _get_signature returns proper type for returning None."""
        def a_func(a: int, b: float) -> None:
            """Does nothing"""
        _, return_type = _get_signature(a_func)
        self.assertEqual(return_type, None)

    def test_get_signature_basic(self):
        """Test that _get_signature on basic types returns correct signature."""
        def a_func(a: int, b: float, c: str, d: bool) -> int:
            """Does nothing"""
        param_types = [int, float, str, bool]
        params, return_type = _get_signature(a_func)
        self.assertSequenceEqual(params, param_types)
        self.assertEqual(return_type, int)

    def test_get_signature_arrays(self):
        """Test that _get_signature on lists returns correct signature."""
        def a_func(a: list[int], b: list[float], c: list[str],
                   d: list[bool]) -> list[int]:
            """Does nothing"""
        param_types = [
            unreal.Array(int), unreal.Array(float), unreal.Array(str),
            unreal.Array(bool)]
        params, return_type = _get_signature(a_func)
        self.assertSequenceEqual(params, param_types)
        self.assertEqual(return_type, unreal.Array(int))

    def test_get_signature_maps(self):
        """Test that _get_signature on dicts returns correct signature."""
        def a_func(a: dict[str, int], b: dict[str, float], c: dict[str, str],
                   d: dict[str, bool]) -> dict[str, int]:
            """Does nothing"""
        param_types = [
            unreal.Map(str, int), unreal.Map(str, float), unreal.Map(str, str),
            unreal.Map(str, bool)]
        params, return_type = _get_signature(a_func)
        self.assertSequenceEqual(params, param_types)
        self.assertEqual(return_type, unreal.Map(str, int))

    def test_get_signature_sets(self):
        """Test that _get_signature on sets returns correct signature."""
        def a_func(a: set[int], b: set[float], c: set[str],
                   d: set[bool]) -> set[int]:
            """Does nothing"""
        param_types = [
            unreal.Set(int), unreal.Set(float), unreal.Set(str),
            unreal.Set(bool)]
        params, return_type = _get_signature(a_func)
        self.assertSequenceEqual(params, param_types)
        self.assertEqual(return_type, unreal.Set(int))

    def test_get_signature_object_class(self):
        """Test that _get_signature on object/class returns correct signature."""
        def a_func(a: unreal.Object, b: unreal.Class) -> unreal.Object:
            """Does nothing"""
        param_types = [
            unreal.Object, unreal.Class]
        params, return_type = _get_signature(a_func)
        self.assertSequenceEqual(params, param_types)
        self.assertEqual(return_type, unreal.Object)

class TestGetDefaultValueForType(unittest.TestCase):
    """Tests for _get_default_value_for_type."""

    def test_none_returns_none(self):
        self.assertIsNone(_get_default_value_for_type(None))

    def test_tuple_optional_returns_none(self):
        """(Type, None) tuples representing Optional types should return None."""
        self.assertIsNone(_get_default_value_for_type((unreal.Object, None)))
        self.assertIsNone(_get_default_value_for_type((unreal.Map(str, str), None)))

    def test_tuple_non_optional_falls_through(self):
        """Tuples that don't match (Type, None) are not treated as Optional."""
        with self.assertRaises(AssertionError):
            _get_default_value_for_type((unreal.Object, unreal.Object))

    def test_object_type_returns_none(self):
        self.assertIsNone(_get_default_value_for_type(unreal.Object))

    def test_array_type_returns_itself(self):
        t = unreal.Array(int)
        self.assertEqual(_get_default_value_for_type(t), t)

    def test_map_type_returns_itself(self):
        t = unreal.Map(str, str)
        self.assertEqual(_get_default_value_for_type(t), t)


class TestUnannotatedToolset(unittest.TestCase):
    """Test marking unannotated toolset methods as a tool_call."""

    def test_no_param_annotations(self):
        """Test tool call on method with no param annotations raises exception.

        """
        with self.assertRaises(ToolCallMissingAnnotation):
            @unreal.uclass()
            class UnannotatedToolset(unreal.ToolsetDefinition):
                """Python-defined Toolset with no param annotations."""
                @tool_call
                @staticmethod
                def method_one(input_one, input_two) -> int:
                    return input_one + input_two

    def test_no_exception_with_annotations(self):
        """Test tool call with annotations present works properly."""
        @unreal.uclass()
        class AnnotatedToolset(unreal.ToolsetDefinition):
            """Python-defined Toolset with annotations."""
            @tool_call
            @staticmethod
            def method_one(input_one: int, input_two: int) -> int:
                return input_one + input_two
        cdo = unreal.get_default_object(AnnotatedToolset)
        self.assertIsNotNone(cdo)


class TestToolCallSignatures(unittest.TestCase):
    """Test tool_call on methods with various signatures."""

    def test_tool_call_simple_types(self):
        """Test tool_call on method with simple types."""
        def method(a: int, b: str, c: float, d: bool) -> bool:
            """."""
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_list_params(self):
        """Test tool_call on method with list param."""
        def method(a: list[int], b: str, c: float, d: bool) -> list[int]:
            """."""
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_dict_params(self):
        """Test tool_call on method with dict param."""
        def method(a: dict[str, int]) -> dict[str, int]:
            """."""
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_set_params(self):
        """Test tool_call on method with set param."""
        def method(a: set[int], b: str, c: float, d: bool) -> bool:
            """."""
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_no_return(self):
        """Test tool_call with no annotated return value."""
        def method(a: int):
            """."""
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_optional_dict_param(self):
        """Test tool_call on method with optional dict param."""
        def method(a: str, tags: dict[str, str] | None = None) -> list[str]:
            """."""
            return []
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_optional_list_param(self):
        """Test tool_call on method with optional list param."""
        def method(a: str, items: list[str] | None = None) -> list[str]:
            """."""
            return []
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))

    def test_tool_call_optional_set_param(self):
        """Test tool_call on method with optional set param."""
        def method(a: str, items: set[str] | None = None) -> bool:
            """."""
            return True
        ufunc = tool_call(method)
        self.assertTrue(isinstance(ufunc, unreal.FunctionDef))


class TestToolCallWithRaising(unittest.TestCase):
    """Test tool_call's tool_raising_exceptions context manager."""

    def test_with_raising(self):
        """Test tool exceptions with tool_raising_exceptions."""
        with tool_raising_exceptions():
            # Test two different ways of asserting on raise.
            with self.assertRaisesRegex(RuntimeError, 'NameError') as context:
                ErrorProneToolset.bad_tool('ignore')
            self.assertIn('NameError: Bad tool bad', str(context.exception))

            with self.assertRaises(RuntimeError) as context:
                ErrorProneToolset.bad_tool('ignore')
            self.assertIn('NameError: Bad tool bad', str(context.exception))

    def test_without_raising(self):
        """Test tool exceptions without tool_raising_exceptions.

        In the normal case, without a tool_raising_exceptions context,
        exceptions raised by tool calls are caught and sent to
        unreal.SystemLibrary.raise_script_error so that the C++ side of the
        toolset registry can examine them and pass them on to the agent.
        """
        try:
            ErrorProneToolset.bad_tool('ignore')
        except Exception as exc:
            self.fail(
                'Tool call raised exception to Python unexpectedly, '
                f'without using tool_raising_exceptions: {exc}')
