# Copyright Epic Games, Inc. All Rights Reserved.

import toolset_registry
import unreal

@unreal.uenum()
class SomeKindOfEnum(unreal.EnumBase):
    """Just some kind of enum with values."""
    ValueOne = unreal.uvalue(0)
    ValueTwo = unreal.uvalue(1)
    ValueThree = unreal.uvalue(2)

@unreal.ustruct()
class ToolsetTestInput(unreal.StructBase):
    """Input struct that has some parameters."""
    # Setting ToolTip metadata will add it to a 'description' field for the
    # property in the schema.
    value_1 = unreal.uproperty(str, meta={'ToolTip': 'Input string'})
    # The ClampMin, ClampMax metadata will show up in the schema as 'minimum',
    # 'maximum' fields.
    value_2 = unreal.uproperty(int, meta={'ClampMin': 0, 'ClampMax': 50})
    kind_of_input = unreal.uproperty(SomeKindOfEnum)

@unreal.ustruct()
class ToolsetTestOutput(unreal.StructBase):
    """Output struct that has success field and some results."""
    success = unreal.uproperty(bool)
    a_number = unreal.uproperty(float)
    many_results = unreal.uproperty(unreal.Array(str))

@unreal.uclass()
class ToolsetTestObject(unreal.Object):
    """An Object for use in tests."""
    a_number = unreal.uproperty(float)
    a_string = unreal.uproperty(str)

@unreal.uclass()
class ToolsetTestActor(unreal.Actor):
    """An Actor subclass for use in tests."""

@unreal.uclass()
class DemoPythonToolset(unreal.ToolsetDefinition):
    """Demo implementation of an AI Toolset written in Python."""

    @toolset_registry.tool_call
    @staticmethod
    def hello_world(msg: str) -> str:
        """Demo hello tool function.

        Args:
            msg: Message to display to the world.

        Returns:
            String to be displayed.
        """
        return f'Hello, world! {msg} from demo toolset'

    @toolset_registry.tool_call
    @staticmethod
    def hello_many_worlds(msg: str, world_count: int = 42) -> int:
        """Demo hello tool function.

        Args:
            msg: Message to display to the world.
            world_count: How many worlds to greet.  Defaults to 42.

        Returns:
            Number of worlds greeted.
        """
        return world_count

    @toolset_registry.tool_call
    @staticmethod
    def hello_struct(test_input: ToolsetTestInput) -> ToolsetTestOutput:
        """Demo function with ustruct input/output.

        Args:
            test_input: An input struct.  If 'value_1' is set to 'fail',
            'success' will be set to False in the output

        Returns:
            An output struct.

        """
        output = ToolsetTestOutput()
        if test_input.value_1 == 'fail':
            output.success = False
            output.a_number = -1.0
            output.many_results = []
        else:
            output.success = True
            output.a_number = 42.0
            output.many_results = ['a', 'b', 'c']
        return output

    @toolset_registry.tool_call
    @staticmethod
    def hello_void() -> None:
        """Demo function that takes no params and returns nothing."""

    @toolset_registry.tool_call
    @staticmethod
    def hello_list(input: list[str]) -> list[str]:
        """Demo function that takes a list and returns a list."""
        return input

    @toolset_registry.tool_call
    @staticmethod
    def hello_dict(input: dict[str, float]) -> dict[str, float]:
        """Demo function that takes a dict and returns a dict."""
        return input

    @toolset_registry.tool_call
    @staticmethod
    def hello_set(input: set[float]) -> set[float]:
        """Demo function that takes a set and returns a set."""
        return input

    @toolset_registry.tool_call
    @staticmethod
    def hello_optional(input: float | None = None) -> float | None:
        """Demo function that has an optional input."""
        return input

    @toolset_registry.tool_call
    @staticmethod
    def hello_object(input: unreal.Object) -> unreal.Object:
        """Demo function that has an Object input."""
        return input

@unreal.uclass()
class ErrorProneToolset(unreal.ToolsetDefinition):
    """Toolset that errors out."""

    @toolset_registry.tool_call
    @staticmethod
    def bad_tool(msg: str) -> int:
        """Raises error when called."""
        raise NameError('Bad tool bad')

    @toolset_registry.tool_call
    @staticmethod
    def bad_typed_tool(msg: str) -> int:
        """Raises errors at scripting layer when called.

        Abuse the type annotations to tell the Python scripting layer that the
        return value will be an integer, but returning None, in order to force
        the Python scripting layer to throw exceptions when trying to convert a
        Python NoneType value to a native Unreal integer type property.

        """
        return None # type: ignore

    @toolset_registry.tool_call
    @staticmethod
    def takes_uobject(obj: unreal.Object) -> None:
        """Takes UObject param."""
        return

    @toolset_registry.tool_call
    @staticmethod
    def takes_optional_uobject(obj: unreal.Object | None) -> None:
        """Takes optional UObject param."""
        return

    @toolset_registry.tool_call
    @staticmethod
    def takes_uclass(obj: unreal.Class) -> None:
        """Takes UClass param."""
        return

    @toolset_registry.tool_call
    @staticmethod
    def takes_actor(obj: unreal.Actor) -> None:
        """Takes Actor param."""
        return
