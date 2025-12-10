#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}

class Circular_linked_list{
    private:
    Node *head;

    public:
    //Contructor
    Circular_linked_list(){
        head=nullptr;
    }

    //create function
    void create(int n){
        if(n<=0){
            cout<<"Number of nodes should be more than 0"<<endl;
            return;
        }

        int x;
        cout<<"Enter data value of Node 1:";
        cin>>x;
        head=new Node{x,nullptr};
        head->next=head;
        
        Node *p=head;
        for(int i=2;i<=n;i++){
            cout<<"Enter data value for Node "<<i<<": ";
            cin>>x;
            Node *temp=new Node{x,nullptr};
            temp->next=head;
            p->next=temp;
            p=temp;
        }
    }

    //display function
    void display(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node *p=head;
        int i=1;
        do{
            cout<<"Data value of Node "<<i<<": "<<p->data<<endl;
            p=p->next;
            i++;
        }while(p!=head);
    }

    //Destructor
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


}