#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

/* Insert at end of linked list */
void Insert(Node*& head, int x) {
    Node* t = new Node{x, nullptr};

    if (head == nullptr) {
        head = t;
        return;
    }

    Node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = t;
}

/* Delete from front of linked list */
int Delete(Node*& head) {
    if (head == nullptr)
        return -1;

    Node* p = head;
    int x = p->data;
    head = head->next;
    delete p;
    return x;
}

int countDigits(int x) {
    if (x == 0) return 1;

    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}

int getBinIndex(int x, int index) {
    return (int)(x / pow(10, index)) % 10;
}

void InitializeBins(Node** bins, int n) {
    for (int i = 0; i < n; i++)
        bins[i] = nullptr;
}

void RadixSort(vector<int>& A) {
    int maxVal = *max_element(A.begin(), A.end());
    int nPasses = countDigits(maxVal);
    int n = A.size();

    Node** bins = new Node*[10];
    InitializeBins(bins, 10);

    for (int pass = 0; pass < nPasses; pass++) {

        // Distribute elements into bins
        for (int i = 0; i < n; i++) {
            int index = getBinIndex(A[i], pass);
            Insert(bins[index], A[i]);
        }

        // Collect elements back into array
        int k = 0;
        for (int i = 0; i < 10; i++) {
            while (bins[i] != nullptr) {
                A[k++] = Delete(bins[i]);
            }
        }
    }

    delete[] bins;
}

/* Driver */
int main() {
    vector<int> A = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};

    RadixSort(A);

    for (int x : A)
        cout << x << " ";

    return 0;
}
