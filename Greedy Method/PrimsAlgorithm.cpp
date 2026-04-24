#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<functional>
using namespace std;

class Graph{
private:
    int V;
    list<pair<int,int>> *l;

public:
    // Constructor
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>>[V];
    }

    // add edge
    void addEdge(int wt,int u,int v){
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});
    }

    // print adjacency list
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

  
    int PrimsAlgorithm(int start){
        vector<bool> vis(V,false);

        //(weight,node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});
        int sum = 0;

        while(!pq.empty()){
            auto top = pq.top();   
            pq.pop();

            int wt = top.first;   
            int node = top.second;

            if(vis[node]) continue;

            vis[node] = true;
            sum += wt;

            for(auto i : l[node]){
                int neigh = i.first;
                int neigh_wt = i.second;

                if(!vis[neigh]){
                    pq.push({neigh_wt, neigh}); 
                }
            }
        }
        return sum;
    }
};

int main() {
    Graph g(5);

    // add edges (weight, u, v)
    g.addEdge(2, 0, 1);
    g.addEdge(1, 0, 2);
    g.addEdge(1, 1, 2);
    g.addEdge(2, 2, 4);
    g.addEdge(2, 2, 3);
    g.addEdge(1, 4, 3);

    g.PrintAdjList();

    // run Prim's
    cout << "MST Weight: " << g.PrimsAlgorithm(0);

    return 0;
}