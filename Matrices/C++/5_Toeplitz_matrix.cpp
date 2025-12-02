#include <iostream>
using namespace std;

class Toeplitz_matrix {
private:
    int *A;
    int n;

public:
    // Constructor
    Toeplitz_matrix(int n = 10) {
        this->n = n;
        A = new int[2 * n - 1]();
    }

    // Destructor
    ~Toeplitz_matrix() {
        delete[] A;
    }

    // set function
    void set(int i, int j, int x) {
        if (i <= j) {
            A[j - i] = x;            // upper diagonal + main diagonal
        } else {
            A[n + (i - j) - 1] = x;  // lower diagonal
        }
    }

    // get function
    int get(int i, int j) {
        if (i <= j) {
            return A[j - i];
        } else {
            return A[n + (i - j) - 1];
        }
    }

    // Display function
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    Toeplitz_matrix TOE(n);

    cout << "Enter elements for Toeplitz matrix:\n";

    // We only need to input first row and first column (minus duplicate)
    cout << "Enter first row (" << n << " elements):\n";
    for (int j = 1; j <= n; j++) {
        int x;
        cin >> x;
        TOE.set(1, j, x);
    }

    cout << "Enter first column (" << n-1 << " elements, excluding A[1][1]):\n";
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        TOE.set(i, 1, x);
    }

    cout << "\nToeplitz Matrix:\n";
    TOE.display();

    return 0;
}
