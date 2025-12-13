#include<iostream>
using namespace std;

struct Node{
    Node* prev;
    int data;
    Node* next;
};

class Doubly_Linked_List{
    private:
    Node* first;

    public:
    //Constructor
    Doubly_Linked_List(){
        first=nullptr;
    }

    //Create function
    void create(int n){
        if(n<=0){
            cout<<"Number of terms cannot be less than zero"<<endl;
            return;
        }

        int x;
        cout<<"Enter data value for Node 1:";
        cin>>x;
        first=new Node{nullptr,x,nullptr};
        Node *p=first;

        for(int i=2;i<=n;i++){
            cout<<"Enter data value for Node "<<i<<": ";
            cin>>x;
            Node *temp=new Node{nullptr,x,nullptr};
            p->next=temp;
            temp->prev=p;
            p=temp;
        }
    }

    //Display function
    void display(){
        if(first==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node *p=first;
        int i=1;
        while(p!=nullptr){
            cout<<"Data value at Node "<<i<<": "<<p->data<<endl;
            p=p->next;
            i++;
        }
    }


    //Destructor
    ~Doubly_Linked_List(){
        Node *p=first;
        while(p!=nullptr){
            Node *temp=p;
            p=p->next;
            delete temp;
        }
    }
};

int main(){
    Doubly_Linked_List dll;
    dll.create(5);
    dll.display();
       return 0;
    return 0;
}