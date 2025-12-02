#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

public:
    // Constructor
    Array(int size = 10, int length = 10, bool not_filled = false) {
        this->size = size;
        if (length > size) {
            length = size;
        }
        this->length = length;
        A = new int[size];

        if (not_filled) {
            for (int i = 0; i < length; i++) {
                cout << "Value at A[" << i << "]: ";
                cin >> A[i];
            }
        } else {
            for (int i = 0; i < length; i++) {
                A[i] = 0;
            }
        }
    }

    void display_Array() {
        for (int i = 0; i < length; i++) {
            cout << A[i] << "\t";
        }
        cout << endl;
    }

    int max() {
        if (length == 0) {
            cout << "Array is empty!";
            return -1;
        }
        int maximum = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] > maximum) {
                maximum = A[i];
            }
        }
        return maximum;
    }

    int get(int index) {
        if (index >= 0 && index < length) {
            return A[index];
        } else {
            return -1; // safer
        }
    }

    void set(int index, int x) {
        if (index >= 0 && index < length) {
            A[index] = x;
        }
    }

    // ✅ Pair sum function using hashing
    void find_pair_sum(int k) {
        if (length == 0) {
            cout << "Array is empty!";
            return;
        }

        int h = max();
        Array H(h + 1, h + 1, false); // zero-initialized hash

        for (int i = 0; i < length; i++) {
            int complement = k - A[i];
            if (complement >= 0 && complement <= h && H.get(complement) > 0) {
                cout << "Pair: " << A[i] << " + " << complement << " = " << k << endl;
            }
            int val = H.get(A[i]);
            H.set(A[i], val + 1);
        }
    }

    ~Array() {
        delete[] A;
        // cout << "The destructor was called!"; // remove this for clean output
    }
};

int main() {
    Array arr(10, 5, true); // user inputs 5 elements
    arr.display_Array();
    arr.find_pair_sum(10);  // Example: find pairs that sum to 10
    return 0;
}

