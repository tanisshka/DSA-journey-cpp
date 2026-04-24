#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;

public:
    DisjointSet(int V) {
        rank.resize(V + 1, 0);
        parent.resize(V + 1);

        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }

    int FindUltParent(int node) {
        if (node != parent[node]) {
            return parent[node] = FindUltParent(parent[node]);
        }
        return parent[node];
    }

    void UnionByRank(int u, int v) {
        int pu = FindUltParent(u);
        int pv = FindUltParent(v);

        if (pu == pv) return;

        if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pu] = pv;
        }
    }
};

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}


int KruskalsAlgorithm(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);

    DisjointSet ds(n);
    int mstcost = 0;

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (ds.FindUltParent(u) != ds.FindUltParent(v)) {
            mstcost += edge.weight;
            ds.UnionByRank(u, v);
        }
    }
    return mstcost;
}

int main() {
    int n = 7;

    vector<Edge> edges = {
        {1, 2, 26},
        {1, 6, 10},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 6, 25},
        {5, 7, 24},
    };

    cout << "MST Weight: " << KruskalsAlgorithm(n, edges) << endl;
    return 0;
}