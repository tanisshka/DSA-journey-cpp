//Problem: Find the middle node of the single linked list
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Linked_List{
    private:
    Node *first;

    public:
    Linked_List(){
        first=nullptr;
    }

    int finding_middle_node_sol1(){
        int length=count();
        int middle_node;
        //Length is even
        if(length%2==0){
            middle_node=length/2;
            return middle_node;
        }else{
            middle_node=(length+1)/2;
            return middle_node;
        }
    }

    //Slow and fast pointer function method
    int finding_middle_node_sol2(){
        Node *p=first;
        Node *q=first;
        int middle_node;
        while(q){
            q=q->next;
            if(q){
                q=q->next;
                p=p->next;  
            }
        }
        middle_node=p->data;
        return middle_node;
    }

    void create(int n){
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
            p->next=temp;
            p=temp;
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

    int count(){
        Node *p=first;
        int c=0;
        while(p){
            p=p->next;
            c++;
        }
        return c;
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

int main(){
    Linked_List list;
    int n;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    list.create(n);
    
    cout << "\n--- Displaying List ---\n";
    list.display();
    
    cout << "\n--- Finding Middle Node ---\n";
    cout << "Total nodes: " << list.count() << endl;
    cout << "Middle node position (Sol 1): " << list.finding_middle_node_sol1() << endl;
    cout << "Middle node value (Sol 2): " << list.finding_middle_node_sol2() << endl;
    
    return 0;
}