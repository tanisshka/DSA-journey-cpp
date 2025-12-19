//Problem: Find the intersection point of two intersecting lists
#include<iostream>
#include<stack>
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

    // Function to find intersection point using stack
    static Node* find_intersection_using_stack(Linked_List &list1, Linked_List &list2){
        stack<Node*> s1, s2;
        
        // Push all nodes of first list into stack s1
        Node *p = list1.first;
        while(p){
            s1.push(p);
            p = p->next;
        }
        
        // Push all nodes of second list into stack s2
        Node *q = list2.first;
        while(q){
            s2.push(q);
            q = q->next;
        }
        
        Node *intersection = nullptr;
        
        // Pop and compare addresses from both stacks
        while(!s1.empty() && !s2.empty()){
            Node *node1 = s1.top();
            Node *node2 = s2.top();
            
            // If addresses are same, store it and pop both
            if(node1 == node2){
                intersection = node1;
                s1.pop();
                s2.pop();
            }
            else{
                // Addresses are different, break the loop
                break;
            }
        }
        
        return intersection;
    }

    // Helper function to manually create intersection for testing
    void create_intersection_at(Linked_List &other_list, int position){
        if(position <= 0 || position > count()){
            cout << "Invalid position for intersection\n";
            return;
        }
        
        Node *p = first;
        for(int i = 1; i < position && p != nullptr; i++){
            p = p->next;
        }
        
        // Find the last node of other_list
        Node *q = other_list.first;
        while(q && q->next){
            q = q->next;
        }
        
        // Make intersection
        if(q){
            q->next = p;
        }
    }

    void create(int n){
        if (n <= 0)
        {
            cout << "n is less than 0\n";
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
            cout << "Address " << i << " : " << p << endl;
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

    Node* get_first(){
        return first;
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
    Linked_List list1, list2;
    
    cout << "=== Creating First List ===\n";
    int n1;
    cout << "Enter number of nodes for list 1: ";
    cin >> n1;
    list1.create(n1);
    
    cout << "\n=== Creating Second List ===\n";
    int n2;
    cout << "Enter number of nodes for list 2: ";
    cin >> n2;
    list2.create(n2);
    
    // Create intersection manually for testing
    cout << "\n=== Creating Intersection ===\n";
    cout << "Enter position in list 1 where intersection should occur (1 to " << list1.count() << "): ";
    int pos;
    cin >> pos;
    list1.create_intersection_at(list2, pos);
    
    cout << "\n=== List 1 ===\n";
    list1.display();
    
    cout << "\n=== List 2 (with intersection) ===\n";
    list2.display();
    
    // Find intersection
    Node* intersection = Linked_List::find_intersection_using_stack(list1, list2);
    
    if(intersection){
        cout << "\n=== Intersection Found ===\n";
        cout << "Intersection point data: " << intersection->data << endl;
        cout << "Intersection point address: " << intersection << endl;
    }
    else{
        cout << "\n=== No Intersection Found ===\n";
    }
    
    return 0;
}