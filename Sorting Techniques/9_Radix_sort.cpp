#include<iostream>
#include<algorith>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
}

void Insert(Node* &head,int x){
    Node t=new Node{x,nullptr};

    if(head==nullptr){
        head=t;
        return;
    }
    Node *p=head;
    while(p->next){
        p=p->next;
    }
    p->next=t;
}

int Delete(Node* &head){
    //No nodes
    if(head==nullptr){
        return -1;
    }
    //1 Node
    if(head->next==nullptr){
        int x=head->data;
        delete head;
        head=nullptr;
        return x;
    }
    
    //2 Node
    Node* p=head;
    Node* q=nullptr;

    while(p->next){
        q=p;
        p=p->next;
    }

    int x=p->data;
    q=nullptr;
    delete p;
    return x;
}

