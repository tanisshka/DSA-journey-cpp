#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {

private:

    int m(vector<int> &arr,
          vector<vector<int>> &M,
          vector<vector<int>> &S)
    {
        int n = arr.size();

        for(int diff = 1; diff < n - 1; diff++) {

            for(int i = 1; i < n - diff; i++) {

                int j = i + diff;

                M[i][j] = INT_MAX;

                for(int k = i; k < j; k++) {

                    int cost =
                        M[i][k]
                        + M[k+1][j]
                        + arr[i-1] * arr[k] * arr[j];

                    if(cost < M[i][j]) {

                        M[i][j] = cost;

                        S[i][j] = k;
                    }
                }
            }
        }

        return M[1][n-1];
    }


    void printOrder(int i, int j,
                    vector<vector<int>>& S)
    {

        if(i == j) {
            cout << "A" << i;
            return;
        }

        cout << "(";

        printOrder(i, S[i][j], S);

        printOrder(S[i][j] + 1, j, S);

        cout << ")";
    }

public:

    void matrixMultiplication(vector<int>& arr)
    {

        int n = arr.size();

        vector<vector<int>> M(
            n,
            vector<int>(n, 0)
        );

        vector<vector<int>> S(
            n,
            vector<int>(n, 0)
        );

        int minCost = m(arr, M, S);

        cout << "Minimum Cost = "
             << minCost << endl;

        cout << "Optimal Order = ";

        printOrder(1, n - 1, S);

        cout << endl;
    }
};

int main() {

    vector<int> arr = {3, 2, 4, 2, 5};

    Solution s;

    s.matrixMultiplication(arr);

    return 0;
}