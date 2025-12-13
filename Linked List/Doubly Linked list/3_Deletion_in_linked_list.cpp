#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class Doubly_Linked_List
{
private:
    Node *first;

public:
    // Constructor
    Doubly_Linked_List()
    {
        first = nullptr;
    }

    // Create function
    void create(int n)
    {
        if (n <= 0)
        {
            cout << "Number of terms cannot be less than zero" << endl;
            return;
        }

        int x;
        cout << "Enter data value for Node 1:";
        cin >> x;
        first = new Node{nullptr, x, nullptr};
        Node *p = first;

        for (int i = 2; i <= n; i++)
        {
            cout << "Enter data value for Node " << i << ": ";
            cin >> x;
            Node *temp = new Node{nullptr, x, nullptr};
            p->next = temp;
            temp->prev = p;
            p = temp;
        }
    }

    // Display function
    void display()
    {
        if (first == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = first;
        int i = 1;
        while (p != nullptr)
        {
            cout << "Data value at Node " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    // Delete at front
    int DeleteFront()
    {
        // Case 1: 0 nodes
        if (first == nullptr)
        {
            cout << "List is empty.Cannot delete!" << endl;
            return -1;
        }

        int x;
        // Case 2: 1 node
        if (first->next == nullptr)
        {
            Node *p = first;
            x = p->data;
            first = nullptr;
            delete p;
            return x;
        }

        // Case 3:multiple nodes
        Node *p = first;
        first = first->next;
        x = p->data;
        delete p;
        first->prev = nullptr;
        return x;
    }

    // Delete from back
    int DeleteBack()
    {
        // Case 1: 0 nodes
        if (first == nullptr)
        {
            cout << "List is empty. Cannot delete" << endl;
            return -1;
        }

        int x;
        Node *p = first;

        // Case 2: 1 node
        if (first->next == nullptr)
        {
            first = nullptr;
            x = p->data;
            delete p;
            return x;
        }

        // Case 3: multiple nodes
        while (p->next != nullptr)
        {
            p = p->next;
        }
        x = p->data;
        p->prev->next = nullptr; 
        delete p;
        return x;
    }

    //Delete at given position
    int deleteAtPosition(int pos){
        //Case 1:Position is invalid
        if(pos<=0){
            cout<<"Position must be greater than zero"<<endl;
            return -1;
        }

        //Case 1.1:0  nodes 
        if(first==nullptr){
            cout<<"List is empty.Cannot delete!"<<endl;
            return -1;
        }

        int x;
        Node *p=first;
        //Case 2:position ==1
        if(pos==1){
            //Case 2.1: 1 node
            if(first->next==nullptr){
                first=nullptr;
                x=p->data;
                delete p;
                return x;
            }

            //Case 2.2: multiple nodes
            first=first->next;
            x=p->data;
            first->prev=nullptr;
            delete p;
            return x;
        }

        //Case 3:position > 1
        for(int i=1;i<pos && p!=nullptr;i++){
            p=p->next;
        }

        if(p==nullptr){
            cout<<"Position "<<pos<<" is out of bounds!"<<endl;
            return -1;
        }

        if(p->next!=nullptr){
            p->prev->next=p->next;
            p->next->prev=p->prev;
            x=p->data;
            delete p;
            return x;
        }else{
            p->prev->next=nullptr;
            x=p->data;
            delete p;
            return x;
        }

    }

    // Destructor
    ~Doubly_Linked_List()
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
    Doubly_Linked_List dll;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    dll.create(n);

    cout << "\nInitial list:\n";
    dll.display();

    cout << "\nDeleting from front...\n";
    dll.DeleteFront();
    dll.display();

    cout << "\nDeleting from back...\n";
    dll.DeleteBack();
    dll.display();

    int pos;
    cout << "\nEnter position to delete: ";
    cin >> pos;
    dll.deleteAtPosition(pos);

    cout << "\nFinal list:\n";
    dll.display();

    return 0;
}
