#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{

    int V;
    list<int> *l;

    bool DFS(int node, int parent, vector<bool> &vis);

public:

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v);

    bool isCycle();
};



void Graph::addEdge(int u, int v)
{
    l[u].push_back(v);
    l[v].push_back(u);
}



bool Graph::DFS(int node, int parent, vector<bool> &vis)
{

    vis[node] = true;

    for(auto adjNode : l[node])
    {

        if(!vis[adjNode])
        {

            if(DFS(adjNode, node, vis))
            {
                return true;
            }

        }

        else if(adjNode != parent)
        {

            return true;
        }

    }

    return false;

}



bool Graph::isCycle()
{

    vector<bool> vis(V, false);

    for(int i = 0; i < V; i++)
    {

        if(!vis[i])
        {

            if(DFS(i, -1, vis))
            {

                return true;
            }

        }

    }

    return false;

}



int main()
{

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1); // cycle


    if(g.isCycle())
    {

        cout<<"Cycle exists"<<endl;

    }

    else
    {

        cout<<"No cycle"<<endl;

    }

}