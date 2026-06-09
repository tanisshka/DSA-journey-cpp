#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {

private:

    int m(int i, int j,
          vector<vector<int>>& M,
          vector<vector<int>>& S,
          vector<int>& d)
    {

        if(i == j) {
            return 0;
        }

        if(M[i][j] != -1) {
            return M[i][j];
        }

        int minCost = INT_MAX;

        for(int k = i; k < j; k++) {

            int left = m(i, k, M, S, d);
            int right = m(k + 1, j, M, S, d);

            int cost =
                left +
                right +
                d[i - 1] * d[k] * d[j];

            if(cost < minCost) {

                minCost = cost;

                S[i][j] = k; // store split point
            }
        }

        M[i][j] = minCost;

        return minCost;
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
            vector<int>(n, -1)
        );

        vector<vector<int>> S(
            n,
            vector<int>(n, 0)
        );

        int minCost =
            m(1, n - 1, M, S, arr);

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