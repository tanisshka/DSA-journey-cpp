#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:

    vector<int> profit;
    vector<int> weight;
    vector<vector<int>> dp;

    // Memoization Function
    int knap(int n, int m)
    {
        // Base Case
        if(n == 0 || m == 0)
            return 0;

        // Already solved
        if(dp[n][m] != -1)
            return dp[n][m];

        // If current item can fit
        if(weight[n] <= m)
        {
            int include =
                profit[n] + knap(n - 1, m - weight[n]);

            int exclude =
                knap(n - 1, m);

            dp[n][m] = max(include, exclude);
        }
        else
        {
            // Item too heavy
            dp[n][m] = knap(n - 1, m);
        }

        return dp[n][m];
    }

    // Function to print selected items
    void printSelectedItems(int n, int m)
    {
        cout << "\nSelected Items:\n";

        int i = n;
        int j = m;

        while(i > 0 && j > 0)
        {
            // Item selected
            if(dp[i][j] != dp[i-1][j])
            {
                cout << "Item " << i
                     << " -> Weight: " << weight[i]
                     << ", Profit: " << profit[i]
                     << endl;

                // Reduce remaining capacity
                j = j - weight[i];
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
    obj.weight.resize(n + 1);
    obj.profit.resize(n + 1);

    cout << "\nEnter weights:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "Weight of item " << i << ": ";
        cin >> obj.weight[i];
    }

    cout << "\nEnter profits:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "Profit of item " << i << ": ";
        cin >> obj.profit[i];
    }

    // Initialize DP table with -1
    obj.dp.resize(n + 1, vector<int>(m + 1, -1));

    // Find maximum profit
    int ans = obj.knap(n, m);

    cout << "\nMaximum Profit = " << ans << endl;

    // Print selected items
    obj.printSelectedItems(n, m);

    return 0;
}