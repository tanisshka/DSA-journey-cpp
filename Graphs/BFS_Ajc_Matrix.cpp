#include <iostream>
#include <queue>
using namespace std;

void BFS(int vtx, int A[][8], int n) {
    queue<int> Q;
    int visited[8] = {0};

    visited[vtx] = 1;
    cout << "Visited Vertex: " << vtx << endl;
    Q.push(vtx);

    while (!Q.empty()) {
        int u = Q.front();   
        Q.pop();             

        for (int v = 0; v < n; v++) {
            if (A[u][v] != 0 && visited[v] == 0) {
                cout << "Visited Vertex: " << v << endl;
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}

int main() {
    int A[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0},
        {0,1,0,1,0,0,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,0,1,0,1,0,0},
        {0,0,0,1,1,0,1,1},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0}
    };

    cout << "Vertex: 1\n";
    BFS(1, A, 8);

    cout << "\nVertex: 4\n";
    BFS(4, A, 8);
}
