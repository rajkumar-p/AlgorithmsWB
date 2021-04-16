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

    def add_edges(self, v1_v2_id_pairs):
        for v1_id, v2_id in v1_v2_id_pairs:
            self.add_edge(v1_id, v2_id)

    def add_edge(self, v1_id, v2_id):
        v1 = self._vertices[v1_id]
        v2 = self._vertices[v2_id]
        if v1 == None or v2 == None:
            return
        self._adj_list[v1].append(v2)

    def get_vertices_count(self):
        return len(self._vertices)

    def get_trasposed_list(self):
        new_adj_list = {}
        for key in self._adj_list.keys():
            new_adj_list[key] = []

        for key in self._adj_list.keys():
            for v in self._adj_list[key]:
                new_adj_list[v].append(key)

        return new_adj_list

    def print_graph(self):
        print_header("Graph: {}".format(self._name))
        for key in self._adj_list.keys():
            print("Vertex: {} has {}-out edges".format(key.id(), len(self._adj_list[key])))
            edges = []
            for v in self._adj_list[key]:
                edges.append("({}, {})".format(key.id(), v.id()))
            print(" >{}".format("|".join(edges)))
        print()

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


class UndirectedGraph(Graph):
    def __init__(self, name):
        super().__init__(name)

    def add_edge(self, v1_id, v2_id):
        super().add_edge(v1_id, v2_id)
        super().add_edge(v2_id, v1_id)


class Vertex:
    def __init__(self, id):
        self._id = id

    def __hash__(self):
        return hash(self._id)

    def id(self):
        return self._id


def print_header(s, filler="%"):
    header_str = "{0}-----{1}-----{0}".format(filler, s)
    top_str = filler * len(header_str)
    bottom_str = filler * len(header_str)
    print(top_str)
    print(header_str)
    print(bottom_str)


def print_sub_header(s):
    sub_header = "  >>>>>{}<<<<<".format(s)
    print(sub_header)


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

    print_sub_header("Test 2")
    g = Graph("dg2")
    g.add_vertices([1, 2, 3, 4, 5])
    g.add_edges([(1, 2), (1, 3), (1, 5), (2, 4), (2, 3), (2, 5), (4, 3), (4, 5)])
    expected_result = None
    sink = get_universal_sink(g)
    assert(sink is None)
    assert(sink == expected_result)

    print_sub_header("Test 3")
    g = Graph("dg3")
    g.add_vertices([1, 2, 3, 4, 5, 6])
    g.add_edges([(1, 2), (3, 2), (4, 2), (5, 2), (6, 2)])
    expected_result = g.get_vertex(2)
    sink = get_universal_sink(g)
    assert(sink is not None)
    assert(sink == expected_result)


if __name__ == "__main__":
    test_get_universal_sink()
