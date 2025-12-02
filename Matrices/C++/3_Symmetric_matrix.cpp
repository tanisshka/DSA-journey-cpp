#include <iostream>
using namespace std;

class Symmetric {
private:
    int *A;
    int n;

public:
    // Constructor
    Symmetric(int n = 10) {
        this->n = n;
        A = new int[n * (n + 1) / 2]{};  // allocate space for lower triangle
    }

    // Row-major set function (handles i < j automatically)
    void setRowMajor(int i, int j, int x) {
        if (i >= j) {
            int index = ((i - 1) * i) / 2 + (j - 1);
            A[index] = x;
        } else {
            // store in symmetric position
            int index = ((j - 1) * j) / 2 + (i - 1);
            A[index] = x;
        }
    }

    // Column-major set function (handles i < j automatically)
    void setColumnMajor(int i, int j, int x) {
        if (i >= j) {
            int index = n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j);
            A[index] = x;
        } else {
            int index = n * (i - 1) - ((i - 2) * (i - 1)) / 2 + (j - i);
            A[index] = x;
        }
    }

    // Row-major get function
    int getRowMajor(int i, int j) {
        if (i >= j)
            return A[(i * (i - 1)) / 2 + (j - 1)];
        else
            return A[(j * (j - 1)) / 2 + (i - 1)];
    }

    // Column-major get function
    int getColMajor(int i, int j) {
        if (i >= j)
            return A[n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j)];
        else
            return A[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + (j - i)];
    }

    // Get dimension
    int get_dimension() {
        return n;
    }

    // Display function
    void Display(bool row = true) {
        cout << "\nSymmetric Matrix (" 
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

    // Destructor
    ~Symmetric() {
        delete[] A;
    }
};

int main() {
    int d;
    while (true) {
        cout << "Enter dimension: ";
        if (!(cin >> d)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (d > 0) break;
        cout << "Dimension must be positive.\n";
    }

    Symmetric mat(d);

    cout << "Enter elements of lower triangular part (i >= j):\n";
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= i; j++) {
            int x;
            cin >> x;
            mat.setRowMajor(i, j, x);
        }
    }

    // Example: directly set M[3][5] = 99 (even though i < j)
    if (d >= 5)
        mat.setRowMajor(3, 5, 99);

    mat.Display(true);  // show row-major
}
