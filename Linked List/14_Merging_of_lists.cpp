#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Linked_list {
private:
    Node* first;

public:
    Linked_list() {
        first = nullptr;
    }

    Node* getFirst() { return first; }
    void setFirst(Node* p) { first = p; }

    // Create list
    void create(int n) {
        if (n <= 0) return;

        int x;
        cout << "Enter data for Node 1: ";
        cin >> x;

        first = new Node{x, nullptr};
        Node* p = first;

        for (int i = 2; i <= n; i++) {
            cout << "Enter data for Node " << i << ": ";
            cin >> x;

            Node* temp = new Node{x, nullptr};
            p->next = temp;
            p = temp;
        }
    }

    // Display
    void display() {
        Node* p = first;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Check sorted
    int IsSorted() {
        Node* p = first;
        int prev = INT_MIN;

        while (p != nullptr) {
            if (p->data < prev)
                return 0;
            prev = p->data;
            p = p->next;
        }
        return 1;
    }

    // MERGE 
    Node* Merge(Linked_list* A) {
        Node* p = first;
        Node* q = A->first;

        Node* third = nullptr;
        Node* last = nullptr;

        if (p->data < q->data) {
            third = last = p;
            p = p->next;
            last->next = nullptr;
        }
        else {
            third = last = q;
            q = q->next;
            last->next = nullptr;
        }

        while (p && q) {
            if (p->data < q->data) {
                last->next = p;
                last = p;
                p = p->next;
                last->next = nullptr;
            }
            else {
                last->next = q;
                last = q;
                q = q->next;
                last->next = nullptr;
            }
        }

        if (p) last->next = p;
        if (q) last->next = q;

        return third;
    }

    // Remove duplicates from sorted list
    void Remove_Duplicates() {
        if (first == nullptr) return;

        Node* p = first;
        Node* q = first->next;

        while (q != nullptr) {
            if (p->data != q->data) {
                p = q;
                q = q->next;
            }
            else {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }

    // Destructor
    ~Linked_list() {
        Node* p = first;
        while (p) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
};


/// ===========================
///          MAIN
/// ===========================

int main() {
    Linked_list L1, L2;

    int n1, n2;

    cout << "Enter number of nodes for List 1: ";
    cin >> n1;
    L1.create(n1);

    cout << "Enter number of nodes for List 2: ";
    cin >> n2;
    L2.create(n2);

    cout << "\nList 1: ";
    L1.display();

    cout << "List 2: ";
    L2.display();


    // Step 2: Check sorted
    if (!L1.IsSorted() || !L2.IsSorted()) {
        cout << "\nOne of the lists is NOT sorted! Cannot merge.\n";
        return 0;
    }

    // Step 3: Merge (Abdul Bari style)
    cout << "\nMerging lists...\n";
    Node* mergedHead = L1.Merge(&L2);

    Linked_list MergedList;
    MergedList.setFirst(mergedHead);

    cout << "\nMerged List: ";
    MergedList.display();

    // Step 4: Remove duplicates
    cout << "\nRemoving duplicates...\n";
    MergedList.Remove_Duplicates();

    cout << "\nFinal Merged List (No Duplicates): ";
    MergedList.display();

    return 0;
}
