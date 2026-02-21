#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Graph{

    int V;
    list<int> *l;

public:

    // Constructor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    // Create graph
    void AddEdge(int u, int v){

        l[u].push_back(v);
        l[v].push_back(u);

    }

    // BFS Traversal
    void BFS(int vtx){

        queue<int> Q;

        vector<bool> vis(V, false);

        vis[vtx] = true;

        Q.push(vtx);

        cout<<"Visited Vertex: "<<vtx<<endl;

        while(!Q.empty()){

            int u = Q.front();

            Q.pop();

            for(int neigh : l[u]){

                if(!vis[neigh]){

                    vis[neigh] = true;

                    Q.push(neigh);

                    cout<<"Visited Vertex: "<<neigh<<endl;

                }
            }
        }
    }
};


int main(){

    Graph g(5);

    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,3);
    g.AddEdge(2,4);

    g.BFS(0);

    return 0;
}