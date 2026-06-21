# Copyright Epic Games, Inc. All Rights Reserved.
"""Tests for editor_toolset.toolsets.blueprint_dsl.

All graph operations are performed through pure-Python fake callbacks so that
no Blueprint assets or Unreal graph objects are needed.
"""

import collections
import dataclasses
import unittest

from editor_toolset.toolsets import blueprint_dsl
from editor_toolset.toolsets.blueprint_dsl import Symbol, parse, tokenize


# ---------------------------------------------------------------------------
# Fake types — stand-ins for NodeInfo / PinInfo / PinID
# ---------------------------------------------------------------------------

_EXEC_TYPE = 'Exec'
_FakePoint = collections.namedtuple('_FakePoint', ['x', 'y'])


@dataclasses.dataclass
class _FakePin:
    name: str
    type_id: str
    pin_id: object = dataclasses.field(default_factory=object)
    connected_pins: list = dataclasses.field(default_factory=list)
    value: str = ''


@dataclasses.dataclass(eq=False)
class _FakePinID:
    """Identifies a pin.

    When used as ``_FakePin.pin_id`` (transpiler tests) ``node`` is a ``_FakeNode``
    and ``direction`` is ``'input'`` or ``'output'``.  When stored in
    ``connected_pins`` (decompiler tests) ``direction`` is left as ``''``.
    """
    node: object
    index_id: int
    direction: str = ''

    def __repr__(self) -> str:
        type_id = getattr(self.node, 'type_id', '?')
        return f'<{type_id}:{self.direction or "pin"}#{self.index_id}>'


@dataclasses.dataclass
class _FakeNodeInfo:
    type_id: str
    input_pins: list
    output_pins: list
    position: object = dataclasses.field(default_factory=lambda: _FakePoint(0, 0))
    __hash__ = object.__hash__


class _FakeNode:
    def __init__(self, type_id: str):
        self.type_id = type_id
        self._info: '_FakeNodeInfo' = _make_node_info(type_id)


def _make_node_info(type_id: str) -> _FakeNodeInfo:
    """Return a _FakeNodeInfo with appropriate pins for *type_id*."""
    if type_id == 'Utilities|FlowControl|Branch':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Condition', 'bool')],
            output_pins=[_FakePin('then', _EXEC_TYPE), _FakePin('else', _EXEC_TYPE)],
        )
    if type_id == 'Utilities|FlowControl|WhileLoop':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Condition', 'bool')],
            output_pins=[_FakePin('LoopBody', _EXEC_TYPE), _FakePin('Completed', _EXEC_TYPE)],
        )
    if type_id.startswith('AddEvent|'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[],
            output_pins=[_FakePin('then', _EXEC_TYPE)],
        )
    if type_id == 'Math|Vector|MakeVector':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('X', 'float'), _FakePin('Y', 'float'), _FakePin('Z', 'float')],
            output_pins=[_FakePin('ReturnValue', 'Vector')],
        )
    if type_id == 'Math|Vector|BreakVector':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('InVec', 'Vector')],
            output_pins=[_FakePin('X', 'float'), _FakePin('Y', 'float'), _FakePin('Z', 'float')],
        )
    if type_id == 'Math|Rotator|MakeRotator':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('Pitch', 'float'), _FakePin('Yaw', 'float'), _FakePin('Roll', 'float')],
            output_pins=[_FakePin('ReturnValue', 'Rotator')],
        )
    if type_id == 'Math|Rotator|BreakRotator':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('InRot', 'Rotator')],
            output_pins=[_FakePin('Pitch', 'float'), _FakePin('Yaw', 'float'), _FakePin('Roll', 'float')],
        )
    if type_id == 'Math|Transform|MakeTransform':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('Location', 'Vector'), _FakePin('Rotation', 'Rotator'),
                        _FakePin('Scale', 'Vector')],
            output_pins=[_FakePin('ReturnValue', 'Transform')],
        )
    if type_id == 'Math|Transform|BreakTransform':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('InTransform', 'Transform')],
            output_pins=[_FakePin('Location', 'Vector'), _FakePin('Rotation', 'Rotator'),
                         _FakePin('Scale', 'Vector')],
        )
    if type_id in ('Utilities|FlowControl|ForEachLoop', 'Utilities|Array|ForEachLoop'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Array', 'array')],
            output_pins=[
                _FakePin('LoopBody', _EXEC_TYPE),
                _FakePin('Array Element', 'wildcard'),
                _FakePin('Array Index', 'int'),
                _FakePin('Completed', _EXEC_TYPE),
            ],
        )
    if type_id in ('Utilities|FlowControl|ForEachLoopWithBreak',
                   'Utilities|Array|ForEachLoopWithBreak'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[
                _FakePin('execute', _EXEC_TYPE),
                _FakePin('Break', _EXEC_TYPE),
                _FakePin('Array', 'array'),
            ],
            output_pins=[
                _FakePin('LoopBody', _EXEC_TYPE),
                _FakePin('Array Element', 'wildcard'),
                _FakePin('Array Index', 'int'),
                _FakePin('Completed', _EXEC_TYPE),
            ],
        )
    if type_id == 'Utilities|FlowControl|ForLoop':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[
                _FakePin('execute', _EXEC_TYPE),
                _FakePin('FirstIndex', 'int'),
                _FakePin('LastIndex', 'int'),
            ],
            output_pins=[
                _FakePin('LoopBody', _EXEC_TYPE),
                _FakePin('Index', 'int'),
                _FakePin('Completed', _EXEC_TYPE),
            ],
        )
    if type_id == 'Utilities|FlowControl|ForLoopWithBreak':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[
                _FakePin('execute', _EXEC_TYPE),
                _FakePin('Break', _EXEC_TYPE),
                _FakePin('FirstIndex', 'int'),
                _FakePin('LastIndex', 'int'),
            ],
            output_pins=[
                _FakePin('LoopBody', _EXEC_TYPE),
                _FakePin('Index', 'int'),
                _FakePin('Completed', _EXEC_TYPE),
            ],
        )
    if type_id == 'Utilities|FlowControl|MultiGate':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE)],
            output_pins=[_FakePin('Out 0', _EXEC_TYPE), _FakePin('Out 1', _EXEC_TYPE)],
        )
    if type_id in ('Utilities|FlowControl|Select', 'Utilities|Select'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[
                _FakePin('A', 'wildcard'),
                _FakePin('B', 'wildcard'),
                _FakePin('Condition', 'bool'),
            ],
            output_pins=[_FakePin('ReturnValue', 'wildcard')],
        )
    if type_id.startswith('Utilities|Operators|'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('A', 'wildcard'), _FakePin('B', 'wildcard')],
            output_pins=[_FakePin('Result', 'wildcard')],
        )
    if type_id in ('Math|Boolean|ANDBoolean', 'Math|Boolean|ORBoolean',
                   'Math|Boolean|XORBoolean', 'Math|Boolean|NORBoolean'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('A', 'bool'), _FakePin('B', 'bool')],
            output_pins=[_FakePin('Result', 'bool')],
        )
    if type_id == 'Math|Boolean|NOTBoolean':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('Input', 'bool')],
            output_pins=[_FakePin('Result', 'bool')],
        )
    if type_id == '|ReturnNode':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('ReturnValue', 'wildcard')],
            output_pins=[],
        )
    if type_id in ('Utilities|FlowControl|SwitchOnInt', 'Utilities|FlowControl|SwitchOnString',
                   'Utilities|FlowControl|Switch|SwitchonInt', 'Utilities|FlowControl|Switch|SwitchonString'):
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Selection', 'wildcard')],
            output_pins=[
                _FakePin('0', _EXEC_TYPE),
                _FakePin('1', _EXEC_TYPE),
                _FakePin('Default', _EXEC_TYPE),
            ],
        )
    if type_id == 'Variables|Getareferencetoself':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[],
            output_pins=[_FakePin('self', 'Self Object Reference')],
        )
    if type_id == 'Utilities|IsValid':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Object', 'object')],
            output_pins=[_FakePin('Is Valid', _EXEC_TYPE), _FakePin('Is Not Valid', _EXEC_TYPE)],
        )
    if type_id == 'Ability|Tasks|WaitDelay':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Duration', 'float')],
            output_pins=[_FakePin('OnWait', _EXEC_TYPE), _FakePin('OnComplete', _EXEC_TYPE)],
        )
    if type_id == 'Ability|Tasks|PlayMontage':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Montage', 'object')],
            output_pins=[
                _FakePin('OnCompleted', _EXEC_TYPE),
                _FakePin('OnBlendOut', _EXEC_TYPE),
                _FakePin('OnInterrupted', _EXEC_TYPE),
            ],
        )
    if type_id == 'Utilities|Casting|CastToActor':
        return _FakeNodeInfo(
            type_id=type_id,
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('Object', 'object')],
            output_pins=[
                _FakePin('then', _EXEC_TYPE),
                _FakePin('CastFailed', _EXEC_TYPE),
                _FakePin('AsActor', 'object'),
            ],
        )
    # Generic exec node (e.g. PrintString, custom event)
    return _FakeNodeInfo(
        type_id=type_id,
        input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('InString', 'string')],
        output_pins=[_FakePin('then', _EXEC_TYPE), _FakePin('ReturnValue', 'wildcard')],
    )


# ---------------------------------------------------------------------------
# Test helpers
# ---------------------------------------------------------------------------

class _TranspilerTest(unittest.TestCase):
    """Base class: fake callbacks, _run() helper, and graph-assertion utilities."""

    def setUp(self):
        self._created: list[str] = []
        self._connected: list[tuple] = []
        self._pin_values: list[tuple] = []
        self._node_list: list[_FakeNode] = []

    def _create(self, graph, type_id, pos):
        node = _FakeNode(type_id)
        # Replace the placeholder object() pin_ids with traceable _FakePinID
        # instances so that connections can be asserted on in tests.
        ni = node._info
        for i, pin in enumerate(ni.input_pins):
            pin.pin_id = _FakePinID(node=node, index_id=i, direction='input')
        for i, pin in enumerate(ni.output_pins):
            pin.pin_id = _FakePinID(node=node, index_id=i, direction='output')
        self._created.append(type_id)
        self._node_list.append(node)
        return node

    def _connect(self, out_pin, in_pin):
        self._connected.append((out_pin, in_pin))

    def _run(self, code: str, existing_nodes=None) -> None:
        existing = list(existing_nodes or [])
        blueprint_dsl.Transpiler(
            None,
            self._create,
            self._connect,
            lambda n: n._info,
            lambda pid, val: self._pin_values.append((pid, val)),
            lambda graph: existing,
        ).transpile(code)

    def _created_types(self) -> list[str]:
        return self._created

    # ------------------------------------------------------------------ #
    # Node finders                                                        #
    # ------------------------------------------------------------------ #

    def _nodes_of_type(self, type_id: str) -> list[_FakeNode]:
        """Return all created nodes of *type_id* in creation order."""
        return [n for n in self._node_list if n.type_id == type_id]

    def _node_of_type(self, type_id: str) -> _FakeNode:
        """Return the single created node of *type_id*; fail if count != 1."""
        nodes = self._nodes_of_type(type_id)
        self.assertEqual(len(nodes), 1,
                         f'Expected exactly 1 {type_id!r} node, found {len(nodes)}')
        return nodes[0]

    # ------------------------------------------------------------------ #
    # Pin accessors                                                       #
    # ------------------------------------------------------------------ #

    def _data_out(self, node: _FakeNode, idx: int = 0) -> _FakePinID:
        """Return the *idx*-th non-exec output PinID of *node*."""
        data = [p for p in node._info.output_pins if p.type_id != _EXEC_TYPE]
        return data[idx].pin_id

    def _data_in(self, node: _FakeNode, idx: int = 0) -> _FakePinID:
        """Return the *idx*-th non-exec input PinID of *node*."""
        data = [p for p in node._info.input_pins if p.type_id != _EXEC_TYPE]
        return data[idx].pin_id

    def _named_out(self, node: _FakeNode, name: str) -> _FakePinID:
        """Return the output PinID of the pin named *name* on *node*."""
        pin = next((p for p in node._info.output_pins if p.name == name), None)
        self.assertIsNotNone(pin, f'No output pin {name!r} on {node.type_id!r}')
        return pin.pin_id

    def _named_in(self, node: _FakeNode, name: str) -> _FakePinID:
        """Return the input PinID of the pin named *name* on *node*."""
        pin = next((p for p in node._info.input_pins if p.name == name), None)
        self.assertIsNotNone(pin, f'No input pin {name!r} on {node.type_id!r}')
        return pin.pin_id

    # ------------------------------------------------------------------ #
    # Graph-structure assertions                                          #
    # ------------------------------------------------------------------ #

    def assertConnected(self, out_pin: _FakePinID, in_pin: _FakePinID, msg: str = '') -> None:
        """Assert that *out_pin* was wired to *in_pin* during transpilation."""
        self.assertIn(
            (out_pin, in_pin), self._connected,
            msg or f'Expected connection {out_pin!r} → {in_pin!r}')

    def assertCreatedBefore(self, first_type: str, second_type: str) -> None:
        """Assert that the first *first_type* node was created before any *second_type* node."""
        types = self._created_types()
        self.assertIn(first_type, types, f'{first_type!r} was never created')
        self.assertIn(second_type, types, f'{second_type!r} was never created')
        self.assertLess(
            types.index(first_type), types.index(second_type),
            f'Expected {first_type!r} created before {second_type!r}, '
            f'but order was {types}')


# ---------------------------------------------------------------------------
# Parser tests
# ---------------------------------------------------------------------------

class TokenizeTest(unittest.TestCase):

    def test_parens(self):
        tokens = tokenize('()')
        self.assertEqual(tokens, [Symbol('('), Symbol(')')])

    def test_integer(self):
        self.assertEqual(tokenize('42'), [42])
        self.assertIsInstance(tokenize('42')[0], int)

    def test_negative_integer(self):
        self.assertEqual(tokenize('-3'), [-3])

    def test_float(self):
        self.assertEqual(tokenize('3.14'), [3.14])

    def test_bool_true(self):
        self.assertEqual(tokenize('true'), [True])
        self.assertEqual(tokenize('True'), [True])
        self.assertEqual(tokenize('TRUE'), [True])

    def test_bool_false(self):
        self.assertEqual(tokenize('false'), [False])

    def test_symbol(self):
        toks = tokenize('MyVar')
        self.assertEqual(toks, [Symbol('MyVar')])
        self.assertIsInstance(toks[0], Symbol)

    def test_symbol_with_pipe(self):
        """Type IDs with | are valid symbols — core advantage over Python IDL."""
        toks = tokenize('Math|Float|sin(degrees)')
        self.assertEqual(toks, [Symbol('Math|Float|sin(degrees)')])

    def test_keyword_symbol(self):
        toks = tokenize(':PinName')
        self.assertEqual(toks, [Symbol(':PinName')])
        self.assertTrue(str(toks[0]).startswith(':'))

    def test_string_literal(self):
        toks = tokenize('"hello world"')
        self.assertEqual(toks, ['hello world'])
        self.assertNotIsInstance(toks[0], Symbol)

    def test_string_escape(self):
        toks = tokenize(r'"say \"hi\""')
        self.assertEqual(toks, ['say "hi"'])

    def test_string_backslash_escape(self):
        toks = tokenize(r'"C:\\path"')
        self.assertEqual(toks, ['C:\\path'])

    def test_string_backslash_and_quote_escape(self):
        toks = tokenize(r'"a\\\"b"')
        self.assertEqual(toks, ['a\\"b'])

    def test_comment_stripped(self):
        toks = tokenize('foo ; this is a comment\nbar')
        self.assertEqual(toks, [Symbol('foo'), Symbol('bar')])

    def test_comment_only_line(self):
        self.assertEqual(tokenize('; whole line comment'), [])

    def test_unterminated_string_raises(self):
        with self.assertRaises(RuntimeError):
            tokenize('"unclosed')

    def test_quoted_keyword(self):
        self.assertEqual(tokenize(':"Is Valid"'), [Symbol(':Is Valid')])

    def test_quoted_keyword_with_multiple_spaces(self):
        self.assertEqual(tokenize(':"Array Element"'), [Symbol(':Array Element')])

    def test_quoted_keyword_in_list(self):
        self.assertEqual(
            tokenize('(:"Is Not Valid")'),
            [Symbol('('), Symbol(':Is Not Valid'), Symbol(')')])

    def test_quoted_keyword_backslash_escape(self):
        self.assertEqual(tokenize(r':"C:\\pin"'), [Symbol(':C:\\pin')])

    def test_quoted_keyword_unterminated_raises(self):
        with self.assertRaises(RuntimeError):
            tokenize(':"unterminated')


class ParseTest(unittest.TestCase):

    def test_empty(self):
        self.assertEqual(parse(''), [])

    def test_atom(self):
        self.assertEqual(parse('42'), [42])

    def test_simple_list(self):
        self.assertEqual(parse('(a b c)'), [[Symbol('a'), Symbol('b'), Symbol('c')]])

    def test_nested_list(self):
        result = parse('(a (b c) d)')
        self.assertEqual(result, [[Symbol('a'), [Symbol('b'), Symbol('c')], Symbol('d')]])

    def test_multiple_top_level_forms(self):
        result = parse('(event A) (event B)')
        self.assertEqual(len(result), 2)

    def test_type_id_with_parens_in_symbol(self):
        result = parse('(Math|Float|sin(degrees) x)')
        self.assertEqual(result[0][0], Symbol('Math|Float|sin(degrees)'))

    def test_keyword_in_list(self):
        result = parse('(f :Pin 1)')
        self.assertEqual(result[0][1], Symbol(':Pin'))

    def test_unclosed_paren_raises(self):
        with self.assertRaises(RuntimeError):
            parse('(a b')

    def test_unexpected_close_paren_raises(self):
        with self.assertRaises(RuntimeError):
            parse(')')

    def test_bool_literals(self):
        result = parse('(f true false)')
        self.assertIs(result[0][1], True)
        self.assertIs(result[0][2], False)


# ---------------------------------------------------------------------------
# Transpiler — event / fn forms
# ---------------------------------------------------------------------------

class EventFormTest(_TranspilerTest):

    def test_event_creates_entry_node(self):
        self._run('(event EventBeginPlay)')
        self.assertIn('AddEvent|EventBeginPlay', self._created)

    def test_event_body_stmt_created(self):
        self._run('(event EventBeginPlay\n  (Development|PrintString "hi"))')
        self.assertIn('Development|PrintString', self._created)

    def test_multiple_events(self):
        self._run('(event EventBeginPlay)\n(event EventTick)')
        self.assertIn('AddEvent|EventBeginPlay', self._created)
        self.assertIn('AddEvent|EventTick', self._created)

    def test_event_prefix_in_name_is_stripped(self):
        """LLM using the type_id 'AddEvent|Foo' as the event name should create 'AddEvent|Foo', not 'AddEvent|AddEvent|Foo'."""
        self._run('(event AddEvent|ResetCooldown)')
        self.assertIn('AddEvent|ResetCooldown', self._created)
        self.assertNotIn('AddEvent|AddEvent|ResetCooldown', self._created)

    def test_custom_event_creates_custom_type_id(self):
        self._run('(event Custom|OnDamageTaken)')
        self.assertIn('AddEvent|Custom|OnDamageTaken', self._created)

    def test_wrong_top_level_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(bind x 1)')

    def test_bad_head_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(loop Foo)')

    def test_self_binding_available(self):
        self._run('(event EventBeginPlay\n  (Development|PrintString self))')
        self.assertIn('Variables|Getareferencetoself', self._created)

    def test_self_binding_not_created_when_param_named_self(self):
        """If an event param is named 'self', no Self Reference node is created."""
        node = _FakeNode('AddEvent|Foo')
        node._info = _FakeNodeInfo(
            type_id='AddEvent|Foo',
            input_pins=[],
            output_pins=[
                _FakePin('execute', _EXEC_TYPE, object()),
                _FakePin('self', 'object', object()),
            ],
        )
        self._run('(event Foo)', existing_nodes=[node])
        self.assertNotIn('Variables|Getareferencetoself', self._created)


class FnFormTest(_TranspilerTest):

    def test_fn_missing_param_list_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(fn DoubleIt)')

    def test_fn_body_creates_node(self):
        self._run('(fn DoubleIt ()\n  (Development|PrintString "x"))')
        self.assertIn('Development|PrintString', self._created)

    def test_fn_param_not_in_graph_raises(self):
        with self.assertRaisesRegex(RuntimeError, 'not found in graph'):
            self._run('(fn DoubleIt (Value)\n  (Development|PrintString "x"))')


# ---------------------------------------------------------------------------
# Transpiler — bind
# ---------------------------------------------------------------------------

class BindTest(_TranspilerTest):

    def test_bind_single_output(self):
        self._run('(event Foo\n  (bind x (Math|Vector|MakeVector 1.0 2.0 3.0)))')
        self.assertIn('Math|Vector|MakeVector', self._created)

    def test_bind_multi_output(self):
        vec = '(Math|Vector|MakeVector 1.0 2.0 3.0)'
        self._run(f'(event Foo\n  (bind v {vec})\n  (bind (x y z) (Math|Vector|BreakVector v)))')
        self.assertIn('Math|Vector|BreakVector', self._created)

    def test_bind_then_use_variable(self):
        self._run(
            '(event Foo\n'
            '  (bind x (Math|Vector|MakeVector 0.0 0.0 0.0))\n'
            '  (Development|PrintString x))')
        self.assertIn('Math|Vector|MakeVector', self._created)
        self.assertIn('Development|PrintString', self._created)

    def test_undefined_variable_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString undefined_var))')

    def test_bind_requires_target_and_expr(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (bind))')

    def test_bind_multi_too_many_targets_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (bind (x y z w) (Math|Vector|BreakVector MyVec)))')

    def test_bind_literal_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (bind x 42))')

    def test_rebind_same_name_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind x (Math|Vector|MakeVector 1.0 0.0 0.0))\n'
                '  (bind x (Math|Vector|MakeVector 0.0 1.0 0.0)))')

    def test_rebind_in_while_body_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind n (Math|Vector|MakeVector 1.0 0.0 0.0))\n'
                '  (while (== 1 1)\n'
                '    (bind n (Math|Vector|MakeVector 0.0 1.0 0.0))))')

    def test_rebind_multi_output_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind (x y z) (Math|Vector|BreakVector (Math|Vector|MakeVector 1.0 0.0 0.0)))\n'
                '  (bind (x y z) (Math|Vector|BreakVector (Math|Vector|MakeVector 0.0 1.0 0.0))))')

    def test_bind_exec_cont_creates_node(self):
        self._run(
            '(event Foo\n'
            '  (bind actor (Utilities|Casting|CastToActor :Object "x")\n'
            '    (:then)\n'
            '    (:CastFailed)))')
        self.assertIn('Utilities|Casting|CastToActor', self._created)

    def test_bind_exec_cont_name_available_in_body(self):
        self._run(
            '(event Foo\n'
            '  (bind actor (Utilities|Casting|CastToActor :Object "x")\n'
            '    (:then (Development|PrintString :InString actor))))')
        cast_node = self._node_of_type('Utilities|Casting|CastToActor')
        print_node = self._node_of_type('Development|PrintString')
        self.assertConnected(self._data_out(cast_node), self._named_in(print_node, 'InString'))

    def test_bind_exec_cont_name_not_in_outer_scope(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind actor (Utilities|Casting|CastToActor :Object "x")\n'
                '    (:then))\n'
                '  (Development|PrintString :InString actor))')

    def test_bind_exec_cont_non_cont_extra_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind actor (Utilities|Casting|CastToActor :Object "x")\n'
                '    (:then)\n'
                '    "junk"))')

    def test_bind_multi_target_with_exec_cont_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (bind (a b) (Utilities|Casting|CastToActor :Object "x")\n'
                '    (:then)))')


# ---------------------------------------------------------------------------
# Transpiler — call / keyword args
# ---------------------------------------------------------------------------

class CallTest(_TranspilerTest):

    def test_positional_args_set_pin_values(self):
        self._run('(event Foo\n  (Development|PrintString "hello"))')
        values = [v for _, v in self._pin_values]
        self.assertIn('hello', values)

    def test_keyword_arg(self):
        self._run(
            '(event Foo\n'
            '  (Development|PrintString :InString "world"))')
        values = [v for _, v in self._pin_values]
        self.assertIn('world', values)

    def test_positional_after_keyword_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString :InString "x" "extra"))')

    def test_too_many_positional_args_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString "a" "b"))')

    def test_unknown_keyword_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString :NoSuchPin "x"))')

    def test_keyword_with_no_value_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString :InString))')

    def test_duplicate_keyword_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (Development|PrintString :InString "a" :InString "b"))')

    def test_integer_literal_set_as_string(self):
        self._run('(event Foo\n  (Development|PrintString 42))')
        values = [v for _, v in self._pin_values]
        self.assertIn('42', values)

    def test_float_literal(self):
        self._run('(event Foo\n  (Development|PrintString 3.14))')
        values = [v for _, v in self._pin_values]
        self.assertIn('3.14', values)

    def test_bool_true_literal(self):
        self._run('(event Foo\n  (Development|PrintString true))')
        values = [v for _, v in self._pin_values]
        self.assertIn('true', values)

    def test_bool_false_literal(self):
        self._run('(event Foo\n  (Development|PrintString false))')
        values = [v for _, v in self._pin_values]
        self.assertIn('false', values)

    def test_type_id_with_parens_works(self):
        """Type IDs containing ( and ) are passed verbatim — no encoding needed."""
        self._run('(event Foo\n  (Math|Float|sin(degrees) 45.0))')
        self.assertIn('Math|Float|sin(degrees)', self._created)

    def test_type_id_with_pipe_works(self):
        self._run('(event Foo\n  (Some|Deep|Node|Path "x"))')
        self.assertIn('Some|Deep|Node|Path', self._created)


# ---------------------------------------------------------------------------
# Transpiler — operators
# ---------------------------------------------------------------------------

class OperatorTest(_TranspilerTest):

    def _run_op(self, op: str):
        self._run(f'(event Foo\n  (bind x ({op} 1 2)))')

    def test_add(self):
        self._run_op('+')
        self.assertIn('Utilities|Operators|Add', self._created)

    def test_subtract(self):
        self._run_op('-')
        self.assertIn('Utilities|Operators|Subtract', self._created)

    def test_multiply(self):
        self._run_op('*')
        self.assertIn('Utilities|Operators|Multiply', self._created)

    def test_divide(self):
        self._run_op('/')
        self.assertIn('Utilities|Operators|Divide', self._created)

    def test_modulo(self):
        self._run_op('%')
        self.assertIn('Utilities|Operators|Modulo', self._created)

    def test_equal(self):
        self._run_op('==')
        self.assertIn('Utilities|Operators|Equal(==)', self._created)

    def test_not_equal(self):
        self._run_op('!=')
        self.assertIn('Utilities|Operators|NotEqual(!=)', self._created)

    def test_less(self):
        self._run_op('<')
        self.assertIn('Utilities|Operators|Less(<)', self._created)

    def test_less_equal(self):
        self._run_op('<=')
        self.assertIn('Utilities|Operators|LessEqual(<=)', self._created)

    def test_greater(self):
        self._run_op('>')
        self.assertIn('Utilities|Operators|Greater(>)', self._created)

    def test_greater_equal(self):
        self._run_op('>=')
        self.assertIn('Utilities|Operators|GreaterEqual(>=)', self._created)

    def test_and(self):
        self._run_op('and')
        self.assertIn('Math|Boolean|ANDBoolean', self._created)

    def test_or(self):
        self._run_op('or')
        self.assertIn('Math|Boolean|ORBoolean', self._created)

    def test_xor(self):
        self._run_op('xor')
        self.assertIn('Math|Boolean|XORBoolean', self._created)

    def test_add_with_string_operand_uses_append(self):
        for code in (
            '(event Foo\n  (bind x (+ "hello" " world")))',
            '(event Foo\n  (bind x (+ 1 " suffix")))',
        ):
            self.setUp()
            self._run(code)
            self.assertIn('Utilities|String|Append', self._created)
            self.assertNotIn('Utilities|Operators|Add', self._created)

    def test_add_with_numeric_literals_uses_add(self):
        self._run('(event Foo\n  (bind x (+ 1 2)))')
        self.assertIn('Utilities|Operators|Add', self._created)
        self.assertNotIn('Utilities|String|Append', self._created)

    def test_not(self):
        self._run('(event Foo\n  (bind x (not true)))')
        self.assertIn('Math|Boolean|NOTBoolean', self._created)

    def test_neg(self):
        self._run('(event Foo\n  (bind x (neg 5)))')
        self.assertIn('Utilities|Operators|Subtract', self._created)
        values = [v for _, v in self._pin_values]
        self.assertIn('0', values)

    def test_binop_wrong_arg_count_raises(self):
        for code in (
            '(event Foo\n  (bind x (+ 1)))',
            '(event Foo\n  (bind x (+ 1 2 3)))',
        ):
            with self.assertRaises(RuntimeError):
                self._run(code)

    def test_not_wrong_arg_count_raises(self):
        for code in (
            '(event Foo\n  (bind x (not)))',
            '(event Foo\n  (bind x (not true false)))',
        ):
            with self.assertRaises(RuntimeError):
                self._run(code)

    def test_neg_wrong_arg_count_raises(self):
        for code in (
            '(event Foo\n  (bind x (neg)))',
            '(event Foo\n  (bind x (neg 1 2)))',
        ):
            with self.assertRaises(RuntimeError):
                self._run(code)


# ---------------------------------------------------------------------------
# Transpiler — component access
# ---------------------------------------------------------------------------

class ComponentAccessTest(_TranspilerTest):

    def _run_comp(self, attr: str, break_type: str):
        self._run(
            f'(event Foo\n'
            f'  (bind v (Math|Vector|MakeVector 0.0 0.0 0.0))\n'
            f'  (bind c (.{attr} v)))')
        self.assertIn(break_type, self._created)

    def test_x(self):
        self._run_comp('x', 'Math|Vector|BreakVector')

    def test_y(self):
        self._run_comp('y', 'Math|Vector|BreakVector')

    def test_z(self):
        self._run_comp('z', 'Math|Vector|BreakVector')

    def test_pitch(self):
        self._run_comp('pitch', 'Math|Rotator|BreakRotator')

    def test_pitch_wires_pitch_pin(self):
        self._run(
            '(event Foo\n'
            '  (bind r (Math|Rotator|MakeRotator 0.0 0.0 0.0))\n'
            '  (Development|PrintString (.pitch r)))')
        break_node = self._node_of_type('Math|Rotator|BreakRotator')
        printer = self._node_of_type('Development|PrintString')
        self.assertConnected(
            self._named_out(break_node, 'Pitch'),
            self._named_in(printer, 'InString'))

    def test_yaw(self):
        self._run_comp('yaw', 'Math|Rotator|BreakRotator')

    def test_yaw_wires_yaw_pin(self):
        self._run(
            '(event Foo\n'
            '  (bind r (Math|Rotator|MakeRotator 0.0 0.0 0.0))\n'
            '  (Development|PrintString (.yaw r)))')
        break_node = self._node_of_type('Math|Rotator|BreakRotator')
        printer = self._node_of_type('Development|PrintString')
        self.assertConnected(
            self._named_out(break_node, 'Yaw'),
            self._named_in(printer, 'InString'))

    def test_roll(self):
        self._run_comp('roll', 'Math|Rotator|BreakRotator')

    def test_location(self):
        self._run_comp('location', 'Math|Transform|BreakTransform')

    def test_rotation(self):
        self._run_comp('rotation', 'Math|Transform|BreakTransform')

    def test_scale(self):
        self._run_comp('scale', 'Math|Transform|BreakTransform')

    def test_unsupported_attr_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (bind c (.w v)))')


# ---------------------------------------------------------------------------
# Transpiler — if / branch
# ---------------------------------------------------------------------------

class IfTest(_TranspilerTest):

    def test_if_creates_branch_node(self):
        self._run('(event Foo\n  (if true\n    (Development|PrintString "yes")))')
        self.assertIn('Utilities|FlowControl|Branch', self._created)

    def test_if_then_only(self):
        self._run('(event Foo\n  (if true\n    (Development|PrintString "y")))')
        self.assertIn('Development|PrintString', self._created)

    def test_if_else(self):
        self._run(
            '(event Foo\n'
            '  (if true\n'
            '    (Development|PrintString "yes")\n'
            '    (else\n'
            '      (Development|PrintString "no"))))')
        self.assertEqual(self._created.count('Development|PrintString'), 2)

    def test_nested_if_in_else(self):
        self._run(
            '(event Foo\n'
            '  (if true\n'
            '    (Development|PrintString "a")\n'
            '    (else\n'
            '      (if false\n'
            '        (Development|PrintString "b")))))')
        self.assertEqual(self._created.count('Utilities|FlowControl|Branch'), 2)

    def test_if_missing_condition_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (if))')

    def test_code_after_if_runs(self):
        for code in (
            '(event Foo\n'
            '  (if true\n'
            '    (Development|PrintString "yes"))\n'
            '  (Math|Vector|MakeVector 1.0 2.0 3.0))',

            '(event Foo\n'
            '  (if true\n'
            '    (Development|PrintString "yes")\n'
            '    (else\n'
            '      (Development|PrintString "no")))\n'
            '  (Math|Vector|MakeVector 1.0 2.0 3.0))',
        ):
            self.setUp()
            self._run(code)
            self.assertIn('Math|Vector|MakeVector', self._created)


# ---------------------------------------------------------------------------
# Transpiler — for loops
# ---------------------------------------------------------------------------

class ForRangeTest(_TranspilerTest):

    def test_for_range_creates_for_loop(self):
        self._run('(event Foo\n  (for _ (range 5)\n    (Development|PrintString "x")))')
        self.assertIn('Utilities|FlowControl|ForLoop', self._created)

    def test_for_range_sets_last_index(self):
        self._run('(event Foo\n  (for _ (range 5)))')
        values = [v for _, v in self._pin_values]
        self.assertIn('4', values)

    def test_for_range_start_stop(self):
        self._run('(event Foo\n  (for _ (range 2 7)))')
        values = [v for _, v in self._pin_values]
        self.assertIn('2', values)
        self.assertIn('6', values)

    def test_for_range_too_many_args_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (for _ (range 0 5 2)))')

    def test_for_range_binds_index_var(self):
        self._run('(event Foo\n  (for i (range 3)\n    (Development|PrintString i)))')
        self.assertIn('Development|PrintString', self._created)


class ForEachTest(_TranspilerTest):

    def test_for_each_creates_for_each_loop(self):
        self._run(
            '(event Foo\n'
            '  (bind arr (Some|GetArray))\n'
            '  (for elem arr\n'
            '    (Development|PrintString elem)))')
        self.assertIn('Utilities|Array|ForEachLoop', self._created)


# ---------------------------------------------------------------------------
# Transpiler — while
# ---------------------------------------------------------------------------

class WhileTest(_TranspilerTest):

    def test_while_creates_loop_and_body(self):
        self._run('(event Foo\n  (while true\n    (Development|PrintString "x")))')
        self.assertIn('Utilities|FlowControl|WhileLoop', self._created)
        self.assertIn('Development|PrintString', self._created)

    def test_while_missing_condition_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (while))')


# ---------------------------------------------------------------------------
# Transpiler — select (ternary)
# ---------------------------------------------------------------------------

class SelectTest(_TranspilerTest):

    def test_select_creates_select_node(self):
        self._run('(event Foo\n  (bind x (select true 1.0 2.0)))')
        self.assertIn('Utilities|Select', self._created)

    def test_select_wrong_arg_count_raises(self):
        for code in (
            '(event Foo\n  (bind x (select true 1.0)))',
            '(event Foo\n  (bind x (select true 1.0 2.0 3.0)))',
        ):
            with self.assertRaises(RuntimeError):
                self._run(code)


# ---------------------------------------------------------------------------
# Transpiler — return
# ---------------------------------------------------------------------------

class ReturnTest(_TranspilerTest):

    def _make_graph_with_return(self):
        ret_node = _FakeNode('|ReturnNode')
        return [ret_node]

    def test_return_no_value(self):
        nodes = self._make_graph_with_return()
        self._run('(event Foo\n  (return))', existing_nodes=nodes)
        self.assertEqual(self._pin_values, [])

    def test_return_single_value(self):
        nodes = self._make_graph_with_return()
        self._run('(event Foo\n  (return 42))', existing_nodes=nodes)
        values = [v for _, v in self._pin_values]
        self.assertIn('42', values)

    def test_return_too_many_values_raises(self):
        nodes = self._make_graph_with_return()
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (return 1 2))', existing_nodes=nodes)

    def test_unreachable_code_after_return_raises(self):
        nodes = self._make_graph_with_return()
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (return 1)\n'
                '  (Development|PrintString "unreachable"))',
                existing_nodes=nodes)


# ---------------------------------------------------------------------------
# Decompiler helpers and fakes
# ---------------------------------------------------------------------------

def _make_decompiler_node(type_id: str, position=None) -> _FakeNodeInfo:
    ni = _make_node_info(type_id)
    if position is not None:
        ni.position = position
    return ni


def _wire_exec(src_ni: _FakeNodeInfo, src_pin_name: str,
               dst_ni: _FakeNodeInfo, dst_pin_name: str = 'execute') -> None:
    """Connect an exec output of src_ni to an exec input of dst_ni."""
    src_pin = next(p for p in src_ni.output_pins if p.name == src_pin_name)
    dst_pin = next(p for p in dst_ni.input_pins if p.name == dst_pin_name)
    src_pin.connected_pins.append(_FakePinID(node=dst_ni, index_id=0))
    dst_pin.connected_pins.append(_FakePinID(node=src_ni, index_id=0))


def _wire_data(src_ni: _FakeNodeInfo, src_pin_name: str,
               dst_ni: _FakeNodeInfo, dst_pin_name: str) -> None:
    """Connect a data output of src_ni to a data input of dst_ni (bidirectional)."""
    src_idx = next(i for i, p in enumerate(src_ni.output_pins) if p.name == src_pin_name)
    dst_idx = next(i for i, p in enumerate(dst_ni.input_pins) if p.name == dst_pin_name)
    src_pin = src_ni.output_pins[src_idx]
    dst_pin = dst_ni.input_pins[dst_idx]
    dst_pin.connected_pins.append(_FakePinID(node=src_ni, index_id=src_idx))
    src_pin.connected_pins.append(_FakePinID(node=dst_ni, index_id=dst_idx))


def _run_decompiler(nodes: list) -> str:
    node_map = {id(ni): ni for ni in nodes}

    def get_info(node):
        return node_map[id(node)]

    return blueprint_dsl.Decompiler(
        None,
        get_info,
        lambda g: list(nodes),
    ).decompile()


# ---------------------------------------------------------------------------
# Decompiler tests
# ---------------------------------------------------------------------------

class DecompilerCallStmtTest(unittest.TestCase):

    def test_single_call_no_outputs(self):
        event = _make_node_info('AddEvent|Foo')
        call = _make_node_info('Development|PrintString')
        call.input_pins[1].value = 'hello'
        _wire_exec(event, 'then', call)
        result = _run_decompiler([event, call])
        self.assertIn('(Development|PrintString', result)
        self.assertIn('"hello"', result)

    def test_call_with_needed_output_gets_bind(self):
        event = _make_node_info('AddEvent|Foo')
        getter = _make_node_info('Transformation|GetActorLocation')
        getter.input_pins = [_FakePin('execute', _EXEC_TYPE)]
        getter.output_pins = [_FakePin('then', _EXEC_TYPE),
                               _FakePin('ReturnValue', 'Vector')]
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', getter)
        _wire_exec(getter, 'then', printer)
        _wire_data(getter, 'ReturnValue', printer, 'InString')
        result = _run_decompiler([event, getter, printer])
        self.assertIn('bind', result)
        self.assertIn('Transformation|GetActorLocation', result)


class DecompilerBranchTest(unittest.TestCase):

    def test_branch_emits_if(self):
        event = _make_node_info('AddEvent|Foo')
        branch = _make_node_info('Utilities|FlowControl|Branch')
        branch.input_pins[1].value = 'true'
        then_call = _make_node_info('Development|PrintString')
        then_call.input_pins[1].value = 'yes'
        _wire_exec(event, 'then', branch)
        _wire_exec(branch, 'then', then_call)
        result = _run_decompiler([event, branch, then_call])
        self.assertIn('(if', result)
        self.assertIn('(Development|PrintString', result)

    def test_branch_with_else(self):
        event = _make_node_info('AddEvent|Foo')
        branch = _make_node_info('Utilities|FlowControl|Branch')
        branch.input_pins[1].value = 'true'
        then_call = _make_node_info('Development|PrintString')
        else_call = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', branch)
        _wire_exec(branch, 'then', then_call)
        _wire_exec(branch, 'else', else_call)
        result = _run_decompiler([event, branch, then_call, else_call])
        self.assertIn('(if', result)
        self.assertIn('(else', result)

    def test_empty_then_body_flips_condition_to_avoid_placeholder(self):
        """When the then-branch is empty, the decompiler flips the condition to avoid (if x _ (else BODY))."""
        event = _make_node_info('AddEvent|Foo')
        branch = _make_node_info('Utilities|FlowControl|Branch')
        branch.input_pins[1].value = 'true'
        body = _make_node_info('Development|PrintString')
        body.input_pins[1].value = 'on cooldown'
        # Only the else (false) path is connected — then is empty.
        _wire_exec(event, 'then', branch)
        _wire_exec(branch, 'else', body)
        result = _run_decompiler([event, branch, body])
        # Should flip to (if (not true) ...) — no placeholder _ and no (else in output.
        self.assertNotIn('  _', result, f'Placeholder should be eliminated: {result}')
        self.assertNotIn('(else', result)
        self.assertIn('(not true)', result)

    def test_double_negation_stripped_when_flipping(self):
        """(if (not x) _ (else BODY)) canonicalizes to (if x BODY), not (if (not (not x)) BODY).

        Mirrors the real-world pattern: boolVar → NOT → Branch → else-path, which the
        decompiler should emit as (if boolVar ...) rather than (if (not boolVar) _ (else ...)).
        """
        event = _make_node_info('AddEvent|Foo')
        not_node = _make_node_info('Math|Boolean|NOTBoolean')
        not_node.input_pins[0].value = 'true'
        branch = _make_node_info('Utilities|FlowControl|Branch')
        body = _make_node_info('Development|PrintString')
        body.input_pins[1].value = 'on cooldown'
        _wire_exec(event, 'then', branch)
        _wire_data(not_node, 'Result', branch, 'Condition')
        # Only the else (false) path is connected — then is empty.
        _wire_exec(branch, 'else', body)
        result = _run_decompiler([event, not_node, branch, body])
        # NOT(x) → else path ≡ x → then path: should emit (if true ...) not (if (not true) _ (else ...)).
        self.assertIn('(if true', result)
        self.assertNotIn('(not', result)
        self.assertNotIn('(else', result)

    def test_shared_post_branch_node_is_outside_if_else(self):
        """A node reachable from both branches must decompile after the (if ...) block, not inside it."""
        event = _make_node_info('AddEvent|Foo')
        branch = _make_node_info('Utilities|FlowControl|Branch')
        branch.input_pins[1].value = 'true'
        then_call = _make_node_info('Development|PrintString')
        then_call.input_pins[1].value = 'then'
        else_call = _make_node_info('Development|PrintString')
        else_call.input_pins[1].value = 'else'
        end_call = _make_node_info('Development|PrintString')
        end_call.input_pins[1].value = 'end'
        _wire_exec(event, 'then', branch)
        _wire_exec(branch, 'then', then_call)
        _wire_exec(branch, 'else', else_call)
        _wire_exec(then_call, 'then', end_call)
        _wire_exec(else_call, 'then', end_call)
        result = _run_decompiler([event, branch, then_call, else_call, end_call])
        lines = result.splitlines()
        end_lines = [l for l in lines if '"end"' in l]
        self.assertEqual(len(end_lines), 1, f'Expected exactly one "end" line, got: {end_lines}')
        # Must be at event-body indent (2 spaces), not inside a branch body (4+ spaces).
        self.assertRegex(end_lines[0], r'^  \S',
                         f'"end" should be at 2-space indent: {end_lines[0]!r}')

    def test_nested_if_shared_node_is_outside_all_ifs(self):
        """A node reachable from all branches of a nested if must decompile after the outermost if."""
        event = _make_node_info('AddEvent|Foo')
        outer_branch = _make_node_info('Utilities|FlowControl|Branch')
        outer_branch.input_pins[1].value = 'true'
        inner_branch = _make_node_info('Utilities|FlowControl|Branch')
        inner_branch.input_pins[1].value = 'false'
        then_a = _make_node_info('Development|PrintString')
        then_a.input_pins[1].value = 'A'
        then_b = _make_node_info('Development|PrintString')
        then_b.input_pins[1].value = 'B'
        else_c = _make_node_info('Development|PrintString')
        else_c.input_pins[1].value = 'C'
        end_call = _make_node_info('Development|PrintString')
        end_call.input_pins[1].value = 'end'
        _wire_exec(event, 'then', outer_branch)
        _wire_exec(outer_branch, 'then', inner_branch)
        _wire_exec(outer_branch, 'else', else_c)
        _wire_exec(inner_branch, 'then', then_a)
        _wire_exec(inner_branch, 'else', then_b)
        _wire_exec(then_a, 'then', end_call)
        _wire_exec(then_b, 'then', end_call)
        _wire_exec(else_c, 'then', end_call)
        result = _run_decompiler([event, outer_branch, inner_branch, then_a, then_b, else_c, end_call])
        lines = result.splitlines()
        end_lines = [l for l in lines if '"end"' in l]
        self.assertEqual(len(end_lines), 1, f'Expected exactly one "end" line, got: {end_lines}')
        # Must be at event-body indent (2 spaces), not inside any if body.
        self.assertRegex(end_lines[0], r'^  \S',
                         f'"end" should be at 2-space indent: {end_lines[0]!r}')


class DecompilerForLoopTest(unittest.TestCase):

    def test_for_loop_emits_range(self):
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|ForLoop')
        loop.input_pins[1].value = '0'
        loop.input_pins[2].value = '4'
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        result = _run_decompiler([event, loop, body])
        self.assertIn('(for', result)
        self.assertIn('(range', result)
        self.assertIn('5', result)

    def test_for_loop_with_nonzero_start(self):
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|ForLoop')
        loop.input_pins[1].value = '2'
        loop.input_pins[2].value = '9'
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        result = _run_decompiler([event, loop, body])
        self.assertIn('(range 2 10)', result)


class DecompilerForEachTest(unittest.TestCase):

    def test_for_each_emits_for(self):
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|ForEachLoop')
        loop.input_pins[1].value = ''
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        result = _run_decompiler([event, loop, body])
        self.assertIn('(for', result)


class DecompilerWhileTest(unittest.TestCase):

    def test_while_emits_while(self):
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|WhileLoop')
        loop.input_pins[1].value = 'true'
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        result = _run_decompiler([event, loop, body])
        self.assertIn('(while', result)
        self.assertIn('true', result)


class DecompilerReturnTest(unittest.TestCase):

    def test_return_no_inputs(self):
        event = _make_node_info('AddEvent|Foo')
        ret = _make_node_info('|ReturnNode')
        ret.input_pins = [_FakePin('execute', _EXEC_TYPE)]
        _wire_exec(event, 'then', ret)
        result = _run_decompiler([event, ret])
        self.assertIn('(return)', result)

    def test_return_single_value(self):
        event = _make_node_info('AddEvent|Foo')
        ret = _make_node_info('|ReturnNode')
        ret.input_pins[1].value = '42'
        _wire_exec(event, 'then', ret)
        result = _run_decompiler([event, ret])
        self.assertIn('(return', result)


class DecompilerOperatorExprTest(unittest.TestCase):

    def _make_op_graph(self, type_id: str) -> str:
        event = _make_node_info('AddEvent|Foo')
        op_node = _make_node_info(type_id)
        op_node.input_pins[0].value = '1'
        op_node.input_pins[1].value = '2'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(op_node, 'Result', printer, 'InString')
        return _run_decompiler([event, op_node, printer])

    def test_add_inlines_as_expression(self):
        result = self._make_op_graph('Utilities|Operators|Add')
        self.assertIn('(+', result)

    def test_and_inlines(self):
        result = self._make_op_graph('Math|Boolean|ANDBoolean')
        self.assertIn('(and', result)

    def test_not_inlines(self):
        event = _make_node_info('AddEvent|Foo')
        not_node = _make_node_info('Math|Boolean|NOTBoolean')
        not_node.input_pins[0].value = 'true'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(not_node, 'Result', printer, 'InString')
        result = _run_decompiler([event, not_node, printer])
        self.assertIn('(not', result)

    def test_self_ref_node_emits_self(self):
        """Variables|Self-Reference (NodeInfo type_id) must decompile to the 'self' keyword."""
        event = _make_node_info('AddEvent|Foo')
        self_node = _FakeNodeInfo(
            type_id='Variables|Self-Reference',
            input_pins=[],
            output_pins=[_FakePin('self', 'Object Reference')],
        )
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(self_node, 'self', printer, 'InString')
        result = _run_decompiler([event, self_node, printer])
        self.assertIn(' self', result)
        self.assertNotIn('Variables|Self-Reference', result)


class DecompilerComponentAccessTest(unittest.TestCase):

    def test_break_vector_emits_dot_x(self):
        event = _make_node_info('AddEvent|Foo')
        break_v = _make_node_info('Math|Vector|BreakVector')
        break_v.input_pins[0].value = '0'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(break_v, 'X', printer, 'InString')
        result = _run_decompiler([event, break_v, printer])
        self.assertIn('(.x', result)

    def test_break_rotator_pitch_emits_dot_pitch(self):
        event = _make_node_info('AddEvent|Foo')
        break_r = _make_node_info('Math|Rotator|BreakRotator')
        break_r.input_pins[0].value = '0'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(break_r, 'Pitch', printer, 'InString')
        result = _run_decompiler([event, break_r, printer])
        self.assertIn('(.pitch', result)

    def test_break_rotator_yaw_emits_dot_yaw(self):
        event = _make_node_info('AddEvent|Foo')
        break_r = _make_node_info('Math|Rotator|BreakRotator')
        break_r.input_pins[0].value = '0'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(break_r, 'Yaw', printer, 'InString')
        result = _run_decompiler([event, break_r, printer])
        self.assertIn('(.yaw', result)

    def test_break_transform_location(self):
        event = _make_node_info('AddEvent|Foo')
        break_t = _make_node_info('Math|Transform|BreakTransform')
        break_t.input_pins[0].value = '0'
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(break_t, 'Location', printer, 'InString')
        result = _run_decompiler([event, break_t, printer])
        self.assertIn('(.location', result)


class DecompilerTrailingDefaultStripTest(unittest.TestCase):
    """Pure nodes inlined as expressions strip trailing pins that match their schema default."""

    def test_unconnected_self_pin_not_emitted_as_zero(self):
        """GetActorLocation with implicit self should decompile without a trailing 0 argument."""
        event = _make_node_info('AddEvent|Foo')
        pure = _FakeNodeInfo(
            type_id='Transformation|GetActorLocation',
            input_pins=[_FakePin('self', 'Actor Object Reference', value='')],
            output_pins=[_FakePin('ReturnValue', 'Vector')],
        )
        printer = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', printer)
        _wire_data(pure, 'ReturnValue', printer, 'InString')

        def fake_get_node_type_pins(_graph, type_id):
            if type_id == 'Transformation|GetActorLocation':
                return _FakeNodeInfo(
                    type_id=type_id,
                    input_pins=[_FakePin('self', 'Actor Object Reference', value='')],
                    output_pins=[_FakePin('ReturnValue', 'Vector')],
                )
            return _FakeNodeInfo(type_id=type_id, input_pins=[], output_pins=[])

        nodes = [event, pure, printer]
        node_map = {id(ni): ni for ni in nodes}
        result = blueprint_dsl.Decompiler(
            None,
            lambda n: node_map[id(n)],
            lambda _g: nodes,
            get_node_type_pins_fn=fake_get_node_type_pins,
        ).decompile()

        self.assertIn('(Transformation|GetActorLocation)', result)
        self.assertNotIn('(Transformation|GetActorLocation 0', result)

    def test_single_arg_matching_default_is_kept(self):
        """A setter with one arg equal to the schema default must still emit that arg."""
        event = _make_node_info('AddEvent|Foo')
        setter = _FakeNodeInfo(
            type_id='Variables|Default|SetScore',
            input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('New Value', 'int', value='0')],
            output_pins=[_FakePin('then', _EXEC_TYPE)],
        )
        _wire_exec(event, 'then', setter)

        def fake_get_node_type_pins(_graph, type_id):
            if type_id == 'Variables|Default|SetScore':
                return _FakeNodeInfo(
                    type_id=type_id,
                    input_pins=[_FakePin('execute', _EXEC_TYPE), _FakePin('New Value', 'int', value='0')],
                    output_pins=[_FakePin('then', _EXEC_TYPE)],
                )
            return _FakeNodeInfo(type_id=type_id, input_pins=[], output_pins=[])

        nodes = [event, setter]
        node_map = {id(ni): ni for ni in nodes}
        result = blueprint_dsl.Decompiler(
            None,
            lambda n: node_map[id(n)],
            lambda _g: nodes,
            get_node_type_pins_fn=fake_get_node_type_pins,
        ).decompile()

        self.assertIn('(Variables|Default|SetScore 0)', result)


class DecompilerEventHeaderTest(unittest.TestCase):

    def test_event_header(self):
        event = _make_node_info('AddEvent|EventBeginPlay')
        result = _run_decompiler([event])
        self.assertIn('(event EventBeginPlay', result)

    def test_custom_event_header_preserves_custom_prefix(self):
        event = _make_node_info('AddEvent|Custom|OnDamageTaken')
        result = _run_decompiler([event])
        self.assertIn('(event Custom|OnDamageTaken', result)

    def test_fn_header_with_params(self):
        fn_entry = _make_node_info('|DoubleIt')
        fn_entry.type_id = '|DoubleIt'
        fn_entry.input_pins = []
        fn_entry.output_pins = [
            _FakePin('then', _EXEC_TYPE),
            _FakePin('Value', 'float'),
        ]
        result = _run_decompiler([fn_entry])
        self.assertIn('(fn DoubleIt (Value)', result)


class DecompilerMultiGateRaisesTest(unittest.TestCase):

    def test_multigate_raises(self):
        event = _make_node_info('AddEvent|Foo')
        mg = _make_node_info('Utilities|FlowControl|MultiGate')
        _wire_exec(event, 'then', mg)
        with self.assertRaises(RuntimeError):
            _run_decompiler([event, mg])


# ---------------------------------------------------------------------------
# Format helpers
# ---------------------------------------------------------------------------

class FormatLiteralTest(unittest.TestCase):

    def test_bool_true(self):
        self.assertEqual(blueprint_dsl._format_literal(True), 'true')

    def test_bool_false(self):
        self.assertEqual(blueprint_dsl._format_literal(False), 'false')

    def test_int(self):
        self.assertEqual(blueprint_dsl._format_literal(42), '42')

    def test_float(self):
        self.assertEqual(blueprint_dsl._format_literal(3.14), '3.14')

    def test_string(self):
        self.assertEqual(blueprint_dsl._format_literal('hello'), 'hello')


class FormatValueTest(unittest.TestCase):

    def test_bool_formats(self):
        self.assertEqual(blueprint_dsl._format_pin_default('true', 'bool'), 'true')
        self.assertEqual(blueprint_dsl._format_pin_default('false', 'bool'), 'false')
        self.assertEqual(blueprint_dsl._format_pin_default('True', 'bool'), 'true')

    def test_bool_boolean_type_id(self):
        self.assertEqual(blueprint_dsl._format_pin_default('true', 'Boolean'), 'true')
        self.assertEqual(blueprint_dsl._format_pin_default('false', 'Boolean'), 'false')

    def test_string_like_types_are_quoted(self):
        for type_id, val in (
            ('string', 'hi'),
            ('String (by ref)', 'alpha'),
            ('Name', 'MyName'),
            ('Text', 'hello'),
        ):
            self.assertEqual(blueprint_dsl._format_pin_default(val, type_id), f'"{val}"')

    def test_numeric_passthrough(self):
        self.assertEqual(blueprint_dsl._format_pin_default('3.14', 'float'), '3.14')

    def test_integer_passthrough(self):
        self.assertEqual(blueprint_dsl._format_pin_default('42', 'int'), '42')

    def test_empty_numeric_fallback(self):
        self.assertEqual(blueprint_dsl._format_pin_default('', 'float'), '0')

    def test_enum_value_quoted(self):
        self.assertEqual(blueprint_dsl._format_pin_default('AlwaysSpawn', 'ESpawnActorCollisionHandlingMethod'), '"AlwaysSpawn"')

    def test_class_path_quoted(self):
        self.assertEqual(blueprint_dsl._format_pin_default('/Script/Engine.StaticMeshActor', 'object'), '"/Script/Engine.StaticMeshActor"')


class SwitchDecompilerTest(unittest.TestCase):
    """Switch nodes decompile using the (switch ...) keyword form."""

    def test_switch_emits_switch_keyword(self):
        event = _make_node_info('AddEvent|Foo')
        sw = _make_node_info('Utilities|FlowControl|Switch|SwitchonInt')
        sw.input_pins[1].value = '0'
        case0 = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', sw)
        _wire_exec(sw, '0', case0)
        result = _run_decompiler([event, sw, case0])
        self.assertIn('switch', result)

    def test_switch_emits_node_type_and_cases(self):
        event = _make_node_info('AddEvent|Foo')
        sw = _make_node_info('Utilities|FlowControl|Switch|SwitchonInt')
        sw.input_pins[1].value = '0'
        case0 = _make_node_info('Development|PrintString')
        case1 = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', sw)
        _wire_exec(sw, '0', case0)
        _wire_exec(sw, '1', case1)
        result = _run_decompiler([event, sw, case0, case1])
        self.assertIn('Utilities|FlowControl|Switch|SwitchonInt', result)
        self.assertIn('(:0', result)
        self.assertIn('(:1', result)

    def test_switch_default_case(self):
        event = _make_node_info('AddEvent|Foo')
        sw = _make_node_info('Utilities|FlowControl|Switch|SwitchonInt')
        sw.input_pins[1].value = '0'
        default = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', sw)
        _wire_exec(sw, 'Default', default)
        result = _run_decompiler([event, sw, default])
        self.assertIn('(:Default', result)

    def test_switch_parentheses_balanced(self):
        event = _make_node_info('AddEvent|Foo')
        sw = _make_node_info('Utilities|FlowControl|Switch|SwitchonInt')
        sw.input_pins[1].value = '0'
        case0 = _make_node_info('Development|PrintString')
        case1 = _make_node_info('Development|PrintString')
        default = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', sw)
        _wire_exec(sw, '0', case0)
        _wire_exec(sw, '1', case1)
        _wire_exec(sw, 'Default', default)
        result = _run_decompiler([event, sw, case0, case1, default])
        self.assertEqual(result.count('('), result.count(')'))


class QuotedPinNameTest(_TranspilerTest):
    """Transpiler: pin names with spaces use the :"quoted" form."""

    def test_quoted_exec_continuation_wires_node(self):
        self._run(
            '(event Foo\n'
            '  (Utilities|IsValid\n'
            '    (:"Is Valid"\n'
            '      (Development|PrintString "ok"))\n'
            '    (:"Is Not Valid"\n'
            '      (Development|PrintString "nil"))))'
        )
        self.assertIn('Utilities|IsValid', self._created_types())
        self.assertEqual(self._created_types().count('Development|PrintString'), 2)

    def test_quoted_keyword_data_arg(self):
        # :"InString" as a keyword arg (same mechanism, different position)
        self._run('(event Foo (Development|PrintString :"InString" "hello"))')
        values = [str(v) for _, v in self._pin_values]
        self.assertIn('hello', values)

    def test_quoted_exec_unknown_pin_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (Utilities|IsValid\n'
                '    (:"No Such Pin")))'
            )


class QuotedPinNameDecompilerTest(unittest.TestCase):
    """Decompiler: exec output pins with spaces are emitted as :\"name\"."""

    def test_space_in_exec_pin_name_is_quoted(self):
        event = _make_node_info('AddEvent|Foo')
        node = _make_node_info('Utilities|IsValid')
        on_valid = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', node)
        _wire_exec(node, 'Is Valid', on_valid)
        result = _run_decompiler([event, node, on_valid])
        self.assertIn('(:"Is Valid"', result)

    def test_quoted_pin_name_parentheses_balanced(self):
        event = _make_node_info('AddEvent|Foo')
        node = _make_node_info('Utilities|IsValid')
        on_valid = _make_node_info('Development|PrintString')
        on_invalid = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', node)
        _wire_exec(node, 'Is Valid', on_valid)
        _wire_exec(node, 'Is Not Valid', on_invalid)
        result = _run_decompiler([event, node, on_valid, on_invalid])
        self.assertEqual(result.count('('), result.count(')'))

    def test_simple_pin_name_not_quoted(self):
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|WaitDelay')
        task.input_pins[1].value = '1.0'
        on_complete = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', task)
        _wire_exec(task, 'OnComplete', on_complete)
        result = _run_decompiler([event, task, on_complete])
        # No quotes around a simple identifier pin name.
        self.assertIn('(:OnComplete', result)
        self.assertNotIn('(:"OnComplete"', result)


class IncrementExprTest(unittest.TestCase):

    def test_integer_string(self):
        self.assertEqual(blueprint_dsl._increment_expr('4'), '5')

    def test_non_integer_wraps_in_add(self):
        self.assertEqual(blueprint_dsl._increment_expr('n'), '(+ n 1)')


# ---------------------------------------------------------------------------
# Multi-exec output tests (transpiler)
# ---------------------------------------------------------------------------

class MultiExecTranspilerTest(_TranspilerTest):
    """Transpiler: nodes with named exec outputs (latent / ability task nodes)."""

    def test_multi_exec_creates_node(self):
        self._run('(event Foo (Ability|Tasks|WaitDelay 2.0 (:OnWait) (:OnComplete)))')
        self.assertIn('Ability|Tasks|WaitDelay', self._created_types())

    def test_multi_exec_wires_continuation_bodies(self):
        self._run(
            '(event Foo\n'
            '  (Ability|Tasks|WaitDelay 2.0\n'
            '    (:OnWait\n'
            '      (Development|PrintString "waiting"))\n'
            '    (:OnComplete\n'
            '      (Development|PrintString "done"))))'
        )
        types = self._created_types()
        self.assertIn('Ability|Tasks|WaitDelay', types)
        # Both continuation body nodes must be created.
        self.assertEqual(types.count('Development|PrintString'), 2)

    def test_multi_exec_terminates_enclosing_exec(self):
        # Statements after a multi-exec call should raise as unreachable.
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (Ability|Tasks|WaitDelay 2.0\n'
                '    (:OnWait)\n'
                '    (:OnComplete))\n'
                '  (Development|PrintString "unreachable"))'
            )

    def test_multi_exec_unknown_pin_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (Ability|Tasks|WaitDelay 2.0\n'
                '    (:BadPin)))'
            )

    def test_multi_exec_positional_arg_after_continuation_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (Ability|Tasks|WaitDelay\n'
                '    (:OnWait)\n'
                '    2.0))'  # positional arg after exec continuation
            )

    def test_multi_exec_many_continuations(self):
        self._run(
            '(event Foo\n'
            '  (Ability|Tasks|PlayMontage\n'
            '    (:OnCompleted   (Development|PrintString "a"))\n'
            '    (:OnBlendOut    (Development|PrintString "b"))\n'
            '    (:OnInterrupted (Development|PrintString "c"))))'
        )
        types = self._created_types()
        self.assertIn('Ability|Tasks|PlayMontage', types)
        self.assertEqual(types.count('Development|PrintString'), 3)

    def test_multi_exec_data_arg_still_wired(self):
        self._run(
            '(event Foo\n'
            '  (Ability|Tasks|WaitDelay 2.0\n'
            '    (:OnWait)\n'
            '    (:OnComplete)))'
        )
        # The Duration pin value should have been set to '2.0'.
        values = [str(v) for _, v in self._pin_values]
        self.assertIn('2.0', values)


# ---------------------------------------------------------------------------
# Multi-exec output tests (decompiler)
# ---------------------------------------------------------------------------

class MultiExecDecompilerTest(unittest.TestCase):
    """Decompiler: nodes with named exec outputs emit (:PinName ...) continuations."""

    def test_multi_exec_emits_continuations(self):
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|WaitDelay')
        task.input_pins[1].value = '2.0'
        on_wait = _make_node_info('Development|PrintString')
        on_wait.input_pins[1].value = 'waiting'
        on_complete = _make_node_info('Development|PrintString')
        on_complete.input_pins[1].value = 'done'
        _wire_exec(event, 'then', task)
        _wire_exec(task, 'OnWait', on_wait)
        _wire_exec(task, 'OnComplete', on_complete)
        result = _run_decompiler([event, task, on_wait, on_complete])
        self.assertIn('Ability|Tasks|WaitDelay', result)
        self.assertIn('(:OnWait', result)
        self.assertIn('(:OnComplete', result)
        self.assertIn('"waiting"', result)
        self.assertIn('"done"', result)

    def test_multi_exec_single_continuation(self):
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|WaitDelay')
        task.input_pins[1].value = '1.0'
        on_complete = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', task)
        _wire_exec(task, 'OnComplete', on_complete)
        result = _run_decompiler([event, task, on_complete])
        self.assertIn('Ability|Tasks|WaitDelay', result)
        self.assertIn('(:OnComplete', result)

    def test_multi_exec_unconnected_continuations_not_emitted(self):
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|WaitDelay')
        task.input_pins[1].value = '1.0'
        # Neither OnWait nor OnComplete connected.
        _wire_exec(event, 'then', task)
        result = _run_decompiler([event, task])
        # Node still emitted (as a bare call), but no continuation syntax.
        self.assertIn('Ability|Tasks|WaitDelay', result)
        self.assertNotIn('(:On', result)

    def test_multi_exec_three_continuations(self):
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|PlayMontage')
        on_a = _make_node_info('Development|PrintString')
        on_b = _make_node_info('Development|PrintString')
        on_c = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', task)
        _wire_exec(task, 'OnCompleted', on_a)
        _wire_exec(task, 'OnBlendOut', on_b)
        _wire_exec(task, 'OnInterrupted', on_c)
        result = _run_decompiler([event, task, on_a, on_b, on_c])
        self.assertIn('(:OnCompleted', result)
        self.assertIn('(:OnBlendOut', result)
        self.assertIn('(:OnInterrupted', result)

    def test_multi_exec_parentheses_balanced(self):
        """Output must have balanced parentheses."""
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|WaitDelay')
        on_wait = _make_node_info('Development|PrintString')
        on_complete = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', task)
        _wire_exec(task, 'OnWait', on_wait)
        _wire_exec(task, 'OnComplete', on_complete)
        result = _run_decompiler([event, task, on_wait, on_complete])
        self.assertEqual(result.count('('), result.count(')'))

    def test_multi_exec_empty_continuations_balanced(self):
        """A non-last empty continuation must not produce extra closing parens.

        When multiple continuations point to the same node, the second and later
        visits produce empty cont_lines (node already visited). The non-last empty
        case (`:OnBlendOut` here) was the previously-broken path.
        """
        event = _make_node_info('AddEvent|Foo')
        task = _make_node_info('Ability|Tasks|PlayMontage')
        end = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', task)
        # All three wire to the same node: first visit produces body (non-empty),
        # subsequent visits see it already visited → empty continuation.
        # OnCompleted=non-empty non-last, OnBlendOut=empty non-last, OnInterrupted=empty last.
        _wire_exec(task, 'OnCompleted', end)
        _wire_exec(task, 'OnBlendOut', end)
        _wire_exec(task, 'OnInterrupted', end)
        result = _run_decompiler([event, task, end])
        self.assertEqual(result.count('('), result.count(')'))


# ---------------------------------------------------------------------------
# Break in loops (transpiler)
# ---------------------------------------------------------------------------

class BreakTranspilerTest(_TranspilerTest):
    """Transpiler: (break) triggers ForLoopWithBreak / ForEachLoopWithBreak."""

    def test_break_in_range_loop_creates_for_loop_with_break(self):
        self._run(
            '(event Foo\n'
            '  (for i (range 10)\n'
            '    (if (== i 5)\n'
            '      (break))))'
        )
        types = self._created_types()
        self.assertIn('Utilities|FlowControl|ForLoopWithBreak', types)
        self.assertNotIn('Utilities|FlowControl|ForLoop', types)

    def test_break_in_foreach_creates_for_each_with_break(self):
        self._run(
            '(event Foo\n'
            '  (for elem (Variables|Default|GetMyArray)\n'
            '    (if true\n'
            '      (break))))'
        )
        types = self._created_types()
        self.assertIn('Utilities|Array|ForEachLoopWithBreak', types)
        self.assertNotIn('Utilities|Array|ForEachLoop', types)

    def test_no_break_uses_regular_for_loop(self):
        self._run(
            '(event Foo\n'
            '  (for i (range 10)\n'
            '    (Development|PrintString "hi")))'
        )
        types = self._created_types()
        self.assertIn('Utilities|FlowControl|ForLoop', types)
        self.assertNotIn('Utilities|FlowControl|ForLoopWithBreak', types)

    def test_break_outside_loop_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (break))')

    def test_nested_loop_break_does_not_infect_outer_loop(self):
        """Break in the inner loop must not cause the outer loop to use ForLoopWithBreak."""
        self._run(
            '(event Foo\n'
            '  (for i (range 10)\n'
            '    (for j (range 10)\n'
            '      (if true\n'
            '        (break)))))'
        )
        types = self._created_types()
        self.assertIn('Utilities|FlowControl|ForLoop', types)
        self.assertIn('Utilities|FlowControl|ForLoopWithBreak', types)
        # Outer (regular ForLoop) must be created before the inner break variant.
        self.assertLess(
            types.index('Utilities|FlowControl|ForLoop'),
            types.index('Utilities|FlowControl|ForLoopWithBreak'),
        )


# ---------------------------------------------------------------------------
# Break in loops (decompiler)
# ---------------------------------------------------------------------------

class BreakDecompilerTest(unittest.TestCase):
    """Decompiler: ForLoopWithBreak / ForEachLoopWithBreak emit (break)."""

    def _make_for_loop_with_break_result(self) -> str:
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|ForLoopWithBreak')
        next(p for p in loop.input_pins if p.name == 'FirstIndex').value = '0'
        next(p for p in loop.input_pins if p.name == 'LastIndex').value = '4'
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        _wire_exec(body, 'then', loop, 'Break')
        return _run_decompiler([event, loop, body])

    def test_for_loop_with_break_emits_break(self):
        result = self._make_for_loop_with_break_result()
        self.assertIn('(break)', result)
        self.assertIn('(for', result)
        self.assertEqual(result.count('('), result.count(')'))

    def test_for_each_with_break_emits_break(self):
        event = _make_node_info('AddEvent|Foo')
        loop = _make_node_info('Utilities|FlowControl|ForEachLoopWithBreak')
        body = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', loop)
        _wire_exec(loop, 'LoopBody', body)
        _wire_exec(body, 'then', loop, 'Break')
        result = _run_decompiler([event, loop, body])
        self.assertIn('(break)', result)
        self.assertIn('(for', result)


# ---------------------------------------------------------------------------
# elif chains (transpiler)
# ---------------------------------------------------------------------------

class ElifTranspilerTest(_TranspilerTest):
    """Transpiler: (elif ...) compiles to a chained Branch node."""

    def test_elif_creates_two_branch_nodes(self):
        self._run(
            '(event Foo\n'
            '  (if (== 1 1)\n'
            '    (Development|PrintString "a")\n'
            '    (elif (== 2 2)\n'
            '      (Development|PrintString "b"))))'
        )
        types = self._created_types()
        self.assertEqual(types.count('Utilities|FlowControl|Branch'), 2)

    def test_elif_chain_three_branches(self):
        self._run(
            '(event Foo\n'
            '  (if (== 1 1)\n'
            '    (Development|PrintString "a")\n'
            '    (elif (== 2 2)\n'
            '      (Development|PrintString "b")\n'
            '      (elif (== 3 3)\n'
            '        (Development|PrintString "c")))))'
        )
        types = self._created_types()
        self.assertEqual(types.count('Utilities|FlowControl|Branch'), 3)

    def test_elif_with_else_creates_branch_with_else_body(self):
        self._run(
            '(event Foo\n'
            '  (if (== 1 1)\n'
            '    (Development|PrintString "a")\n'
            '    (elif (== 2 2)\n'
            '      (Development|PrintString "b")\n'
            '      (else\n'
            '        (Development|PrintString "c")))))'
        )
        types = self._created_types()
        self.assertEqual(types.count('Utilities|FlowControl|Branch'), 2)
        self.assertEqual(types.count('Development|PrintString'), 3)


# ---------------------------------------------------------------------------
# elif chains (decompiler)
# ---------------------------------------------------------------------------

class ElifDecompilerTest(unittest.TestCase):
    """Decompiler: Branch→else→Branch chain emits (elif ...) forms."""

    def _make_if_elif(self):
        """Build: event → Branch (if) → then_a; Branch.else → Branch (elif) → then_b."""
        event = _make_node_info('AddEvent|Foo')
        branch_if = _make_node_info('Utilities|FlowControl|Branch')
        branch_if.input_pins[1].value = 'true'
        branch_elif = _make_node_info('Utilities|FlowControl|Branch')
        branch_elif.input_pins[1].value = 'true'
        then_a = _make_node_info('Development|PrintString')
        then_a.input_pins[1].value = 'a'
        then_b = _make_node_info('Development|PrintString')
        then_b.input_pins[1].value = 'b'
        _wire_exec(event, 'then', branch_if)
        _wire_exec(branch_if, 'then', then_a)
        _wire_exec(branch_if, 'else', branch_elif)
        _wire_exec(branch_elif, 'then', then_b)
        return [event, branch_if, branch_elif, then_a, then_b]

    def test_elif_basic_chain(self):
        """A Branch→else→Branch emits elif (not bare else) with balanced parens."""
        result = _run_decompiler(self._make_if_elif())
        self.assertIn('elif', result)
        self.assertNotIn('(else', result)
        self.assertEqual(result.count('('), result.count(')'))

    def test_elif_chain_three_branches_emits_two_elifs(self):
        event = _make_node_info('AddEvent|Foo')
        br1 = _make_node_info('Utilities|FlowControl|Branch')
        br1.input_pins[1].value = 'true'
        br2 = _make_node_info('Utilities|FlowControl|Branch')
        br2.input_pins[1].value = 'true'
        br3 = _make_node_info('Utilities|FlowControl|Branch')
        br3.input_pins[1].value = 'true'
        a = _make_node_info('Development|PrintString')
        b = _make_node_info('Development|PrintString')
        c = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', br1)
        _wire_exec(br1, 'then', a)
        _wire_exec(br1, 'else', br2)
        _wire_exec(br2, 'then', b)
        _wire_exec(br2, 'else', br3)
        _wire_exec(br3, 'then', c)
        result = _run_decompiler([event, br1, br2, br3, a, b, c])
        self.assertEqual(result.count('elif'), 2)
        self.assertEqual(result.count('('), result.count(')'))

    def test_elif_with_else_emits_else_clause(self):
        event = _make_node_info('AddEvent|Foo')
        br_if = _make_node_info('Utilities|FlowControl|Branch')
        br_if.input_pins[1].value = 'true'
        br_elif = _make_node_info('Utilities|FlowControl|Branch')
        br_elif.input_pins[1].value = 'true'
        then_a = _make_node_info('Development|PrintString')
        then_b = _make_node_info('Development|PrintString')
        else_c = _make_node_info('Development|PrintString')
        _wire_exec(event, 'then', br_if)
        _wire_exec(br_if, 'then', then_a)
        _wire_exec(br_if, 'else', br_elif)
        _wire_exec(br_elif, 'then', then_b)
        _wire_exec(br_elif, 'else', else_c)
        result = _run_decompiler([event, br_if, br_elif, then_a, then_b, else_c])
        self.assertIn('elif', result)
        self.assertIn('(else', result)
        self.assertEqual(result.count('('), result.count(')'))


# ---------------------------------------------------------------------------
# switch keyword (transpiler)
# ---------------------------------------------------------------------------

class SwitchTranspilerTest(_TranspilerTest):
    """Transpiler: (switch TypeId value ...) creates the named switch node."""

    def test_switch_creates_named_switch_node(self):
        self._run(
            '(event Foo\n'
            '  (switch Utilities|FlowControl|SwitchOnInt 0\n'
            '    (:0)\n'
            '    (:1)\n'
            '    (:Default)))'
        )
        self.assertIn('Utilities|FlowControl|SwitchOnInt', self._created_types())

    def test_switch_string_variant_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (switch Utilities|FlowControl|SwitchOnString "hello"\n'
                '    (:0)\n'
                '    (:Default)))'
            )

    def test_switch_continuation_bodies_created(self):
        self._run(
            '(event Foo\n'
            '  (switch Utilities|FlowControl|SwitchOnInt 0\n'
            '    (:0\n'
            '      (Development|PrintString "zero"))\n'
            '    (:Default\n'
            '      (Development|PrintString "other"))))'
        )
        types = self._created_types()
        self.assertEqual(types.count('Development|PrintString'), 2)

    def test_switch_severs_enclosing_exec(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (switch Utilities|FlowControl|SwitchOnInt 0\n'
                '    (:0)\n'
                '    (:Default))\n'
                '  (Development|PrintString "unreachable"))'
            )

    def test_switch_unknown_pin_raises(self):
        with self.assertRaises(RuntimeError):
            self._run(
                '(event Foo\n'
                '  (switch Utilities|FlowControl|SwitchOnInt 0\n'
                '    (:BadPin)))'
            )

    def test_switch_missing_args_raises(self):
        with self.assertRaises(RuntimeError):
            self._run('(event Foo\n  (switch Utilities|FlowControl|SwitchOnInt))')


# ---------------------------------------------------------------------------
# Inline-arg ordering and connection tests
# ---------------------------------------------------------------------------

class InlineArgOrderTest(_TranspilerTest):
    """Guards the pre-evaluation fix applied to every _eval_* / _process_* method.

    Expression sub-nodes must be CREATED BEFORE their consumer nodes so that the
    graph layout is correct (left-to-right data flow), and their outputs must be
    CONNECTED to the right input pins.

    Each test names the specific transpiler method it is exercising.
    """

    # ------------------------------------------------------------------ #
    # _create_call_node — positional args                                 #
    # ------------------------------------------------------------------ #

    def test_inline_positional_arg(self):
        self._run('(event Foo\n  (Development|PrintString (Math|Rotator|MakeRotator 0.0 1.0 0.0)))')
        make = self._node_of_type('Math|Rotator|MakeRotator')
        call = self._node_of_type('Development|PrintString')
        self.assertCreatedBefore('Math|Rotator|MakeRotator', 'Development|PrintString')
        self.assertConnected(self._data_out(make), self._data_in(call))

    def test_multiple_inline_positional_args(self):
        """Expression args precede the consumer and connect to the correct positional inputs."""
        self._run(
            '(event Foo\n'
            '  (Math|Transform|MakeTransform\n'
            '    (Math|Vector|MakeVector 1.0 0.0 0.0)\n'
            '    (Math|Rotator|MakeRotator 0.0 0.0 0.0)\n'
            '    (Math|Vector|MakeVector 0.0 0.0 1.0)))'
        )
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Math|Transform|MakeTransform')
        self.assertCreatedBefore('Math|Rotator|MakeRotator', 'Math|Transform|MakeTransform')
        xform = self._node_of_type('Math|Transform|MakeTransform')
        rot   = self._node_of_type('Math|Rotator|MakeRotator')
        vecs  = self._nodes_of_type('Math|Vector|MakeVector')
        self.assertEqual(len(vecs), 2)
        self.assertConnected(self._data_out(vecs[0]), self._named_in(xform, 'Location'))
        self.assertConnected(self._data_out(rot),     self._named_in(xform, 'Rotation'))
        self.assertConnected(self._data_out(vecs[1]), self._named_in(xform, 'Scale'))

    # ------------------------------------------------------------------ #
    # _create_call_node — keyword args                                    #
    # ------------------------------------------------------------------ #

    def test_inline_keyword_arg(self):
        self._run(
            '(event Foo\n'
            '  (Development|PrintString :InString (Math|Rotator|MakeRotator 0.0 0.0 0.0)))'
        )
        make = self._node_of_type('Math|Rotator|MakeRotator')
        call = self._node_of_type('Development|PrintString')
        self.assertCreatedBefore('Math|Rotator|MakeRotator', 'Development|PrintString')
        self.assertConnected(self._data_out(make), self._named_in(call, 'InString'))

    # ------------------------------------------------------------------ #
    # _eval_binop                                                         #
    # ------------------------------------------------------------------ #

    def test_binop_expression_arg_created_before_op(self):
        self._run('(event Foo\n  (bind r (+ (Math|Vector|MakeVector 1.0 2.0 3.0) 0)))')
        vec = self._node_of_type('Math|Vector|MakeVector')
        add = self._node_of_type('Utilities|Operators|Add')
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Utilities|Operators|Add')
        self.assertConnected(self._data_out(vec), self._data_in(add, 0))

        self.setUp()
        self._run('(event Foo\n  (bind r (+ 0 (Math|Vector|MakeVector 1.0 2.0 3.0))))')
        vec = self._node_of_type('Math|Vector|MakeVector')
        add = self._node_of_type('Utilities|Operators|Add')
        self.assertConnected(self._data_out(vec), self._data_in(add, 1))

    def test_binop_both_expression_args_created_before_op(self):
        """_eval_binop: both lhs and rhs expression nodes created before the operator."""
        self._run(
            '(event Foo\n'
            '  (bind r (+ (Math|Vector|MakeVector 1.0 2.0 3.0)\n'
            '             (Math|Rotator|MakeRotator 0.0 0.0 0.0))))'
        )
        self.assertCreatedBefore('Math|Vector|MakeVector',  'Utilities|Operators|Add')
        self.assertCreatedBefore('Math|Rotator|MakeRotator', 'Utilities|Operators|Add')

    # ------------------------------------------------------------------ #
    # _eval_component_access                                              #
    # ------------------------------------------------------------------ #

    def test_component_access_expression(self):
        self._run('(event Foo\n  (bind z (.z (Math|Vector|MakeVector 0.0 0.0 5.0))))')
        vec = self._node_of_type('Math|Vector|MakeVector')
        brk = self._node_of_type('Math|Vector|BreakVector')
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Math|Vector|BreakVector')
        self.assertConnected(self._data_out(vec), self._data_in(brk))

    # ------------------------------------------------------------------ #
    # _eval_not                                                           #
    # ------------------------------------------------------------------ #

    def test_not_expression(self):
        self._run('(event Foo\n  (bind r (not (== 1 2))))')
        eq       = self._node_of_type('Utilities|Operators|Equal(==)')
        not_node = self._node_of_type('Math|Boolean|NOTBoolean')
        self.assertCreatedBefore('Utilities|Operators|Equal(==)', 'Math|Boolean|NOTBoolean')
        self.assertConnected(self._data_out(eq), self._data_in(not_node))

    # ------------------------------------------------------------------ #
    # _eval_neg                                                           #
    # ------------------------------------------------------------------ #

    def test_neg_expression(self):
        self._run('(event Foo\n  (bind r (neg (Math|Vector|MakeVector 0.0 1.0 0.0))))')
        vec = self._node_of_type('Math|Vector|MakeVector')
        sub = self._node_of_type('Utilities|Operators|Subtract')
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Utilities|Operators|Subtract')
        self.assertConnected(self._data_out(vec), self._data_in(sub, 1))

    # ------------------------------------------------------------------ #
    # _eval_select                                                        #
    # ------------------------------------------------------------------ #

    def test_select_expression_args_created_before_select_node(self):
        """_eval_select: all expression args created before the Select node."""
        self._run(
            '(event Foo\n'
            '  (bind r (select true\n'
            '    (Math|Vector|MakeVector 1.0 0.0 0.0)\n'
            '    (Math|Rotator|MakeRotator 0.0 0.0 0.0))))'
        )
        self.assertCreatedBefore('Math|Vector|MakeVector',  'Utilities|Select')
        self.assertCreatedBefore('Math|Rotator|MakeRotator', 'Utilities|Select')

    # ------------------------------------------------------------------ #
    # _process_if                                                         #
    # ------------------------------------------------------------------ #

    def test_if_expression_condition_created_before_branch(self):
        """_process_if: expression condition nodes created before the Branch node."""
        self._run(
            '(event Foo\n'
            '  (if (not (== 1 2))\n'
            '    (Development|PrintString "yes")))'
        )
        self.assertCreatedBefore('Utilities|Operators|Equal(==)', 'Utilities|FlowControl|Branch')
        self.assertCreatedBefore('Math|Boolean|NOTBoolean',        'Utilities|FlowControl|Branch')

    def test_if_expression_condition_connected_to_branch_condition_pin(self):
        """_process_if: expression condition output wired to Branch Condition input."""
        self._run(
            '(event Foo\n'
            '  (if (not true)\n'
            '    (Development|PrintString "yes")))'
        )
        not_node = self._node_of_type('Math|Boolean|NOTBoolean')
        branch   = self._node_of_type('Utilities|FlowControl|Branch')
        self.assertConnected(self._data_out(not_node), self._named_in(branch, 'Condition'))

    # ------------------------------------------------------------------ #
    # _process_while                                                      #
    # ------------------------------------------------------------------ #

    def test_while_expression_condition(self):
        self._run(
            '(event Foo\n'
            '  (while (not true)\n'
            '    (Development|PrintString "x")))'
        )
        not_node = self._node_of_type('Math|Boolean|NOTBoolean')
        loop     = self._node_of_type('Utilities|FlowControl|WhileLoop')
        self.assertCreatedBefore('Math|Boolean|NOTBoolean', 'Utilities|FlowControl|WhileLoop')
        self.assertConnected(self._data_out(not_node), self._named_in(loop, 'Condition'))

    # ------------------------------------------------------------------ #
    # _process_for_each                                                   #
    # ------------------------------------------------------------------ #

    def test_for_each_inline_iterator(self):
        self._run(
            '(event Foo\n'
            '  (for elem (Math|Vector|MakeVector 0.0 0.0 0.0)\n'
            '    (Development|PrintString "x")))'
        )
        vec  = self._node_of_type('Math|Vector|MakeVector')
        loop = self._node_of_type('Utilities|Array|ForEachLoop')
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Utilities|Array|ForEachLoop')
        self.assertConnected(self._data_out(vec), self._named_in(loop, 'Array'))

    # ------------------------------------------------------------------ #
    # _process_switch                                                     #
    # ------------------------------------------------------------------ #

    def test_switch_expression_value_created_before_switch_node(self):
        """_process_switch: expression value node created before the Switch node."""
        self._run(
            '(event Foo\n'
            '  (switch Utilities|FlowControl|SwitchOnInt\n'
            '    (Math|Vector|MakeVector 0.0 0.0 0.0)\n'
            '    (:0)\n'
            '    (:Default)))'
        )
        self.assertCreatedBefore('Math|Vector|MakeVector', 'Utilities|FlowControl|SwitchOnInt')

    # ------------------------------------------------------------------ #
    # _process_for_range                                                  #
    # ------------------------------------------------------------------ #

    def test_for_range_expression_stop_creates_nodes_before_loop(self):
        """_process_for_range: when stop is an expression, its nodes precede ForLoop.

        (range (+ 3 7)) → stop_expr=(+ 3 7) → last_expr=[- (+ 3 7) 1].
        Both the Add and the Subtract used to compute LastIndex must be created
        before the ForLoop node.
        """
        self._run(
            '(event Foo\n'
            '  (for i (range (+ 3 7))\n'
            '    (Development|PrintString "x")))'
        )
        self.assertCreatedBefore('Utilities|Operators|Add',      'Utilities|FlowControl|ForLoop')
        self.assertCreatedBefore('Utilities|Operators|Subtract', 'Utilities|FlowControl|ForLoop')


# ---------------------------------------------------------------------------
# _GraphSnapshot tests
# ---------------------------------------------------------------------------

@dataclasses.dataclass
class _SnapConnected:
    """Fake connected_pin for _GraphSnapshot tests.

    ``direction`` is an int: 0 = input (EGPD_INPUT), 1 = output (EGPD_OUTPUT).
    """
    node: object
    index_id: int
    direction: int


class _SnapNode:
    """Fake node for _GraphSnapshot tests -- carries a stable path string."""

    def __init__(self, path: str, type_id: str = 'Development|PrintString',
                 input_pins=None, output_pins=None):
        self._path = path
        self._info = _FakeNodeInfo(
            type_id=type_id,
            input_pins=list(input_pins or []),
            output_pins=list(output_pins or []),
        )

    def get_path_name(self) -> str:
        return self._path


def _snap_event(path: str) -> _SnapNode:
    """Exec-root event node: one exec output, no exec input."""
    node = _SnapNode(path, 'AddEvent|Snap')
    then_pin = _FakePin('then', _EXEC_TYPE)
    then_pin.pin_id = _FakePinID(node=node, index_id=0, direction='output')
    node._info.output_pins = [then_pin]
    return node


def _snap_action(path: str) -> _SnapNode:
    """Generic action node: exec in + exec out."""
    node = _SnapNode(path, 'Development|PrintString')
    exec_in = _FakePin('execute', _EXEC_TYPE)
    exec_in.pin_id = _FakePinID(node=node, index_id=0, direction='input')
    exec_out = _FakePin('then', _EXEC_TYPE)
    exec_out.pin_id = _FakePinID(node=node, index_id=0, direction='output')
    node._info.input_pins = [exec_in]
    node._info.output_pins = [exec_out]
    return node


def _snap_wire(src: _SnapNode, tgt: _SnapNode, src_pin: str = 'then') -> None:
    """Bidirectionally wire src's named exec output to tgt's exec input."""
    out_pin = next((p for p in src._info.output_pins if p.name == src_pin), None)
    in_pin = next((p for p in tgt._info.input_pins if p.type_id == _EXEC_TYPE), None)
    if out_pin is not None:
        out_pin.connected_pins.append(_SnapConnected(tgt, 0, 0))  # 0 = EGPD_INPUT
    if in_pin is not None:
        in_pin.connected_pins.append(_SnapConnected(src, 0, 1))   # 1 = EGPD_OUTPUT


class _GraphSnapshotTest(unittest.TestCase):
    """Tests for blueprint_dsl._GraphSnapshot."""

    @staticmethod
    def _make(nodes: list) -> blueprint_dsl._GraphSnapshot:
        return blueprint_dsl._GraphSnapshot(
            None,
            lambda _graph: nodes,
            lambda n: n._info,
        )

    # ------------------------------------------------------------------ #
    # __init__                                                             #
    # ------------------------------------------------------------------ #

    def test_init_captures_all_paths(self):
        a = _snap_event('path/A')
        b = _snap_action('path/B')
        snap = self._make([a, b])
        self.assertEqual(snap.pre_existing_paths, {'path/A', 'path/B'})

    def test_init_captures_connected_exec_output(self):
        src = _snap_event('path/Src')
        tgt = _snap_action('path/Tgt')
        _snap_wire(src, tgt)
        snap = self._make([src, tgt])
        self.assertEqual(len(snap.exec_connections), 1)
        conn = snap.exec_connections[0]
        self.assertEqual(conn.src_node_path, 'path/Src')
        self.assertEqual(conn.src_pin_name, 'then')
        self.assertEqual(len(conn.targets), 1)
        self.assertEqual(conn.targets[0].node_path, 'path/Tgt')
        self.assertEqual(conn.targets[0].index_id, 0)

    def test_init_skips_unconnected_exec_pins(self):
        node = _snap_event('path/A')
        snap = self._make([node])
        self.assertEqual(snap.exec_connections, [])

    def test_init_skips_non_exec_connected_pins(self):
        tgt = _SnapNode('path/Tgt')
        src = _SnapNode('path/Src', output_pins=[
            _FakePin('Value', 'float',
                     connected_pins=[_SnapConnected(tgt, 0, 0)]),
        ])
        snap = self._make([src])
        self.assertEqual(snap.exec_connections, [])

    # ------------------------------------------------------------------ #
    # rollback                                                             #
    # ------------------------------------------------------------------ #

    def test_rollback_deletes_new_nodes(self):
        old = _snap_event('path/Old')
        snap = self._make([old])
        new = _snap_action('path/New')
        current = [old, new]
        deleted = []
        snap.rollback(None, lambda _: current, lambda n: n._info,
                      lambda n: deleted.append(n.get_path_name()),
                      lambda a, b: None)
        self.assertIn('path/New', deleted)
        self.assertNotIn('path/Old', deleted)

    def test_rollback_keeps_pre_existing_nodes(self):
        node = _snap_event('path/Keep')
        snap = self._make([node])
        deleted = []
        snap.rollback(None, lambda _: [node], lambda n: n._info,
                      lambda n: deleted.append(n.get_path_name()),
                      lambda a, b: None)
        self.assertEqual(deleted, [])

    def test_rollback_restores_exec_connection(self):
        src = _snap_event('path/Src')
        tgt = _snap_action('path/Tgt')
        _snap_wire(src, tgt)
        snap = self._make([src, tgt])
        for pin in src._info.output_pins:
            pin.connected_pins.clear()
        reconnected = []
        snap.rollback(None, lambda _: [src, tgt], lambda n: n._info,
                      lambda n: None,
                      lambda out, inp: reconnected.append((out, inp)))
        self.assertEqual(len(reconnected), 1)

    # ------------------------------------------------------------------ #
    # delete_stale                                                         #
    # ------------------------------------------------------------------ #

    def test_delete_stale_removes_unreachable_node(self):
        event = _snap_event('path/Evt')
        action = _snap_action('path/Act')
        orphan = _snap_action('path/Orphan')
        _snap_wire(event, action)
        snap = self._make([event, action, orphan])
        deleted = []
        snap.delete_stale(None, lambda _: [event, action, orphan], lambda n: n._info,
                          lambda n: deleted.append(n.get_path_name()))
        self.assertIn('path/Orphan', deleted)
        self.assertNotIn('path/Evt', deleted)
        self.assertNotIn('path/Act', deleted)

    def test_delete_stale_keeps_all_reachable_nodes(self):
        event = _snap_event('path/Evt')
        action = _snap_action('path/Act')
        _snap_wire(event, action)
        snap = self._make([event, action])
        deleted = []
        snap.delete_stale(None, lambda _: [event, action], lambda n: n._info,
                          lambda n: deleted.append(n.get_path_name()))
        self.assertEqual(deleted, [])

    def test_delete_stale_removes_old_event_superseded_by_same_type(self):
        old_evt = _snap_event('path/OldEvt')
        old_act = _snap_action('path/OldAct')
        _snap_wire(old_evt, old_act)
        snap = self._make([old_evt, old_act])
        new_evt = _snap_event('path/NewEvt')
        new_act = _snap_action('path/NewAct')
        _snap_wire(new_evt, new_act)
        all_nodes = [old_evt, old_act, new_evt, new_act]
        deleted = []
        snap.delete_stale(None, lambda _: all_nodes, lambda n: n._info,
                          lambda n: deleted.append(n.get_path_name()))
        self.assertIn('path/OldEvt', deleted)
        self.assertIn('path/OldAct', deleted)
        self.assertNotIn('path/NewEvt', deleted)
        self.assertNotIn('path/NewAct', deleted)


if __name__ == '__main__':
    unittest.main()
