#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <list>
using namespace std;

class Graph
{
private:
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int wt, int u, int v)
    {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void PrintAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (auto neigh : l[i])
            {
                cout << "(" << neigh.first << ", " << neigh.second << ") ";
            }
            cout << endl;
        }
    }

    vector<int> DijkstraAlgorithm(int source)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st; // {distance, node}

        dist[source] = 0;
        st.insert({0, source});

        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());

            int dis = top.first;
            int node = top.second;

            for (auto i : l[node])
            {
                int adjNode = i.first;
                int edgeWeight = i.second;

                if (dis + edgeWeight < dist[adjNode])
                {
                    // remove old value if exists
                    if (dist[adjNode] != INT_MAX)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    void DijkstraAlgorithmWrapper(int source)
    {
        vector<int> dist = DijkstraAlgorithm(source);

        for (int i = 0; i < V; i++)
        {
            cout << "Distance from " << source << " to " << i << " = " << dist[i] << endl;
        }
    }
};

int main()
{
    int V = 6;
    Graph g(V);

    g.addEdge(4, 0, 1);
    g.addEdge(4, 0, 2);
    g.addEdge(2, 1, 2);
    g.addEdge(3, 2, 3);
    g.addEdge(6, 2, 5);
    g.addEdge(1, 2, 4);
    g.addEdge(3, 4, 5);
    g.addEdge(2, 3, 5);

    cout << "Adjacency List:\n";
    g.PrintAdjList();

    cout << "\nDijkstra from source 0:\n";
    g.DijkstraAlgorithmWrapper(0);

    return 0;
}