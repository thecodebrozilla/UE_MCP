# Copyright Epic Games, Inc. All Rights Reserved.

import collections
from dataclasses import dataclass, field
from typing import Callable

import unreal

Node = unreal.EdGraphNode
NodeId = int
EdgeKey = tuple[NodeId, NodeId]


@dataclass
class _NodeAdjacencyMap:
    """Edges of the graph derived from walking every node's output pins.

    downstream: for each node, the set of nodes it directly feeds into.
    incoming: for each node, how many unique nodes feed directly into it.
    pin_frac: for each connected pair, the normalised position of the source pin
              (0.0 = topmost pin, 1.0 = bottommost) used to preserve pin order
              when sorting nodes vertically.
    """
    downstream: dict[NodeId, set[NodeId]]
    incoming: dict[NodeId, int]
    pin_frac: dict[EdgeKey, float]


@dataclass
class _NodeDepthMap:
    """Column index and immediate parents for every node.

    depth: the column each node belongs in, where 0 is the leftmost column.
           Determined by the longest path from any source node so that a node
           always sits to the right of everything that feeds into it.
    upstream: for each node, the set of nodes that feed directly into it.
    """
    depth: dict[NodeId, int]
    upstream: dict[NodeId, set[NodeId]]


@dataclass
class _VirtualGraph:
    """The graph after long edges are broken up with placeholder dummy nodes.

    Any edge that skips one or more columns is replaced by a chain of dummy
    nodes, one per intermediate column. This lets the crossing minimiser reason
    about wire routing at every column, not just at the endpoints of long edges.
    Dummy nodes are assigned negative ids so they never collide with real node
    ids, which are memory addresses and always positive.

    downstream: for each node, the set of nodes it directly feeds (real and dummy).
    upstream: for each node, the set of nodes that feed directly into it (real and dummy).
    depth: column index for every node including dummies.
    pin_frac: pin fraction for every edge, carried along dummy chains unchanged.
    """
    downstream: dict[NodeId, set[NodeId]]
    upstream: dict[NodeId, set[NodeId]]
    depth: dict[NodeId, int]
    pin_frac: dict[EdgeKey, float]


@dataclass
class _ColumnLayout:
    """The ordered contents of each column after crossing minimisation.

    col_list: column indices in left-to-right order.
    col_order: for each column, the nodes it contains listed top-to-bottom
               (includes both real nodes and dummies).
    """
    col_list: list[int]
    col_order: dict[int, list[NodeId]]


@dataclass
class _BBox:
    """Axis-aligned bounding box, inclusive of node sizes and padding."""
    x1: int
    y1: int
    x2: int
    y2: int


class GraphFormatter:
    """Arranges graph nodes into a readable left-to-right layered layout.

    All graph operations are injected as callables so the formatter works with
    any graph representation, including lightweight fakes in unit tests.
    """

    COL_PADDING = 100
    ROW_PADDING = 100

    def __init__(
        self,
        get_out_pins: Callable,
        get_connected_pins: Callable,
        get_pin_owner: Callable,
        get_node_pos: Callable,
        set_node_pos: Callable,
        get_node_size: Callable | None = None,
    ):
        """
        Args:
            get_out_pins: (node) -> list[pin] — output pins in index order.
            get_connected_pins: (pin) -> list[pin] — input pins connected to this output pin.
            get_pin_owner: (pin) -> node — node that owns this pin.
            get_node_pos: (node) -> (int, int) — current (x, y) position of the node.
            set_node_pos: (node, int, int) -> None — move the node to (x, y).
            get_node_size: (node) -> (int, int) — (width, height) of the node. When provided,
                           column widths and row spacing adapt to actual node dimensions plus
                           COL_PADDING / ROW_PADDING. When omitted, COL_PADDING and ROW_PADDING
                           are used as the full spacing values.
        """
        self._get_out_pins = get_out_pins
        self._get_connected_pins = get_connected_pins
        self._get_pin_owner = get_pin_owner
        self._get_node_pos = get_node_pos
        self._set_node_pos = set_node_pos
        self._get_node_size = get_node_size

    def arrange(self, all_nodes: list[Node], to_arrange: set[Node]) -> None:
        """Lays out to_arrange nodes within the context of all_nodes.

        Two-phase algorithm:

        Phase 1 — layout nodes in subgraph.  Each connected component is arranged
        independently using Sugiyama.  Nodes not in to_arrange act as immovable
        anchors; arranged nodes align to them.  For fully-selected components
        (no anchors) the result is translated back to the component's original
        bounding box.

        Phase 2 — layout subgraphs in graph.  Fully-selected components are then
        moved as rigid units so their bounding boxes do not overlap each other.
        Partially-selected components are not touched in this phase (their anchors
        already pin them to the canvas).

        Args:
            all_nodes: Every node in the graph, including anchors outside to_arrange.
            to_arrange: The subset of nodes to reposition.
        """
        if len(all_nodes) <= 1:
            return

        node_ids = {id(n): n for n in all_nodes}
        all_nids = set(node_ids)
        arrange_ids = {id(n) for n in to_arrange}

        node_sizes = (
            {id(n): self._get_node_size(n) for n in all_nodes}
            if self._get_node_size else {}
        )

        adj = self._build_adjacency(all_nodes, all_nids)
        components = self._find_components(all_nids, adj)

        full_comp_nids: list[set[NodeId]] = []
        fixed_comps: list[set[NodeId]] = []  # components whose nodes won't move in Phase 2

        for comp in components:
            comp_arrange = comp & arrange_ids
            if comp_arrange:
                self._run_sugiyama(comp, comp_arrange, node_ids, node_sizes, adj)
                if not (comp - comp_arrange):
                    full_comp_nids.append(comp_arrange)
                else:
                    fixed_comps.append(comp)
            else:
                fixed_comps.append(comp)

        # Compute obstacle bboxes after Phase 1 so partial components reflect their
        # post-layout positions when full components are placed around them.
        obstacle_bboxes = [self._nodes_bbox(comp, node_ids, node_sizes) for comp in fixed_comps]

        self._layout_subgraphs_in_graph(full_comp_nids, obstacle_bboxes, node_ids, node_sizes)
        self._separate_overlapping(arrange_ids, node_ids, node_sizes)

    def _compute_col_widths(
        self,
        node_ids: dict[NodeId, object],
        depth: dict[NodeId, int],
        col_list: list[int],
        node_sizes: dict[NodeId, tuple[int, int]],
    ) -> dict[int, int]:
        """Returns the width of each column — max node width in that column plus COL_PADDING."""
        col_widths: dict[int, int] = {col: self.COL_PADDING for col in col_list}
        for nid, col in depth.items():
            if nid in node_ids and nid in node_sizes:
                w, _ = node_sizes[nid]
                col_widths[col] = max(col_widths[col], w + self.COL_PADDING)
        return col_widths

    @staticmethod
    def _compute_col_x_offsets(col_list: list[int], col_widths: dict[int, int]) -> dict[int, int]:
        """Returns the left-edge X position of each column based on cumulative widths."""
        col_x: dict[int, int] = {}
        x = 0
        for col in col_list:
            col_x[col] = x
            x += col_widths[col]
        return col_x

    @staticmethod
    def _find_components(all_nids: set[NodeId], adj: _NodeAdjacencyMap) -> list[set[NodeId]]:
        """Returns the weakly-connected components of the graph.

        Treats the directed graph as undirected so a node is in the same component
        as everything it either feeds into or receives from.
        """
        undirected: dict[NodeId, set[NodeId]] = {nid: set() for nid in all_nids}
        for src, dsts in adj.downstream.items():
            for dst in dsts:
                undirected[src].add(dst)
                undirected[dst].add(src)

        visited: set[NodeId] = set()
        components: list[set[NodeId]] = []
        for start in all_nids:
            if start in visited:
                continue
            component: set[NodeId] = set()
            queue = collections.deque([start])
            while queue:
                nid = queue.popleft()
                if nid in visited:
                    continue
                visited.add(nid)
                component.add(nid)
                for neighbour in undirected[nid]:
                    if neighbour not in visited:
                        queue.append(neighbour)
            components.append(component)
        return components

    @staticmethod
    def _subset_adj(pass_nids: set[NodeId], adj: _NodeAdjacencyMap) -> _NodeAdjacencyMap:
        """Restricts a global adjacency map to a subset of nodes."""
        downstream = {nid: adj.downstream[nid] & pass_nids for nid in pass_nids}
        incoming: dict[NodeId, int] = {nid: 0 for nid in pass_nids}
        for src in pass_nids:
            for dst in downstream[src]:
                incoming[dst] += 1
        pin_frac = {k: v for k, v in adj.pin_frac.items() if k[0] in pass_nids and k[1] in pass_nids}
        return _NodeAdjacencyMap(downstream, incoming, pin_frac)

    def _run_sugiyama(
        self,
        pass_nids: set[NodeId],
        arrange_ids: set[NodeId],
        node_ids: dict[NodeId, object],
        node_sizes: dict[NodeId, tuple[int, int]],
        adj: _NodeAdjacencyMap,
    ) -> None:
        """Runs the full Sugiyama pipeline on a subset of nodes and moves them.

        When anchor nodes are present in the pass (partial-component case) the
        arranged nodes are translated so that their column grid aligns with the
        anchors' actual X positions. When there are no anchors (full-component
        case) a bounding-box translation restores the subgraph to its original
        canvas area.
        """
        pass_adj = self._subset_adj(pass_nids, adj)
        pass_node_ids = {nid: node_ids[nid] for nid in pass_nids}

        layers = self._assign_layers(pass_nids, pass_adj)
        vgraph = self._insert_dummy_nodes(pass_nids, pass_adj, layers)
        columns: dict[int, list[NodeId]] = collections.defaultdict(list)
        for nid, col in vgraph.depth.items():
            columns[col].append(nid)
        col_list = sorted(columns.keys())
        col_order = {
            col: sorted(
                columns[col],
                key=lambda nid: (self._get_node_pos(node_ids[nid])[1] if nid in node_ids else 0),
            )
            for col in col_list
        }
        layout = _ColumnLayout(col_list, col_order)
        col_widths = self._compute_col_widths(pass_node_ids, layers.depth, layout.col_list, node_sizes)
        col_x = self._compute_col_x_offsets(layout.col_list, col_widths)
        positions = self._assign_coordinates(pass_node_ids, arrange_ids, layers, layout, node_sizes)
        anchor_ids = pass_nids - arrange_ids
        self._translate_to_canvas(arrange_ids, anchor_ids, col_x, layers, positions, node_ids)

    def _translate_to_canvas(
        self,
        arrange_ids: set[NodeId],
        anchor_ids: set[NodeId],
        col_x: dict[int, int],
        layers: _NodeDepthMap,
        positions: dict[NodeId, int],
        node_ids: dict[NodeId, object],
    ) -> None:
        """Writes computed positions back to the canvas with an origin correction.

        With anchors: shifts the grid so its columns align with the anchors' actual X
        positions (Y stays as computed). Without anchors: translates the entire result
        so the bounding-box top-left matches the original canvas position, preserving
        the subgraph's location for Phase 2 to handle.
        """
        if anchor_ids:
            x_offsets = [
                self._get_node_pos(node_ids[nid])[0] - col_x[layers.depth[nid]]
                for nid in anchor_ids if nid in layers.depth
            ]
            offset_x = round(sum(x_offsets) / len(x_offsets)) if x_offsets else 0
            offset_y = 0
        else:
            orig_xs, orig_ys = zip(*(self._get_node_pos(node_ids[nid]) for nid in arrange_ids))
            result_xs = [col_x[layers.depth[nid]] for nid in arrange_ids]
            result_ys = [positions[nid] for nid in arrange_ids]
            offset_x = min(orig_xs) - min(result_xs)
            offset_y = min(orig_ys) - min(result_ys)

        for nid in arrange_ids:
            self._set_node_pos(
                node_ids[nid],
                col_x[layers.depth[nid]] + offset_x,
                positions[nid] + offset_y,
            )

    def _separate_overlapping(
        self,
        arrange_ids: set[NodeId],
        node_ids: dict[NodeId, object],
        node_sizes: dict[NodeId, tuple[int, int]],
    ) -> None:
        """Pushes arranged nodes apart so no two nodes visually overlap after layout.

        Processes nodes in ascending (x, y) order — earlier nodes stay put, later ones
        are nudged down. The occupied set is seeded with all non-arranged (anchor) nodes
        so that arranged nodes also avoid landing on top of unmoved neighbours.
        """
        placed: list[tuple[int, int, int, int]] = [
            (*self._get_node_pos(node_ids[nid]), *node_sizes.get(nid, (0, 0)))
            for nid in node_ids if nid not in arrange_ids
        ]
        ordered = sorted(arrange_ids, key=lambda nid: self._get_node_pos(node_ids[nid]))
        for nid in ordered:
            x, y = self._get_node_pos(node_ids[nid])
            w, h = node_sizes.get(nid, (0, 0))
            while any(
                x < px + pw + self.COL_PADDING and px < x + max(w, 1) + self.COL_PADDING and
                y < py + ph + self.ROW_PADDING and py < y + max(h, 1) + self.ROW_PADDING
                for px, py, pw, ph in placed
            ):
                y += max(h, 1) + self.ROW_PADDING
            self._set_node_pos(node_ids[nid], x, y)
            placed.append((x, y, w, h))

    def _nodes_bbox(
        self,
        nids: set[NodeId],
        node_ids: dict[NodeId, object],
        node_sizes: dict[NodeId, tuple[int, int]],
    ) -> _BBox:
        """Returns the bounding box for a set of nodes, including padding."""
        xs = [self._get_node_pos(node_ids[nid])[0] for nid in nids]
        ys = [self._get_node_pos(node_ids[nid])[1] for nid in nids]
        ws = [node_sizes.get(nid, (0, 0))[0] for nid in nids]
        hs = [node_sizes.get(nid, (0, 0))[1] for nid in nids]
        return _BBox(
            x1=min(xs),
            y1=min(ys),
            x2=max(x + max(w, 1) for x, w in zip(xs, ws)) + self.COL_PADDING,
            y2=max(y + max(h, 1) for y, h in zip(ys, hs)) + self.ROW_PADDING,
        )

    def _layout_subgraphs_in_graph(
        self,
        full_comp_nids: list[set[NodeId]],
        obstacle_bboxes: list[_BBox],
        node_ids: dict[NodeId, object],
        node_sizes: dict[NodeId, tuple[int, int]],
    ) -> None:
        """Phase 2: align fully-selected subgraphs with their nearest neighbour.

        For each component, finds the nearest already-placed bbox and snaps to
        whichever axis requires less movement:
          - X-column alignment: left edge snapped to neighbour's left edge → clean vertical stacks.
          - Y-row alignment: X kept as-is → neighbour is beside us, not above/below.
        After any X snap, a floor-Y push ensures no vertical overlap.
        """
        if not full_comp_nids:
            return

        def _bbox_key(nids):
            bb = self._nodes_bbox(nids, node_ids, node_sizes)
            return bb.y1, bb.x1
        sorted_comps = sorted(full_comp_nids, key=_bbox_key)
        placed: list[_BBox] = list(obstacle_bboxes)

        for nids in sorted_comps:
            bb = self._nodes_bbox(nids, node_ids, node_sizes)
            w = bb.x2 - bb.x1
            h = bb.y2 - bb.y1

            new_x1 = bb.x1
            if placed:
                cx = (bb.x1 + bb.x2) / 2
                cy = (bb.y1 + bb.y2) / 2
                nearest = min(
                    placed,
                    key=lambda b: ((b.x1 + b.x2) / 2 - cx) ** 2 + ((b.y1 + b.y2) / 2 - cy) ** 2,
                )
                # Snap to the axis that requires less movement.
                # X-column: align left edges (move horizontally by nearest.x1 - bb.x1).
                # Y-row: neighbour is beside us — leave X alone, floor_y handles Y.
                if abs(nearest.x1 - bb.x1) <= abs(nearest.y1 - bb.y1):
                    new_x1 = nearest.x1

            new_x2 = new_x1 + w
            floor_y = max(
                (b.y2 for b in placed if b.x1 < new_x2 and b.x2 > new_x1),
                default=bb.y1,
            )
            target_y = max(bb.y1, floor_y)
            dx = new_x1 - bb.x1
            dy = target_y - bb.y1
            if dx or dy:
                for nid in nids:
                    px, py = self._get_node_pos(node_ids[nid])
                    self._set_node_pos(node_ids[nid], px + dx, py + dy)
            placed.append(_BBox(new_x1, target_y, new_x2, target_y + h))

    def _build_adjacency(self, all_nodes: list[Node], all_nids: set[NodeId]) -> _NodeAdjacencyMap:
        """Walks every node's output pins and builds the downstream graph.

        Returns:
            _NodeAdjacencyMap with downstream, incoming, and pin_frac populated.
        """
        downstream: dict[NodeId, set[NodeId]] = {nid: set() for nid in all_nids}
        incoming: dict[NodeId, int] = {nid: 0 for nid in all_nids}
        pin_frac: dict[EdgeKey, float] = {}

        for node in all_nodes:
            src_id = id(node)
            out_pins = self._get_out_pins(node)
            n_pins = len(out_pins)
            for pin_idx, pin in enumerate(out_pins):
                frac = pin_idx / max(1, n_pins - 1)
                for connected_pin in self._get_connected_pins(pin):
                    dst_id = id(self._get_pin_owner(connected_pin))
                    if dst_id in all_nids:
                        if dst_id not in downstream[src_id]:
                            downstream[src_id].add(dst_id)
                            incoming[dst_id] += 1
                        key = (src_id, dst_id)
                        if key not in pin_frac or frac < pin_frac[key]:
                            pin_frac[key] = frac

        return _NodeAdjacencyMap(downstream, incoming, pin_frac)

    @staticmethod
    def _assign_layers(all_nids: set[NodeId], adj: _NodeAdjacencyMap) -> _NodeDepthMap:
        """Assigns each node a column depth via longest-path topological sort.

        Pure source nodes are pulled one column left of their earliest consumer
        so variable getters don't sit unnecessarily far from the nodes they feed.
        """
        depth: dict[NodeId, int] = {nid: 0 for nid in all_nids}
        remaining = dict(adj.incoming)
        queue = collections.deque(nid for nid, count in remaining.items() if count == 0)
        while queue:
            nid = queue.popleft()
            for dst_id in adj.downstream[nid]:
                depth[dst_id] = max(depth[dst_id], depth[nid] + 1)
                remaining[dst_id] -= 1
                if remaining[dst_id] == 0:
                    queue.append(dst_id)

        for nid in all_nids:
            if adj.incoming[nid] == 0 and adj.downstream[nid]:
                depth[nid] = max(0, min(depth[dst] for dst in adj.downstream[nid]) - 1)

        upstream: dict[NodeId, set[NodeId]] = {nid: set() for nid in all_nids}
        for src, dsts in adj.downstream.items():
            for dst in dsts:
                upstream[dst].add(src)

        return _NodeDepthMap(depth, upstream)

    @staticmethod
    def _insert_dummy_nodes(all_nids: set[NodeId], adj: _NodeAdjacencyMap, layers: _NodeDepthMap) -> _VirtualGraph:
        """Replaces edges that span multiple layers with chains of virtual dummy nodes.

        Dummy nodes are negative integers that never exist in the real graph.
        They allow the crossing minimiser to see and resolve tangles at every
        intermediate layer, not just at the endpoints of long edges.
        """
        next_dummy: list[int] = [-1]
        v_down: dict[NodeId, set[NodeId]] = {nid: set(adj.downstream[nid]) for nid in all_nids}
        v_up: dict[NodeId, set[NodeId]] = {nid: set(layers.upstream[nid]) for nid in all_nids}
        v_depth: dict[NodeId, int] = dict(layers.depth)
        v_frac: dict[EdgeKey, float] = dict(adj.pin_frac)

        for src in list(all_nids):
            for dst in list(adj.downstream[src]):
                span = layers.depth[dst] - layers.depth[src]
                if span <= 1:
                    continue
                v_down[src].discard(dst)
                v_up[dst].discard(src)
                frac = v_frac.get((src, dst), 0.5)
                prev = src
                for layer in range(layers.depth[src] + 1, layers.depth[dst]):
                    dummy = next_dummy[0]
                    next_dummy[0] -= 1
                    v_down[dummy] = set()
                    v_up[dummy] = {prev}
                    v_depth[dummy] = layer
                    v_down[prev].add(dummy)
                    v_frac[(prev, dummy)] = frac
                    prev = dummy
                v_down[prev].add(dst)
                v_up.setdefault(dst, set()).add(prev)
                v_frac[(prev, dst)] = frac

        return _VirtualGraph(v_down, v_up, v_depth, v_frac)

    def _assign_coordinates(
        self,
        node_ids: dict[NodeId, object],
        arrange_ids: set[NodeId],
        layers: _NodeDepthMap,
        layout: _ColumnLayout,
        node_sizes: dict[NodeId, tuple[int, int]],
    ) -> dict[NodeId, int]:
        """Assigns a Y coordinate to each real node.

        Each node tries to align with the average Y of its upstream neighbours.
        Fixed (anchor) nodes lock their current Y first; arranged nodes only push
        down to avoid collisions with them. Row spacing is based on each node's
        own height plus ROW_PADDING.
        """
        positions: dict[NodeId, int] = {}

        # In partial-component mode the anchors establish the vertical frame of
        # reference.  Source nodes (no upstream connections) fall back to next_y
        # when choosing their preferred Y, so starting next_y at 0 would place
        # them far below any anchors that live at a large Y.  Using the minimum
        # anchor Y as the floor keeps isolated arranged nodes in the same vertical
        # region as the rest of the component.
        anchor_ys = [
            self._get_node_pos(node_ids[nid])[1]
            for nid in node_ids if nid not in arrange_ids
        ]
        base_y = min(anchor_ys) if anchor_ys else 0

        for col in layout.col_list:
            real_order = [nid for nid in layout.col_order[col] if nid in node_ids]
            fixed_ys: list[int] = []
            for nid in real_order:
                if nid not in arrange_ids:
                    y = self._get_node_pos(node_ids[nid])[1]
                    positions[nid] = y
                    fixed_ys.append(y)

            next_y = base_y
            for nid in real_order:
                if nid not in arrange_ids:
                    continue
                _, h = node_sizes.get(nid, (0, 0))
                row_spacing = h + self.ROW_PADDING
                ups = [positions[s] for s in layers.upstream[nid] if s in positions]
                preferred_y = round(sum(ups) / len(ups)) if ups else next_y
                y = max(next_y, preferred_y)
                while any(abs(y - fy) < row_spacing for fy in fixed_ys):
                    y += row_spacing
                positions[nid] = y
                next_y = y + row_spacing

        return positions
