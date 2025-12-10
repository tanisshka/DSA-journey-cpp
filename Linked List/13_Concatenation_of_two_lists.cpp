#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Linked_List {
private:
    Node *first;

public:
    Linked_List() : first(nullptr) {}

    void create(int n) {
        if (n <= 0) {
            cout << "Cannot create list with size " << n << endl;
            return;
        }

        int x;
        cout << "Enter data for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; ++i) {
            cout << "Enter data for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    void display() {
        if (first == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node *p = first;
        int i = 1;

        while (p != nullptr) {
            cout << "Data " << i << ": " << p->data << endl;
            p = p->next;
            ++i;
        }
    }

    // Concatenation function
    void Concatenation(Linked_List *A) {
        if (A->first == nullptr)   // If second list is empty
            return;

        if (first == nullptr) {    // If current list is empty
            first = A->first;
            A->first = nullptr;
            return;
        }

        Node *p = first;
        while (p->next != nullptr)
            p = p->next;

        p->next = A->first;
        A->first = nullptr;
    }

    ~Linked_List() {
        Node *p = first;
        while (p) {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    Linked_List A, B;

    int n1, n2;

    cout << "Enter size of List A: ";
    cin >> n1;
    A.create(n1);

    cout << "\nEnter size of List B: ";
    cin >> n2;
    B.create(n2);

    cout << "\nList A before concatenation:\n";
    A.display();

    cout << "\nList B before concatenation:\n";
    B.display();

    cout << "\nConcatenating B into A...\n";
    A.Concatenation(&B);

    cout << "\nList A after concatenation:\n";
    A.display();

    cout << "\nList B after concatenation (should be empty):\n";
    B.display();

    return 0;
}
