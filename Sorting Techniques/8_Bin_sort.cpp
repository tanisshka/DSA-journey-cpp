#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void Insert(Node* &head, int x) {
    Node* t = new Node{x, nullptr};

    if (head == nullptr) {
        head = t;
        return;
    }

    Node* p = head;
    while (p->next)
        p = p->next;

    p->next = t;
}

int Delete(Node* &head) {
    if (head == nullptr)
        return -1;

    if (head->next == nullptr) {
        int x = head->data;
        delete head;
        head = nullptr;
        return x;
    }

    Node* p = head;
    Node* q = nullptr;

    while (p->next) {
        q = p;
        p = p->next;
    }

    int x = p->data;
    q->next = nullptr;
    delete p;
    return x;
}

void BinSort(vector<int> &A){
    int mx = *max_element(A.begin(), A.end());
    Node** Bins = new Node*[mx + 1];

    for (int i = 0; i <= mx; i++)
        Bins[i] = nullptr;

    for (int i = 0; i < A.size(); i++)
        Insert(Bins[A[i]], A[i]);

    int i = 0, j = 0;
    while (i <= mx) {
        while (Bins[i] != nullptr)
            A[j++] = Delete(Bins[i]);
        i++;
    }

    delete[] Bins;
}

int main() {
    vector<int> A = {6, 3, 9, 10, 15, 6, 8, 12, 3};

    cout << "Before sorting:\n";
    for (int x : A) cout << x << " ";

    BinSort(A);

    cout << "\nAfter sorting:\n";
    for (int x : A) cout << x << " ";

    return 0;
}
