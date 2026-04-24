#include<iostream>
#include<vector>
using namespace std;

int C(int n, int r, vector<vector<int>> &look_up_table) {
    if (r == 0 || r == n) {
        return look_up_table[n][r] = 1;
    }

    if (look_up_table[n][r] != -1) {
        return look_up_table[n][r];
    }

    return look_up_table[n][r] =
        C(n-1, r-1, look_up_table) + C(n-1, r, look_up_table);
}

int main() {
    int n, r;
    cout << "Enter n & r: ";
    cin >> n >> r;

    vector<vector<int>> look_up_table(n+1, vector<int>(n+1, -1));

    cout << "C(" << n << ", " << r << ") = "
         << C(n, r, look_up_table) << endl;

    // Pascal Triangle
    vector<vector<int>> ans(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int val = C(i, j, look_up_table);
            ans[i].push_back(val);
        }
    }

    // Print Pascal Triangle
    cout << "\nPascal Triangle:\n";
    for (int i = 0; i < n; i++) {
        for (int val : ans[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}