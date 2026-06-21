# Copyright Epic Games, Inc. All Rights Reserved.
"""
Epic Developer AI Python Toolset.

Provides @toolset_registry.tool_call decorator.
"""

from collections.abc import Callable
from contextlib import contextmanager
from contextvars import ContextVar
from functools import wraps
import inspect
from types import NoneType, UnionType
from typing import get_args, get_origin, Any, Generator, Sequence

from ._unreal import get_unreal_module

# Context variable to control exception handling behavior in tool calls.
# When True, exceptions are re-raised instead of being converted to script errors.
# Useful for testing and debugging.
_tool_raise_exceptions = ContextVar('tool_raise_exceptions', default=False)


@contextmanager
def tool_raising_exceptions() -> Generator[None, None, None]:
    """Context manager to temporarily enable exception raising in tool calls.

    When used, exceptions in tool calls will be raised normally instead of being
    converted to script errors. This is useful for testing and debugging.

    Example:
        with tool_raising_exceptions():
            # Exceptions will be raised here
            some_toolset.some_tool()

    Note: the ufunction decorator wraps all raised exceptions in RuntimeError,
    so tests must do something like this:

        def tool_that_raises_ValueError():
            ...

        with tool_raising_exceptions():
            with self.assertRaisesRegex(RuntimeError, 'ValueError'):
                tool_that_raises_ValueError()

    or
        with tool_raising_exceptions():
            with self.assertRaises(RuntimeError) as context:
                tool_that_raises_ValueError()
            self.assertIn('ValueError: ', str(context.exception))
    """
    token = _tool_raise_exceptions.set(True)
    try:
        yield
    finally:
        _tool_raise_exceptions.reset(token)


class ToolCallMissingAnnotation(Exception):
    """Raised when a method marked as a tool call is missing annotations."""


def _python_to_unreal_type(annotation: Any) -> Any:
    """Converts typing annotation types into the types that Unreal expects.

    Most types pass straight through but containers are transformed accordingly.
    """

    origin = get_origin(annotation)
    args = get_args(annotation)

    optional = False
    if origin is UnionType and NoneType in args:
        assert len(args) == 2, 'Optional params can only contain None and one other type.'
        optional = True
        temp_args = list(args)
        temp_args.remove(NoneType)
        annotation = temp_args[0]
        origin = get_origin(annotation)
        args = get_args(annotation)

    def check_args(args: Sequence[Any], num_required: int):
        """Raise ToolCallMissingAnnotation if number of args is less than
        required, or one of the required args is None or not a type."""
        if not args or len(args) < num_required:
            raise ToolCallMissingAnnotation(
                f'Type {annotation}: missing types for {origin}')
        for arg in args[:num_required]:
            if not (arg and isinstance(arg, type)):
                raise ToolCallMissingAnnotation(
                    f'Type {annotation}: missing types for {origin}')

    unreal = get_unreal_module()
    if origin:
        match origin:
            case _islist if origin is list:
                check_args(args, 1)
                annotation = unreal.Array(args[0])
            case _isdict if origin is dict:
                check_args(args, 2)
                # Schema generator only supports dicts with string keys.
                if not args[0] is str:
                    raise ToolCallMissingAnnotation(
                        f'Type {annotation}: only string keys supported for dict')
                annotation = unreal.Map(args[0], args[1])
            case _isset if origin is set:
                check_args(args, 1)
                annotation = unreal.Set(args[0])
    else:
        # container types to be converted to Unreal equivalent need to specify
        # type contained.
        if annotation is list or annotation is dict or annotation is set:
            raise ToolCallMissingAnnotation(
                f'Type {annotation}: missing specification for contained type.')

    return (annotation, None) if optional else annotation


def _get_signature(func: Callable[..., Any]) -> tuple[list[type], type | None]:
    """Inspect function's signature and return param and return value type."""
    signature = inspect.signature(func, eval_str=True)
    params: list[type] = []
    for param_name, param in signature.parameters.items():
        if param_name != 'self':
            if param.annotation is param.empty:
                raise ToolCallMissingAnnotation(
                    f'Tool call {func.__name__}: param {param_name} has no annotation')
            params.append(_python_to_unreal_type(param.annotation))

    return_type: type | None = None
    return_type = signature.return_annotation
    if return_type:
        return_type = _python_to_unreal_type(return_type)
    return (params, return_type)


def _get_default_value_for_type(in_type_or_static_class : type | None) -> object | None:
    """Return default value for type."""
    unreal = get_unreal_module()
    # No type has a default of None.
    if in_type_or_static_class is None:
        return None
    # Containers default to the Unreal type.
    if isinstance(
        in_type_or_static_class,
        (unreal.Array, unreal.Map, unreal.Set)
    ):
        return in_type_or_static_class
    # Optional values default to None.
    if (isinstance(in_type_or_static_class, tuple) and
        len(in_type_or_static_class) == 2 and
        in_type_or_static_class[1] is None):
        return None
    assert isinstance(in_type_or_static_class, type), (
        f'Expected a type, got: {in_type_or_static_class!r}')
    # UObject and UClass instances default to None.
    if issubclass(in_type_or_static_class, (unreal.Object, unreal.Class)):
        return None
    # Everything else defaults to an instance of the default.
    return in_type_or_static_class()


def tool_call(func: Callable[..., Any]):
    """Decorator to wrap and declare a toolset method as a tool.

    Used to mark a method as a tool (UFunction) suitable for calling from an AI
    agent.  Tool method params and return types must be annotated.

    Note: Tool calls must be static methods.

    Note: Python exceptions in the tool method are caught and raised as script
    errors so the toolset registry can treat them as errors from the tool.
    Script error events however are not broadcast outside of the game thread, so
    tools *must* be called from the game thread in order to properly get errors
    detected.

    Args:
        func: Method to mark as a tool.

    Returns:
        The generated UFunction.

    Raises:
        ToolCallMissingAnnotation: if any params or return type are missing
    annotations that would cause the unreal.ufunction decorator to fail.
    """
    unreal = get_unreal_module()
    params, return_type = _get_signature(func)

    @wraps(func)
    def _wrapped_func(*args: Any, **kwargs: Any):
        try:
            return func(*args, **kwargs)
        except Exception as e:  # pylint: disable=broad-exception-caught
            if _tool_raise_exceptions.get():
                # Note: ufunction wraps all exceptions as RuntimeError
                raise
            unreal.SystemLibrary.raise_script_error(f'{str(e)}')
            return _get_default_value_for_type(return_type)

    # UFunction uses inspect.getfullargspec to enumerate parameters, which isn't
    # handled by functools.wraps, so we need to modify _wrapped_func's signature
    # as well.
    _wrapped_func.__signature__ = inspect.signature(func) # type: ignore

    ufunction = unreal.ufunction(
        static=True, params=params, ret=return_type, meta={'AICallable' : ''}
    )
    assert callable(ufunction)
    return ufunction(_wrapped_func)
