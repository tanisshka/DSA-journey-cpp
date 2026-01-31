#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A, int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    vector<int> B(A.size());

    while (i <= mid && j <= h) {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= h)
        B[k++] = A[j++];

    for (int x = l; x <= h; x++)
        A[x] = B[x];
}

void RMergeSort(vector<int> &A, int l, int h) {
    if (l < h) {                     // ❌ was while
        int mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

void MergeWrapper(vector<int> &A) {
    RMergeSort(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {38, 27, 43, 3, 9, 82, 10};
    MergeWrapper(A);

    for (int x : A)
        cout << x << " ";
}
