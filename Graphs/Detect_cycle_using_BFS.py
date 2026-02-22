from collections import deque


class Graph:

    def __init__(self, V):

        self.V = V
        self.l = [[] for _ in range(V)]


    def addEdge(self, u, v):

        self.l[u].append(v)
        self.l[v].append(u)


    def DetectCycle(self, src, vis):

        q = deque()

        vis[src] = True

        q.append((src, -1))


        while q:

            node, parent = q.popleft()


            for adjNode in self.l[node]:

                if not vis[adjNode]:

                    vis[adjNode] = True

                    q.append((adjNode, node))


                elif adjNode != parent:

                    return True


        return False


    def isCycle(self):

        vis = [False] * self.V


        for i in range(self.V):

            if not vis[i]:

                if self.DetectCycle(i, vis):

                    return True


        return False



# main function

g = Graph(5)

g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 3)
g.addEdge(3, 4)
g.addEdge(4, 1)   # cycle


if g.isCycle():

    print("Cycle exists")

else:

    print("No cycle")