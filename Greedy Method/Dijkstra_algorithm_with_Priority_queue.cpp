#include <iostream>
#include <queue>
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

    vector<int> DijkstraAlgorithm(int source, vector<int> &dist)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});
        dist[source] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int dis = top.first;
            int node = top.second;

            // Skip outdated entries
            if (dis > dist[node])
                continue;

            for (auto i : l[node])
            {
                int adjNode = i.first;
                int edgeWeight = i.second;

                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    void DijkstraAlgorithmWrapper(int source)
    {
        vector<int> dist(V, INT_MAX);
        dist = DijkstraAlgorithm(source, dist);

        // optional: print result
        for (int i = 0; i < V; i++)
        {
            cout << "Distance from " << source << " to " << i << " = " << dist[i] << endl;
        }
    }
};

int main()
{
    // number of vertices
    int V = 6;
    Graph g(V);

    // add edges: (weight, u, v)
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