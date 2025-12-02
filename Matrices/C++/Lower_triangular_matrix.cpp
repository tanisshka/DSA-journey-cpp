#include <iostream>
using namespace std;

class Ltriangle {
private:
    int *A;
    int n;

public:
    // Constructor
    Ltriangle(int n = 10) {
        this->n = n;
        A = new int[n * (n + 1) / 2]{}; // only store lower elements
    }

    // Destructor
    ~Ltriangle() {
        delete[] A;
    }

    // Row-major set
    void setRowMajor(int i, int j, int x) {
        if (i >= j) {
            int index = ((i - 1) * i) / 2 + (j - 1);
            A[index] = x;
        }
    }

    // Column-major set
    void setColMajor(int i, int j, int x) {
        if (i >= j) {
            int index = n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j);
            A[index] = x;
        }
    }

    // Row-major get
    int getRowMajor(int i, int j) {
        if (i >= j) {
            int index = ((i - 1) * i) / 2 + (j - 1);
            return A[index];
        } else {
            return 0;
        }
    }

    // Column-major get
    int getColMajor(int i, int j) {
        if (i >= j) {
            int index = n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j);
            return A[index];
        } else {
            return 0;
        }
    }

    // Display function
    void Display(bool row = true) {
        cout << "\nLower Triangular Matrix (" 
             << (row ? "Row-Major" : "Column-Major") << "):\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (row)
                    cout << getRowMajor(i, j) << " ";
                else
                    cout << getColMajor(i, j) << " ";
            }
            cout << endl;
        }
    }

    int getN() { return n; }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    Ltriangle lt(n);

    cout << "Enter elements of lower triangular matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            lt.setRowMajor(i, j, x); // you can also test setColMajor here
        }
    }

    lt.Display(true);  // row-major
    lt.Display(false); // column-major

    return 0;
}
