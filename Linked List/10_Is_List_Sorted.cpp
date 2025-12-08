#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Linked_List {
private:
    Node* first;

public:
    Linked_List() {
        first = nullptr;
    }

    // Create list
void insertSorted(int x) {
    Node* t = new Node{x, nullptr};

    // Case 1: Empty list
    if (first == nullptr) {
        first = t;
        return;
    }

    Node* p = first;
    Node* q = nullptr;

    // Traverse until correct position found (allows duplicates)
    while (p != nullptr && p->data <= x) {
        q = p;
        p = p->next;
    }

    // Case 2: Insert at front
    if (q == nullptr) {
        t->next = first;
        first = t;
    }
    else {
        t->next = q->next;
        q->next = t;
    }
}


    // Display list
    void display() {
        Node* p = first;
        int i = 1;

        if (!p) {
            cout << "List is empty.\n";
            return;
        }

        while (p) {
            cout << "Data value of node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    //Function to check if the list is dorted or not
    int IsSorted(){
        if(first==nullptr){
            cout<<"List is empty"<<endl;
            return -1;
        }

        Node *p=first;
        int x=INT_MIN;
        while(p!=nullptr){
            if(p->data<x){
                return 0;
            }
            x=p->data;
            p=p->next;
        }
        return 1;
    }

    // Destructor
    ~Linked_List() {
        Node* p = first;
        while (p) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    Linked_List list;
    int n;

    cout << "Enter number of nodes to create: ";
    cin >> n;

    list.create(n);

    cout << "\nLinked List:\n";
    list.display();

    cout << "\nChecking if the list is sorted...\n";
    int result = list.IsSorted();

    if (result == -1) {
        cout << "Cannot check sorting because the list is empty.\n";
    }
    else if (result == 1) {
        cout << "The linked list IS sorted.\n";
    }
    else {
        cout << "The linked list is NOT sorted.\n";
    }

    return 0;
}

