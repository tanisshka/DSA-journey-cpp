#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Count_Sort(vector<int> &A){
    int mx = *max_element(A.begin(), A.end());
    vector<int> count(mx + 1, 0);

    // Count frequencies
    for (int i = 0; i < A.size(); i++) {
        count[A[i]]++;
    }

    int i = 0;
    int j = 0;

    // Rebuild array
    while (i <= mx) {
        while (count[i] > 0) {
            A[j++] = i;
            count[i]--;
        }
        i++;
    }
}

int main(){
    vector<int> A = {4, 2, 2, 8, 3, 3, 1};

    cout << "Before sorting: ";
    for(int x : A) cout << x << " ";

    Count_Sort(A);

    cout << "\nAfter sorting: ";
    for(int x : A) cout << x << " ";

    return 0;
}
