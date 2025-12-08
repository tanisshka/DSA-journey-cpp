// Inserting elements in the linked list

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Linked_List{
private:
    Node *first;

public:
    Linked_List(){
        first = nullptr;
    }

    // Create function
    void create(int n){
        if(n <= 0) return;

        int x;
        cout << "Enter the value for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for(int i = 2; i <= n; i++){
            cout << "Enter the value for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    // Display function
    void display(){
        Node *p = first;
        int i = 1;

        while(p != nullptr){
            cout << "Data " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    // Insert element at front
    void Insert_at_front(int x){
        Node *t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }

    // Insert at any position
    void Insert(int position, int x){
        if(position < 0)
            return;  

        Node *t = new Node;
        t->data = x;
        t->next = nullptr;

        // Case 1: insert at front (also covers empty list)
        if(position == 0){
            t->next = first;
            first = t;
            return;
        }

        // Case 2: insert in middle or end
        Node *p = first;

        for(int i = 1; i < position && p->next != nullptr; i++){
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }


    void InsertAtLast(int x){
        Node *t=new Node;
        t->data=x;
        t->next=nullptr;

        if(first==nullptr){
            first=t;
            return;
        }
        Node *p=first;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=t;
    }

    // Destructor
    ~Linked_List(){
        Node *p = first;
        while(p != nullptr){
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

    cout << "\nOriginal Linked List:\n";
    list.display();

    // Insert at front
    int x;
    cout << "\nEnter value to insert at front: ";
    cin >> x;

    list.Insert_at_front(x);

    cout << "\nLinked List after inserting at front:\n";
    list.display();

    // Insert at position
    int pos, value;
    cout << "\nEnter position to insert: ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;

    list.Insert(pos, value);

    cout << "\nLinked List after inserting at position " << pos << ":\n";
    list.display();

    return 0;
}
