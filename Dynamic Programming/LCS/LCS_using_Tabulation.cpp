#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {

public:

    void solve(string a, string b) {

        // 1-based indexing
        string s1 = "#" + a;
        string s2 = "#" + b;

        int n = a.length();
        int m = b.length();

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Tabulation
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // Characters match
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Characters don't match
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of LCS
        int length = dp[n][m];

        // Reconstruct LCS string
        string lcs = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            // Character matched
            if (s1[i] == s2[j]) {
                lcs += s1[i];
                i--;
                j--;
            }

            // Move towards larger value
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }

            else {
                j--;
            }
        }

        // Reverse because we built it backwards
        reverse(lcs.begin(), lcs.end());

        cout << "LCS Length : " << length << endl;
        cout << "LCS String : " << lcs << endl;
    }
};

int main() {

    Solution obj;

    string s1 = "abcdef";
    string s2 = "ace";

    obj.solve(s1, s2);

    return 0;
}