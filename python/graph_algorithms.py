class Vertex:
    def __init__(self, id):
        self._id = id

    def __hash__(self):
        return hash(self._id)

    def id(self):
        return self._id


def print_graph(adj_list):
    for key in adj_list.keys():
        print("Vertex: {} has {}-out edges".format(key.id(), len(adj_list[key])))
        edges = []
        for v in adj_list[key]:
            edges.append("({}, {})".format(key.id(), v.id()))
        print(" >{}".format("|".join(edges)))


def print_out_degrees(adj_list):
    for key in adj_list.keys():
        print("Vertex{} has out degree of: {}".format(key.id(), len(adj_list[key])))


def print_adj_matrix(adj_list):
    matrix = []
    for key in adj_list.keys():
        l = [0 for _ in range(len(adj_list))]
        for v in adj_list[key]:
            l[v.id() - 1] = 1
        matrix.append(l)
    for entry in matrix:
        print(entry)


if __name__ == "__main__":
    v1 = Vertex(1)
    v2 = Vertex(2)
    v3 = Vertex(3)
    v4 = Vertex(4)
    v5 = Vertex(5)

    adj_list = {}
    adj_list[v1] = [v2, v5]
    adj_list[v2] = [v1, v3, v4, v5]
    adj_list[v3] = [v2, v4]
    adj_list[v4] = [v2, v3, v5]
    adj_list[v5] = [v1, v2, v4]
