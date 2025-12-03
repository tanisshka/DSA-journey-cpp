#include <iostream>
#include <vector>
using namespace std;

struct Term {
    int row;
    int col;
    int val;
};

class Sparse {
public:
    int rows, cols, numTerms;
    vector<Term> terms;

    // Constructor
    Sparse(int r = 0, int c = 0, int n = 0) {
        rows = r;
        cols = c;
        numTerms = n;
        terms.resize(n);
    }

    // Input sparse elements
    void input() {
        cout << "Enter (row col value) for non-zero elements:\n";
        for (int i = 0; i < numTerms; i++) {
            cin >> terms[i].row >> terms[i].col >> terms[i].val;
        }
    }

    // Display coordinate list
    void display() {
        cout << "\nSparse Matrix (row col value format):\n";
        for (auto &t : terms) {
            cout << t.row << " " << t.col << " " << t.val << endl;
        }
    }

    // Get value from full matrix representation
    int get(int i, int j) {
        for (auto &t : terms) {
            if (t.row == i && t.col == j)
                return t.val;
        }
        return 0;
    }

    // Display full matrix (visual)
    void displayFullMatrix() {
        cout << "\nFull Matrix Representation:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    // ADD TWO SPARSE MATRICES
    Sparse add(Sparse &B) {
        if (rows != B.rows || cols != B.cols) {
            throw runtime_error("Matrices dimensions must match!");
        }

        vector<Term> result;
        int i = 0, j = 0;

        while (i < numTerms && j < B.numTerms) {

            // Compare (row, col)
            if (terms[i].row < B.terms[j].row ||
               (terms[i].row == B.terms[j].row && terms[i].col < B.terms[j].col)) {

                result.push_back(terms[i]);
                i++;
            }
            else if (B.terms[j].row < terms[i].row ||
                    (B.terms[j].row == terms[i].row && B.terms[j].col < terms[i].col)) {

                result.push_back(B.terms[j]);
                j++;
            }
            else {
                // Match → add values
                int summed = terms[i].val + B.terms[j].val;
                if (summed != 0) {
                    result.push_back({terms[i].row, terms[i].col, summed});
                }
                i++;
                j++;
            }
        }

        // Remaining elements
        while (i < numTerms) result.push_back(terms[i++]);
        while (j < B.numTerms) result.push_back(B.terms[j++]);

        Sparse C(rows, cols, result.size());
        C.terms = result;

        return C;
    }
};

int main() {
    int r, c, n1, n2;

    cout << "Enter rows, cols, non-zero count of Matrix A: ";
    cin >> r >> c >> n1;
    Sparse A(r, c, n1);
    A.input();

    cout << "Enter non-zero count of Matrix B: ";
    cin >> n2;
    Sparse B(r, c, n2);
    B.input();

    cout << "\nMatrix A:";
    A.display();
    A.displayFullMatrix();

    cout << "\nMatrix B:";
    B.display();
    B.displayFullMatrix();

    cout << "\nMatrix C = A + B:";
    Sparse C = A.add(B);
    C.display();
    C.displayFullMatrix();

    return 0;
}
