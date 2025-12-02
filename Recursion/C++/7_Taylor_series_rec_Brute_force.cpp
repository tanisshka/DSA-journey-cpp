#include <iostream>
using namespace std;

double e(int x, int n) {
    static double p = 1; // power of x
    static double f = 1; // factorial
    double r;
    if (n == 0) {
        return 1;
    } else {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int main() {
    cout << e(1, 10) << endl;   // e^1 ≈ 2.7182
    return 0;
}
