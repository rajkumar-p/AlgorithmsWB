class Graph:
    def __init__(self, name):
        self._name = name
        self._vertices = {}
        self._adj_list = {}

    def add_vertex(self, v_id):
        v = Vertex(v_id)
        self._vertices[v_id] = v
        self._adj_list[v] = []

    def add_edge(self, v1_id, v2_id):
        v1 = self._vertices[v1_id]
        v2 = self._vertices[v2_id]
        if v1 == None or v2 == None:
            return
        self._adj_list[v1].append(v2)

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


if __name__ == "__main__":
    g = Graph("DG 1")

    g.add_vertex(1)
    g.add_vertex(2)
    g.add_vertex(3)
    g.add_vertex(4)
    g.add_vertex(5)

    g.add_edge(1, 2)
    g.add_edge(1, 5)

    g.add_edge(2, 1)
    g.add_edge(2, 3)
    g.add_edge(2, 4)
    g.add_edge(2, 5)

    g.add_edge(3, 2)
    g.add_edge(3, 4)

    g.add_edge(4, 2)
    g.add_edge(4, 3)
    g.add_edge(4, 5)

    g.add_edge(5, 1)
    g.add_edge(5, 2)
    g.add_edge(5, 4)

    g.print_graph()
    g.print_adj_matrix()

    ug = UndirectedGraph("UG 1")
    ug.add_vertex(1)
    ug.add_vertex(2)
    ug.add_vertex(3)
    ug.add_vertex(4)
    ug.add_vertex(5)

    ug.add_edge(1, 2)
    ug.add_edge(1, 5)

    ug.add_edge(2, 3)
    ug.add_edge(2, 4)
    ug.add_edge(2, 5)

    ug.add_edge(3, 4)

    ug.add_edge(4, 5)

    ug.print_graph()
    ug.print_adj_matrix()

