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

    // helpers
    void Preorder(Node* p);
    void Inorder(Node* p);
    void Postorder(Node* p);
    void Destroy(Node* p);

    // insertion helpers
    Node* RecursiveInsert(Node* p, int key);
    void IterativeInsert(int key);

public:
    Binary_Search_Tree();
    ~Binary_Search_Tree();

    void CreateTree(const vector<int>& arr, bool useRecursive = true);
    void InsertRecursive(int key);
    void InsertIterative(int key);

    void Display(int order = 1);
    void Levelorder();
};

/* ---------- Constructor / Destructor ---------- */

Binary_Search_Tree::Binary_Search_Tree() {
    root = nullptr;
}

Binary_Search_Tree::~Binary_Search_Tree() {
    Destroy(root);
    cout << "Tree destroyed successfully\n";
}

/* ---------- Recursive Insert ---------- */

Node* Binary_Search_Tree::RecursiveInsert(Node* p, int key) {
    if (p == nullptr)
        return new Node{nullptr, key, nullptr};

    if (key < p->data)
        p->lchild = RecursiveInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsert(p->rchild, key);
    // duplicates ignored

    return p;
}

void Binary_Search_Tree::InsertRecursive(int key) {
    root = RecursiveInsert(root, key);
}

/* ---------- Iterative Insert ---------- */

void Binary_Search_Tree::IterativeInsert(int key) {
    Node* t = root;
    Node* r = nullptr;

    while (t != nullptr) {
        r = t;
        if (key == t->data)
            return;                 // no duplicates
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }

    Node* n = new Node{nullptr, key, nullptr};

    if (r == nullptr)               // tree empty
        root = n;
    else if (key < r->data)
        r->lchild = n;
    else
        r->rchild = n;
}

void Binary_Search_Tree::InsertIterative(int key) {
    IterativeInsert(key);
}

/* ---------- Create Tree ---------- */

void Binary_Search_Tree::CreateTree(const vector<int>& arr, bool useRecursive) {
    for (int x : arr) {
        if (useRecursive)
            InsertRecursive(x);
        else
            InsertIterative(x);
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
    Binary_Search_Tree bst1, bst2;

    vector<int> values = {30, 20, 40, 10, 25, 35, 50};

    // Recursive build
    bst1.CreateTree(values, true);
    bst1.Display(1);
    bst1.Display(4);

    cout << endl;

    // Iterative build
    bst2.CreateTree(values, false);
    bst2.Display(1);
    bst2.Display(4);

    return 0;
}
