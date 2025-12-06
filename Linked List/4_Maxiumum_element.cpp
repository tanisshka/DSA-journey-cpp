// Find the maximum element in the linked list
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Linked_List {
private:
    Node *first;

public:
    Linked_List() {
        first = nullptr;
    }

    void create(int n) {
        if (n <= 0) {
            return;
        }

        int x;
        cout << "Enter the value for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++) {
            cout << "Enter the value for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;     // FIXED: was p = next (wrong)
        }
    }

    void display() {
        Node *p = first;
        int i = 1;

        while (p != nullptr) {
            cout << "Data value at node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    int max() {
        int x = INT_MIN;
        Node *p = first;

        while (p != nullptr) {
            if (p->data > x) {
                x = p->data;
            }
            p = p->next;
        }
        return x;
    }

    int Max_Recursive(Node *p){
        if(p==nullptr){
            return INT_MIN;
        }
        int x=Max_Recursive(p->next);
        return (p->data>x)?p->data:x;
    }

    int Max_Recursive(){
        return Max_Recursive(first);
    }

    ~Linked_List() {
        Node *p = first;
        while (p != nullptr) {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};



int main() {
    Linked_List list;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    list.create(n);

    cout << "\nLinked List Elements:\n";
    list.display();

    cout << "\nMaximum element (Iterative) = " << list.max() << endl;
    cout << "Maximum element (Recursive) = " << list.Max_Recursive() << endl;

    return 0;
}
