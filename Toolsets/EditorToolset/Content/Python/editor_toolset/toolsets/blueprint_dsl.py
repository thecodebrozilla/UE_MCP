# Copyright Epic Games, Inc. All Rights Reserved.

"""S-expression IDL for Blueprint graphs: transpile DSL text → nodes, decompile nodes → DSL text."""

import collections
import dataclasses
import re
import sys
from typing import Callable

# Blueprint graphs can have deep pure-node expression chains; ensure enough stack.
if sys.getrecursionlimit() < 5000:
    sys.setrecursionlimit(5000)

import unreal

from editor_toolset.toolsets.blueprint_node import NodeInfo, PinInfo, PinID

# ---------------------------------------------------------------------------
# Usage reference
# ---------------------------------------------------------------------------

USAGE = """\
GRAMMAR OVERVIEW

    (event EventName
      stmt ...)
    (event EventName (Param1 Param2 ...)
      stmt ...)

    (fn FunctionName (Param1 Param2 ...)
      stmt ...)

STATEMENTS

    bind          (bind var expr)
                  (bind (a b) (NodeType|Id args...))
    exec          (NodeType|Id args...)
    return        (return)  (return expr)  (return e1 e2)
    if            (if cond
                    stmt ...
                    [(elif cond stmt ...) | (else stmt ...)])
    elif          Must be the LAST form inside an (if) or (elif) body — it IS
                  the else branch, not a statement after it.
    for           (for i (range stop) stmt ...)
                  (for i (range start stop) stmt ...)
                  (for elem array-expr stmt ...)
    while         (while cond stmt ...)
    switch        (switch TypeId value (:Case stmt...) ...)
                  Short aliases: int  string  name  (see SWITCH ALIASES below)
    break         (break)

MULTI-EXEC (latent/task nodes with named exec outputs)

    (NodeType|Id args...
      (:ExecOut1
        stmt ...)
      (:ExecOut2
        stmt ...))

    Named exec continuations are sub-lists whose head starts with ":".
    They must appear after all data args and keyword args.
    The call terminates the enclosing exec flow (like if/branch).
    Pin names with spaces use the quoted form: (:"Pin Name" stmts...).

    DATA OUTPUTS inside continuations — a multi-exec node's data output pins are
    automatically available inside its continuation bodies as underscore-prefixed
    variables derived from the pin name (spaces → underscores, lowercased):

        "As Static Mesh Actor" → _as_static_mesh_actor
        "Return Value"         → _return_value

    Use get_node_type_pins() to discover the exact output pin names (and therefore
    the variable name) for any multi-exec node.

    EXPLICIT NAMING — to avoid relying on the auto-generated underscore name, wrap
    the node call in (bind var ...).  The name you choose is then directly available
    inside every continuation body.  It is not accessible outside the bind form.

    Preferred form for casts:
      (bind meshActor (Utilities|Casting|CastToStaticMeshActor :Object spawnedActor)
        (:then
          (bind comp (Class|StaticMeshActor|GetStaticMeshComponent :self meshActor))
          (Components|StaticMesh|SetStaticMesh :self comp :NewMesh "/Engine/BasicShapes/Cube.Cube"))
        (:CastFailed))

    DISAMBIGUATION — two uses of the ":" prefix:
      :PinName val       keyword DATA argument  (bare symbol followed by a value)
      (:PinName stmts…)  exec CONTINUATION      (sub-list whose head starts with ":")

    Example — Gameplay Ability Task:
      (Ability|Tasks|WaitDelay 2.0
        (:OnWait
          (Development|PrintString "waiting"))
        (:OnComplete
          (Development|PrintString "done")))

    Example — IsValid (pin names contain spaces):
      (Utilities|IsValid obj
        (:"Is Valid"
          (Development|PrintString "ok"))
        (:"Is Not Valid"
          (Development|PrintString "nil")))

EXPRESSIONS

    literal       1  3.14  "hello"  true  false
    variable      MyVar

    Any unquoted word that is not a number or boolean is treated as a
    variable reference.  Values that look like identifiers but are NOT
    variables — class paths, enum names, asset references — MUST be
    quoted or you will get an "Undefined variable" error:

        class path   "/Script/Engine.StaticMeshActor"   ← needs quotes
        enum value   "AlwaysSpawn"                       ← needs quotes
        asset ref    "/Game/Meshes/SM_Cube.SM_Cube"      ← needs quotes
    arithmetic    (+ a b)  (- a b)  (* a b)  (/ a b)  (% a b)
    comparison    (== a b)  (!= a b)  (< a b)  (<= a b)  (> a b)  (>= a b)
    boolean       (and a b)  (or a b)  (xor a b)  (not expr)  (neg expr)
    ternary       (select cond a b)    ; if cond then a else b
    vector        (.x v)  (.y v)  (.z v)
    rotator       (.pitch r)  (.yaw r)  (.roll r)
    transform     (.location t)  (.rotation t)  (.scale t)
    node call     (NodeType|Id pos-args... :PinName val ...)

NODE CALLS

    Type IDs are used verbatim:
        (Math|Float|sin(degrees) angle)
        (Development|PrintString "hello")
        (Development|PrintString :InString "hello" :Duration 5.0)

    Variables (Blueprint member variables):
        (Variables|Default|GetMyVar)
        (Variables|Default|SetMyVar value)

OPERATORS
    arithmetic:   +  -  *  /  %
    comparison:   ==  !=  <  <=  >  >=
    boolean:      and  or  xor  not
    unary minus:  (- expr)          negate a value; (neg expr) is a deprecated alias

COMPONENT ACCESS maps to Break* nodes:
    .x .y .z             → Math|Vector|BreakVector
    .pitch .yaw .roll    → Math|Rotator|BreakRotator
    .location .rotation .scale → Math|Transform|BreakTransform

SWITCH ALIASES
    Short names expand to the full Blueprint node type ID:
        int    → Utilities|FlowControl|SwitchOnInt
        string → Utilities|FlowControl|SwitchOnString
        name   → Utilities|FlowControl|SwitchOnName

    Example:
        (switch int (Variables|Default|GetDamageType)
          (:0 (Development|PrintString "fire"))
          (:1 (Development|PrintString "ice"))
          (:Default (Development|PrintString "other")))

    For enum switches use the full type ID: Utilities|FlowControl|SwitchOn<EnumName>

SELF REFERENCE
    Inside any event or fn body, the variable `self` is automatically bound
    to a Self Reference node (the owning Blueprint object).  Use it anywhere
    a node expects an Object pin:

        (Utilities|Time|SetTimerbyFunctionName
          :Object self
          :FunctionName "SpawnCube"
          :Time 3.0
          :bLooping true)

    If the event already exposes a parameter named `self` (rare), no extra
    Self Reference node is created and that parameter is used instead.

COMMENTS
    ; everything after a semicolon on a line is ignored

IMPORTANT — REUSE VALUES WITH BIND, NEVER REPEAT CALLS

    Every (NodeType|Id ...) call creates a new node in the graph and runs
    it again.  Repeating the same call to use its output in two places
    creates two nodes — doubling execution, and producing different values
    for impure functions (random, physics queries, GetActorLocation, etc.).

    WRONG — creates two GetActorLocation nodes, each executing separately:
        (if (> (.z (Transformation|GetActorLocation)) 0)
          (Development|PrintString (Math|Float|ToString
            (.z (Transformation|GetActorLocation)))))

    RIGHT — one node bound once, reused freely:
        (bind loc (Transformation|GetActorLocation))
        (if (> (.z loc) 0)
          (Development|PrintString (Math|Float|ToString (.z loc))))

    Rule: if a node's output is needed in more than one place, always bind it
    first and reference the variable.  Inline calls are only safe when the
    result is consumed exactly once.

EXAMPLES

    (event EventBeginPlay
      (bind loc (Transformation|GetActorLocation))
      (if (> (.z loc) 0)
        (for _ (range 5)
          (Development|PrintString "tick"))))

    (event OnHit
      (switch int (Variables|Default|GetDamageType)
        (:0
          (Development|PrintString "fire"))
        (:1
          (Development|PrintString "ice"))
        (:Default
          (Development|PrintString "other"))))

    (fn Clamp (Value Min Max)
      (if (< Value Min)
        (return Min)
        (elif (> Value Max)
          (return Max)
          (else
            (return Value)))))

    (fn DoubleIt (Value)
      (return (* Value 2)))

    (fn ClampedScale (Value Multiplier)
      (return (* (select (< Value 0.0) 0.0
                   (select (> Value 100.0) 100.0 Value))
                 Multiplier)))

    (fn OffsetTransform (T Offset)
      (return (Math|Transform|MakeTransform
                (+ (.location T) Offset)
                (.rotation T)
                (.scale T))))

    ; Class paths and enum values must be quoted strings (unquoted words are
    ; treated as variable references and will raise "Undefined variable").
    (fn SpawnCubeAbove ()
      (bind loc (Transformation|GetActorLocation))
      (bind spawnLoc (+ loc (Math|Vector|MakeVector :X 0.0 :Y 0.0 :Z 200.0)))
      (Game|SpawnActorfromClass
        :Class "/Script/Engine.StaticMeshActor"
        :SpawnTransform (Math|Transform|MakeTransform :Location spawnLoc)
        :CollisionHandlingOverride "AlwaysSpawn"))
"""


# ---------------------------------------------------------------------------
# S-expression parser
# ---------------------------------------------------------------------------

class Symbol(str):
    """An unquoted S-expression atom: variable name, type ID, operator, or :keyword."""


def _source_line(text: str, pos: int) -> tuple[int, str]:
    """Return the 1-based line number and line text containing character *pos*."""
    before = text[:pos]
    line_num = before.count('\n') + 1
    line_start = before.rfind('\n') + 1
    line_end = text.find('\n', pos)
    line_text = text[line_start:line_end if line_end != -1 else len(text)]
    return line_num, line_text


def _format_form(form) -> str:
    """Render a parsed form as a compact DSL string for error messages."""
    if isinstance(form, list):
        s = '(' + ' '.join(_format_form(x) for x in form) + ')'
    elif isinstance(form, bool):
        s = 'true' if form else 'false'
    elif isinstance(form, str) and not isinstance(form, Symbol):
        s = f'"{form}"'
    else:
        s = str(form)
    return s if len(s) <= 80 else s[:77] + '...'


def tokenize(text: str) -> list:
    """Split *text* into a flat list of atoms and paren Symbols."""
    tokens = []
    i = 0
    n = len(text)
    while i < n:
        c = text[i]
        if c == ';':
            while i < n and text[i] != '\n':
                i += 1
        elif c in '()':
            tokens.append(Symbol(c))
            i += 1
        elif c == '"':
            j = i + 1
            while j < n and text[j] != '"':
                if text[j] == '\\':
                    j += 1
                j += 1
            if j >= n:
                line_num, line_text = _source_line(text, i)
                raise RuntimeError(
                    f'Line {line_num}: unterminated string literal\n  {line_text}')
            tokens.append(text[i + 1:j].replace('\\"', '"').replace('\\\\', '\\'))
            i = j + 1
        elif c in ' \t\n\r':
            i += 1
        else:
            j = i
            while j < n:
                c2 = text[j]
                if c2 in ' \t\n\r;"':
                    break
                if c2 == ')':
                    break
                if c2 == '(':
                    # consume balanced (...) as part of this symbol, e.g. Equal(==), sin(degrees)
                    depth = 0
                    while j < n:
                        if text[j] == '(':
                            depth += 1
                        elif text[j] == ')':
                            depth -= 1
                            if depth == 0:
                                j += 1
                                break
                        j += 1
                    break
                j += 1
            atom = text[i:j]
            i = j
            # Quoted keyword: bare ':' immediately followed by a string literal,
            # e.g. :"Array Element" → Symbol(':Array Element').
            if atom == ':' and i < n and text[i] == '"':
                k = i + 1
                while k < n and text[k] != '"':
                    if text[k] == '\\':
                        k += 1
                    k += 1
                if k >= n:
                    line_num, line_text = _source_line(text, i)
                    raise RuntimeError(
                        f'Line {line_num}: unterminated string in quoted keyword\n  {line_text}')
                tokens.append(Symbol(':' + text[i + 1:k].replace('\\"', '"').replace('\\\\', '\\')))
                i = k + 1
                continue
            if atom.lower() == 'true':
                tokens.append(True)
            elif atom.lower() == 'false':
                tokens.append(False)
            else:
                try:
                    tokens.append(int(atom))
                except ValueError:
                    try:
                        tokens.append(float(atom))
                    except ValueError:
                        tokens.append(Symbol(atom))
    return tokens


def parse(text: str) -> list:
    """Parse *text* and return a list of top-level S-expression forms."""
    tokens = tokenize(text)
    pos = 0

    def read_form():
        nonlocal pos
        if pos >= len(tokens):
            raise RuntimeError('Unexpected end of input')
        tok = tokens[pos]
        if isinstance(tok, Symbol) and tok == ')':
            raise RuntimeError('Unexpected )')
        if isinstance(tok, Symbol) and tok == '(':
            pos += 1
            items = []
            while pos < len(tokens):
                if isinstance(tokens[pos], Symbol) and tokens[pos] == ')':
                    pos += 1
                    return items
                items.append(read_form())
            raise RuntimeError('Unclosed parenthesis')
        pos += 1
        return tok

    forms = []
    while pos < len(tokens):
        forms.append(read_form())
    return forms


# ---------------------------------------------------------------------------
# Literal formatting helpers
# ---------------------------------------------------------------------------

def _format_literal(val: bool | int | float | str) -> str:
    """Convert a parsed literal to the string Blueprint uses for pin default values."""
    if isinstance(val, bool):
        return 'true' if val else 'false'
    if isinstance(val, str) and not isinstance(val, Symbol):
        return val
    return str(val)


def _format_pin_default(value: str, type_id: str) -> str:
    """Format a pin's stored default value string as DSL source text."""
    type_lower = type_id.lower()
    if type_lower in ('bool', 'boolean'):
        return 'true' if value.lower() == 'true' else 'false'
    if any(type_lower.startswith(t) for t in ('string', 'text', 'name')):
        escaped = value.replace('"', '\\"')
        return f'"{escaped}"'
    if not value:
        return '0'
    try:
        int(value)
        return value
    except ValueError:
        pass
    try:
        float(value)
        return value
    except ValueError:
        pass
    escaped = value.replace('\\', '\\\\').replace('"', '\\"')
    return f'"{escaped}"'


def _format_pin_name(name: str) -> str:
    """Return a tokenizer-safe keyword name — quoted if it contains whitespace or special chars."""
    if any(c in name for c in ' \t\n\r;"()'):
        return '"' + name.replace('\\', '\\\\').replace('"', '\\"') + '"'
    return name


def _invert_expr(expr: str) -> str:
    """Invert a DSL boolean expression string: strips outer (not ...) or wraps in one."""
    if expr.startswith('(not ') and expr.endswith(')'):
        return expr[5:-1]
    return f'(not {expr})'


def _increment_expr(expr: str) -> str:
    """Convert inclusive Blueprint LastIndex to exclusive Python/DSL stop value."""
    try:
        return str(int(expr) + 1)
    except ValueError:
        return f'(+ {expr} 1)'


# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

EXEC_TYPE       = 'Exec'
_EVENT_PFX      = 'AddEvent|'
_BRANCH         = 'Utilities|FlowControl|Branch'
_FOR_LOOP       = 'Utilities|FlowControl|ForLoop'
_FOR_EACH_LOOP  = 'Utilities|FlowControl|ForEachLoop'
_FOR_EACH_LOOP_ARRAY = 'Utilities|Array|ForEachLoop'
_WHILE          = 'Utilities|FlowControl|WhileLoop'
_SELECT_NODE    = 'Utilities|Select'
_SEQUENCE       = 'Utilities|FlowControl|Sequence'
_MULTI_GATE     = 'Utilities|FlowControl|MultiGate'
_FOR_LOOP_BREAK = 'Utilities|FlowControl|ForLoopWithBreak'
_FOR_EACH_BREAK = 'Utilities|FlowControl|ForEachLoopWithBreak'
_FOR_EACH_ARRAY_BREAK = 'Utilities|Array|ForEachLoopWithBreak'
_SWITCH_PFX     = 'Utilities|FlowControl|Switch|'
_SWITCH_ALIASES: dict[str, str] = {
    'int':    'Utilities|FlowControl|Switch|SwitchonInt',
    'string': 'Utilities|FlowControl|Switch|SwitchonString',
    'name':   'Utilities|FlowControl|Switch|SwitchonName',
}
_RETURN_NODE    = '|ReturnNode'
_ADD_RETURN_NODE = '|AddReturnNode...'
_REROUTE_NODE   = '|RerouteNode'
_SELF_REF       = 'Variables|Getareferencetoself'
_SELF_REF_ALT   = 'Variables|Self-Reference'
_NOT_BOOLEAN    = 'Math|Boolean|NOTBoolean'
_STRING_APPEND  = 'Utilities|String|Append'

_PIN_THEN       = 'then'
_PIN_ELSE       = 'else'
_PIN_LOOP_BODY  = 'LoopBody'
_PIN_COMPLETED  = 'Completed'
_PIN_CONDITION  = 'Condition'
_PIN_FIRST_IDX  = 'FirstIndex'
_PIN_LAST_IDX   = 'LastIndex'
_PIN_INDEX      = 'Index'
_PIN_ARRAY      = 'Array'
_PIN_ARRAY_ELEM = 'Array Element'
_PIN_BREAK_IN   = 'Break'

# MakeLiteral nodes used to supply typed values to wildcard pins.
_WILDCARD_LITERAL_NODES: dict[type, str] = {
    bool:  'Math|Boolean|MakeLiteralBool',
    int:   'Math|Integer|MakeLiteralInt',
    float: 'Math|Float|MakeLiteralFloat',
    str:   'Utilities|String|MakeLiteralString',
}

_NODE_X_STRIDE   = 280
_EVENT_Y_STRIDE  = 600
_BRANCH_Y_OFFSET = 200

_BIN_OPS: dict[Symbol, str] = {
    Symbol('+'):   'Utilities|Operators|Add',
    Symbol('-'):   'Utilities|Operators|Subtract',
    Symbol('*'):   'Utilities|Operators|Multiply',
    Symbol('/'):   'Utilities|Operators|Divide',
    Symbol('%'):   'Utilities|Operators|Modulo',
    Symbol('xor'): 'Math|Boolean|XORBoolean',
    Symbol('=='):  'Utilities|Operators|Equal(==)',
    Symbol('!='):  'Utilities|Operators|NotEqual(!=)',
    Symbol('<'):   'Utilities|Operators|Less(<)',
    Symbol('<='):  'Utilities|Operators|LessEqual(<=)',
    Symbol('>'):   'Utilities|Operators|Greater(>)',
    Symbol('>='):  'Utilities|Operators|GreaterEqual(>=)',
    Symbol('and'): 'Math|Boolean|ANDBoolean',
    Symbol('or'):  'Math|Boolean|ORBoolean',
}

_TYPE_ID_TO_OP: dict[str, str] = {v: str(k) for k, v in _BIN_OPS.items()}

# Concrete promoted operator type IDs produced when wildcard pins resolve to a specific type.
_TYPE_ID_TO_OP.update({
    'Math|Integer|int+int':          '+',
    'Math|Integer|int-int':          '-',
    'Math|Integer|int*int':          '*',
    'Math|Integer|int/int':          '/',
    'Math|Integer|int%int':          '%',
    'Math|Integer|integer==integer': '==',
    'Math|Integer|integer!=integer': '!=',
    'Math|Integer|integer<integer':  '<',
    'Math|Integer|integer<=integer': '<=',
    'Math|Integer|integer>integer':  '>',
    'Math|Integer|integer>=integer': '>=',
    'Math|Float|float+float':        '+',
    'Math|Float|float-float':        '-',
    'Math|Float|float*float':        '*',
    'Math|Float|float/float':        '/',
    'Math|Float|float<float':        '<',
    'Math|Float|float<=float':       '<=',
    'Math|Float|float>float':        '>',
    'Math|Float|float>=float':       '>=',
    # Promoted wildcard operators resolved to concrete typed variants (Xxx(Type) style).
    'Math|Integer|Equal(Integer)':        '==',
    'Math|Integer|NotEqual(Integer)':     '!=',
    'Math|Integer|Less(Integer)':         '<',
    'Math|Integer|LessEqual(Integer)':    '<=',
    'Math|Integer|Greater(Integer)':      '>',
    'Math|Integer|GreaterEqual(Integer)': '>=',
    'Math|Float|Equal(Float)':            '==',
    'Math|Float|NotEqual(Float)':         '!=',
    'Math|Float|Less(Float)':             '<',
    'Math|Float|LessEqual(Float)':        '<=',
    'Math|Float|Greater(Float)':          '>',
    'Math|Float|GreaterEqual(Float)':     '>=',
})

_SUBTRACT_TYPE_IDS: frozenset[str] = frozenset(
    tid for tid, op in _TYPE_ID_TO_OP.items() if op == '-'
)
_MAKE_LITERAL_COLLAPSED: frozenset[str] = frozenset(_WILDCARD_LITERAL_NODES.values())

_COMPONENT_ACCESS: dict[str, tuple[str, str]] = {
    'x':        ('Math|Vector|BreakVector',       'X'),
    'y':        ('Math|Vector|BreakVector',       'Y'),
    'z':        ('Math|Vector|BreakVector',       'Z'),
    'pitch':    ('Math|Rotator|BreakRotator',     'Pitch'),
    'yaw':      ('Math|Rotator|BreakRotator',     'Yaw'),
    'roll':     ('Math|Rotator|BreakRotator',     'Roll'),
    'location': ('Math|Transform|BreakTransform', 'Location'),
    'rotation': ('Math|Transform|BreakTransform', 'Rotation'),
    'scale':    ('Math|Transform|BreakTransform', 'Scale'),
}
_COMP_REV: dict[tuple[str, str], str] = {
    (tid, pin): attr for attr, (tid, pin) in _COMPONENT_ACCESS.items()
}

_RESERVED = frozenset({
    Symbol('event'), Symbol('fn'), Symbol('bind'), Symbol('return'),
    Symbol('if'), Symbol('elif'), Symbol('else'), Symbol('for'), Symbol('range'),
    Symbol('while'), Symbol('break'), Symbol('switch'),
    Symbol('select'), Symbol('not'), Symbol('neg'),
    *_BIN_OPS.keys(),
})


# ---------------------------------------------------------------------------
# Pin helpers
# ---------------------------------------------------------------------------

def _data_ins(ni: NodeInfo) -> list[PinInfo]:
    """Return the non-exec input pins of *ni*."""
    return [p for p in ni.input_pins if p.type_id != EXEC_TYPE]


def _strip_implicit_self(ins: list[PinInfo]) -> list[PinInfo]:
    """Remove the leading 'self' pin when it is unconnected and empty.

    Blueprint function-call nodes expose an implicit self/target pin as their
    first data input. When the call is on the owner object (the default), this
    pin has no connection and an empty value. Emitting it would produce a
    spurious '0' arg in the DSL, which breaks round-trips.
    """
    if ins and ins[0].name.lower() == 'self' and not ins[0].connected_pins and ins[0].value == '':
        return ins[1:]
    return ins


def _data_outs(ni: NodeInfo) -> list[PinInfo]:
    """Return the non-exec, non-delegate output pins of *ni*."""
    return [p for p in ni.output_pins if p.type_id != EXEC_TYPE and p.name != 'OutputDelegate']


def _uses_symbol(forms: list, name: str) -> bool:
    """Return True if Symbol *name* appears anywhere in the parsed form tree."""
    for item in forms:
        if isinstance(item, Symbol) and str(item) == name:
            return True
        if isinstance(item, list) and _uses_symbol(item, name):
            return True
    return False


def _follow_reroutes(src_node, src_ni, src_pid, get_node_info_fn, *,
                     raise_on_cycle: bool = True):
    """Follow reroute (knot) node chains from (src_node, src_ni, src_pid).

    Returns (node, ni, pid, halted) where halted=True means traversal stopped at a
    dead-end reroute (no connected input). Raises RuntimeError on cycle when
    raise_on_cycle=True; returns (node, ni, pid, True) when raise_on_cycle=False.
    """
    visited: set[str] = set()
    while src_ni.type_id == _REROUTE_NODE:
        path = src_node.get_path_name()
        if path in visited:
            if raise_on_cycle:
                raise RuntimeError(
                    'Cycle detected in reroute (knot) nodes — graph is malformed.')
            return src_node, src_ni, src_pid, True
        visited.add(path)
        ins = _data_ins(src_ni)
        if not ins or not ins[0].connected_pins:
            return src_node, src_ni, src_pid, True
        src_pid = ins[0].connected_pins[0]
        src_node = src_pid.node
        src_ni = get_node_info_fn(src_node)
    return src_node, src_ni, src_pid, False


def _sanitize_pin_name(name: str, default: str = 'tmp') -> str:
    """Normalize a pin name to a lowercase identifier safe for use as a DSL variable."""
    return re.sub(r'[^A-Za-z0-9]', '_', name).strip('_').lower() or default


def _select_pins(ins: list[PinInfo]) -> tuple[PinInfo | None, list[PinInfo]]:
    """Return (condition_pin, value_pins) from a Select node's data input pins."""
    cond_pin = next(
        (p for p in ins
         if p.name.lower() in ('condition', 'bpicka', 'option', 'index')), None)
    return cond_pin, [p for p in ins if p is not cond_pin]


def _contains_break(forms: list) -> bool:
    """Return True if *forms* contains a (break) at any depth, not crossing loop boundaries."""
    for item in forms:
        if not isinstance(item, list) or not item:
            continue
        head = item[0]
        if isinstance(head, Symbol) and head == Symbol('break'):
            return True
        if isinstance(head, Symbol) and head in (Symbol('for'), Symbol('while')):
            continue
        if _contains_break(item):
            return True
    return False


def _merge_branch_exec(then_ctx, then_out, else_ctx) -> list:
    """Collect post-branch pending exec pins from both sides of a Branch node."""
    pending = list(then_ctx.pending_exec if then_ctx else ([then_out] if then_out else []))
    pending += list(else_ctx.pending_exec)
    return pending


def _clean_error(msg: str) -> str:
    """Strip Python traceback boilerplate from a ufunction-wrapped exception message.

    When a @tool_call callback raises inside tool_raising_exceptions(), ufunction
    formats the exception as a full Python traceback string.  Extract just the
    final exception line(s) so DSL errors stay readable.
    """
    if '\n  File "' not in msg:
        return msg
    lines = msg.splitlines()
    for i in range(len(lines) - 1, 0, -1):
        if lines[i] and not lines[i].startswith(' '):
            return '\n'.join(lines[i:])
    return msg


# ---------------------------------------------------------------------------
# Transpiler
# ---------------------------------------------------------------------------

@dataclasses.dataclass
class _StablePinRef:
    """A pin reference that survives Blueprint recompiles."""
    node_path: str
    index_id: int
    is_input: bool


@dataclasses.dataclass
class _ExecConnection:
    """Captures one exec output pin and the pins it was connected to, for rollback."""
    src_node_path: str
    src_pin_name: str
    targets: list[_StablePinRef]


class _GraphSnapshot:
    def __init__(self, graph: unreal.EdGraph, get_nodes_fn: Callable, get_node_info_fn: Callable) -> None:
        self.pre_existing_paths: set[str] = set()
        self.exec_connections: list[_ExecConnection] = []
        for node in get_nodes_fn(graph):
            path = node.get_path_name()
            self.pre_existing_paths.add(path)
            ni = get_node_info_fn(node)
            for pin in ni.output_pins:
                if pin.type_id == EXEC_TYPE and pin.connected_pins:
                    self.exec_connections.append(_ExecConnection(
                        src_node_path=path,
                        src_pin_name=pin.name,
                        targets=[
                            _StablePinRef(c.node.get_path_name(), c.index_id, True)
                            for c in pin.connected_pins
                        ],
                    ))

    def rollback(self, graph: unreal.EdGraph, get_nodes_fn: Callable, get_node_info_fn: Callable,
                 delete_node_fn: Callable, connect_pins_fn: Callable) -> None:
        for node in get_nodes_fn(graph):
            if node.get_path_name() not in self.pre_existing_paths:
                delete_node_fn(node)
        path_to_node = {n.get_path_name(): n for n in get_nodes_fn(graph)}
        for conn in self.exec_connections:
            src_node = path_to_node.get(conn.src_node_path)
            if not src_node:
                continue
            src_ni = get_node_info_fn(src_node)
            src_pin = next((p for p in src_ni.output_pins if p.name == conn.src_pin_name), None)
            if not src_pin:
                continue
            for target in conn.targets:
                tgt_node = path_to_node.get(target.node_path)
                if not tgt_node:
                    continue
                tgt_ni = get_node_info_fn(tgt_node)
                tgt_pins = tgt_ni.input_pins if target.is_input else tgt_ni.output_pins
                tgt_pin = next((p.pin_id for p in tgt_pins if p.pin_id.index_id == target.index_id), None)
                if tgt_pin:
                    connect_pins_fn(src_pin.pin_id, tgt_pin)

    def delete_stale(self, graph: unreal.EdGraph, get_nodes_fn: Callable, get_node_info_fn: Callable,
                     delete_node_fn: Callable) -> None:
        """Delete pre-existing nodes that are no longer reachable from any exec root.

        Algorithm: BFS from every exec-root node (nodes with exec outputs but no exec inputs),
        marking all reachable nodes as live. Pre-existing nodes not visited are stale and removed.
        The new_root_type_ids filter excludes old entry nodes whose type was just re-created by
        this transpile call — we never want to delete the node we just populated.
        """
        type_id_by_path: dict[str, str] = {}
        is_root_by_path: dict[str, bool] = {}
        neighbors_by_path: dict[str, list[str]] = {}
        for node in get_nodes_fn(graph):
            path = node.get_path_name()
            ni = get_node_info_fn(node)
            type_id_by_path[path] = ni.type_id
            is_root_by_path[path] = (
                any(p.type_id == EXEC_TYPE for p in ni.output_pins)
                and not any(p.type_id == EXEC_TYPE for p in ni.input_pins)
            )
            neighbors_by_path[path] = [
                c.node.get_path_name()
                for pin in list(ni.input_pins) + list(ni.output_pins)
                for c in pin.connected_pins
            ]

        new_root_type_ids = {
            type_id_by_path[p]
            for p, is_root in is_root_by_path.items()
            if is_root and p not in self.pre_existing_paths
        }

        root_paths = [
            p for p, is_root in is_root_by_path.items()
            if is_root and not (p in self.pre_existing_paths and type_id_by_path[p] in new_root_type_ids)
        ]

        visited: set[str] = set()
        queue = list(root_paths)
        while queue:
            path = queue.pop()
            if path in visited:
                continue
            visited.add(path)
            queue.extend(neighbors_by_path[path])

        stale_paths = {
            p for p in self.pre_existing_paths
            if p not in visited and p in type_id_by_path
        }

        for node in get_nodes_fn(graph):
            if node.get_path_name() in stale_paths:
                delete_node_fn(node)


@dataclasses.dataclass
class _TranspileCtx:
    """Per-transpile-call state threaded through process methods."""
    x: int
    y: int
    # Exec output pins to wire at the next statement; replaced (not mutated) after each stmt.
    pending_exec: list
    break_pin: 'PinID | None'


class Transpiler:
    """Converts S-expression DSL text into Blueprint graph nodes."""

    def __init__(
            self,
            graph: unreal.EdGraph,
            create_node_fn: Callable,
            connect_pins_fn: Callable,
            get_node_info_fn: Callable,
            set_pin_value_fn: Callable,
            get_nodes_fn: Callable,
            *,
            delete_node_fn: Callable | None = None,
            find_node_types_fn: Callable | None = None) -> None:
        """Initialize with graph callbacks."""
        self.graph              = graph
        self._create_node       = create_node_fn
        self._connect_pins      = connect_pins_fn
        self._get_node_info     = get_node_info_fn
        self._set_pin_value     = set_pin_value_fn
        self._get_nodes         = get_nodes_fn
        self._delete_node       = delete_node_fn
        self._find_node_types   = find_node_types_fn

    # ------------------------------------------------------------------
    # Node ops
    # ------------------------------------------------------------------

    def _create(self, type_id: str, ctx: _TranspileCtx) -> unreal.EdGraphNode:
        """Create a node of *type_id* at the current position and advance the cursor."""
        pos = unreal.IntPoint(ctx.x, ctx.y)
        ctx.x += _NODE_X_STRIDE
        return self._create_node(self.graph, type_id, pos)

    def _connect(self, out_pin: PinID, in_pin: PinID) -> None:
        self._connect_pins(out_pin, in_pin)

    def _set_value(self, pin_id: PinID, value: str) -> None:
        self._set_pin_value(pin_id, value)

    def _make_literal(self, value: bool | int | float | str, ctx: _TranspileCtx) -> PinID:
        """Create a typed MakeLiteral* node for *value* and return its output PinID.

        Used when a literal must be wired to a Wildcard pin, which cannot accept
        a default value until its type is resolved by a connected wire.
        """
        node_type = _WILDCARD_LITERAL_NODES[type(value)]
        node = self._create(node_type, ctx)
        ni = self._get_node_info(node)
        data_ins = [p for p in ni.input_pins if p.type_id != EXEC_TYPE]
        if data_ins:
            formatted = _format_literal(value) if isinstance(value, (bool, int, float)) else value
            self._set_value(data_ins[0].pin_id, formatted)
        outs = _data_outs(ni)
        assert outs, f'MakeLiteral node {node_type} has no data output pin'
        return outs[0].pin_id

    # ------------------------------------------------------------------
    # Pin helpers
    # ------------------------------------------------------------------

    @staticmethod
    def _exec_out(ni: NodeInfo, name: str) -> PinID | None:
        """Return the PinID of the named exec output pin, or None if absent."""
        pin = next((p for p in ni.output_pins if p.type_id == EXEC_TYPE and p.name == name), None)
        return pin.pin_id if pin else None

    def _wire_exec(self, ni: NodeInfo, ctx: _TranspileCtx) -> bool:
        """Connect all pending exec outputs to *ni*'s exec input; return True on success."""
        exec_in = next((p for p in ni.input_pins if p.type_id == EXEC_TYPE), None)
        if exec_in and ctx.pending_exec:
            for exec_pin in ctx.pending_exec:
                self._connect(exec_pin, exec_in.pin_id)
            return True
        return False

    def _wire_with_pre(self, expr: object, pin: PinInfo, pre_out: 'PinID | None',
                       bindings: dict[str, PinID], ctx: _TranspileCtx) -> None:
        """Wire *expr* to *pin*, using already-evaluated *pre_out* when *expr* is a list.

        Call _eval_expr on list args *before* creating the parent node so sub-nodes
        land at smaller X coordinates; pass the result here as *pre_out*.
        """
        if isinstance(expr, list):
            if pre_out is not None:
                self._connect(pre_out, pin.pin_id)
        else:
            self._wire_arg(expr, pin, bindings, ctx)

    def _wire_condition(self, ni: NodeInfo, cond: object, bindings: dict[str, PinID], *,
                        pre_out: 'PinID | None' = None) -> None:
        """Wire *cond* to the Condition input pin of *ni*; use *pre_out* if already evaluated."""
        cond_pin = next((p for p in ni.input_pins if p.name == _PIN_CONDITION), None)
        if cond_pin is None:
            return
        if pre_out is not None:
            self._connect(pre_out, cond_pin.pin_id)
        elif not isinstance(cond, (list, Symbol)):
            self._set_value(cond_pin.pin_id, _format_literal(cond))
        elif isinstance(cond, Symbol):
            src = bindings.get(str(cond))
            if src is not None:
                self._connect(src, cond_pin.pin_id)
        # list with pre_out=None means _eval_expr returned None (no output) — nothing to wire

    # ------------------------------------------------------------------
    # Graph lookup
    # ------------------------------------------------------------------

    def _find_entry_node(self, name: str) -> unreal.EdGraphNode | None:
        """Return the existing event or function entry node for *name*, or None."""
        name_lower = name.lower()
        for node in self._get_nodes(self.graph):
            ni = self._get_node_info(node)
            if ni.type_id.startswith(_EVENT_PFX):
                if ni.type_id[len(_EVENT_PFX):].lower() == name_lower:
                    return node
            elif ni.type_id.lower() == f'|{name_lower}':
                return node
        return None

    def _find_return_node(self) -> unreal.EdGraphNode | None:
        """Return the ReturnNode in the graph, or None if no return node exists."""
        for node in self._get_nodes(self.graph):
            if self._get_node_info(node).type_id == _RETURN_NODE:
                return node
        return None

    # ------------------------------------------------------------------
    # Argument wiring
    # ------------------------------------------------------------------

    def _wire_arg(self, src: object, pin: PinInfo, bindings: dict[str, PinID],
                  ctx: _TranspileCtx) -> None:
        """Wire *src* — a literal, Symbol variable, or list expression — to *pin*."""
        if isinstance(src, (bool, int, float)):
            if pin.type_id == 'Wildcard':
                self._connect(self._make_literal(src, ctx), pin.pin_id)
            else:
                self._set_value(pin.pin_id, _format_literal(src))
        elif isinstance(src, str) and not isinstance(src, Symbol):
            if pin.type_id == 'Wildcard':
                self._connect(self._make_literal(src, ctx), pin.pin_id)
            else:
                self._set_value(pin.pin_id, src)
        elif isinstance(src, Symbol):
            pin_id = bindings.get(str(src))
            if pin_id is None:
                s = str(src)
                if s.startswith('/'):
                    raise RuntimeError(
                        f'"{s}" looks like a class path or asset reference and must be '
                        f'a quoted string: \\"{s}\\"')
                available = [k for k in bindings if not str(k).startswith('_')]
                raise RuntimeError(
                    f'Undefined variable "{src}". '
                    f'Available: {available or list(bindings)}')
            self._connect(pin_id, pin.pin_id)
        else:
            out = self._eval_expr(src, bindings, ctx)
            if out is not None:
                self._connect(out, pin.pin_id)

    # ------------------------------------------------------------------
    # Call node creation
    # ------------------------------------------------------------------

    def _create_call_node(self, form: list, bindings: dict[str, PinID],
                          ctx: _TranspileCtx, bind_name: str | None = None) -> NodeInfo:
        """Create, exec-wire, and arg-wire a node for *form*; return its NodeInfo."""
        type_id = str(form[0])
        pos_args = []
        kw_args = []
        seen_kw: set[str] = set()
        exec_conts: list[tuple[str, list]] = []  # (pin_name, stmts)
        i = 1
        while i < len(form):
            arg = form[i]
            # Exec continuation: (:PinName stmts...)
            if (isinstance(arg, list) and arg
                    and isinstance(arg[0], Symbol) and arg[0].startswith(':')):
                exec_conts.append((str(arg[0])[1:], arg[1:]))
                i += 1
            # Keyword data arg: :PinName value
            elif isinstance(arg, Symbol) and arg.startswith(':'):
                pin_name = str(arg)[1:]
                if i + 1 >= len(form):
                    raise RuntimeError(f'Keyword :{pin_name} has no value in ({type_id} ...)')
                if pin_name in seen_kw:
                    raise RuntimeError(
                        f'Duplicate keyword argument :{pin_name} in ({type_id} ...)')
                seen_kw.add(pin_name)
                kw_args.append((pin_name, form[i + 1]))
                i += 2
            else:
                if kw_args or exec_conts:
                    raise RuntimeError(
                        f'Positional arg after keyword arg or exec continuation in ({type_id} ...)')
                pos_args.append(arg)
                i += 1

        # Pre-evaluate list expressions so their nodes land to the left of the call node.
        pre_pos = [self._eval_expr(a, bindings, ctx) if isinstance(a, list) else None
                   for a in pos_args]
        pre_kw = {name: (self._eval_expr(v, bindings, ctx) if isinstance(v, list) else None)
                  for name, v in kw_args}

        node = self._create(type_id, ctx)
        ni = self._get_node_info(node)

        wired = self._wire_exec(ni, ctx)
        if exec_conts:
            ctx.pending_exec = []  # multi-exec terminates the enclosing exec flow
        elif wired:
            then_pin = self._exec_out(ni, _PIN_THEN)
            ctx.pending_exec = [then_pin] if then_pin is not None else []

        ins = _data_ins(ni)
        if len(pos_args) > len(ins):
            raise RuntimeError(
                f'{type_id} received {len(pos_args)} positional arg(s) but has '
                f'{len(ins)} data input pin(s). Available: {[p.name for p in ins]}')
        for arg, pin, pre_out in zip(pos_args, ins, pre_pos):
            self._wire_with_pre(arg, pin, pre_out, bindings, ctx)

        if kw_args:
            pin_by_name = {p.name: p for p in ins}
            for pin_name, val in kw_args:
                pin = pin_by_name.get(pin_name)
                if pin is None:
                    out_names = [p.name for p in _data_outs(ni)]
                    raise RuntimeError(
                        f'Unknown input pin "{pin_name}" on {type_id}. '
                        f'Input pins: {list(pin_by_name)}. '
                        f'Output pins: {out_names} (use positional bind to capture outputs)')
                self._wire_with_pre(val, pin, pre_kw[pin_name], bindings, ctx)

        if exec_conts:
            # Inject the node's data outputs into cont_bindings so continuation
            # bodies can reference the result (e.g. the casted object from Cast).
            # Names are the pin name sanitized to _snake_case, e.g.
            # "As Static Mesh Actor" → _as_static_mesh_actor.
            cont_bindings = dict(bindings)
            for pin in _data_outs(ni):
                sanitized = _sanitize_pin_name(pin.name, 'out')
                cont_bindings.setdefault(f'_{sanitized}', pin.pin_id)
            if bind_name is not None:
                outs = _data_outs(ni)
                if outs:
                    cont_bindings[bind_name] = outs[0].pin_id
            for pin_name, stmts in exec_conts:
                exec_pin_id = self._exec_out(ni, pin_name)
                if exec_pin_id is None:
                    available = [p.name for p in ni.output_pins if p.type_id == EXEC_TYPE]
                    raise RuntimeError(
                        f'Unknown exec output "{pin_name}" on {type_id}. '
                        f'Available: {available}')
                if stmts:
                    cont_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                             pending_exec=[exec_pin_id], break_pin=ctx.break_pin)
                    self._process_stmts(stmts, cont_bindings, cont_ctx)

        return ni

    # ------------------------------------------------------------------
    # Expression evaluation
    # ------------------------------------------------------------------

    def _eval_expr(self, expr: object, bindings: dict[str, PinID],
                   ctx: _TranspileCtx) -> PinID | None:
        """Evaluate *expr* and return the output PinID that holds its value (or None)."""
        if isinstance(expr, bool):
            return None
        if isinstance(expr, (int, float)):
            return None
        if isinstance(expr, str) and not isinstance(expr, Symbol):
            return None
        if isinstance(expr, Symbol):
            pin_id = bindings.get(str(expr))
            if pin_id is None:
                user_vars = [k for k in bindings if not str(k).startswith('_')]
                cont_vars = [k for k in bindings if str(k).startswith('_')]
                msg = f'Undefined variable "{expr}". Available: {user_vars or list(bindings)}'
                if cont_vars:
                    msg += f'. Continuation outputs in scope: {cont_vars}'
                raise RuntimeError(msg)
            return pin_id
        if isinstance(expr, list):
            if not expr:
                raise RuntimeError('Empty expression ()')
            head = expr[0]
            if isinstance(head, Symbol) and str(head).startswith('.'):
                return self._eval_component_access(expr, bindings, ctx)
            if head == Symbol('select'):
                return self._eval_select(expr, bindings, ctx)
            if head == Symbol('not'):
                return self._eval_not(expr, bindings, ctx)
            if head == Symbol('neg'):
                return self._eval_neg(expr, bindings, ctx)
            if head in _BIN_OPS:
                return self._eval_binop(expr, bindings, ctx)
            return self._eval_node_call(expr, bindings, ctx)
        raise RuntimeError(f'Unsupported expression: {expr!r}')

    def _eval_node_call(self, form: list, bindings: dict[str, PinID],
                        ctx: _TranspileCtx) -> PinID | None:
        """Create a call node from *form* and return the first data output PinID."""
        ni = self._create_call_node(form, bindings, ctx)
        outs = _data_outs(ni)
        return outs[0].pin_id if outs else None

    def _eval_binop(self, form: list, bindings: dict[str, PinID],
                    ctx: _TranspileCtx) -> PinID | None:
        """Create a binary operator node from *form* and return its output PinID."""
        op = str(form[0])
        if op == '-' and len(form) == 2:
            return self._eval_neg(form, bindings, ctx)
        if len(form) != 3:
            raise RuntimeError(f'({op} ...) requires exactly 2 arguments, got {len(form) - 1}')
        type_id = _BIN_OPS[form[0]]
        # Promote + to string append when either immediate arg is a string literal, because
        # Blueprint's promotable Add node only resolves to numeric types.
        if form[0] == Symbol('+') and any(
            isinstance(a, str) and not isinstance(a, Symbol) for a in form[1:]
        ):
            type_id = _STRING_APPEND
        pre1 = self._eval_expr(form[1], bindings, ctx) if isinstance(form[1], list) else None
        pre2 = self._eval_expr(form[2], bindings, ctx) if isinstance(form[2], list) else None
        node = self._create(type_id, ctx)
        ni = self._get_node_info(node)
        ins = _data_ins(ni)
        if ins:
            self._wire_with_pre(form[1], ins[0], pre1, bindings, ctx)
        if len(ins) > 1:
            self._wire_with_pre(form[2], ins[1], pre2, bindings, ctx)
        outs = _data_outs(ni)
        return outs[0].pin_id if outs else None

    def _eval_component_access(self, form: list, bindings: dict[str, PinID],
                               ctx: _TranspileCtx) -> PinID | None:
        """Create a Break* node for a (.attr obj) expression and return the named output PinID."""
        attr = str(form[0])[1:]
        entry = _COMPONENT_ACCESS.get(attr)
        if entry is None:
            raise RuntimeError(
                f'Unsupported component ".{attr}". '
                f'Supported: {list(_COMPONENT_ACCESS)}')
        type_id, pin_name = entry
        src = self._eval_expr(form[1], bindings, ctx) if len(form) > 1 else None
        node = self._create(type_id, ctx)
        ni = self._get_node_info(node)
        if src is not None:
            ins = _data_ins(ni)
            if ins:
                self._connect(src, ins[0].pin_id)
        out = next((p for p in ni.output_pins if p.name == pin_name), None)
        return out.pin_id if out else None

    def _eval_select(self, form: list, bindings: dict[str, PinID],
                     ctx: _TranspileCtx) -> PinID | None:
        """Create a Select node from a (select cond a b) expression and return its output PinID."""
        if len(form) != 4:
            raise RuntimeError(f'(select ...) requires exactly 3 arguments (cond a b), got {len(form) - 1}')
        pre_args = [self._eval_expr(a, bindings, ctx) if isinstance(a, list) else None
                    for a in form[1:]]
        node = self._create(_SELECT_NODE, ctx)
        ni = self._get_node_info(node)
        ins = _data_ins(ni)
        cond_pin, value_pins = _select_pins(ins)
        if cond_pin and len(form) > 1:
            self._wire_with_pre(form[1], cond_pin, pre_args[0], bindings, ctx)
        # (select cond a b) means "if cond then a else b".
        # The Select node picks Option 0 when Index=false and Option 1 when Index=true,
        # so wire a -> Option 1 and b -> Option 0.
        reversed_value_pins = list(reversed(value_pins))
        for i, pin in enumerate(reversed_value_pins):
            if i + 2 < len(form):
                pre_out = pre_args[i + 1] if i + 1 < len(pre_args) else None
                self._wire_with_pre(form[i + 2], pin, pre_out, bindings, ctx)
        outs = _data_outs(ni)
        return outs[0].pin_id if outs else None

    def _eval_not(self, form: list, bindings: dict[str, PinID],
                  ctx: _TranspileCtx) -> PinID | None:
        """Create a NOTBoolean node from a (not expr) expression and return its output PinID."""
        if len(form) != 2:
            raise RuntimeError(f'(not ...) requires exactly 1 argument, got {len(form) - 1}')
        pre = self._eval_expr(form[1], bindings, ctx) if isinstance(form[1], list) else None
        node = self._create(_NOT_BOOLEAN, ctx)
        ni = self._get_node_info(node)
        ins = _data_ins(ni)
        if ins:
            self._wire_with_pre(form[1], ins[0], pre, bindings, ctx)
        outs = _data_outs(ni)
        return outs[0].pin_id if outs else None

    def _eval_neg(self, form: list, bindings: dict[str, PinID],
                  ctx: _TranspileCtx) -> PinID | None:
        """Implement unary negation (0 - expr) for both (- expr) and the (neg expr) alias."""
        if len(form) != 2:
            raise RuntimeError(
                f'({form[0]} ...) requires exactly 1 argument, got {len(form) - 1}. '
                f'For unary minus write (- expr); for binary subtraction write (- a b).')
        type_id = _BIN_OPS[Symbol('-')]
        pre = self._eval_expr(form[1], bindings, ctx) if isinstance(form[1], list) else None
        node = self._create(type_id, ctx)
        ni = self._get_node_info(node)
        ins = _data_ins(ni)
        # Wire B first so the wildcard pin resolves its type, then set A to 0.
        if len(ins) > 1:
            self._wire_with_pre(form[1], ins[1], pre, bindings, ctx)
        if ins:
            self._set_value(ins[0].pin_id, '0')
        outs = _data_outs(ni)
        return outs[0].pin_id if outs else None

    # ------------------------------------------------------------------
    # Statement processing
    # ------------------------------------------------------------------

    def _process_stmts(self, stmts: list, bindings: dict[str, PinID],
                       ctx: _TranspileCtx) -> None:
        """Execute each statement in *stmts*, threading exec flow and updating *bindings*."""
        for i, stmt in enumerate(stmts):
            if not isinstance(stmt, list):
                raise RuntimeError(f'Statement must be a list, got: {stmt!r}')
            exec_before = ctx.pending_exec
            head = stmt[0]
            try:
                if head == Symbol('bind'):
                    self._process_bind(stmt, bindings, ctx)
                elif head == Symbol('return'):
                    self._process_return(stmt, bindings, ctx)
                elif head == Symbol('if'):
                    self._process_if(stmt, bindings, ctx)
                elif head == Symbol('for'):
                    self._process_for(stmt, bindings, ctx)
                elif head == Symbol('while'):
                    self._process_while(stmt, bindings, ctx)
                elif head == Symbol('break'):
                    if ctx.break_pin is None:
                        raise RuntimeError('(break) used outside a breakable loop')
                    for pin in ctx.pending_exec:
                        self._connect(pin, ctx.break_pin)
                    ctx.pending_exec = []
                elif head == Symbol('switch'):
                    self._process_switch(stmt, bindings, ctx)
                elif head in (Symbol('elif'), Symbol('else')):
                    raise RuntimeError(
                        f'({head}) must be the last form inside an (if) or (elif) body — '
                        f'it is the else branch, not a statement after it')
                else:
                    self._eval_node_call(stmt, bindings, ctx)
            except RuntimeError as exc:
                msg = _clean_error(str(exc))
                if '\n  in: ' not in msg:
                    raise RuntimeError(f'{msg}\n  in: {_format_form(stmt)}') from None
                raise

            if exec_before and not ctx.pending_exec:
                remaining = stmts[i + 1:]
                if remaining:
                    raise RuntimeError(
                        f'Unreachable code after branch/return: {remaining[0]!r}')
                break

    def _process_bind(self, form: list, bindings: dict[str, PinID],
                      ctx: _TranspileCtx) -> None:
        """Evaluate a (bind target expr) form and store the output PinID in *bindings*."""
        if len(form) < 3:
            raise RuntimeError(f'(bind) requires a target and an expression')
        target = form[1]
        val_expr = form[2]

        # (bind name expr (:Pin stmts...) ...) — exec continuations on the expression.
        # 'name' is available inside the continuation bodies but not in the outer scope.
        extra = form[3:]
        if extra:
            non_cont = [f for f in extra if not (
                isinstance(f, list) and f
                and isinstance(f[0], Symbol) and f[0].startswith(':')
            )]
            if non_cont:
                raise RuntimeError(
                    f'(bind) expects only exec continuations after the expression, '
                    f'got: {[_format_form(f) for f in non_cont]}')
            if isinstance(target, list):
                raise RuntimeError(
                    '(bind (a b) ...) with exec continuations is not supported. '
                    'Use a single name target.')
            name = str(target)
            if not isinstance(val_expr, list):
                raise RuntimeError(
                    f'(bind {name} ...) with exec continuations requires a node call, '
                    f'got: {val_expr!r}')
            combined_form = list(val_expr) + extra
            self._create_call_node(combined_form, bindings, ctx, bind_name=name)
            return

        if isinstance(target, list):
            if not isinstance(val_expr, list):
                raise RuntimeError(
                    f'Multi-output bind requires a node call, got: {val_expr!r}')
            already = [str(lhs) for lhs in target if str(lhs) in bindings]
            if already:
                raise RuntimeError(
                    f'(bind) cannot rebind already-bound name(s): {already}. '
                    f'Bindings are immutable aliases — use a different variable name.')
            ni = self._create_call_node(val_expr, bindings, ctx)
            outs = _data_outs(ni)
            if len(target) > len(outs):
                raise RuntimeError(
                    f'Multi-output bind has {len(target)} target(s) but node has '
                    f'{len(outs)} data output pin(s). Available: {[p.name for p in outs]}')
            for lhs, pin in zip(target, outs):
                bindings[str(lhs)] = pin.pin_id
        else:
            name = str(target)
            if name in bindings:
                raise RuntimeError(
                    f"(bind) cannot rebind '{name}' — it is already bound. "
                    f'Bindings are immutable aliases. Use a different variable name, '
                    f'or use Blueprint local variables for mutable state.')
            out = self._eval_expr(val_expr, bindings, ctx)
            if out is None:
                raise RuntimeError(
                    f'(bind {name} ...) expression produced no output pin. '
                    f'Use a node call expression, not a literal.')
            bindings[name] = out

    def _process_return(self, form: list, bindings: dict[str, PinID],
                        ctx: _TranspileCtx) -> None:
        """Wire a (return ...) form to a new result node and sever exec flow.

        Each (return ...) creates its own K2Node_FunctionResult so branching
        functions (if/elif/else) wire independent data values per return path.
        In EventGraphs and other non-returning graphs, (return) acts as a
        no-op exec terminator.
        """
        if self._find_return_node() is None:
            # EventGraph and other non-returning graphs have no return node.
            ctx.pending_exec = []
            return
        ret_node = self._create(_ADD_RETURN_NODE, ctx)
        ni = self._get_node_info(ret_node)
        self._wire_exec(ni, ctx)
        ctx.pending_exec = []
        ins = _data_ins(ni)
        return_vals = form[1:]
        if len(return_vals) > len(ins):
            raise RuntimeError(
                f'(return) has {len(return_vals)} value(s) but function has '
                f'{len(ins)} return pin(s). Available: {[p.name for p in ins]}')
        for val, pin in zip(return_vals, ins):
            self._wire_arg(val, pin, bindings, ctx)

    def _process_if(self, form: list, bindings: dict[str, PinID],
                    ctx: _TranspileCtx) -> None:
        """Create a Branch node for an (if cond then... [elif|else ...]) form."""
        if len(form) < 2:
            raise RuntimeError('(if) requires a condition')
        cond = form[1]
        body = form[2:]
        then_stmts = body
        else_stmts = []
        elif_form = None
        if body and isinstance(body[-1], list) and body[-1]:
            last = body[-1]
            if isinstance(last[0], Symbol):
                if last[0] == Symbol('else'):
                    else_stmts = last[1:]
                    then_stmts = body[:-1]
                elif last[0] == Symbol('elif'):
                    elif_form = last
                    then_stmts = body[:-1]

        cond_pre = self._eval_expr(cond, bindings, ctx) if isinstance(cond, list) else None
        branch = self._create(_BRANCH, ctx)
        ni = self._get_node_info(branch)
        self._wire_exec(ni, ctx)
        self._wire_condition(ni, cond, bindings, pre_out=cond_pre)

        then_out = self._exec_out(ni, _PIN_THEN)
        else_out = self._exec_out(ni, _PIN_ELSE)

        then_ctx = None
        if then_out and then_stmts:
            then_ctx = _TranspileCtx(x=ctx.x, y=ctx.y, pending_exec=[then_out], break_pin=ctx.break_pin)
            self._process_stmts(then_stmts, dict(bindings), then_ctx)

        # Three-case exec merge after the branch node:
        #   then_ctx is None when then_stmts is empty — the raw then_out pin is already pending.
        #   _merge_branch_exec collects both sides so code after the (if) wires to all open paths.
        if elif_form is not None and else_out:
            # (elif cond ...) → compile as (if cond ...) wired to the else output.
            else_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                     pending_exec=[else_out], break_pin=ctx.break_pin)
            nested_if = [Symbol('if')] + elif_form[1:]
            self._process_stmts([nested_if], dict(bindings), else_ctx)
            ctx.pending_exec = _merge_branch_exec(then_ctx, then_out, else_ctx)
        elif else_out and else_stmts:
            else_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                     pending_exec=[else_out], break_pin=ctx.break_pin)
            self._process_stmts(else_stmts, dict(bindings), else_ctx)
            ctx.pending_exec = _merge_branch_exec(then_ctx, then_out, else_ctx)
        else:
            # No else: Branch.False and end of then-body both continue after the if.
            pending = [else_out] if else_out else []
            if then_ctx:
                pending = pending + list(then_ctx.pending_exec)
            elif then_out:
                pending = pending + [then_out]
            ctx.pending_exec = pending

    def _process_for(self, form: list, bindings: dict[str, PinID],
                     ctx: _TranspileCtx) -> None:
        """Dispatch a (for var iter body...) form to range or foreach processing."""
        if len(form) < 3:
            raise RuntimeError('(for) requires a variable and an iterable')
        var_name = str(form[1])
        iter_expr = form[2]
        body_stmts = form[3:]
        if (isinstance(iter_expr, list) and iter_expr
                and iter_expr[0] == Symbol('range')):
            self._process_for_range(var_name, iter_expr, body_stmts, bindings, ctx)
        else:
            self._process_for_each(var_name, iter_expr, body_stmts, bindings, ctx)

    def _process_loop_body(self, body_out: PinID | None, done_out: PinID | None,
                           var_name: str, var_pin_id: PinID | None,
                           ni: NodeInfo, body_stmts: list, bindings: dict[str, PinID],
                           has_break: bool, ctx: _TranspileCtx) -> None:
        """Wire the loop body exec output, bind the loop variable, and set the completion exec."""
        inner = dict(bindings)
        if var_pin_id is not None and var_name != '_':
            inner[var_name] = var_pin_id
        if body_out:
            body_break_pin = ctx.break_pin
            if has_break:
                break_input = next(
                    (p for p in ni.input_pins if p.type_id == EXEC_TYPE and p.name == _PIN_BREAK_IN), None)
                if break_input is not None:
                    body_break_pin = break_input.pin_id
            body_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                     pending_exec=[body_out], break_pin=body_break_pin)
            self._process_stmts(body_stmts, inner, body_ctx)
        ctx.pending_exec = [done_out] if done_out else []

    def _process_for_range(self, var_name: str, range_form: list,
                            body_stmts: list, bindings: dict[str, PinID],
                            ctx: _TranspileCtx) -> None:
        """Create a ForLoop node for a (for var (range ...) body...) form."""
        args = range_form[1:]
        if len(args) == 1:
            start_expr = 0
            stop_expr = args[0]
        elif len(args) == 2:
            start_expr = args[0]
            stop_expr = args[1]
        else:
            raise RuntimeError(f'(range) takes 1 or 2 args, got {len(args)}')

        if isinstance(stop_expr, int):
            last_expr = stop_expr - 1
        else:
            last_expr = [Symbol('-'), stop_expr, 1]

        has_break = _contains_break(body_stmts)
        loop_type = _FOR_LOOP_BREAK if has_break else _FOR_LOOP
        pre_start = self._eval_expr(start_expr, bindings, ctx) if isinstance(start_expr, list) else None
        pre_last  = self._eval_expr(last_expr,  bindings, ctx) if isinstance(last_expr,  list) else None
        loop = self._create(loop_type, ctx)
        ni = self._get_node_info(loop)
        self._wire_exec(ni, ctx)

        first_pin = next((p for p in ni.input_pins if p.name == _PIN_FIRST_IDX), None)
        last_pin  = next((p for p in ni.input_pins if p.name == _PIN_LAST_IDX),  None)
        for pin, expr, pre_out in (
                (first_pin, start_expr, pre_start),
                (last_pin,  last_expr,  pre_last)):
            if pin is not None:
                self._wire_with_pre(expr, pin, pre_out, bindings, ctx)

        idx_pin  = next((p for p in ni.output_pins if p.name == _PIN_INDEX), None)
        body_out = self._exec_out(ni, _PIN_LOOP_BODY)
        done_out = self._exec_out(ni, _PIN_COMPLETED)
        self._process_loop_body(body_out, done_out, var_name,
                                idx_pin.pin_id if idx_pin else None,
                                ni, body_stmts, bindings, has_break, ctx)

    def _process_for_each(self, var_name: str, iter_expr: object,
                           body_stmts: list, bindings: dict[str, PinID],
                           ctx: _TranspileCtx) -> None:
        """Create a ForEachLoop node for a (for var array body...) form."""
        has_break = _contains_break(body_stmts)
        loop_type = _FOR_EACH_ARRAY_BREAK if has_break else _FOR_EACH_LOOP_ARRAY
        iter_pre = self._eval_expr(iter_expr, bindings, ctx)
        loop = self._create(loop_type, ctx)
        ni = self._get_node_info(loop)
        self._wire_exec(ni, ctx)

        array_pin = next((p for p in ni.input_pins if p.name == _PIN_ARRAY), None)
        if array_pin is not None and iter_pre is not None:
            self._connect(iter_pre, array_pin.pin_id)

        elem_pin = next((p for p in ni.output_pins if p.name == _PIN_ARRAY_ELEM), None)
        body_out = self._exec_out(ni, _PIN_LOOP_BODY)
        done_out = self._exec_out(ni, _PIN_COMPLETED)
        self._process_loop_body(body_out, done_out, var_name,
                                elem_pin.pin_id if elem_pin else None,
                                ni, body_stmts, bindings, has_break, ctx)

    def _process_while(self, form: list, bindings: dict[str, PinID],
                       ctx: _TranspileCtx) -> None:
        """Create a WhileLoop node for a (while cond body...) form."""
        if len(form) < 2:
            raise RuntimeError('(while) requires a condition')
        cond = form[1]
        body_stmts = form[2:]

        cond_pre = self._eval_expr(cond, bindings, ctx) if isinstance(cond, list) else None
        loop = self._create(_WHILE, ctx)
        ni = self._get_node_info(loop)
        self._wire_exec(ni, ctx)
        self._wire_condition(ni, cond, bindings, pre_out=cond_pre)

        body_out = self._exec_out(ni, _PIN_LOOP_BODY)
        done_out = self._exec_out(ni, _PIN_COMPLETED)

        if body_out:
            body_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                     pending_exec=[body_out], break_pin=ctx.break_pin)
            self._process_stmts(body_stmts, dict(bindings), body_ctx)

        ctx.pending_exec = [done_out] if done_out else []

    def _process_switch(self, form: list, bindings: dict[str, PinID],
                        ctx: _TranspileCtx) -> None:
        """Create a Switch node for a (switch TypeId value (:Case stmts...) ...) form."""
        if len(form) < 3:
            raise RuntimeError(
                '(switch) requires a node type ID and a value: '
                '(switch Utilities|FlowControl|SwitchOnInt value (:Case ...))')
        type_id = _SWITCH_ALIASES.get(str(form[1]), str(form[1]))
        if 'SwitchOnString' in type_id or 'SwitchOnName' in type_id:
            raise RuntimeError(
                'String and Name switch nodes are not supported by the DSL (switch) form. '
                'Use set_properties to configure pin_names directly.')
        value_expr = form[2]

        value_pre = self._eval_expr(value_expr, bindings, ctx) if isinstance(value_expr, list) else None
        node = self._create(type_id, ctx)

        non_default = [str(item[0])[1:] for item in form[3:]
                       if isinstance(item, list) and item
                       and str(item[0])[1:].lower() != 'default']
        if non_default and self.graph is not None:
            bp_editor = unreal.BlueprintGraphEditor.get_graph_editor(node.get_outer())
            assert isinstance(bp_editor, unreal.BlueprintGraphEditor), 'Could not get graph editor for switch node'
            for _ in range(len(non_default)):
                bp_editor.add_node_pin(node)  # type: ignore

        ni = self._get_node_info(node)
        self._wire_exec(ni, ctx)
        ctx.pending_exec = []  # switch severs the enclosing exec flow

        ins = _data_ins(ni)
        if ins:
            self._wire_with_pre(value_expr, ins[0], value_pre, bindings, ctx)

        for item in form[3:]:
            if not (isinstance(item, list) and item
                    and isinstance(item[0], Symbol) and item[0].startswith(':')):
                raise RuntimeError(
                    f'(switch) continuation must be (:CaseName stmts...), got: {item!r}')
            pin_name = str(item[0])[1:]
            stmts = item[1:]
            exec_pin = self._exec_out(ni, pin_name)
            if exec_pin is None:
                available = [p.name for p in ni.output_pins if p.type_id == EXEC_TYPE]
                raise RuntimeError(
                    f'Unknown exec output "{pin_name}" on {type_id}. '
                    f'Available: {available}')
            if stmts:
                cont_ctx = _TranspileCtx(x=ctx.x, y=ctx.y + _BRANCH_Y_OFFSET,
                                         pending_exec=[exec_pin], break_pin=ctx.break_pin)
                self._process_stmts(stmts, dict(bindings), cont_ctx)

    # ------------------------------------------------------------------
    # Entry point
    # ------------------------------------------------------------------

    def transpile(self, code: str) -> None:
        """Parse *code* and populate the graph with Blueprint nodes."""
        snapshot = _GraphSnapshot(self.graph, self._get_nodes, self._get_node_info) if self._delete_node else None
        try:
            forms = parse(code)
            event_y = 0
            for form in forms:
                if not isinstance(form, list) or len(form) < 2:
                    raise RuntimeError(
                        f'Top-level form must be (event ...) or (fn ...): {form!r}')
                head = form[0]
                if head not in (Symbol('event'), Symbol('fn')):
                    raise RuntimeError(
                        f'Top-level form must start with "event" or "fn", got: {head!r}')

                name = str(form[1])
                if name.startswith(_EVENT_PFX):
                    name = name[len(_EVENT_PFX):]
                if head == Symbol('fn'):
                    if len(form) < 3 or not isinstance(form[2], list):
                        raise RuntimeError(f'(fn {name} ...) requires a parameter list')
                    body_stmts = form[3:]
                else:
                    # Optional param list: (event Name (p1 p2...) stmts...) or (event Name stmts...)
                    # A param list is a flat list of plain identifiers with no | and no reserved words.
                    # This distinguishes (OtherActor) from statement lists like (switch int ...).
                    if (len(form) > 2 and isinstance(form[2], list)
                            and all(isinstance(e, Symbol) and '|' not in str(e)
                                    and e not in _RESERVED
                                    for e in form[2])):
                        body_stmts = form[3:]
                    else:
                        body_stmts = form[2:]

                try:
                    event_node = self._find_entry_node(name)
                    if event_node is None:
                        event_node = self._create_node(
                            self.graph, f'{_EVENT_PFX}{name}', unreal.IntPoint(0, event_y))

                    if event_node is None:
                        raise RuntimeError(f'Could not find or create entry node for "{name}"')

                    event_ni = self._get_node_info(event_node)
                    event_pos = event_ni.position

                    then_pin = self._exec_out(event_ni, _PIN_THEN)
                    child_ctx = _TranspileCtx(
                        x=event_pos.x + _NODE_X_STRIDE,
                        y=event_pos.y,
                        pending_exec=[then_pin] if then_pin is not None else [],
                        break_pin=None)

                    bindings: dict[str, PinID] = {
                        p.name: p.pin_id
                        for p in event_ni.output_pins
                        if p.type_id != EXEC_TYPE and p.name != 'OutputDelegate'
                    }

                    if head == Symbol('fn'):
                        missing = [str(p) for p in form[2] if str(p) not in bindings]
                        if missing:
                            raise RuntimeError(
                                f'Function parameter(s) not found in graph: {missing}')

                    if 'self' not in bindings and _uses_symbol(body_stmts, 'self'):
                        self_node = self._create_node(
                            self.graph, _SELF_REF,
                            unreal.IntPoint(event_pos.x, event_pos.y - 80))
                        if self_node is not None:
                            self_ni = self._get_node_info(self_node)
                            self_out = next(
                                (p for p in self_ni.output_pins if p.name == 'self'), None)
                            if self_out is not None:
                                bindings['self'] = self_out.pin_id

                    self._process_stmts(body_stmts, bindings, child_ctx)
                except RuntimeError as exc:
                    msg = _clean_error(str(exc))
                    context = f'({head} {name})'
                    if context not in msg:
                        raise RuntimeError(f'{msg}\n  in: {context}') from None
                    raise

                event_y += _EVENT_Y_STRIDE
        except Exception:
            if snapshot:
                snapshot.rollback(self.graph, self._get_nodes, self._get_node_info,
                                  self._delete_node, self._connect_pins)
            raise
        if snapshot:
            snapshot.delete_stale(self.graph, self._get_nodes, self._get_node_info, self._delete_node)


# ---------------------------------------------------------------------------
# Decompiler
# ---------------------------------------------------------------------------

_Bindings = dict[tuple[object, int], str]


@dataclasses.dataclass
class _DecompileCtx:
    """Per-decompile-call state threaded through emit methods."""
    exec_visited: set
    needed_outputs: set


@dataclasses.dataclass
class _EmitState:
    """Scope state passed through every decompiler emit method."""
    bindings: _Bindings
    indent: int
    lines: list['_SForm']
    ctx: _DecompileCtx

    def pad(self) -> str:
        return '  ' * self.indent

    def child(self, extra_indent: int = 1) -> '_EmitState':
        """New scope: fresh line buffer, copied bindings, deeper indent."""
        return _EmitState(dict(self.bindings), self.indent + extra_indent, [], self.ctx)

    def make_form(self, head: str, *extra, close_count: int = 1) -> '_SForm':
        """Promote self.lines (plus any extra _SForm children) into an _SForm."""
        return _SForm(head, self.lines + list(extra), close_count)

    def flatten(self) -> list[str]:
        """Render self.lines to a flat list of strings."""
        return [line for form in self.lines for line in form.render()]


@dataclasses.dataclass
class _SForm:
    """A structured S-expression form.

    head opens close_count parens; render() appends close_count ')' to the last output line.
    close_count > 1 only when the head opens multiple parens on one line, e.g. '(bind x (foo'.
    """
    head: str
    children: list['_SForm']
    close_count: int = 1

    def render(self) -> list[str]:
        lines = [self.head]
        for child in self.children:
            lines.extend(child.render())
        lines[-1] += ')' * self.close_count
        return lines



def _placeholder(pad: str) -> '_SForm':
    return _SForm(f'{pad}_', [], close_count=0)


class Decompiler:
    """Converts Blueprint graph nodes into S-expression DSL text."""

    def __init__(self, graph: unreal.EdGraph, get_node_info_fn: Callable, get_nodes_fn: Callable,
                 *, get_node_type_pins_fn: Callable | None = None,
                 find_node_types_fn: Callable | None = None) -> None:
        """Initialize with graph and read-only access callbacks."""
        self._graph = graph
        self._get_node_info = get_node_info_fn
        self._get_nodes = get_nodes_fn
        self._get_node_type_pins = get_node_type_pins_fn
        self._find_node_types_fn = find_node_types_fn
        self._type_defaults: dict[str, dict[str, str]] = {}

    def _find_entry_nodes(self) -> list[unreal.EdGraphNode]:
        """Return all exec-root nodes: nodes with exec outputs but no exec inputs."""
        result = []
        for node in self._get_nodes(self._graph):
            ni = self._get_node_info(node)
            if ni.type_id == _RETURN_NODE:
                continue
            has_exec_out = any(p.type_id == EXEC_TYPE for p in ni.output_pins)
            has_exec_in  = any(p.type_id == EXEC_TYPE for p in ni.input_pins)
            if has_exec_out and not has_exec_in:
                result.append(node)
        return result

    def _follow_exec_named(self, ni: NodeInfo, pin_name: str) -> unreal.EdGraphNode | None:
        """Return the first node connected to the named exec output of *ni*, or None."""
        pin = next((p for p in ni.output_pins if p.type_id == EXEC_TYPE and p.name == pin_name), None)
        if pin is None or not pin.connected_pins:
            return None
        return pin.connected_pins[0].node

    def _collect_needed_outputs(self, entry_nodes: list[unreal.EdGraphNode]) -> set[tuple[object, int]]:
        """Return (node, output-index) pairs whose values are consumed by downstream exec nodes."""
        needed: set = set()
        visited: set = set()
        queue: collections.deque = collections.deque(entry_nodes)
        while queue:
            node = queue.popleft()
            if node in visited:
                continue
            visited.add(node)
            ni = self._get_node_info(node)
            has_exec_in  = any(p.type_id == EXEC_TYPE for p in ni.input_pins)
            has_exec_out = any(p.type_id == EXEC_TYPE for p in ni.output_pins)
            if has_exec_in and has_exec_out:
                for idx, pin in enumerate(ni.output_pins):
                    if pin.type_id == EXEC_TYPE or pin.name == 'OutputDelegate':
                        continue
                    if pin.connected_pins:
                        needed.add((node, idx))
            for ep in ni.output_pins:
                if ep.type_id == EXEC_TYPE and ep.connected_pins:
                    queue.append(ep.connected_pins[0].node)
        return needed

    def _alloc_tmp(self, pin: PinInfo, bindings: _Bindings) -> str:
        """Allocate a unique underscore-prefixed variable name derived from *pin*'s name."""
        sanitized = _sanitize_pin_name(pin.name)
        base = f'_{sanitized}'
        used = set(bindings.values())
        if base not in used:
            return base
        n = 1
        while f'{base}_{n}' in used:
            n += 1
        return f'{base}_{n}'

    # ------------------------------------------------------------------
    # Expression emission (inline)
    # ------------------------------------------------------------------

    def _emit_expr(self, pin_info: PinInfo, bindings: _Bindings,
                   _visiting: set | None = None) -> str:
        """Emit the DSL expression for the value arriving on *pin_info*, recursing into pure nodes."""
        if not pin_info.connected_pins:
            return _format_pin_default(pin_info.value, pin_info.type_id)

        src_pid = pin_info.connected_pins[0]
        src_node = src_pid.node
        src_ni = self._get_node_info(src_node)

        src_node, src_ni, src_pid, halted = _follow_reroutes(
            src_node, src_ni, src_pid, self._get_node_info)
        if halted:
            ins = _data_ins(src_ni)
            return _format_pin_default(ins[0].value if ins else '', '')

        if src_pid.index_id >= len(src_ni.output_pins):
            raise RuntimeError(
                f'Pin index {src_pid.index_id} out of range on "{src_ni.type_id}" '
                f'(has {len(src_ni.output_pins)} output pins) — graph may be malformed.')

        return self._emit_source_expr(src_node, src_ni, src_pid.index_id, bindings, _visiting)

    def _emit_binop_expr(self, type_id: str, src_ni: NodeInfo,
                         bindings: _Bindings, _visiting: set) -> str:
        op = _TYPE_ID_TO_OP[type_id]
        ins = _data_ins(src_ni)
        left  = self._emit_expr(ins[0], bindings, _visiting) if len(ins) > 0 else '_'
        right = self._emit_expr(ins[1], bindings, _visiting) if len(ins) > 1 else '_'
        if op == '-' and left == '0':
            return f'(- {right})'
        return f'({op} {left} {right})'

    def _emit_not_expr(self, src_ni: NodeInfo, bindings: _Bindings, _visiting: set) -> str:
        ins = _data_ins(src_ni)
        operand = self._emit_expr(ins[0], bindings, _visiting) if ins else '_'
        return f'(not {operand})'

    def _emit_select_expr(self, src_ni: NodeInfo, bindings: _Bindings, _visiting: set) -> str:
        ins = _data_ins(src_ni)
        cond_pin, value_pins = _select_pins(ins)
        cond = self._emit_expr(cond_pin, bindings, _visiting) if cond_pin else 'true'
        # Option 1 is the true branch (a), Option 0 is the false branch (b).
        a    = self._emit_expr(value_pins[1], bindings, _visiting) if len(value_pins) > 1 else '_'
        b    = self._emit_expr(value_pins[0], bindings, _visiting) if len(value_pins) > 0 else '_'
        return f'(select {cond} {a} {b})'

    def _emit_component_expr(self, type_id: str, src_ni: NodeInfo, src_pin: PinInfo,
                             bindings: _Bindings, _visiting: set) -> str:
        attr = _COMP_REV[(type_id, src_pin.name)]
        ins = _data_ins(src_ni)
        obj_expr = self._emit_expr(ins[0], bindings, _visiting) if ins else '_'
        return f'(.{attr} {obj_expr})'

    def _emit_source_expr(self, src_node: unreal.EdGraphNode, src_ni: NodeInfo,
                          output_idx: int, bindings: _Bindings,
                          _visiting: set | None = None) -> str:
        """Emit the DSL expression produced by *src_node*'s output at *output_idx*."""
        src_pin = src_ni.output_pins[output_idx]
        key = (src_node, output_idx)
        if key in bindings:
            return bindings[key]

        if _visiting is None:
            _visiting = set()
        if key in _visiting:
            raise RuntimeError(
                f'Cycle detected in data-flow graph at "{src_ni.type_id}" — graph is malformed.')
        _visiting = _visiting | {key}

        type_id = self._expand_type_id(src_ni.type_id)

        if type_id in (_SELF_REF, _SELF_REF_ALT):
            return 'self'

        # Collapse MakeLiteral* nodes to their literal value so round-trips are clean.
        if type_id in _MAKE_LITERAL_COLLAPSED:
            ins = _data_ins(src_ni)
            if ins and not ins[0].connected_pins:
                return _format_pin_default(ins[0].value, ins[0].type_id)

        if type_id in _TYPE_ID_TO_OP:
            return self._emit_binop_expr(type_id, src_ni, bindings, _visiting)

        if type_id == _NOT_BOOLEAN:
            return self._emit_not_expr(src_ni, bindings, _visiting)

        if type_id == _SELECT_NODE:
            return self._emit_select_expr(src_ni, bindings, _visiting)

        comp_key = (type_id, src_pin.name)
        if comp_key in _COMP_REV:
            return self._emit_component_expr(type_id, src_ni, src_pin, bindings, _visiting)

        ins = _strip_implicit_self(_data_ins(src_ni))
        args = [self._emit_expr(p, bindings, _visiting) for p in ins]
        args = self._strip_trailing_defaults(args, ins, type_id)
        return f'({" ".join([type_id] + args)})'

    def _unwrap_dec(self, last_pin: PinInfo, bindings: _Bindings) -> str | None:
        """If *last_pin* is wired to (A - 1), return the DSL expression for A; else None.

        Cancels the -1/+1 pair written by the transpiler for non-literal range stops so
        that (for i (range expr) ...) round-trips without the noise of (range (+ (- expr 1) 1)).
        """
        if not last_pin.connected_pins:
            return None
        src_pid = last_pin.connected_pins[0]
        src_node = src_pid.node
        src_ni = self._get_node_info(src_node)
        if src_ni.type_id not in _SUBTRACT_TYPE_IDS:
            return None
        ins = _data_ins(src_ni)
        if len(ins) < 2:
            return None
        b_pin = ins[1]
        b_is_one = False
        if not b_pin.connected_pins:
            b_is_one = (b_pin.value == '1')
        else:
            b_src_pid = b_pin.connected_pins[0]
            b_src_ni = self._get_node_info(b_src_pid.node)
            if b_src_ni.type_id in _MAKE_LITERAL_COLLAPSED:
                b_ins = _data_ins(b_src_ni)
                b_is_one = bool(b_ins and not b_ins[0].connected_pins and b_ins[0].value == '1')
        if not b_is_one:
            return None
        return self._emit_expr(ins[0], bindings)

    def _expand_type_id(self, type_id: str) -> str:
        """Resolve a '|Name' NodeInfo type_id to its canonical 'Category|Name' create-node form."""
        if not type_id.startswith('|') or self._find_node_types_fn is None:
            return type_id
        lower = type_id.lower()
        candidates = [t for t in self._find_node_types_fn(self._graph, type_id, [])
                      if t.lower().endswith(lower)]
        if not candidates:
            return type_id
        variables  = [t for t in candidates if t.startswith('Variables|')]
        components = [t for t in candidates if t.startswith('Components|')]
        preferred  = variables or components
        return (preferred or candidates)[0]

    def _get_schema_defaults(self, type_id: str) -> dict[str, str]:
        """Return {pin_name → default_value} for *type_id*, fetched once and cached."""
        if type_id in self._type_defaults:
            return self._type_defaults[type_id]
        if self._get_node_type_pins is None:
            self._type_defaults[type_id] = {}
            return {}
        try:
            ni = self._get_node_type_pins(self._graph, type_id)
            defaults = {p.name: p.value for p in _data_ins(ni)}
        except Exception:
            defaults = {}
        self._type_defaults[type_id] = defaults
        return defaults

    def _strip_trailing_defaults(self, args: list[str], ins: list[PinInfo],
                                 type_id: str) -> list[str]:
        """Remove trailing args whose unconnected pin values match the schema default."""
        defaults = self._get_schema_defaults(type_id)
        if not defaults:
            return args
        result = list(args)
        while len(result) > 1:
            pin = ins[len(result) - 1]
            if pin.connected_pins:
                break
            schema_default = defaults.get(pin.name)
            if schema_default is None:
                break
            if _format_pin_default(pin.value, pin.type_id) != _format_pin_default(schema_default, pin.type_id):
                break
            result.pop()
        return result

    def _walk_pure_inputs_of(self, pin: PinInfo, seen: set) -> None:
        """Recursively collect (node, output_idx) keys from the pure input subgraph of *pin*."""
        if not pin.connected_pins:
            return
        src_pid = pin.connected_pins[0]
        src_node = src_pid.node
        src_ni = self._get_node_info(src_node)
        src_node, src_ni, src_pid, halted = _follow_reroutes(
            src_node, src_ni, src_pid, self._get_node_info, raise_on_cycle=False)
        if halted:
            return
        all_pins = list(src_ni.input_pins) + list(src_ni.output_pins)
        if any(p.type_id == EXEC_TYPE for p in all_pins):
            return
        key = (src_node, src_pid.index_id)
        if key in seen:
            return
        seen.add(key)
        if src_ni.type_id in _MAKE_LITERAL_COLLAPSED:
            return
        for in_pin in _data_ins(src_ni):
            self._walk_pure_inputs_of(in_pin, seen)

    def _collect_shared_pure_outputs(self, entry: unreal.EdGraphNode) -> set[tuple]:
        """Return pure-node output keys consumed by 2+ exec-side nodes in *entry*'s chain."""
        exec_nodes: list = []
        visited_exec: set = set()
        queue: collections.deque = collections.deque([entry])
        while queue:
            node = queue.popleft()
            if node in visited_exec:
                continue
            visited_exec.add(node)
            exec_nodes.append(node)
            ni = self._get_node_info(node)
            for ep in ni.output_pins:
                if ep.type_id == EXEC_TYPE and ep.connected_pins:
                    queue.append(ep.connected_pins[0].node)

        ref_count: collections.Counter = collections.Counter()
        for exec_node in exec_nodes:
            ni = self._get_node_info(exec_node)
            seen_keys: set = set()
            for pin in _data_ins(ni):
                self._walk_pure_inputs_of(pin, seen_keys)
            for k in seen_keys:
                ref_count[k] += 1

        return {k for k, count in ref_count.items() if count >= 2}

    def _topo_sort_hoisted(self, shared_keys: set) -> list:
        """Return *shared_keys* in dependency order (deps before dependents)."""
        result: list = []
        visited: set = set()

        # Iterative post-order DFS. A recursive nested function would close over itself,
        # creating a Python reference cycle that is only broken by PyGC_Collect(). That
        # collection is triggered inside Blueprint compilation, which crashes because
        # finalizing the cycle deallocates UObject wrappers while Python is on the stack.
        for start in sorted(shared_keys, key=lambda k: k[0].get_path_name()):
            if start in visited:
                continue
            stack: list = [(start, False)]
            while stack:
                key, processed = stack.pop()
                if processed:
                    if key not in visited:
                        visited.add(key)
                        result.append(key)
                    continue
                if key in visited:
                    continue
                stack.append((key, True))
                node, idx = key
                ni = self._get_node_info(node)
                for pin in _data_ins(ni):
                    if pin.connected_pins:
                        dep_key = (pin.connected_pins[0].node, pin.connected_pins[0].index_id)
                        if dep_key in shared_keys and dep_key not in visited:
                            stack.append((dep_key, False))

        return result

    # ------------------------------------------------------------------
    # Statement emission (multi-line)
    # ------------------------------------------------------------------

    def _find_join_node(self, then_node: unreal.EdGraphNode | None,
                        else_node: unreal.EdGraphNode | None) -> unreal.EdGraphNode | None:
        """Return the first exec node reachable from both branch sides (the join/post-dominator)."""
        if then_node is None or else_node is None:
            return None
        then_reachable: set = set()
        queue: collections.deque = collections.deque([then_node])
        while queue:
            n = queue.popleft()
            if n is None or n in then_reachable:
                continue
            then_reachable.add(n)
            ni = self._get_node_info(n)
            for pin in ni.output_pins:
                if pin.type_id == EXEC_TYPE and pin.connected_pins:
                    queue.append(pin.connected_pins[0].node)
        bfs_visited: set = set()
        queue = collections.deque([else_node])
        while queue:
            n = queue.popleft()
            if n is None or n in bfs_visited:
                continue
            bfs_visited.add(n)
            if n in then_reachable:
                return n
            ni = self._get_node_info(n)
            for pin in ni.output_pins:
                if pin.type_id == EXEC_TYPE and pin.connected_pins:
                    queue.append(pin.connected_pins[0].node)
        return None

    def _emit_stmts(self, node: unreal.EdGraphNode, state: _EmitState, *,
                    break_node: unreal.EdGraphNode | None = None,
                    stop_node: unreal.EdGraphNode | None = None) -> None:
        """Walk the exec chain from *node* and append DSL statement lines to *state.lines*.

        Loop invariant: each iteration either sets `node` to the next exec node and
        `continue`s, or `return`s (nothing more to emit on this path).
        Each emitter that has a natural continuation returns the next node; emitters that
        terminate exec flow (sequence, switch, multi-exec) return None.
        """
        while node is not None:
            if stop_node is not None and node is stop_node:
                return
            if break_node is not None and node is break_node:
                state.lines.append(_SForm(f'{state.pad()}(break', []))
                return
            if node in state.ctx.exec_visited:
                return
            state.ctx.exec_visited.add(node)
            ni = self._get_node_info(node)
            type_id = ni.type_id

            if type_id == _RETURN_NODE:
                self._emit_return(ni, state)
                return

            if type_id == _BRANCH:
                node = self._emit_branch(node, ni, state, stop_node=stop_node)
                continue

            if type_id in (_FOR_LOOP_BREAK, _FOR_EACH_BREAK, _FOR_EACH_ARRAY_BREAK):
                emit_fn = self._emit_for if type_id == _FOR_LOOP_BREAK else self._emit_for_each
                node = emit_fn(node, ni, state, break_node=node)
                continue

            if type_id == _FOR_LOOP:
                node = self._emit_for(node, ni, state)
                continue

            if type_id in (_FOR_EACH_LOOP, _FOR_EACH_LOOP_ARRAY):
                node = self._emit_for_each(node, ni, state)
                continue

            if type_id == _WHILE:
                node = self._emit_while(node, ni, state)
                continue

            if type_id == _MULTI_GATE:
                raise RuntimeError(
                    'MultiGate cannot be decompiled: it fires one branch per call.')

            if type_id == _SEQUENCE:
                self._emit_sequence(node, ni, state)
                return

            if type_id == _REROUTE_NODE:
                exec_out = next(
                    (p for p in ni.output_pins if p.type_id == EXEC_TYPE and p.connected_pins),
                    None)
                node = exec_out.connected_pins[0].node if exec_out else None
                continue

            if type_id.startswith(_SWITCH_PFX):
                self._emit_switch(node, ni, state)
                return

            non_then_exec = [p for p in ni.output_pins
                              if p.type_id == EXEC_TYPE and p.name != _PIN_THEN and p.connected_pins]
            if non_then_exec:
                self._emit_multi_exec_call(node, ni, state)
                return
            node = self._emit_call_stmt(node, ni, state)

    def _build_cont_forms(self, exec_conts: list[tuple[str, unreal.EdGraphNode]],
                          state: _EmitState) -> list:
        """Build (: PinName ...) _SForm children for exec continuations."""
        cont_pad = '  ' * (state.indent + 1)
        children = []
        for pin_name, cont_node in exec_conts:
            cont_state = state.child(2)
            self._emit_stmts(cont_node, cont_state)
            children.append(cont_state.make_form(f'{cont_pad}(:{_format_pin_name(pin_name)}'))
        return children

    def _emit_multi_exec_call(self, node: unreal.EdGraphNode, ni: NodeInfo,
                              state: _EmitState) -> None:
        """Emit a node call with named exec continuations into *state.lines*."""
        inner = self._build_call_inner(ni, state.bindings)

        assigned = self._collect_assigned_outputs(node, ni, state)

        exec_conts = [
            (p.name, p.connected_pins[0].node)
            for p in ni.output_pins
            if p.type_id == EXEC_TYPE and p.connected_pins
        ]

        cont_forms = self._build_cont_forms(exec_conts, state)
        if assigned:
            lhs = ('(' + ' '.join(assigned) + ')') if len(assigned) > 1 else assigned[0]
            state.lines.append(_SForm(f'{state.pad()}(bind {lhs} ({inner})', cont_forms))
        else:
            state.lines.append(_SForm(f'{state.pad()}({inner}', cont_forms))

    def _collect_assigned_outputs(self, node: unreal.EdGraphNode, ni: NodeInfo,
                                   state: _EmitState) -> list[str]:
        """Collect output pins that need binding, allocate names, and update *state.bindings*."""
        assigned: list[str] = []
        for idx, pin in enumerate(ni.output_pins):
            if pin.type_id == EXEC_TYPE or pin.name == 'OutputDelegate':
                continue
            key = (node, idx)
            if key in state.ctx.needed_outputs:
                name = self._alloc_tmp(pin, state.bindings)
                state.bindings[key] = name
                assigned.append(name)
        return assigned

    def _build_call_inner(self, ni: NodeInfo, bindings: _Bindings) -> str:
        """Build 'TypeId arg1 arg2 ...' for a node call in exec-statement context."""
        type_id = self._expand_type_id(ni.type_id)
        ins = _strip_implicit_self(_data_ins(ni))
        args = [self._emit_expr(p, bindings) for p in ins]
        args = self._strip_trailing_defaults(args, ins, type_id)
        return ' '.join([type_id] + args)

    def _emit_call_stmt(self, node: unreal.EdGraphNode, ni: NodeInfo,
                        state: _EmitState) -> unreal.EdGraphNode | None:
        """Emit a single call statement (or bind form) for *ni*; return the next exec node."""
        inner = self._build_call_inner(ni, state.bindings)

        assigned = self._collect_assigned_outputs(node, ni, state)

        if assigned:
            lhs = ('(' + ' '.join(assigned) + ')') if len(assigned) > 1 else assigned[0]
            state.lines.append(_SForm(f'{state.pad()}(bind {lhs} ({inner}', [], close_count=2))
        else:
            state.lines.append(_SForm(f'{state.pad()}({inner}', []))

        return self._follow_exec_named(ni, _PIN_THEN)

    def _emit_return(self, ni: NodeInfo, state: _EmitState) -> None:
        """Emit a (return ...) statement for *ni* into *state.lines*."""
        ins = _data_ins(ni)
        if not ins:
            state.lines.append(_SForm(f'{state.pad()}(return', []))
        elif len(ins) == 1:
            state.lines.append(_SForm(f'{state.pad()}(return {self._emit_expr(ins[0], state.bindings)}', []))
        else:
            vals = ' '.join(self._emit_expr(p, state.bindings) for p in ins)
            state.lines.append(_SForm(f'{state.pad()}(return {vals}', []))

    def _emit_branch(self, node: unreal.EdGraphNode, ni: NodeInfo,
                     state: _EmitState, *,
                     stop_node: unreal.EdGraphNode | None = None) -> unreal.EdGraphNode | None:
        """Emit an (if ...) or (if ... (elif ...)) form for a Branch node into *state.lines*.

        Returns the join node (first exec node after both branches converge), or None.
        """
        cond_pin = next((p for p in ni.input_pins if p.name == _PIN_CONDITION), None)
        cond_expr = self._emit_expr(cond_pin, state.bindings) if cond_pin else 'true'

        then_node = self._follow_exec_named(ni, _PIN_THEN)
        else_node = self._follow_exec_named(ni, _PIN_ELSE)

        join_node = self._find_join_node(then_node, else_node)
        inner_stop = join_node if join_node is not None else stop_node

        then_state = state.child()
        if then_node:
            self._emit_stmts(then_node, then_state, stop_node=inner_stop)

        if (else_node
                and else_node is not join_node
                and self._get_node_info(else_node).type_id == _BRANCH
                and else_node not in state.ctx.exec_visited):
            elif_form = self._build_elif_lines(else_node, state.child(1), stop_node=inner_stop)
            then_children = then_state.lines or [_placeholder(then_state.pad())]
            state.lines.append(_SForm(f'{state.pad()}(if {cond_expr}', then_children + [elif_form]))
        elif else_node and else_node is not join_node:
            if not then_state.lines:
                # Empty then-body: flip condition so the else-body becomes the then-body.
                # Avoids emitting (if cond _ (else BODY)) which can mislead re-generation.
                flipped_state = state.child()
                self._emit_stmts(else_node, flipped_state, stop_node=inner_stop)
                if flipped_state.lines:
                    state.lines.append(flipped_state.make_form(f'{state.pad()}(if {_invert_expr(cond_expr)}'))
                    return join_node
            else_state = state.child(2)
            self._emit_stmts(else_node, else_state, stop_node=inner_stop)
            else_children = else_state.lines or [_placeholder(else_state.pad())]
            else_form = _SForm(f'{state.pad()}  (else', else_children)
            then_children = then_state.lines or [_placeholder(then_state.pad())]
            state.lines.append(_SForm(f'{state.pad()}(if {cond_expr}', then_children + [else_form]))
        else:
            then_children = then_state.lines or [_placeholder(then_state.pad())]
            state.lines.append(_SForm(f'{state.pad()}(if {cond_expr}', then_children))

        return join_node

    def _build_elif_lines(self, node: unreal.EdGraphNode, state: _EmitState, *,
                          stop_node: unreal.EdGraphNode | None = None) -> '_SForm':
        """Recursively build an (elif ...) _SForm for a Branch node in an elif chain."""
        state.ctx.exec_visited.add(node)
        ni = self._get_node_info(node)
        cond_pin = next((p for p in ni.input_pins if p.name == _PIN_CONDITION), None)
        cond_expr = self._emit_expr(cond_pin, state.bindings) if cond_pin else 'true'

        then_node = self._follow_exec_named(ni, _PIN_THEN)
        else_node = self._follow_exec_named(ni, _PIN_ELSE)

        then_state = state.child()
        if then_node:
            self._emit_stmts(then_node, then_state, stop_node=stop_node)
        then_children = then_state.lines or [_placeholder(then_state.pad())]

        if (else_node
                and else_node is not stop_node
                and self._get_node_info(else_node).type_id == _BRANCH
                and else_node not in state.ctx.exec_visited):
            elif_form = self._build_elif_lines(else_node, state.child(1), stop_node=stop_node)
            return _SForm(f'{state.pad()}(elif {cond_expr}', then_children + [elif_form])
        elif else_node and else_node is not stop_node:
            else_state = state.child(2)
            self._emit_stmts(else_node, else_state, stop_node=stop_node)
            else_children = else_state.lines or [_placeholder(else_state.pad())]
            else_form = _SForm(f'{state.pad()}  (else', else_children)
            return _SForm(f'{state.pad()}(elif {cond_expr}', then_children + [else_form])

        return _SForm(f'{state.pad()}(elif {cond_expr}', then_children)

    def _emit_sequence(self, node: unreal.EdGraphNode, ni: NodeInfo,
                       state: _EmitState) -> None:
        """Emit all exec branches of a Sequence node sequentially into *state.lines*."""
        for pin in ni.output_pins:
            if pin.type_id == EXEC_TYPE and pin.connected_pins:
                self._emit_stmts(pin.connected_pins[0].node, state)

    def _collect_loop_body_lines(self, ni: NodeInfo, state: _EmitState, *,
                                 break_node: unreal.EdGraphNode | None = None) -> list:
        """Collect DSL lines for a loop body, returning a placeholder if empty."""
        body_state = state.child()
        body_node = self._follow_exec_named(ni, _PIN_LOOP_BODY)
        if body_node:
            self._emit_stmts(body_node, body_state, break_node=break_node)
        return body_state.lines or [_placeholder(body_state.pad())]

    def _emit_for(self, node: unreal.EdGraphNode, ni: NodeInfo, state: _EmitState, *,
                  break_node: unreal.EdGraphNode | None = None) -> unreal.EdGraphNode | None:
        """Emit a (for var (range ...) body...) form for a ForLoop node; return next exec node."""
        first_pin = next((p for p in ni.input_pins if p.name == _PIN_FIRST_IDX), None)
        last_pin  = next((p for p in ni.input_pins if p.name == _PIN_LAST_IDX),  None)
        first_expr = self._emit_expr(first_pin, state.bindings) if first_pin else '0'
        last_expr  = self._emit_expr(last_pin,  state.bindings) if last_pin  else '0'
        stop_expr  = (self._unwrap_dec(last_pin, state.bindings) if last_pin else None) \
                     or _increment_expr(last_expr)

        idx_var = '_'
        for out_idx, pin in enumerate(ni.output_pins):
            if pin.name == _PIN_INDEX:
                key = (node, out_idx)
                if key in state.ctx.needed_outputs:
                    idx_var = self._alloc_tmp(pin, state.bindings)
                    state.bindings[key] = idx_var
                break

        range_str = f'(range {stop_expr})' if first_expr == '0' else f'(range {first_expr} {stop_expr})'
        body_lines = self._collect_loop_body_lines(ni, state, break_node=break_node)
        state.lines.append(_SForm(f'{state.pad()}(for {idx_var} {range_str}', body_lines))
        return self._follow_exec_named(ni, _PIN_COMPLETED)

    def _emit_for_each(self, node: unreal.EdGraphNode, ni: NodeInfo, state: _EmitState, *,
                       break_node: unreal.EdGraphNode | None = None) -> unreal.EdGraphNode | None:
        """Emit a (for var array body...) form for a ForEachLoop node; return next exec node."""
        array_pin = next((p for p in ni.input_pins if p.name == _PIN_ARRAY), None)
        array_expr = self._emit_expr(array_pin, state.bindings) if array_pin else '_'

        elem_var = '_'
        for out_idx, pin in enumerate(ni.output_pins):
            if pin.name == _PIN_ARRAY_ELEM:
                key = (node, out_idx)
                if key in state.ctx.needed_outputs:
                    elem_var = self._alloc_tmp(pin, state.bindings)
                    state.bindings[key] = elem_var
                break

        body_lines = self._collect_loop_body_lines(ni, state, break_node=break_node)
        state.lines.append(_SForm(f'{state.pad()}(for {elem_var} {array_expr}', body_lines))
        return self._follow_exec_named(ni, _PIN_COMPLETED)

    def _emit_switch(self, node: unreal.EdGraphNode, ni: NodeInfo, state: _EmitState) -> None:
        """Emit a (switch TypeId value (:Case ...)) form for a Switch node into *state.lines*."""
        type_id = ni.type_id
        ins = _data_ins(ni)
        val_expr = self._emit_expr(ins[0], state.bindings) if ins else '_'

        exec_conts = [
            (p.name, p.connected_pins[0].node)
            for p in ni.output_pins
            if p.type_id == EXEC_TYPE and p.connected_pins
        ]

        cont_forms = self._build_cont_forms(exec_conts, state)
        state.lines.append(_SForm(f'{state.pad()}(switch {type_id} {val_expr}', cont_forms))

    def _emit_while(self, node: unreal.EdGraphNode, ni: NodeInfo,
                    state: _EmitState) -> unreal.EdGraphNode | None:
        """Emit a (while cond body...) form for a WhileLoop node; return next exec node."""
        cond_pin = next((p for p in ni.input_pins if p.name == _PIN_CONDITION), None)
        cond_expr = self._emit_expr(cond_pin, state.bindings) if cond_pin else 'true'
        body_lines = self._collect_loop_body_lines(ni, state)
        state.lines.append(_SForm(f'{state.pad()}(while {cond_expr}', body_lines))
        return self._follow_exec_named(ni, _PIN_COMPLETED)

    # ------------------------------------------------------------------
    # Entry point
    # ------------------------------------------------------------------

    def decompile(self) -> str:
        """Decompile the graph into an S-expression DSL string."""
        entry_nodes = sorted(
            self._find_entry_nodes(),
            key=lambda n: self._get_node_info(n).position.y,
        )
        needed_outputs = self._collect_needed_outputs(entry_nodes)

        lines: list[str] = []
        for entry in entry_nodes:
            ni = self._get_node_info(entry)
            name = ni.type_id[len(_EVENT_PFX):] if ni.type_id.startswith(_EVENT_PFX) else ni.type_id.split('|')[-1]
            params = [p.name for p in ni.output_pins
                      if p.type_id != EXEC_TYPE and p.name != 'OutputDelegate']

            bindings: _Bindings = {}
            for idx, pin in enumerate(ni.output_pins):
                if pin.type_id != EXEC_TYPE and pin.name != 'OutputDelegate':
                    bindings[(entry, idx)] = pin.name

            is_fn = ni.type_id.startswith('|') and not ni.type_id.startswith(_EVENT_PFX)

            if is_fn:
                params_str = '(' + ' '.join(params) + ')'
                lines.append(f'(fn {name} {params_str}')
            elif params:
                params_str = '(' + ' '.join(params) + ')'
                lines.append(f'(event {name} {params_str}')
            else:
                lines.append(f'(event {name}')

            # Pre-emit shared pure expressions as bind stmts before the exec chain.
            hoisted_keys = self._collect_shared_pure_outputs(entry)
            sorted_hoisted = self._topo_sort_hoisted(hoisted_keys)
            hoisted_lines: list[str] = []
            for key in sorted_hoisted:
                h_node, h_idx = key
                h_ni = self._get_node_info(h_node)
                h_pin = h_ni.output_pins[h_idx]
                varname = self._alloc_tmp(h_pin, bindings)
                expr = self._emit_source_expr(h_node, h_ni, h_idx, bindings)
                bindings[key] = varname
                hoisted_lines.append(f'  (bind {varname} {expr})')

            state = _EmitState(
                bindings=bindings,
                indent=1,
                lines=[],
                ctx=_DecompileCtx(exec_visited={entry}, needed_outputs=needed_outputs),
            )
            then_node = self._follow_exec_named(ni, _PIN_THEN)
            if then_node:
                self._emit_stmts(then_node, state)

            all_body = hoisted_lines + state.flatten()
            if all_body:
                lines.extend(all_body)
            lines[-1] += ')'
            lines.append('')

        return '\n'.join(lines)
