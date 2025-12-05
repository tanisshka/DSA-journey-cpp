//Find the sum of all elements
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
        first = nullptr;
    }

    void create(int n){
        if(n <= 0){
            return;
        }

        int x;
        cout << "Enter the value for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for(int i = 2; i <= n; i++){
            cout << "Enter the value for Node " << i << ": ";
            cin >> x;

            Node *temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    void display(){
        Node *p = first;
        int i = 1;

        while(p != nullptr){
            cout << "Data " << i << ": " << p->data << endl;
            p = p->next;
            i++;
        }
    }

    int sum(){
        Node *p = first;
        int s = 0;

        while(p != nullptr){
            s += p->data;
            p = p->next;
        }

        return s;
    }

    int sum_Recursion(Node *p){
        if(p==nullptr){
            return 0;
        }
        return sum_Recursion(p->next)+p->data;
    }

    int sum_Recursion(){
        return sum_Recursion(first);
    }

    ~Linked_List(){
        Node *p = first;
        while(p != nullptr){
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }

};

int main(){
    Linked_List ll;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ll.create(n);

    cout << "\n--- Linked List Elements ---\n";
    ll.display();

    cout << "\nSum of all nodes = " << ll.sum() << endl;
    cout << "Sum (recursive) = " << ll.sum_Recursion() << endl;

    return 0;
}
