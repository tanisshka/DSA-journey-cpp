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


    Node *Search(int key)
    {
        Node *p = first;
        Node q=nullptr;
        while (p != nullptr)
        {
            if (p->data == key)
                return p;
            q=p;
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
    cout << "\nEnter key to search: ";
    cin >> key;

    Node *result = list.Search(key);

    if (result != nullptr)
        cout << "\nKey found! Address = " << result << endl;
    else
        cout << "\nKey NOT found in the list.\n";

    Node *result2 = list.Search_Recursive(key);

    if (result2 != nullptr)
        cout << "Recursive Search: Key found at address " << result2 << endl;
    else
        cout << "Recursive Search: Key NOT found.\n";

    return 0;
}
