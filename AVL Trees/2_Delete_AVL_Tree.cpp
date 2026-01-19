#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    Node *rchild;
    int data;
    int ht;
    Node *lchild;
};

class AVL_Trees
{
private:
    Node *root;
    Node *Insert(Node *t, int x);
    void Preorder(Node *t);
    void Inorder(Node *t);
    void Postorder(Node *t);
    int BF(Node *t);
    int Height(Node *t);
    Node *Rotateright(Node *x);
    Node *Rotateleft(Node *x);
    Node *LL(Node *t);
    Node *LR(Node *t);
    Node *RR(Node *t);
    Node *RL(Node *t);
    void Destroy(Node *t);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
    Node* Delete(Node*p,int key);

public:
    AVL_Trees();
    ~AVL_Trees();
    void Levelorder();
    void Display(int order = 1);
    void Insert(int key);
    void Delete(int key);
};

AVL_Trees::AVL_Trees()
{
    root = nullptr;
}

AVL_Trees::~AVL_Trees()
{
    Destroy(root);
    cout << "Tree destroyed successfully\n";
}

void AVL_Trees::Preorder(Node *t)
{
    if (!t)
        return;
    cout << t->data << " ";
    Preorder(t->lchild);
    Preorder(t->rchild);
}

void AVL_Trees::Inorder(Node *t)
{
    if (!t)
        return;
    Inorder(t->lchild);
    cout << t->data << " ";
    Inorder(t->rchild);
}

void AVL_Trees::Postorder(Node *t)
{
    if (!t)
        return;
    Postorder(t->lchild);
    Postorder(t->rchild);
    cout << t->data << " ";
}

void AVL_Trees::Levelorder()
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
}

void AVL_Trees::Display(int order)
{
    if (!root)
    {
        cout << "Tree is empty!\n";
        return;
    }
    switch (order)
    {
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

void AVL_Trees::Destroy(Node *t)
{
    if (!t)
        return;
    Destroy(t->lchild);
    Destroy(t->rchild);
    delete t;
}

int AVL_Trees::BF(Node *t)
{
    if (t == nullptr)
    {
        return 0;
    }
    int lh;
    int rh;
    if (t->rchild == nullptr)
    {
        rh = 0;
    }
    else
    {
        rh = 1 + t->rchild->ht;
    }
    if (t->lchild == nullptr)
    {
        lh = 0;
    }
    else
    {
        lh = 1 + t->lchild->ht;
    }
    return lh - rh;
}

int AVL_Trees::Height(Node *t)
{
    if (!t)
        return 0;
    int x, y;
    x = Height(t->lchild);
    y = Height(t->rchild);
    return max(x, y) + 1;
}

Node *AVL_Trees::Rotateright(Node *x)
{
    Node *y;
    y = x->lchild;
    x->lchild = y->rchild;
    y->rchild = x;
    y->ht = Height(y);
    x->ht = Height(x);
    return y;
}

Node *AVL_Trees::Rotateleft(Node *x)
{
    Node *y;
    y = x->rchild;
    x->rchild = y->lchild;
    y->lchild = x;
    y->ht = Height(y);
    x->ht = Height(x);
    return y;
}

Node *AVL_Trees::LL(Node *t)
{
    t = Rotateright(t);
    return t;
}

Node *AVL_Trees::LR(Node *t)
{
    t->lchild = Rotateleft(t->lchild);
    t = Rotateright(t);
    return t;
}

Node *AVL_Trees::RR(Node *t)
{
    t = Rotateleft(t);
    return t;
}

Node *AVL_Trees::RL(Node *t)
{
    t->rchild = Rotateright(t->rchild);
    t = Rotateleft(t);
    return t;
}

Node *AVL_Trees::Insert(Node *t, int x)
{
    if (t == nullptr)
    {
        t = new Node{nullptr, x, 0, nullptr};
    }
    else
    {
        if (t->data < x)
        {
            t->rchild = Insert(t->rchild, x);
            if (BF(t) == -2)
            {
                if (x > t->rchild->data)
                {
                    t = RR(t);
                }
                else
                {
                    t = RL(t);
                }
            }
        }
        else
        {
            t->lchild = Insert(t->lchild, x);
            if (BF(t) == 2)
            {
                if (x < t->lchild->data)
                {
                    t = LL(t);
                }
                else
                {
                    t = LR(t);
                }
            }
        }
    }
    t->ht = Height(t);
    return t;
}

void AVL_Trees::Insert(int key)
{
    root = Insert(root, key);
}


Node* AVL_Trees::InPre(Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node* AVL_Trees::InSucc(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node* AVL_Trees::Delete(Node *p, int key)
{
    if (!p)
        return nullptr;

    // BST deletion
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        // Node with one or zero child
        if (!p->lchild && !p->rchild)
        {
            delete p;
            return nullptr;
        }
        else if (Height(p->lchild) > Height(p->rchild))
        {
            Node *q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            Node *q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->ht = Height(p);

    // Rebalancing (6 cases)
    if (BF(p) == 2 && BF(p->lchild) >= 0)
        return LL(p);

    if (BF(p) == 2 && BF(p->lchild) < 0)
        return LR(p);

    if (BF(p) == -2 && BF(p->rchild) <= 0)
        return RR(p);

    if (BF(p) == -2 && BF(p->rchild) > 0)
        return RL(p);

    return p;
}

void AVL_Trees::Delete(int key)
{
    root = Delete(root, key);
}
 
int main()
{
    AVL_Trees tree;

    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(40);
    tree.Insert(50);
    tree.Insert(25);

    cout << "Before Deletion:\n";
    tree.Display(1);

    tree.Delete(40);

    cout << "After Deletion:\n";
    tree.Display(1);

    return 0;
}
