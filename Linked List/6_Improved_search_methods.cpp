// Searching the key element in the linked list
#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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

    void display()
    {
        Node *p = first;
        int i = 1;

        while (p != nullptr)
        {
            cout << "Data value at node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    // Improved search method using MTF(Move to Front)
    Node *Search(int key)
    {
        Node *p = first;
        Node *q = nullptr; // previous node pointer

        while (p != nullptr)
        {
            if (p->data == key)
            {
                if (q != nullptr)
                {
                    // unlink p from current position
                    q->next = p->next;

                    // move p to front
                    p->next = first;
                    first = p;
                }
                return p;
            }

            q = p;
            p = p->next;
        }
        return nullptr;
    }

    Node *Search_Recursive(Node *p, int key)
    {
        if (p == nullptr)
        {
            return nullptr;
        }
        else if (p->data == key)
        {
            return p;
        }
        else
        {
            return Search_Recursive(p->next, key);
        }
    }

    Node *Search_Recursive(int key)
    {
        return Search_Recursive(first, key);
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
    cout << "Enter number of nodes: ";
    cin >> n;

    list.create(n);

    cout << "\nLinked List Elements:\n";
    list.display();

    int key;
    cout << "\nEnter key to search (Move-To-Front): ";
    cin >> key;

    Node *result = list.Search(key);

    if (result != nullptr)
        cout << "\n(MTF) Key found! Node address = " << result << endl;
    else
        cout << "\n(MTF) Key NOT found in the list.\n";

    cout << "\nList after Move-To-Front search:\n";
    list.display();

    cout << "\nEnter key to search (Recursive): ";
    cin >> key;

    Node *result2 = list.Search_Recursive(key);

    if (result2 != nullptr)
        cout << "\n(Recursive) Key found! Node address = " << result2 << endl;
    else
        cout << "\n(Recursive) Key NOT found.\n";

    return 0;
}
