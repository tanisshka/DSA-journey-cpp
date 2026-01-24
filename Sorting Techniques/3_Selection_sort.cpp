#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Selection_sort(vector<int> &A){
    int n = A.size();
    for(int i = 0; i < n - 1; i++){
        int k = i;
        for(int j = i + 1; j < n; j++){
            if(A[k] > A[j]){
                k = j;
            }
        }
        swap(A[k], A[i]);
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};

    cout << "Before: ";
    for(int x : v) cout << x << " ";

    Selection_sort(v);

    cout << "\nAfter: ";
    for(int x : v) cout << x << " ";

    return 0;
}
