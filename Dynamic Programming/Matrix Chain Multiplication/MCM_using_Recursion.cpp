#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> d;

int m(int i, int j) {

    if (i == j) {
        return 0;
    }

    int minCost = INT_MAX;

    
    for (int k = i; k < j; k++) {

        int cost =
            m(i, k) +
            m(k + 1, j) +
            d[i - 1] * d[k] * d[j];

        minCost = min(minCost, cost);
    }

    return minCost;
}

int main() {

    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    d.resize(n + 1);

    cout << "Enter dimensions array:\n";

    for (int i = 0; i <= n; i++) {
        cin >> d[i];
    }

    int answer = m(1, n);

    cout << "Minimum multiplication cost = "
         << answer << endl;

    return 0;
}