#include <iostream>
#include <math.h>
using namespace std;

struct Node{
    int coeff;
    int exp;
    Node *next;
};

class Polynomial{
private:
    Node *first;

public:
    Polynomial(){
        first = nullptr;
    }

    void create(int n){
        if(n <= 0){
            cout << "No of nodes must be greater than zero!" << endl;
            return;
        }

        int coefficient, exponent;
        cout << "Enter coefficient and exponent for Term 1: ";
        cin >> coefficient >> exponent;

        first = new Node{coefficient, exponent, nullptr};
        Node *p = first;

        for(int i = 2; i <= n; i++){
            cout << "Enter coefficient and exponent for Term " << i << ": ";
            cin >> coefficient >> exponent;
            Node *temp = new Node{coefficient, exponent, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    int evaluate(int x){
        Node *p = first;
        int sum = 0;
        while(p){
            sum += p->coeff * pow(x, p->exp);
            p = p->next;
        }
        return sum;
    }

    void display(){
        if(first == nullptr){
            cout << "Polynomial is empty!" << endl;
            return;
        }

        Node *p = first;
        while(p){
            cout << p->coeff << "x^" << p->exp;
            if(p->next) cout << " + ";
            p = p->next;
        }
        cout << endl;
    }

    ~Polynomial(){
        Node *p = first;
        while(p){
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    Polynomial p;
    int n, x;

    cout << "Enter number of terms in the polynomial: ";
    cin >> n;

    p.create(n);

    cout << "\nPolynomial is: ";
    p.display();

    cout << "\n\nEnter value of x to evaluate the polynomial: ";
    cin >> x;

    cout << "\nPolynomial value at x = " << x << " is: "
         << p.evaluate(x) << endl;

    return 0;
}
