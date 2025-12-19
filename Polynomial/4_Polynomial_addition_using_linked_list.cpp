#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node *next;
};

class Polynomial
{
private:
    Node *first;

public:
    Polynomial()
    {
        first = nullptr;
    }

    // Sorted insert + merge same exponents
    void insert(int coefficient, int exponent)
    {
        if (coefficient == 0)
            return;

        Node *temp = new Node{coefficient, exponent, nullptr};

        // Empty list or highest exponent
        if (first == nullptr || exponent > first->exp)
        {
            temp->next = first;
            first = temp;
            return;
        }

        Node *p = first;

        // Same exponent as first
        if (p->exp == exponent)
        {
            p->coeff += coefficient;
            delete temp;
            return;
        }

        // Find correct position
        while (p->next && p->next->exp > exponent)
            p = p->next;

        // Same exponent → add coefficients
        if (p->next && p->next->exp == exponent)
        {
            p->next->coeff += coefficient;
            delete temp;
            return;
        }

        // Insert in list
        temp->next = p->next;
        p->next = temp;
    }

    // Create polynomial (uses sorted insert)
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of terms must be greater than zero!" << endl;
            return;
        }

        int coefficient, exponent;
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter coefficient and exponent for term " << i << ": ";
            cin >> coefficient >> exponent;
            insert(coefficient, exponent);
        }
    }

    // Evaluate polynomial
    int evaluate(int x)
    {
        int sum = 0;
        Node *p = first;
        while (p)
        {
            sum += p->coeff * pow(x, p->exp);
            p = p->next;
        }
        return sum;
    }

    // Add two polynomials
    Polynomial add(Polynomial &other)
    {
        Polynomial result;
        Node *p = first;
        Node *q = other.first;

        while (p && q)
        {
            if (p->exp == q->exp)
            {
                int sum = p->coeff + q->coeff;
                if (sum != 0)
                    result.insert(sum, p->exp);
                p = p->next;
                q = q->next;
            }
            else if (p->exp > q->exp)
            {
                result.insert(p->coeff, p->exp);
                p = p->next;
            }
            else
            {
                result.insert(q->coeff, q->exp);
                q = q->next;
            }
        }

        while (p)
        {
            result.insert(p->coeff, p->exp);
            p = p->next;
        }

        while (q)
        {
            result.insert(q->coeff, q->exp);
            q = q->next;
        }

        return result;
    }

    // Display polynomial
    void display()
    {
        if (first == nullptr)
        {
            cout << "Polynomial is empty!" << endl;
            return;
        }

        Node *p = first;
        while (p)
        {
            cout << p->coeff << "x^" << p->exp;
            if (p->next)
                cout << " + ";
            p = p->next;
        }
        cout << endl;
    }

    // Destructor
    ~Polynomial()
    {
        Node *p = first;
        while (p)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main()
{
    Polynomial p1, p2, p3;
    int n, x;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;
    p1.create(n);

    cout << "\nPolynomial 1: ";
    p1.display();

    cout << "\nEnter number of terms in Polynomial 2: ";
    cin >> n;
    p2.create(n);

    cout << "\nPolynomial 2: ";
    p2.display();

    // Addition
    p3 = p1.add(p2);

    cout << "\nSum of Polynomials: ";
    p3.display();

    // Evaluation
    cout << "\nEnter value of x to evaluate sum polynomial: ";
    cin >> x;

    cout << "Value of polynomial at x = " << x << " is: "
         << p3.evaluate(x) << endl;

    return 0;
}
