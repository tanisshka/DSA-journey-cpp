from collections import deque

class Graph:

    # constructor
    def __init__(self, V):

        self.V = V

        # adjacency list
        self.l = [[] for _ in range(V)]


    # Add Edge
    def add_edge(self, u, v):

        self.l[u].append(v)

        self.l[v].append(u)


    # BFS Traversal
    def bfs(self, vtx):

        Q = deque()

        vis = [False] * self.V


        vis[vtx] = True

        Q.append(vtx)

        print("Visited Vertex:", vtx)


        while Q:

            u = Q.popleft()


            for neigh in self.l[u]:

                if not vis[neigh]:

                    vis[neigh] = True

                    Q.append(neigh)

                    print("Visited Vertex:", neigh)



# main
if __name__ == '__main__':

    g = Graph(5)

    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 3)
    g.add_edge(2, 4)

    g.bfs(0)