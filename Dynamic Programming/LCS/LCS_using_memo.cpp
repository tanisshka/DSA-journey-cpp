#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

private:
    
    vector<vector<int>> dp;

    // Function to find LCS length using memoization
    int lcsLength(string &s1, string &s2, int i, int j) {

        // Base case
        if (i == 0 || j == 0) {
            return 0;
        }

        // Already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + lcsLength(s1, s2, i - 1, j - 1);
        }

        // Characters don't match
        return dp[i][j] = max(
            lcsLength(s1, s2, i - 1, j),
            lcsLength(s1, s2, i, j - 1)
        );
    }

    // Function to reconstruct LCS string
    string buildLCS(string &s1, string &s2, int i, int j) {

        string ans = "";

        while (i > 0 && j > 0) {

            // Character matched
            if (s1[i] == s2[j]) {
                ans = s1[i] + ans;
                i--;
                j--;
            }

            // Move in direction of larger value
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }

        return ans;
    }

public:

    void solve(string a, string b) {

        // 1-based indexing
        string s1 = "#" + a;
        string s2 = "#" + b;

        int n = a.length();
        int m = b.length();

        dp.resize(n + 1, vector<int>(m + 1, -1));

        int length = lcsLength(s1, s2, n, m);

        string lcs = buildLCS(s1, s2, n, m);

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