#include <iostream>
#include <queue>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};

class Binary_Tree {
private:
    Node* root;

    void Inorder(Node* p);
    void Preorder(Node* p);
    void Postorder(Node* p);
    void DestroyTree(Node* p);
    int Sum_of_node_values(Node *p);

public:
    Binary_Tree();
    ~Binary_Tree();

    void Create_Tree();
    void LevelOrder();
    void Display(int order = 1);
    void Sum_of_node_values();


};

// ---------------- Constructor ----------------
Binary_Tree::Binary_Tree() {
    root = nullptr;
}

// ---------------- Destructor ----------------
Binary_Tree::~Binary_Tree() {
    DestroyTree(root);
    cout << "\nTree destroyed successfully" << endl;
}

// ---------------- Destroy Tree ----------------
void Binary_Tree::DestroyTree(Node* p) {
    if (p == nullptr)
        return;

    DestroyTree(p->lchild);
    DestroyTree(p->rchild);
    delete p;
}

// ---------------- Create Tree ----------------
void Binary_Tree::Create_Tree() {
    int rootVal;
    cout << "Enter root value: ";
    cin >> rootVal;

    root = new Node{nullptr, rootVal, nullptr};
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << p->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            p->lchild = new Node{nullptr, leftVal, nullptr};
            q.push(p->lchild);
        }

        cout << "Enter right child of " << p->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            p->rchild = new Node{nullptr, rightVal, nullptr};
            q.push(p->rchild);
        }
    }
}

// ---------------- Traversals ----------------
void Binary_Tree::Preorder(Node* p) {
    if (!p) return;
    cout << p->data << " ";
    Preorder(p->lchild);
    Preorder(p->rchild);
}

void Binary_Tree::Inorder(Node* p) {
    if (!p) return;
    Inorder(p->lchild);
    cout << p->data << " ";
    Inorder(p->rchild);
}

void Binary_Tree::Postorder(Node* p) {
    if (!p) return;
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout << p->data << " ";
}

// ---------------- Level Order ----------------
void Binary_Tree::LevelOrder() {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        cout << p->data << " ";
        if (p->lchild) q.push(p->lchild);
        if (p->rchild) q.push(p->rchild);
    }
}

// ---------------- Display ----------------
void Binary_Tree::Display(int order) {
    if (!root) {
        cout << "Tree is empty!" << endl;
        return;
    }

    switch (order) {
        case 1:
            cout << "Inorder: ";
            Inorder(root);
            break;
        case 2:
            cout << "Preorder: ";
            Preorder(root);
            break;
        case 3:
            cout << "Postorder: ";
            Postorder(root);
            break;
        case 4:
            cout << "Levelorder: ";
            LevelOrder();
            break;
        default:
            cout << "Invalid option!";
    }
    cout << endl;
}


int Binary_Tree::Sum_of_node_values(Node *p){
    int x,y;
    if(p==nullptr){
        return 0;
    }
    x=Sum_of_node_values(p->lchild);
    y=Sum_of_node_values(p->rchild);
    return x+y+p->data;
}

void Binary_Tree::Sum_of_node_values(){
    cout<<"Sum of all values in the Tree: "<<Sum_of_node_values(root)<<endl;
}



// ---------------- Main ----------------
int main() {
    Binary_Tree tree;

    tree.Create_Tree();

    cout << "\n--- Traversals ---\n";
    tree.Display(1);
    tree.Display(2);
    tree.Display(3);
    tree.Display(4);

    cout << "\n--- Sum of Node Values ---\n";
    tree.Sum_of_node_values();

    return 0;
}
