#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{

    int V;
    list<int> *l;

public:

    Graph(int V){

        this->V = V;

        l = new list<int>[V];

    }


    void addEdge(int u,int v){

        l[u].push_back(v);

        l[v].push_back(u);

    }


    void DFSHelper(int vtx, vector<bool> &vis){

        cout<<"Visited Vertex: "<<vtx<<endl;

        vis[vtx] = true;


        for(int neigh : l[vtx]){

            if(!vis[neigh]){

                DFSHelper(neigh, vis);

            }
        }
    }


    void DFS(int vtx){

        vector<bool> vis(V,false);

        DFSHelper(vtx, vis);

    }

};


int main(){

    Graph g(5);   

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.DFS(0);

}