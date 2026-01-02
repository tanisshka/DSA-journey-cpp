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

    void DestroyTree(Node* p);
    void InOrderDisplay(Node* p);
    void PreOrderDisplay(Node* p);
    void PostOrderDisplay(Node* p);

public:
    Binary_Tree();
    ~Binary_Tree();

    void Create_Tree();
    void LevelOrderDisplay();
    void Display(int order = 1); // 1=In, 2=Pre, 3=Post, 4=Level
};

// ---------------- Constructor ----------------
Binary_Tree::Binary_Tree() {
    root = nullptr;
}

// ---------------- Destructor ----------------
Binary_Tree::~Binary_Tree() {
    DestroyTree(root);
    cout << "Tree destroyed successfully" << endl;
}

// ---------------- Destroy Tree ----------------
void Binary_Tree::DestroyTree(Node* p) {
    if (p == nullptr) return;

    DestroyTree(p->lchild);
    DestroyTree(p->rchild);
    delete p;
}

// ---------------- Create Tree ----------------
void Binary_Tree::Create_Tree() {
    int rootVal;
    cout << "Enter root node value: ";
    cin >> rootVal;

    if (rootVal == -1) return;

    root = new Node{nullptr, rootVal, nullptr};
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << p->data << " : ";
        cin >> leftVal;
        if (leftVal != -1) {
            p->lchild = new Node{nullptr, leftVal, nullptr};
            q.push(p->lchild);
        }

        cout << "Enter right child of " << p->data << " : ";
        cin >> rightVal;
        if (rightVal != -1) {
            p->rchild = new Node{nullptr, rightVal, nullptr};
            q.push(p->rchild);
        }
    }
}

// ---------------- Display Wrapper ----------------
void Binary_Tree::Display(int order) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    switch (order) {
        case 1:
            cout << "Inorder Traversal: ";
            InOrderDisplay(root);
            break;
        case 2:
            cout << "Preorder Traversal: ";
            PreOrderDisplay(root);
            break;
        case 3:
            cout << "Postorder Traversal: ";
            PostOrderDisplay(root);
            break;
        case 4:
            cout << "Levelorder Traversal: ";
            LevelOrderDisplay();
            break;
        default:
            cout << "Invalid option!";
    }
    cout << endl;
}

// ---------------- Inorder ----------------
void Binary_Tree::InOrderDisplay(Node* p) {
    if (p == nullptr) return;

    InOrderDisplay(p->lchild);
    cout << p->data << " ";
    InOrderDisplay(p->rchild);
}

// ---------------- Preorder ----------------
void Binary_Tree::PreOrderDisplay(Node* p) {
    if (p == nullptr) return;

    cout << p->data << " ";
    PreOrderDisplay(p->lchild);
    PreOrderDisplay(p->rchild);
}

// ---------------- Postorder ----------------
void Binary_Tree::PostOrderDisplay(Node* p) {
    if (p == nullptr) return;

    PostOrderDisplay(p->lchild);
    PostOrderDisplay(p->rchild);
    cout << p->data << " ";
}

// ---------------- Level Order ----------------
void Binary_Tree::LevelOrderDisplay() {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        cout << p->data << " ";

        if (p->lchild != nullptr)
            q.push(p->lchild);
        if (p->rchild != nullptr)
            q.push(p->rchild);
    }
}

// ---------------- Main ----------------
int main() {
    Binary_Tree tree;

    cout << "Create Binary Tree (-1 for NULL)" << endl;
    tree.Create_Tree();

    cout << "\n--- Traversals ---" << endl;
    tree.Display(1); // Inorder
    tree.Display(2); // Preorder
    tree.Display(3); // Postorder
    tree.Display(4); // Levelorder

    return 0;
}
