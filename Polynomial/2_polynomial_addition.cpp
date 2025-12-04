#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Term
{
    int coef;
    int exp;
};

class Polynomial
{
private:
    int n;
    vector<Term> t;

public:
    Polynomial(int n)
    {
        this->n = n;
        t.resize(n);
    }

    void input()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter coefficient and exponent: ";
            cin >> t[i].coef >> t[i].exp;
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << t[i].coef << "x^" << t[i].exp;
            if (i != n - 1)
                cout << " + ";
        }
        cout << endl;
    }

    int evaluate(int x)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += t[i].coef * pow(x, t[i].exp);
        }
        return sum;
    }

    Polynomial addition(Polynomial &p2)
    {
        vector<Term> result;
        int i = 0, j = 0;

        while (i < n && j < p2.n)
        {
            if (t[i].exp > p2.t[j].exp)
            {
                result.push_back(t[i]);
                i++;
            }
            else if (t[i].exp < p2.t[j].exp)
            {
                result.push_back(p2.t[j]);
                j++;
            }
            else
            {
                int sum = t[i].coef + p2.t[j].coef;
                result.push_back({sum, t[i].exp});
                i++;
                j++;
            }
        }

        while (i < n)
        {
            result.push_back(t[i]);
            i++;
        }

        while (j < p2.n)
        {
            result.push_back(p2.t[j]);
            j++;
        }

        Polynomial res(result.size());
        res.t = result;
        return res;
    }
};

int main()
{
    int n1, n2;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    Polynomial p1(n1);
    cout << "\n--- Enter first polynomial ---\n";
    p1.input();

    cout << "\nFirst Polynomial: ";
    p1.display();

    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n2;
    Polynomial p2(n2);
    cout << "\n--- Enter second polynomial ---\n";
    p2.input();

    cout << "\nSecond Polynomial: ";
    p2.display();

    cout << "\n--- Addition Result ---\n";
    Polynomial sum = p1.addition(p2);
    sum.display();

    return 0;
}
