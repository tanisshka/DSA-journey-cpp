#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A, int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;

    vector<int> B(A.size());   // allocate space

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

void IMergeSort(vector<int> &A) {
    int n = A.size();
    int p;

    for (p = 2; p <= n; p = p * 2) {
        for (int i = 0; i + p - 1 < n; i = i + p) {
            int l = i;
            int h = i + p - 1;
            int mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }

    if (p / 2 < n) {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main() {
    vector<int> A = {10, 7, 8, 9, 1, 5};

    IMergeSort(A);

    for (int x : A)
        cout << x << " ";
}
