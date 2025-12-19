#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class Circular_Doubly_Linked_List
{
private:
    Node *head;

public:
    // Constructor
    Circular_Doubly_Linked_List()
    {
        head = nullptr;
    }

    // Create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of nodes cannot be less than zero" << endl;
            return;
        }

        int x;
        cout << "Enter data value of Node 1: ";
        cin >> x;
        head = new Node{nullptr, x, nullptr};
        Node *p = head;
        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ": ";
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
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot display" << endl;
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

    // Delete From front function
    int DeleteFront()
    {
        // Case 1: 0 nodes
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete!" << endl;
            return -1;
        }
        int x;
        // Case 2: 1 node
        if (head->next == head)
        {
            Node *temp = head;
            x = head->data;
            head = nullptr;
            delete temp;
            return x;
        }

        // Case 3: multiple nodes
        Node *temp = head;
        x = head->data;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
        return x;
    }

    // Delete from back function
    int DeleteBack()
    {
        // Case 1: 0 nodes
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete!" << endl;
            return -1;
        }

        int x;
        // Case 2: 1 node
        if (head->next == head)
        {
            Node *temp = head;
            x = head->data;
            head = nullptr;
            delete temp;
            return x;
        }

        // Case 3: multiple nodes
        Node *p = head->prev;
        x = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return x;
    }

    // Delete at a given position function
    int DeleteAtPosition(int pos)
    {
        // Case 1: pos <= 0
        if (pos <= 0)
        {
            cout << "Position cannot be less than or equal to zero!" << endl;
            return -1;
        }

        // Case 2: List is empty
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete!" << endl;
            return -1;
        }

        int x;
        // Case 3: Position == 1
        if (pos == 1)
        {
            // Case 3.1: 1 node
            if (head->next == head)
            {
                Node *temp = head;
                head = nullptr;
                x = temp->data;
                delete temp;
                return x;
            }

            // Case 3.2: multiple nodes
            Node *temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            x = temp->data;
            delete temp;
            return x;
        }

        // Case 4: pos > 1
        Node *p = head;
        for (int i = 1; i < pos; i++)
        {
            p = p->next;

            // If it has completed the circle, the position is out of bounds
            if (p == head)
            {
                cout << "Position " << pos << " is out of bounds" << endl;
                return -1;
            }
        }

        // Delete the node at position
        x = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return x;
    }

    // Destructor function
    ~Circular_Doubly_Linked_List()
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

int main()
{
    Circular_Doubly_Linked_List list;
    
    cout << "Creating a list with 4 nodes:" << endl;
    list.create(4);
    
    cout << "\nDisplaying list:" << endl;
    list.display();
    
    cout << "\nDeleting from front:" << endl;
    int deleted = list.DeleteFront();
    cout << "Deleted value: " << deleted << endl;
    list.display();
    
    cout << "\nDeleting from back:" << endl;
    deleted = list.DeleteBack();
    cout << "Deleted value: " << deleted << endl;
    list.display();
    
    cout << "\nDeleting at position 2:" << endl;
    deleted = list.DeleteAtPosition(2);
    cout << "Deleted value: " << deleted << endl;
    list.display();
    
    cout << "\nTrying to delete at invalid position 5:" << endl;
    deleted = list.DeleteAtPosition(5);
    
    return 0;
}