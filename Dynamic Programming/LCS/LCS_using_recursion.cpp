#include <iostream>
#include <string>
using namespace std;

class Solution {
private:

    // Recursive function
    string lcs(string &s1, string &s2, int i, int j) {

        // Base case
        if (i == 0 || j == 0) {
            return "";
        }

        // Characters match
        if (s1[i] == s2[j]) {
            return lcs(s1, s2, i - 1, j - 1) + s1[i];
        }

        // Characters don't match
        string op1 = lcs(s1, s2, i - 1, j);
        string op2 = lcs(s1, s2, i, j - 1);

        // Return longer subsequence
        return (op1.length() > op2.length()) ? op1 : op2;
    }

public:

    void solve(string a, string b) {

        
        string s1 = "#" + a;
        string s2 = "#" + b;

        string ans = lcs(s1, s2, a.length(), b.length());

        cout << "LCS String : " << ans << endl;
        cout << "LCS Length : " << ans.length() << endl;
    }
};

int main() {

    Solution obj;

    string s1 = "abcdef";
    string s2 = "ace";

    obj.solve(s1, s2);

    return 0;
}