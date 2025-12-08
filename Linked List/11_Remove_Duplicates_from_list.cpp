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

    void create(int n)
    {
        if (n <= 0)
            return;

        int x;
        cout << "Enter the value for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter the value for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
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

    // Function to check if linked list is sorted
    int IsSorted()
    {
        if (first == nullptr)
        {
            cout << "List is empty" << endl;
            return -1;
        }

        Node *p = first;
        int x = INT_MIN;
        while (p != nullptr)
        {
            if (p->data < x)
            {
                return 0;
            }
            x = p->data;
            p = p->next;
        }
        return 1;
    }

    void RemoveDuplicate()
    {
        if (first == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *p = first;
        Node *q = first->next;

        while (q != nullptr)
        {
            if (p->data == q->data)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
    }

    ~Linked_List()
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
    Linked_List list;
    int n;

    cout << "Enter number of nodes to create: ";
    cin >> n;

    list.create(n);

    cout << "\nOriginal Linked List:\n";
    list.Display();

    // Check sorting first
    int sorted = list.IsSorted();

    if (sorted == -1) {
        cout << "\nCannot check duplicates because the list is empty.\n";
        return 0;
    }
    else if (sorted == 0) {
        cout << "\nThe list is NOT sorted. Cannot remove duplicates.\n";
        return 0;
    }

    cout << "\nThe list IS sorted. Removing duplicates...\n";
    list.RemoveDuplicate();

    cout << "\nLinked List after removing duplicates:\n";
    list.Display();

    return 0;
}
