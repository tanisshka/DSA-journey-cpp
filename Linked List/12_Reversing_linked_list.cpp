#include <iostream>
#include <vector>
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
            cout << "List is empty" << endl;
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

    // Reverse data using vector
    void Reverse_elements() {
        if (first == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = first;
        vector<int> A;

        while (p) {
            A.push_back(p->data);
            p = p->next;
        }

        int n = static_cast<int>(A.size());
        p = first;

        for (int i = n - 1; i >= 0; --i) {
            p->data = A[i];
            p = p->next;
        }
    }

    // Reversing linked list by reversing links (iterative)
    void Reverse_Links() {
        if (first == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = first;
        Node *q = nullptr;
        Node *r = nullptr;

        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }

    // Reversing links using recursion (helper)
    void Recursive_Reverse(Node *q, Node *p) {
        if (p) {
            Recursive_Reverse(p, p->next);
            p->next = q;
        } else {
            first = q;
        }
    }

    // Public wrapper for recursive reverse
    void Recursive_Reverse() {
        Recursive_Reverse(nullptr, first);
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
    Linked_List L;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    L.create(n);

    cout << "\nOriginal List:\n";
    L.display();

    cout << "\nReversed List (elements reversed):\n";
    L.Reverse_elements();
    L.display();

    cout << "\nReversed Back (links reversed - iterative):\n";
    L.Reverse_Links();
    L.display();

    cout << "\nReversed Back Again (links reversed - recursive):\n";
    L.Recursive_Reverse();
    L.display();

    return 0;
}
