#include <iostream>
using namespace std;

class TriDiagonal_matrix {
private:
    int *A;
    int n;

public:
    TriDiagonal_matrix(int n = 10) {
        this->n = n;
        A = new int[3*n - 2]();   // allocate and zero-initialize
    }

    ~TriDiagonal_matrix() {
        delete [] A;
    }

    void set(int i, int j, int x) {
        if (i - j == 1) {                      // lower diagonal
            A[j - 1] = x;
        }
        else if (i - j == 0) {                 // main diagonal
            A[(n - 1) + (j - 1)] = x;
        }
        else if (i - j == -1) {                // upper diagonal
            A[(2 * n - 1) + (i - 1)] = x;      
        }
    }

    int get(int i, int j) {
        if (i - j == 1) 
            return A[j - 1];
        else if (i - j == 0) 
            return A[(n - 1) + (j - 1)];
        else if (i - j == -1) 
            return A[(2 * n - 1) + (i - 1)];
        
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
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

    TriDiagonal_matrix TM(n);

    cout << "Enter non-zero elements (tri-diagonal only):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j >= -1 && i - j <= 1) {
                int x;
                cout << "Enter A[" << i << "][" << j << "]: ";
                cin >> x;
                TM.set(i, j, x);
            }
        }
    }

    cout << "\nTri-diagonal matrix:\n";
    TM.display();
    return 0;
}
