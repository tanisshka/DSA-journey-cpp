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

    void create(int n)
    {
        if (n <= 0)
        {
            cout << "n is less than 0";
            return;
        }

        int x;
        cout << "Enter the value of node 1 :";
        cin >> x;
        first = new Node{x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++)
        {
            int x;
            cout << "Enter the value of node " << i << " :";
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
            cout << "Data " << i << " : " << p->data << endl;
            cout << "Next Pointer: " << i << " : " << p->next << endl;
            p = p->next;
            i++;
        }
    }

    void Display_Recursive(Node *p)
    {
        if (p != nullptr)
        {
            cout << "Data: " << p->data;
            Display_Recursive(p->next);
        }
    }

    void Display_Recursive()
    {
        Display_Recursive(first);
    }

    void Display_Recursive_Reverse_Order(Node *p)
    {
        if (p != nullptr)
        {
            Display_Recursive_Reverse_Order(p->next);
            cout << p->data << endl;
        }
    }

    void Display_Recursive_Reverse_Order()
    {
        Display_Recursive_Reverse_Order(first);
    }

    ~Linked_list()
    {
        Node *p = first;
        while (p != nullptr)
        {
            Node *temp = p;
            p = p->next;
            delete temp; // frees each node
        }
    }
};

int main()
{
    Linked_list L;

    int n;
    cout << "How many nodes do you want to create? ";
    cin >> n;

    L.create(n);

    cout << "\nThe linked list is:\n";
    L.display();
    cout << "--------------------------" << endl;
    L.Display_Recursive_Reverse_Order();

    return 0;
}