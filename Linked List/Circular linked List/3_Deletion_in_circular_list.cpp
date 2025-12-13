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
    Circular_linked_list()
    {
        head = nullptr;
    }

    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of nodes cannot be less than zero" << endl;
            return;
        }

        int x;
        cout << "Enter data value for Node 1:";
        cin >> x;
        head = new Node{x, nullptr};
        head->next = head;
        Node *p = head;
        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ": ";
            cin >> x;
            Node *temp = new Node{x, nullptr}; // FIXED: Added 'new Node'
            temp->next = head;
            p->next = temp;
            p = temp;
        }
    }

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

    // Delete Front
    int deleteFront()
    {
        // Case 1:0 node
        if (head == nullptr)
        {
            cout << "List is empty.Cannot delete" << endl;
            return -1;
        }
        int x = head->data;

        // Case 2: 1 node
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return x;
        }

        // Case 3: Multiple nodes
        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }

        p->next = head->next;
        Node *temp = head;
        head = head->next;
        delete temp;
        return x;
    }

    // Delete at back
    int DeleteBack()
    {
        // Case 1: 0 nodes
        if (head == nullptr)
        {
            cout << "List is empty.Cannot delete" << endl;
            return -1;
        }

        int x;
        // Case 2: 1 node
        if (head->next == head)
        {
            x = head->data;
            delete head;
            head = nullptr;
            return x;
        }

        // Case 3: multiple nodes
        Node *p = head;
        Node *q = nullptr;

        while (p->next != head)
        {
            q = p;
            p = p->next;
        }
        q->next = head;
        x = p->data;
        delete p;
        return x;
    }

    // Delete at a given position
    // Delete at a given position
    int DeleteAtPosition(int pos)
    {
        // Case 1: If position is invalid
        if (pos <= 0)
        {
            cout << "Position cannot be less than or equal to zero" << endl;
            return -1;
        }

        // Case 2: List is empty
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete" << endl;
            return -1;
        }

        int x;

        // Case 3: Delete at position 1 (front)
        if (pos == 1)
        {
            x = head->data;

            // Case 3.1: Only one node
            if (head->next == head) 
            {
                delete head;
                head = nullptr;
                return x;
            }

            // Case 3.2: Multiple nodes
            Node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = head->next; 
            Node *temp = head;
            head = head->next;
            delete temp;
            return x;
        }
        else
        {
            // Case 4: Position is greater than 1
            Node *p = head;

            // Traverse to the node BEFORE the position to delete
            for (int i = 1; i < pos - 1; i++)
            {
                p = p->next;

                // Check if we've looped back to head (position out of bounds)
                if (p == head)
                {
                    cout << "Position " << pos << " is out of bounds" << endl;
                    return -1;
                }
            }

            Node *q = p->next; // q is the node to delete

            // Check if the target position exists
            if (q == head)
            {
                cout << "Position " << pos << " is out of bounds" << endl;
                return -1;
            }

            x = q->data;       
            p->next = q->next; 
            delete q;          
            return x;
        }
    }

    ~Circular_linked_list()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *p = head->next;
        head->next = nullptr;

        while (p != nullptr)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        delete head;
    }
};