//Find the count of number of nodes in the linked list
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
            cout << "Invalid size\n";
            return;
        }

        int x;
        cout << "Enter value for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node *p = first;

        for(int i = 2; i <= n; i++){
            cout << "Enter value for Node " << i << ": ";
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

    int count(){
        Node *p = first;
        int cnt = 0;

        while(p != nullptr){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    int count_recursive(Node *p){
        if(p != nullptr)
            return 1 + count_recursive(p->next);
        return 0;
    }

    int count_recursive(){
        return count_recursive(first);
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

    cout << "\n--- Linked List ---\n";
    ll.display();

    cout << "\nTotal nodes (iterative) = " << ll.count() << endl;
    cout << "Total nodes (recursive) = " << ll.count_recursive() << endl;

    return 0;
}
