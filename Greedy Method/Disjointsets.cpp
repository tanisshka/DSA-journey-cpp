#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;

public:
    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUlParent(int node) {
        if (node != parent[node]) {
            return parent[node] = findUlParent(parent[node]); // path compression
        }
        return parent[node];
    }

    void UnionByRank(int u, int v) {
        int pu = findUlParent(u);
        int pv = findUlParent(v);

        if (pu == pv) return; // already in same set

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

int main() {
    DisjointSet ds(7);

    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);


    cout<<"Before: "<<endl;
    if (ds.findUlParent(3) == ds.findUlParent(7))
        cout << "Same set\n";
    else
        cout << "Different set\n";

    ds.UnionByRank(3,7);

    cout<<"After:"<<endl;
        if (ds.findUlParent(3) == ds.findUlParent(7))
        cout << "Same set\n";
    else
        cout << "Different set\n";

    return 0;
}