#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};

class Binary_Search_Tree {
private:
    Node* root;

    void Preorder(Node* p);
    void Inorder(Node* p);
    void Postorder(Node* p);
    void Destroy(Node* p);
    Node* RecursiveInsert(Node* p, int key);
    Node* IterativeSearch(Node *p,int key);
    Node *RecursiveSearch(Node *p,int key);


public:
    Binary_Search_Tree();
    ~Binary_Search_Tree();

    void CreateTree(const vector<int>& arr);
    void Insert(int key);
    void Display(int order = 1);
    void Levelorder();
    Node* RecursiveSearch(int key);
    Node* IterativeSearch(int key);
};

/* ---------- Constructor & Destructor ---------- */

Binary_Search_Tree::Binary_Search_Tree() {
    root = nullptr;
}

Binary_Search_Tree::~Binary_Search_Tree() {
    Destroy(root);
    cout << "Tree destroyed successfully\n";
}

/* ---------- Core Operations ---------- */

Node* Binary_Search_Tree::RecursiveSearch(Node *p,int key){
    if(p==nullptr){
        return nullptr;
    }else{
        if(p->data==key){
            return p;
        }else if(p->data<key){
            return RecursiveSearch(p->rchild,key);
        }else{
            return RecursiveSearch(p->lchild,key);
        }
    }
}

Node* Binary_Search_Tree::RecursiveSearch(int key){
    Node *t=RecursiveSearch(root,key);
    return t;
}

Node* Binary_Search_Tree::IterativeSearch(Node *p,int key){
    while(p!=nullptr){
        if(p->data==key){
            return p;
        }else if(p->data<key){
            p=p->rchild;
        }else{
            p=p->lchild;
        }
    }
    return nullptr;
}

Node* Binary_Search_Tree::IterativeSearch(int key){
    Node *t=IterativeSearch(root,key);
    return t;
}

Node* Binary_Search_Tree::RecursiveInsert(Node* p, int key) {
    if (p == nullptr) {
        return new Node{nullptr, key, nullptr};
    }

    if (key < p->data)
        p->lchild = RecursiveInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsert(p->rchild, key);
    // duplicates ignored

    return p;
}

void Binary_Search_Tree::Insert(int key) {
    root = RecursiveInsert(root, key);
}

void Binary_Search_Tree::CreateTree(const vector<int>& arr) {
    for (int x : arr) {
        Insert(x);
    }
}

/* ---------- Traversals ---------- */

void Binary_Search_Tree::Inorder(Node* p) {
    if (!p) return;
    Inorder(p->lchild);
    cout << p->data << " ";
    Inorder(p->rchild);
}

void Binary_Search_Tree::Preorder(Node* p) {
    if (!p) return;
    cout << p->data << " ";
    Preorder(p->lchild);
    Preorder(p->rchild);
}

void Binary_Search_Tree::Postorder(Node* p) {
    if (!p) return;
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout << p->data << " ";
}

void Binary_Search_Tree::Levelorder() {
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

/* ---------- Display ---------- */

void Binary_Search_Tree::Display(int order) {
    if (!root) {
        cout << "Tree is empty!\n";
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
        Levelorder();
        break;
    default:
        cout << "Invalid option!";
    }
    cout << endl;
}

/* ---------- Destroy ---------- */

void Binary_Search_Tree::Destroy(Node* p) {
    if (!p) return;
    Destroy(p->lchild);
    Destroy(p->rchild);
    delete p;
}

/* ---------- Main ---------- */

int main() {
    Binary_Search_Tree bst;

    vector<int> values = {30, 20, 40, 10, 25, 35, 50};
    bst.CreateTree(values);

    // Traversals
    bst.Display(1);
    bst.Display(2);
    bst.Display(3);
    bst.Display(4);

    cout << endl;

    // Search tests
    int key1 = 25;
    int key2 = 99;

    Node* r1 = bst.RecursiveSearch(key1);
    if (r1)
        cout << "Recursive Search: " << key1 << " found\n";
    else
        cout << "Recursive Search: " << key1 << " not found\n";

    Node* r2 = bst.IterativeSearch(key2);
    if (r2)
        cout << "Iterative Search: " << key2 << " found\n";
    else
        cout << "Iterative Search: " << key2 << " not found\n";

    return 0;
}
