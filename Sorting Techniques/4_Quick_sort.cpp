#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &A, int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (A[i] <= pivot && i < high) i++;
        while (A[j] > pivot && j > low) j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[low], A[j]);
    return j;
}

void Quick_Sort(vector<int> &A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        Quick_Sort(A, low, pi - 1);
        Quick_Sort(A, pi + 1, high);
    }
}

int main() {
    vector<int> A = {40, 25, 35, 10, 5, 20, 30};

    cout << "Before sorting:\n";
    for (int x : A) cout << x << " ";

    Quick_Sort(A, 0, A.size() - 1);

    cout << "\nAfter sorting:\n";
    for (int x : A) cout << x << " ";

    return 0;
}
