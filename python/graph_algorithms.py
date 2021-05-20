import enum
import queue

MAX_DIST = 1000000000

class Graph:
    def __init__(self, name, adj_list=None):
        self._name = name
        self._vertices = {}
        self._adj_list = {}
        if adj_list is not None:
            for v in adj_list.keys():
                self._vertices[v.id()] = v
            self._adj_list = adj_list

    def set_name(self, new_name):
        self._name = new_name

    def get_vertex(self, v_id):
        return self._vertices.get(v_id, None)

    def add_vertex(self, v_id):
        v = Vertex(v_id)
        self._vertices[v_id] = v
        self._adj_list[v] = []

    def add_vertices(self, v_ids):
        for v_id in v_ids:
            self.add_vertex(v_id)

    def add_edge(self, v1_id, v2_id):
        v1 = self._vertices[v1_id]
        v2 = self._vertices[v2_id]
        if v1 is None or v2 is None:
            return
        self._adj_list[v1].append(v2)

    def add_edges(self, v1_v2_id_pairs):
        for v1_id, v2_id in v1_v2_id_pairs:
            self.add_edge(v1_id, v2_id)

    def get_vertices_count(self):
        return len(self._vertices)

    def get_vertices_ids(self):
        ids = []
        for v_id in self._vertices:
            ids.append(v_id)
        return ids

    def get_vertices(self):
        vertices = []
        for v_id in self._vertices:
            v = self.get_vertex(v_id)
            vertices.append(v)
        return vertices

    def get_edges(self):
        edges = []
        for v in self.get_adj_list():
            adj_vertices = self.get_adj_vertices_of(v)
            for av in adj_vertices:
                edges.append(Edge(v, av))
        return edges

    def get_adj_vertices_of(self, vertex):
        return self._adj_list.get(vertex, None)

    def get_adj_list(self):
        return self._adj_list

    def get_transposed_list(self):
        new_adj_list = {}
        for key in self._adj_list.keys():
            new_adj_list[key] = []

        for key in self._adj_list.keys():
            for v in self._adj_list[key]:
                new_adj_list[v].append(key)

        return new_adj_list

    def get_adj_matrix(self):
        matrix = []
        for key in self._adj_list.keys():
            l = [0 for _ in range(len(self._adj_list))]
            for v in self._adj_list[key]:
                l[v.id() - 1] = 1
            matrix.append(l)

        return matrix

    def print_adj_matrix(self):
        print_header("Graph Matrix: {}".format(self._name))
        matrix = self.get_adj_matrix()
        for entry in matrix:
            print(entry)
        print()

    def print_graph(self):
        print_header("Graph: {}".format(self._name))
        for key in self._adj_list.keys():
            print("Vertex: {} has {}-out edges".format(key.id(), len(self._adj_list[key])))
            edges = []
            for v in self._adj_list[key]:
                edges.append("({}, {})".format(key.id(), v.id()))
            print(" >{}".format("|".join(edges)))
        print()


class UndirectedGraph(Graph):
    def __init__(self, name):
        super().__init__(name)

    def add_edge(self, v1_id, v2_id):
        super().add_edge(v1_id, v2_id)
        super().add_edge(v2_id, v1_id)


# Enum to represent vertex color
class Color(enum.Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


class Vertex:
    def __init__(self, id):
        self._id = id
        self._dist = None
        self._parent = None
        self._color = None
        self._start = None
        self._end = None

    def __hash__(self):
        return hash(self._id)

    def id(self):
        return self._id

    def dist(self):
        return self._dist

    def parent(self):
        return self._parent

    def color(self):
        return self._color

    def start(self):
        return self._start

    def end(self):
        return self._end


class Edge:
    def __init__(self, fr, to):
        self._fr = fr
        self._to = to

    def fr(self):
        return self._fr

    def fr_str(self):
        return self._fr.id()

    def to(self):
        return self._to

    def to_str(self):
        return self._to.id()


# Enum to represent edge type
class EdgeType(enum.Enum):
    TREE_EDGE = 0
    BACK_EDGE = 1
    FORWARD_EDGE = 2
    CROSS_EDGE = 3


class EdgeClassification:
    def __init__(self, fr, to, edge_type):
        self._fr = fr
        self._to = to
        self._edge_type = edge_type

    def fr(self):
        return self._fr

    def fr_str(self):
        return self._fr.id()

    def to(self):
        return self._to

    def to_str(self):
        return self._to.id()

    def edge_type(self):
        if self._edge_type == EdgeType.TREE_EDGE:
            return "Tree Edge"
        elif self._edge_type == EdgeType.BACK_EDGE:
            return "Back Edge"
        else:
            return "Forward Edge"


def print_header(s, filler="%"):
    header_str = "{0}-----{1}-----{0}".format(filler, s)
    top_str = filler * len(header_str)
    bottom_str = filler * len(header_str)
    print(top_str)
    print(header_str)
    print(bottom_str)


def print_sub_header(s):
    sub_header = ":::::{}:::::".format(s)
    print(sub_header)

def print_sub_footer(s):
    sub_footer = "--{}--".format(s)
    print(sub_footer)


def get_universal_sink(graph):
    def confirm_vertex_as_sink(matrix, n_vertices, v_id):
        for j in range(n_vertices):
            if matrix[v_id][j] == 1:
                return False
            if v_id != j and matrix[j][v_id] != 1:
                return False

        return True

    i = j = 0
    matrix = graph.get_adj_matrix()
    n_vertices = graph.get_vertices_count()
    while i < n_vertices and j < n_vertices:
        if matrix[i][j] == 0:
            j = j + 1
        else:
            i = i + 1

    if i == n_vertices:
        return None

    if not confirm_vertex_as_sink(matrix, n_vertices, i):
        return None

    return graph.get_vertex(i + 1)

def test_get_universal_sink():
    print_header("Testing get_universal_sink()")
    print_sub_header("Test 1")
    g = Graph("dg1")
    g.add_vertices([1, 2, 3, 4, 5])
    g.add_edges([(1, 2), (1, 3), (2, 4), (2, 3), (4, 3), (5, 3)])
    expected_result = g.get_vertex(3)
    sink = get_universal_sink(g)
    assert(sink is not None)
    assert(sink == expected_result)
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("dg2")
    g.add_vertices([1, 2, 3, 4, 5])
    g.add_edges([(1, 2), (1, 3), (1, 5), (2, 4), (2, 3), (2, 5), (4, 3), (4, 5)])
    expected_result = None
    sink = get_universal_sink(g)
    assert(sink is None)
    assert(sink == expected_result)
    print_sub_footer("Test 2 - Success")

    print_sub_header("Test 3")
    g = Graph("dg3")
    g.add_vertices([1, 2, 3, 4, 5, 6])
    g.add_edges([(1, 2), (3, 2), (4, 2), (5, 2), (6, 2)])
    expected_result = g.get_vertex(2)
    sink = get_universal_sink(g)
    assert(sink is not None)
    assert(sink == expected_result)
    print_sub_footer("Test 3 - Success")

    print_sub_header("Test 4")
    g = Graph("dg4")
    g.add_vertices([1, 2, 3, 4, 5])
    g.add_edges([(1, 2), (1, 3), (1, 4), (1, 5), (2, 4), (2, 5), (3, 2), (3, 4), (3, 5), (5, 4)])
    expected_result = g.get_vertex(4)
    sink = get_universal_sink(g)
    assert(sink is not None)
    assert(sink == expected_result)
    print_sub_footer("Test 4 - Success")


def breadth_first_search(graph, source_vertex):
    # Init all vertices
    for v in graph.get_vertices():
        v._parent = None
        v._dist = MAX_DIST
        v._color = Color.WHITE

    q = queue.Queue()

    # Init source before putting in q
    source_vertex._parent = None
    source_vertex._dist = 0
    source_vertex._color = Color.GRAY

    q.put(source_vertex)

    # Main loop of the algorithm
    while not q.empty():
        v = q.get_nowait()
        for av in graph.get_adj_vertices_of(v):
            if av.color() == Color.WHITE:
                av._parent = v
                av._dist = v.dist() + 1
                av._color = Color.GRAY

                q.put(av)

        v._color = Color.BLACK

    return graph


def test_breadth_first_search():
    print_header("Testing breadth_first_search()")
    print_sub_header("Test 1")
    ug = UndirectedGraph("ug1")
    ug.add_vertices(["S", "R", "V", "W", "T", "X", "U", "Y"])
    ug.add_edges([("S", "R"), ("S", "W"), ("R", "V"), ("W", "T"),
        ("W", "X"), ("T", "U"), ("T", "X"), ("X", "U"), ("X", "Y"), ("U", "Y")])
    expected_result = {"S": 0, "R": 1, "W": 1, "V": 2, "T": 2, "X": 2, "U": 3, "Y": 3}
    bfs_tree = breadth_first_search(ug, ug.get_vertex("S"))
    for v in bfs_tree.get_vertices():
        assert(v.dist() == expected_result[v.id()])
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("g1")
    g.add_vertices([0, 1, 2, 3])
    g.add_edges([(0, 1), (0, 2), (2, 0), (2, 3), (3, 3), (1, 2)])
    expected_result = {0: 1, 1: 2, 2: 0, 3: 1}
    bfs_tree = breadth_first_search(g, g.get_vertex(2))
    for v in bfs_tree.get_vertices():
        assert(v.dist() == expected_result[v.id()])
    print_sub_footer("Test 2 - Success")

    print_sub_header("Test 3")
    ug = UndirectedGraph("ug2")
    ug.add_vertices(["A", "B", "C", "D", "E", "F", "G", "H", "S"])
    ug.add_edges([("A", "B"), ("A", "S"), ("S", "C"), ("S", "G"), ("C", "D"),
        ("C", "F"), ("G", "F"), ("G", "H"), ("C", "E"), ("E", "H")])
    expected_result = {"A": 2, "B": 3, "C": 0, "D": 1, "E": 1,
            "F": 1, "G": 2, "H": 2, "S": 1}
    bfs_tree = breadth_first_search(ug, ug.get_vertex("C"))
    for v in bfs_tree.get_vertices():
        assert(v.dist() == expected_result[v.id()])
    print_sub_footer("Test 3 - Success")


class Incr:
    def __init__(self, start):
        self._counter = start

    def get_counter(self):
        ret = self._counter
        self._counter = self._counter + 1
        return ret


def depth_first_search(graph):
    for v in graph.get_vertices():
        v._color = Color.WHITE
        v._dist = MAX_DIST

    incr = Incr(0)
    for v in graph.get_vertices():
        if v.color() == Color.WHITE:
            v._dist = 0
            v._color = Color.GRAY
            v._start = incr.get_counter()
            dfs(graph, v, incr)

    return graph


def dfs(graph, v, incr):
    for av in graph.get_adj_vertices_of(v):
        if av.color() == Color.WHITE:
            av._dist = v.dist() + 1
            av._color = Color.GRAY
            av._parent = v
            av._start = incr.get_counter()
            dfs(graph, av, incr)

    v._color = Color.BLACK
    v._end = incr.get_counter()


def depth_first_search2(graph):
    for v in graph.get_vertices():
        v._color = Color.WHITE
        v._dist = MAX_DIST
        v._parent = None

    incr = Incr(0)
    for v in graph.get_vertices():
        if v.color() == Color.WHITE:
            v._dist = 0
            dfs2(graph, v, incr)

    return graph


def dfs2(graph, v, incr):
    v._color = Color.GRAY
    stk = [v]
    while len(stk) != 0:
        tv = stk[-1]
        if tv.color() == Color.BLACK:
            tv._end = incr.get_counter()
            stk.pop()
        else:
            tv._start = incr.get_counter()
            for av in graph.get_adj_vertices_of(tv):
                if av.color() == Color.WHITE:
                    av._color = Color.GRAY
                    av._dist = tv.dist() + 1
                    av._parent = tv
                    stk.append(av)

            tv._color = Color.BLACK


def topological_sort(graph):
    for v in graph.get_vertices():
        v._color = Color.WHITE
        v._start = v._end = None
        v._parent = None

    incr = Incr(0)
    order_list = []
    for v in graph.get_vertices():
        if v.color() == Color.WHITE:
            topo_sort(graph, v, incr, order_list)
    return order_list


def topo_sort(graph, v, incr, order_list):
    v._color = Color.GRAY
    v._start = incr.get_counter()
    stk = [v]
    while not len(stk) == 0:
        tv = stk[-1]
        if tv.color() == Color.BLACK:
            tv.end = incr.get_counter()
            order_list.append(tv)
            stk.pop()
        else:
            for av in graph.get_adj_vertices_of(tv):
                if av.color() == Color.WHITE:
                    av._color = Color.GRAY
                    av._parent = tv
                    av._start = incr.get_counter()
                    stk.append(av)
            tv._color = Color.BLACK


def topological_sort2(graph):
    in_degrees = {}
    for v in graph.get_vertices():
        in_degrees[v] = 0
    edges = graph.get_edges()
    no_edges = len(edges)
    for edge in edges:
        in_degrees[edge.to()] = in_degrees[edge.to()] + 1

    q = queue.Queue()
    for v in in_degrees:
        if in_degrees[v] == 0:
            q.put(v)

    order_list = []
    while not q.empty():
        v = q.get_nowait()
        order_list.append(v.id())
        for av in graph.get_adj_vertices_of(v):
            no_edges = no_edges - 1
            in_degrees[av] = in_degrees[av] - 1
            if in_degrees[av] == 0:
                q.put(av)

    if no_edges != 0:
        return []

    return order_list


def test_depth_first_search():
    print_header("Testing depth_first_search()")
    print_sub_header("Test 1")
    ug = UndirectedGraph("ug1")
    ug.add_vertices(["S", "R", "V", "W", "T", "X", "U", "Y"])
    ug.add_edges([("S", "R"), ("S", "W"), ("R", "V"), ("W", "T"),
                  ("W", "X"), ("T", "U"), ("T", "X"), ("X", "U"), ("X", "Y"), ("U", "Y")])
    _ = depth_first_search(ug)
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("g1")
    g.add_vertices([0, 1, 2, 3])
    g.add_edges([(0, 1), (0, 2), (2, 0), (2, 3), (3, 3), (1, 2)])
    _ = depth_first_search(g)
    print_sub_footer("Test 2 - Success")

    print_sub_header("Test 3")
    ug = UndirectedGraph("ug2")
    ug.add_vertices(["A", "B", "C", "D", "E", "F", "G", "H", "S"])
    ug.add_edges([("A", "B"), ("A", "S"), ("S", "C"), ("S", "G"), ("C", "D"),
                  ("C", "F"), ("G", "F"), ("G", "H"), ("C", "E"), ("E", "H")])
    _ = depth_first_search(ug)
    print_sub_footer("Test 3 - Success")


def test_depth_first_search2():
    print_header("Testing depth_first_search2()")
    print_sub_header("Test 1")
    ug = UndirectedGraph("ug1")
    ug.add_vertices(["S", "R", "V", "W", "T", "X", "U", "Y"])
    ug.add_edges([("S", "R"), ("S", "W"), ("R", "V"), ("W", "T"),
                  ("W", "X"), ("T", "U"), ("T", "X"), ("X", "U"), ("X", "Y"), ("U", "Y")])
    _ = depth_first_search2(ug)
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("g1")
    g.add_vertices([0, 1, 2, 3])
    g.add_edges([(0, 1), (0, 2), (2, 0), (2, 3), (3, 3), (1, 2)])
    _ = depth_first_search2(g)
    print_sub_footer("Test 2 - Success")

    print_sub_header("Test 3")
    ug = UndirectedGraph("ug2")
    ug.add_vertices(["A", "B", "C", "D", "E", "F", "G", "H", "S"])
    ug.add_edges([("A", "B"), ("A", "S"), ("S", "C"), ("S", "G"), ("C", "D"),
                  ("C", "F"), ("G", "F"), ("G", "H"), ("C", "E"), ("E", "H")])
    _ = depth_first_search2(ug)
    print_sub_footer("Test 3 - Success")


def test_topological_sort():
    print_header("Testing topological_sort()")
    print_sub_header("Test 1")
    g = Graph("CLOTHES")
    g.add_vertices(["undershorts", "pants", "belt", "shirt", "tie", "jacket",
                    "socks", "shoes", "watch"])
    g.add_edges([("undershorts", "pants"), ("undershorts", "shoes"),
                 ("pants", "belt"), ("pants", "shoes"),
                 ("belt", "jacket"),
                 ("shirt", "belt"), ("shirt", "tie"),
                 ("tie", "jacket"),
                 ("socks", "shoes")])
    _ = topological_sort(g)
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("DEPS")
    g.add_vertices([5, 11, 2, 7, 8, 9, 3, 10])
    g.add_edges([(5, 11), (11, 2), (7, 11), (7, 8), (8, 9),
                 (11, 9), (11, 10), (3, 8), (3, 10)])
    _ = topological_sort(g)
    print_sub_footer("Test 2 - Success")


def test_topological_sort2():
    print_header("Testing topological_sort2()")
    print_sub_header("Test 1")
    g = Graph("CLOTHES")
    g.add_vertices(["undershorts", "pants", "belt", "shirt", "tie", "jacket",
                    "socks", "shoes", "watch"])
    g.add_edges([("undershorts", "pants"), ("undershorts", "shoes"),
                 ("pants", "belt"), ("pants", "shoes"),
                 ("belt", "jacket"),
                 ("shirt", "belt"), ("shirt", "tie"),
                 ("tie", "jacket"),
                 ("socks", "shoes")])
    _ = topological_sort2(g)
    print_sub_footer("Test 1 - Success")

    print_sub_header("Test 2")
    g = Graph("DEPS")
    g.add_vertices([5, 11, 2, 7, 8, 9, 3, 10])
    g.add_edges([(5, 11), (11, 2), (7, 11), (7, 8), (8, 9),
                 (11, 9), (11, 10), (3, 8), (3, 10)])
    _ = topological_sort2(g)
    print_sub_footer("Test 2 - Success")


if __name__ == "__main__":
    test_get_universal_sink()
    print()
    test_breadth_first_search()
    print()
    test_depth_first_search()
    print()
    test_depth_first_search2()
    print()
    test_topological_sort()
    print()
    test_topological_sort2()
    print()