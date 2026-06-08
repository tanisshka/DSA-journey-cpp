#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:

    vector<int> wt;
    vector<int> p;
    vector<vector<int>> dp;

    // Tabulation Function
    int knapsack(int n, int m)
    {
        // Fill DP Table
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                // Base Case
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }

                // Current item can fit
                else if(wt[i] <= j)
                {
                    dp[i][j] =
                    max(
                        dp[i-1][j],                       // exclude
                        dp[i-1][j-wt[i]] + p[i]          // include
                    );
                }

                // Current item cannot fit
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }

    // Function to print selected items
    void printSelectedItems(int n, int m)
    {
        int i = n;
        int j = m;

        cout << "\nSelected Items:\n";

        while(i > 0 && j > 0)
        {
            // Item selected
            if(dp[i][j] != dp[i-1][j])
            {
                cout << "Include item " << i
                     << " (Weight = " << wt[i]
                     << ", Profit = " << p[i] << ")"
                     << endl;

                j = j - wt[i];
            }

            i--;
        }
    }
};

int main()
{
    Solution obj;

    int n, m;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> m;

    // 1-based indexing
    obj.wt.resize(n + 1);
    obj.p.resize(n + 1);

    cout << "\nEnter weights:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "Weight of item " << i << ": ";
        cin >> obj.wt[i];
    }

    cout << "\nEnter profits:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "Profit of item " << i << ": ";
        cin >> obj.p[i];
    }

    // Initialize DP table
    obj.dp.resize(n + 1, vector<int>(m + 1));

    // Solve Knapsack
    int ans = obj.knapsack(n, m);

    cout << "\nMaximum Profit = " << ans << endl;

    // Print selected items
    obj.printSelectedItems(n, m);

    return 0;
}