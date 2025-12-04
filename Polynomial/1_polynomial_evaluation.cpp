#include <iostream>
#include <cmath>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

class Polynomial {
private:
    int n;
    Term *t;

public:
    Polynomial(int n) {
        this->n = n;
        t = new Term[n];
    }

    ~Polynomial() {
        delete[] t;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient & exponent for term " << i + 1 << ": ";
            cin >> t[i].coeff >> t[i].exp;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << t[i].coeff << "x^" << t[i].exp;
            if (i != n - 1) cout << " + ";
        }
        cout << endl;
    }

    int evaluate(int x) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += t[i].coeff * pow(x, t[i].exp);
        }
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    Polynomial p(n);

    p.input();
    p.display();

    int x;
    cout << "Enter value of x: ";
    cin >> x;

    cout << "Result = " << p.evaluate(x) << endl;

    return 0;
}
