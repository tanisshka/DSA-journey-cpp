#include <iostream>
using namespace std;

struct Node {
    Node *prev;
    int data;
    Node *next;
}; // Added semicolon

class Circular_Linked_List {
private:
    Node *head;

public:
    // Constructor
    Circular_Linked_List() {
        head = nullptr;
    }

    // Create function
    void create(int n) {
        if (n <= 0) {
            cout << "Number of nodes cannot be less than zero!" << endl;
            return;
        }
        
        int x;
        cout << "Enter data value for Node 1: ";
        cin >> x;
        head = new Node{nullptr, x, nullptr};
        Node *p = head;
        
        for (int i = 2; i <= n; i++) {
            cout << "Enter data value for Node " << i << ": ";
            cin >> x;
            Node *temp = new Node{nullptr, x, nullptr};
            temp->prev = p;
            p->next = temp;
            p = temp;
        }
        
        head->prev = p;
        p->next = head;
    }

    // Display function
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node *p = head;
        int i = 1;
        do {
            cout << "Data value of Node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        } while (p != head);
    }

    // Insert at front function
    void InsertAtFront(int x) {
        Node *t = new Node{nullptr, x, nullptr};
        
        // Case 1: 0 nodes
        if (head == nullptr) {
            head = t;
            t->next = t;
            t->prev = t;
            return;
        }
        
        // Case 2: 1 or more nodes 
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t; 
    }

    //Insert At Back function
    void InsertAtBack(int x){
        Node *t=new Node {nullptr,x,nullptr};
        //Case 1: 0 nodes
        if(head==nullptr){
            head=t;
            t->next=t;
            t->prev=t;
            return;
        }

        //Case 2: 1 or multiple nodes
        t->prev=head->prev;
        t->next=head;
        head->prev->next=t;
        head->prev=t;
    }

    // Destructor
    ~Circular_Linked_List() { 
        if (head == nullptr) {
            return;
        }
        
        Node *p = head->next;
        head->next = nullptr; // Break the circular link
        
        // Delete all nodes after head
        while (p != nullptr) {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        
        // Delete head
        delete head;
    }
};

int main() {
    Circular_Linked_List list;
    list.create(3);
    list.display();
    
    cout << "\nAfter InsertAtFront(100):" << endl;
    list.InsertAtFront(100);
    list.display();
    
    cout << "\nAfter InsertAtBack(200):" << endl;
    list.InsertAtBack(200);
    list.display();
    
    return 0;
}