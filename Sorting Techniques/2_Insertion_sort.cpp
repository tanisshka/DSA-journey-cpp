#include<iostream>
#include<vector>
using namespace std;

void display(const vector<int> &A) {
    for(int x : A) {
        cout << x << " ";
    }
    cout << endl;
}

void Insertion_sort(vector<int> &A) {
    int n = A.size();
    for(int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while(j > -1 && key < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    vector<int> v = {40, 10, 30, 20, 50, 5};

    cout << "Before Sorting: ";
    display(v);

    Insertion_sort(v);

    cout << "After Sorting: ";
    display(v);

    return 0;
}
