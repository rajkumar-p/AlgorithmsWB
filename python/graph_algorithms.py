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

    def print_adj_matrix(self):
        print_header("Graph Matrix: {}".format(self._name))
        matrix = []
        for key in self._adj_list.keys():
            l = [0 for _ in range(len(self._adj_list))]
            for v in self._adj_list[key]:
                l[v.id() - 1] = 1
            matrix.append(l)
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


def get_universal_sink_of(graph):
    return None

def test_get_universal_sink_of(graph):
    print_header("Testing get_universal_sink_of()")



if __name__ == "__main__":
    g = Graph("DG 1")

    g.add_vertices([1, 2, 3, 4, 5, 6])
    g.add_edges([(1, 2), (1, 4), (2, 5),
                (3, 5), (3, 6), (4, 2), (5, 4),
                (6, 6)])
    g.print_graph()
    g.print_adj_matrix()
