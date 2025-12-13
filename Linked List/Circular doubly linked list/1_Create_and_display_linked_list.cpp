#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class Circular_Doubly_Linked_list
{
private:
    Node *head;

public:
    Circular_Doubly_Linked_list()
    {
        head = nullptr;
    }

    // Create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of nodes should be more than zero" << endl;
            return;
        }

        int x;
        cout << "Enter data value for Node 1:";
        cin >> x;
        head = new Node{nullptr, x, nullptr};
        Node *p = head;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ":";
            cin >> x;
            Node *temp = new Node{nullptr, x, nullptr};
            temp->prev = p;
            p->next = temp;
            p = temp;
        }

        head->prev = p;
        p->next = head;
    }

    // Display function
    // Display function
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

    ~Circular_Doubly_Linked_list()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *p = head->next; // Start from second node
        head->next = nullptr; // Break the circular link

        // Delete all nodes after head
        while (p != nullptr)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }

        // Delete head
        delete head;
    }
};

int main()
{
    Circular_Doubly_Linked_list cdll;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cdll.create(n);

    cout << "\nCircular Doubly Linked List:\n";
    cdll.display();

    return 0;
}
