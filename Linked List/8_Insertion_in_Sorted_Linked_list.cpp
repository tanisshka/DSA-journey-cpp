#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}; // ← missing semicolon added

class Linked_List
{
private:
    Node *first;

public:
    Linked_List()
    {
        first = nullptr;
    }

    void Display()
    {
        Node *p = first;
        int i = 1;
        while (p != nullptr)
        {
            cout << "Data " << i << ": " << p->data << endl;
            p = p->next; // ← YOU MISSED THIS!
            i++;
        }
    }

    // Insert into sorted linked list
    void Insert(int x)
    {
        Node *t = new Node;
        t->data = x;
        t->next = nullptr;

        if (first == nullptr)
        {
            first = t;
            return;
        }

        Node *p = first;
        Node *q = nullptr;

        // Traverse to find insertion position
        while (p != nullptr && x > p->data)
        {
            q = p;
            p = p->next;
        }

        // Duplicate check
        if (p != nullptr && p->data == x)
        {
            cout << "Duplicate not allowed: " << x << endl;
            delete t;
            return;
        }

        // Insert at beginning
        if (q == nullptr)
        {
            t->next = first;
            first = t;
        }
        else
        { // Insert in between or at end
            t->next = p;
            q->next = t;
        }
    }

    ~Linked_List() {
    Node* p = first;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}
};

int main()
{
    Linked_List ll;

    // Insert elements (unsorted)
    ll.Insert(30);
    ll.Insert(10);
    ll.Insert(50);
    ll.Insert(40);
    ll.Insert(20);

    cout << "Sorted Linked List:\n";
    ll.Display();

    return 0;
}
