#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}; 

class Circular_linked_list
{
private:
    Node *head;

public:
    // Constructor
    Circular_linked_list()
    {
        head = nullptr;
    }

    // create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of nodes should be more than 0" << endl;
            return;
        }

        int x;
        cout << "Enter data value of Node 1:";
        cin >> x;
        head = new Node{x, nullptr};
        head->next = head;

        Node *p = head;
        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ": ";
            cin >> x;
            Node *temp = new Node{x, nullptr};
            temp->next = head;
            p->next = temp;
            p = temp;
        }
    }

    // display function
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = head;
        int i = 1;
        do
        {
            cout << "Data value of Node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        } while (p != head);
    }

    // Insert front
    void InsertFront(int x)
    {
        Node *t = new Node{x, nullptr};

        if (head == nullptr)
        {
            head = t;
            t->next = head; // Make it circular
            return;         // Early return
        }

        t->next = head;
        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        head = t;
    }

    // Insert at back function
    void InsertAtBack(int x)
    {
        Node *t = new Node{x, nullptr};

        if (head == nullptr)
        {
            head = t;
            t->next = head;
            return;
        }

        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        t->next = head;
    }

    void Insert(int pos, int x)
    {
        if (pos < 0)
        {
            cout << "Position cannot be less than zero" << endl;
            return;
        }

        Node *t = new Node{x, nullptr};

        // Handle position 0 (insert at front)
        if (pos == 0)
        {
            if (head == nullptr)
            {
                head = t;
                t->next = head;
                return;
            }

            t->next = head;
            Node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            head = t;
            return; 
        }

        // Handle empty list for pos > 0
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert at position " << pos << endl;
            delete t;
            return;
        }

        // Traverse to position
        Node *p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;

            // Check if we've completed a full circle
            if (p == head)
            {
                cout << "Position " << pos << " is out of bounds" << endl;
                delete t;
                return;
            }
        }

        // Insert the node
        t->next = p->next;
        p->next = t;
    }
    // Destructor
    ~Circular_linked_list()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *p = head->next;
        head->next = nullptr; // Break the circle

        while (p != nullptr)
        { // Changed condition
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        delete head;
    }
}; 