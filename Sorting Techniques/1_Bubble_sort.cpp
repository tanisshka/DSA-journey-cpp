#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void display(const vector<int> &vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

void Bubble_sort(vector<int> &vec) {
    int n = vec.size();
    for(int i = 0; i < n - 1; i++) {
        bool flag = false;
        for(int j = 0; j < n - 1 - i; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }
        if(flag == false) {
            break; 
        }
    }
}

int main() {
    vector<int> v = {15,16,6,8,5};

    cout << "Before Sorting: ";
    display(v);

    Bubble_sort(v);

    cout << "After Sorting: ";
    display(v);

    return 0;
}
