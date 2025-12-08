#include<iostream>
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
    void create(int n) {
        if (n <= 0) {
            cout << "Invalid size. Cannot create list.\n";
            return;
        }

        int x;
        cout << "Enter value of Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node* p = first;

        for (int i = 2; i <= n; i++) {
            cout << "Enter value of Node " << i << ": ";
            cin >> x;
            Node* temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    // Delete first node
    int deleteFront() {
        if (first == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return -1;
        }

        Node* p = first;
        first = first->next;
        int x = p->data;
        delete p;
        return x;
    }

    // Delete node at a given position
    int deleteAtPos(int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return -1;
        }

        if (first == nullptr) {
            cout << "List empty.\n";
            return -1;
        }

        Node* p = first;
        Node* q = nullptr;

        // If deleting first node
        if (pos == 1) {
            first = first->next;
            int x = p->data;
            delete p;
            return x;
        }

        // Traverse to (pos-1)
        for (int i = 1; i < pos && p != nullptr; i++) {
            q = p;
            p = p->next;
        }

        if (p == nullptr) {
            cout << "Position out of range!\n";
            return -1;
        }

        q->next = p->next;
        int x = p->data;
        delete p;
        return x;
    }

    //Delete the last node function
    int deleteBack(){
        if(first==nullptr){
            cout<<"List is empty"<<endl;
            return -1;
        }

        Node *p=first;
        Node *q=nullptr;
        int x;

        while(p->next!=nullptr){
            q=p;
            p=p->next;
        }

        if(q!=nullptr){
            q->next=nullptr;
            x=p->data;
            delete p;
            return x;
        }else{
            first=nullptr;
            x=p->data;
            delete p;
            return x;
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

    cout << "\nLinked List after creation:\n";
    list.display();

    // Delete front
    cout << "\nDeleting first element...\n";
    int deletedValue = list.deleteFront();
    if (deletedValue != -1)
        cout << "Deleted value = " << deletedValue << endl;

    cout << "\nLinked List after deleting front:\n";
    list.display();

    // Delete at position
    cout << "\nEnter position to delete: ";
    int pos;
    cin >> pos;

    int val = list.deleteAtPos(pos);
    if (val != -1)
        cout << "Deleted value = " << val << endl;

    cout << "\nLinked List after deletion at position:\n";
    list.display();


    cout << "\nDeleting last element...\n";
    int lastVal = list.deleteBack();
    if (lastVal != -1)
        cout << "Deleted value = " << lastVal << endl;

    cout << "\nLinked List after deleting last node:\n";
    list.display();

    return 0;
}
