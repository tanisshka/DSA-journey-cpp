#include <iostream>
using namespace std;

double Taylor_sum(int x, int n) {
    double p = 1.0;   // power of x
    double f = 1.0;   // factorial
    double sum = 1.0; // result starts with 1

    for (int i = 1; i <= n; i++) {
        p = p * x;     // x^i
        f = f * i;     // i!
        sum = sum + (p / f);
    }
    return sum;
}

int main() {
    int x, n;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter number of terms n: ";
    cin >> n;

    cout << "Approximation of e^" << x << " = " << Taylor_sum(x, n) << endl;
    return 0;
}
