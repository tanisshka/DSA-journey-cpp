#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/* Initialize hash table */
void InitializeHashContainer(Node **Hash, int n)
{
    for (int i = 0; i < n; i++)
    {
        Hash[i] = nullptr;
    }
}

/* Hash function */
int getHashIndex(int x)
{
    return x % 10;
}

/* Sorted insert into linked list */
void Insert(Node *&head, int x)
{
    Node *t = new Node{x, nullptr};

    // Empty list
    if (head == nullptr)
    {
        head = t;
        return;
    }

    Node *p = head;
    Node *q = nullptr;

    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }

    // Insert at beginning
    if (q == nullptr)
    {
        t->next = head;
        head = t;
    }
    // Insert in middle or end
    else
    {
        q->next = t;
        t->next = p;
    }
}

/* Search in chaining hash */
Node* Search(Node **Hash, int key)
{
    int index = getHashIndex(key);
    Node *p = Hash[index];

    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }

    return nullptr;
}

int DeleteKey(Node **Hash, int key)
{
    int index = getHashIndex(key);
    Node *p = Hash[index];
    Node *q = nullptr;

    while (p && p->data != key)
    {
        q = p;
        p = p->next;
    }

    // Key not found
    if (p == nullptr)
        return -1;

    int x = p->data;

    // Delete first node
    if (q == nullptr)
    {
        Hash[index] = p->next;   
    }
    else
    {
        q->next = p->next;
    }

    delete p;
    return x;
}


/* Display hash table */
void Display(Node **Hash, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Index " << i << ": ";
        Node *p = Hash[i];
        while (p)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
}

/* Main function */
int main()
{
    vector<int> A = {23, 43, 13, 27, 17, 33, 53};

    Node **Hash = new Node *[10];
    InitializeHashContainer(Hash, 10);

    for (int x : A)
    {
        Insert(Hash[getHashIndex(x)], x);
    }

    Display(Hash, 10);

    int key = 27;
    Node *result = Search(Hash, key);

    if (result)
        cout << "\nKey " << key << " found\n";
    else
        cout << "\nKey " << key << " not found\n";

    return 0;
}
