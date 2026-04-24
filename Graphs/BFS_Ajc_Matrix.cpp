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

class Solution {
private:
    void BFS(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col]=1;

        queue<pair<int,int>> q;
        q.push({row,col});

        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){

                    int nrow=row + deltarow;
                    int mcol=col + deltacol;

                    if(nrow>=0 && nrow<n && mcol>=0 && mcol<m 
                    && grid[nrow][mcol]=='1' && vis[nrow][mcol]==0){

                        vis[nrow][mcol]=1;
                        q.push({nrow,mcol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){

                if(grid[row][col]=='1' && vis[row][col]==0){
                    BFS(row,col,vis,grid);
                    cnt++;
                }

            }
        }

        return cnt;
    }
};