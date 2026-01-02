#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};

class Binary_Tree {
private:
    Node* root;

    Node* BuildTree(vector<int>& preorder, vector<int>& inorder,
                    int start, int end, int& preIndex);

    void Preorder(Node* p);
    void Inorder(Node* p);
    void Postorder(Node* p);
    void DestroyTree(Node* p);

public:
    Binary_Tree();
    ~Binary_Tree();

    void CreateTreeFromPreIn(vector<int> preorder, vector<int> inorder);

    void DisplayPreorder();
    void DisplayInorder();
    void DisplayPostorder();
};

// ---------------- Constructor ----------------
Binary_Tree::Binary_Tree() {
    root = nullptr;
}

// ---------------- Destructor ----------------
Binary_Tree::~Binary_Tree() {
    DestroyTree(root);
    cout << "Tree destroyed successfully!" << endl;
}

// ---------------- Build Tree ----------------
Node* Binary_Tree::BuildTree(vector<int>& preorder, vector<int>& inorder,
                             int start, int end, int& preIndex) {
    if (start > end)
        return nullptr;

    Node* p = new Node{nullptr, preorder[preIndex++], nullptr};

    if (start == end)
        return p;

    int split = start;
    while (inorder[split] != p->data)
        split++;

    p->lchild = BuildTree(preorder, inorder, start, split - 1, preIndex);
    p->rchild = BuildTree(preorder, inorder, split + 1, end, preIndex);

    return p;
}

// ---------------- Wrapper ----------------
void Binary_Tree::CreateTreeFromPreIn(vector<int> preorder, vector<int> inorder) {
    int preIndex = 0;
    root = BuildTree(preorder, inorder, 0, inorder.size() - 1, preIndex);
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

// ---------------- Destroy Tree ----------------
void Binary_Tree::DestroyTree(Node* p) {
    if (!p) return;
    DestroyTree(p->lchild);
    DestroyTree(p->rchild);
    delete p;
}

// ---------------- Display ----------------
void Binary_Tree::DisplayPreorder() {
    Preorder(root);
    cout << endl;
}

void Binary_Tree::DisplayInorder() {
    Inorder(root);
    cout << endl;
}

void Binary_Tree::DisplayPostorder() {
    Postorder(root);
    cout << endl;
}

// ---------------- Main ----------------
int main() {
    Binary_Tree tree;

    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    vector<int> inorder  = {40, 20, 50, 10, 30, 60};

    tree.CreateTreeFromPreIn(preorder, inorder);

    cout << "Inorder   : ";
    tree.DisplayInorder();

    cout << "Preorder  : ";
    tree.DisplayPreorder();

    cout << "Postorder : ";
    tree.DisplayPostorder();

    return 0;
}
