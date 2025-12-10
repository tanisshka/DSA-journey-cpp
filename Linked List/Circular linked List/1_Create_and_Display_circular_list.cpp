#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Circular_Linked_List
{
private:
    Node *head;

public:
    Circular_Linked_List()
    {
        head = nullptr;
    }

    // Create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of nodes should be more than 0" << endl;
            return;
        }

        int x;
        cout << "Enter data value of Node 1: ";
        cin >> x;

        head = new Node{x, nullptr};
        head->next = head; // circular
        Node *p = head;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value of Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            temp->next = head;
            p->next = temp;
            p = temp;
        }
    }

    // Display function (Iterative)
    void Display()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
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

    // Recursive display wrapper
    void Recursive_Display()
    {
        static bool firstCall = true;

        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        if (firstCall)
        {
            firstCall = false;
            Recursive_display(head);
            firstCall = true;
        }
    }

    // Recursive display helper
    void Recursive_display(Node *p)
    {
        static bool visited = false;
        static int i = 1;

        if (p == head && visited)
        {
            visited = false;
            i = 1;
            return;
        }

        visited = true;
        cout << "Data value of Node " << i << ": " << p->data << endl;
        i++;

        Recursive_display(p->next);
    }

    ~Circular_linked_list(){
        if(head==nullptr){
            return;
        }

        Node *p=head->next;

        head->next=nullptr;

        while(p!=head){
            Node *temp=p;
            p=p->next;
            delete temp;
        }
        delete head;
    }
};

// ⭐ MAIN FUNCTION ⭐
int main()
{
    Circular_Linked_List list;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    list.create(n);

    cout << "\nIterative Display:\n";
    list.Display();

    cout << "\nRecursive Display:\n";
    list.Recursive_Display();

    return 0;
}
