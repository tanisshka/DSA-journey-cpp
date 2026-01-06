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
    Node* Deletion(Node *t,int key);
    Node* getInorderSuccessor(Node *t);

public:
    Binary_Search_Tree();
    ~Binary_Search_Tree();

    void CreateTree(const vector<int>& arr);
    void Insert(int key);
    void Display(int order = 1);
    void Levelorder();
    void Delete(int key);
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

Node* Binary_Search_Tree::getInorderSuccessor(Node *t){
    while(t->lchild!=nullptr){
        t=t->lchild;
    }
    return t;
}

Node* Binary_Search_Tree::Deletion(Node* t, int key) {
    if (t == nullptr)
        return nullptr;

    if (key < t->data) {
        t->lchild = Deletion(t->lchild, key);
    }
    else if (key > t->data) {
        t->rchild = Deletion(t->rchild, key);
    }
    else {
        // Case 1: Leaf node
        if (t->lchild == nullptr && t->rchild == nullptr) {
            delete t;
            return nullptr;
        }

        // Case 2: One child
        else if (t->lchild == nullptr) {
            Node* temp = t->rchild;
            delete t;
            return temp;
        }
        else if (t->rchild == nullptr) {
            Node* temp = t->lchild;
            delete t;
            return temp;
        }

        // Case 3: Two children
        Node* temp = getInorderSuccessor(t->rchild);
        t->data = temp->data;
        t->rchild = Deletion(t->rchild, temp->data);
    }
    return t;   
}

void Binary_Search_Tree::Delete(int key) {
    root = Deletion(root, key);
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

    cout << "Initial Tree:\n";
    bst.Display(1); // Inorder
    bst.Display(4); // Levelorder

    cout << "\nDeleting node 30 (has TWO children)\n";
    bst.Delete(30);

    cout << "\nTree after deletion:\n";
    bst.Display(1); // Inorder
    bst.Display(4); // Levelorder

    return 0;
}
