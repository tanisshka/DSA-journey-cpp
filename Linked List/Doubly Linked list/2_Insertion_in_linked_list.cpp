#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class Doubly_Linked_List
{
private:
    Node *first;

public:
    // Constructor
    Doubly_Linked_List()
    {
        first = nullptr;
    }

    // Create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of terms cannot be less than zero" << endl;
            return;
        }

        int x;
        cout << "Enter data value for Node 1:";
        cin >> x;
        first = new Node{nullptr, x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ": ";
            cin >> x;
            Node *temp = new Node{nullptr, x, nullptr};
            p->next = temp;
            temp->prev = p;
            p = temp;
        }
    }

    // Display function
    void display()
    {
        if (first == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = first;
        int i = 1;
        while (p != nullptr)
        {
            cout << "Data value at Node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    // Insert At front function
    void InsertAtFront(int x)
    {
        Node *t = new Node{nullptr, x, nullptr};

        // Case 1: 0 nodes
        if (first == nullptr)
        {
            first = t;
            return;
        }

        // Case 2: multiple nodes
        t->next = first;
        first->prev = t;
        first = t;
    }

    // Insert At Back
    void InsertAtBack(int x)
    {
        Node *t = new Node{nullptr, x, nullptr};

        // Case 1:0 nodes
        if (first == nullptr)
        {
            first = t;
            return;
        }

        // Case 2: multiple nodes
        Node *p = first;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }

    // Insert at any given position
    void InsertAtPosition(int pos, int x)
    {
        // Case 1: position is invalid
        if (pos <= 0)
        {
            cout << "Position must be greater than zero!" << endl;
            return;
        }

        Node *t = new Node{nullptr, x, nullptr};

        // Case 2: Position == 1
        if (pos == 1)
        {
            if (first == nullptr)
            {
                first = t;
                return;
            }

            t->next = first;
            first->prev = t;
            first = t;
            return;
        }

        // Case 3: Position is greater than 1
        if (first == nullptr)
        {
            first = t;
            return;
        }

        Node *p = first;
        for (int i = 1; i < pos - 1 && p != nullptr; i++)
        { // Changed to pos-1
            p = p->next;
        }

        if (p == nullptr)
        { // Position is beyond list length
            cout << "Position out of bounds!" << endl;
            delete t;
            return;
        }

        Node *q = p->next;
        p->next = t;
        t->prev = p; // Added semicolon

        if (q != nullptr)
        {
            t->next = q;
            q->prev = t;
        }
    }

    // Destructor
    ~Doubly_Linked_List()
    {
        Node *p = first;
        while (p != nullptr)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main()
{
    Doubly_Linked_List dll;

    // Create a list with 3 nodes
    dll.create(3);

    cout << "\nOriginal List:" << endl;
    dll.display();

    // Insert at front
    dll.InsertAtFront(99);
    cout << "\nAfter inserting 99 at front:" << endl;
    dll.display();

    dll.InsertAtFront(88);
    cout << "\nAfter inserting 88 at front:" << endl;
    dll.display();

    // Test InsertAtBack
    dll.InsertAtBack(77);
    cout << "\nAfter inserting 77 at back:" << endl;
    dll.display();

    dll.InsertAtBack(66);
    cout << "\nAfter inserting 66 at back:" << endl;
    dll.display();

    return 0;
}