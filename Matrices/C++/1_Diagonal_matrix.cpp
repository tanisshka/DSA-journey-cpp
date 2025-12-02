#include <iostream>
using namespace std;

class Diagonal {
private:
    int *A;
    int n;

public:
    Diagonal(int n = 10) {
        this->n = n;
        A = new int[n]{}; // initialize with 0
    }

    void set(int i, int j, int x) {
        if (i == j) {
            A[i - 1] = x;
        }
    }

    int get(int i, int j) {
        if (i == j) {
            return A[i - 1];
        }
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << "\t";
            }
            cout << endl; // ✅ fixed
        }
    }

    int getDimension() {
        return n;
    }

    ~Diagonal() {
        delete[] A;
    }
}; // ✅ semicolon added

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
        cout << "Dimension cannot be 0 or less.\n";
    }
    
    Diagonal dm(d);

    for (int i = 1; i <= d; i++) {
        int x;
        cout << "Enter diagonal element [" << i << "][" << i << "]: ";
        while (!(cin >> x)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        dm.set(i, i, x);
    }

    cout << "\nMatrix:\n";
    dm.display();

    return 0;
}

