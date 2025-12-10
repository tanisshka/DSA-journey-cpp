#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_list
{
private:
    Node *first;

public:
    Linked_list()
    {
        first = nullptr;
    }

    Node *getFirst() { return first; }
    void setFirst(Node *p) { first = p; }

    // Create list
    void create(int n)
    {
        if (n <= 0)
            return;

        int x;
        cout << "Enter data for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    // Display
    void display()
    {
        Node *p = first;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Check is there is loop in linked list
    int isLoop()
    {
        if (first == nullptr)
        {
            return -1;
        }

        Node *p = first;
        Node *q = first;

        while (q && q->next)
        {
            p = p->next;       // slow pointer
            q = q->next->next; // fast pointer

            if (p == q)
            {
                return 1; // loop found
            }
        }

        return 0; // no loop
    }

    // Destructor
    ~Linked_list()
    {
        Node *p = first;
        while (p)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main()
{
    Linked_list L;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    L.create(n);

    cout << "\nYour Linked List: ";
    L.display();

    cout << "\nDo you want to create a loop? (1 = Yes, 0 = No): ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        int pos;
        cout << "Enter the position where last node should connect (1 to " << n << "): ";
        cin >> pos;

        // Validate position
        if (pos >= 1 && pos <= n)
        {
            Node* head = L.getFirst();
            Node* tail = head;

            // Move tail to last node
            while (tail->next != nullptr)
                tail = tail->next;

            // Move to desired position node
            Node* loopNode = head;
            for (int i = 1; i < pos; i++)
                loopNode = loopNode->next;

            // Create loop
            tail->next = loopNode;

            cout << "\nLoop created: Last node now points to node at position " << pos << endl;
        }
        else
        {
            cout << "Invalid position. No loop created.\n";
        }
    }

    cout << "\nChecking for loop...\n";

    int result = L.isLoop();

    if (result == 1)
        cout << "Result: LOOP FOUND in the linked list.\n";
    else if (result == 0)
        cout << "Result: No loop detected.\n";
    else
        cout << "List is empty.\n";

    return 0;
}
