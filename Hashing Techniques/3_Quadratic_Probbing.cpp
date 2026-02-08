#include <iostream>
#include <vector>
using namespace std;

int getHashIndex(int key) {
    return key % 10;
}

int QuadraticProbe(vector<int>& Hash, int key) {
    int idx = getHashIndex(key);
    int i = 1;

    while (Hash[(idx + i * i) % 10] != 0) {
        i++;
        if (i == 10) {
            cout << "Hash table is full\n";
            return -1;
        }
    }

    return (idx + i * i) % 10;
}

void Insert(vector<int>& Hash, int key) {
    int idx = getHashIndex(key);

    if (Hash[idx] != 0) {
        idx = QuadraticProbe(Hash, key);
        if (idx == -1) return;
    }

    Hash[idx] = key;
}

int Search(vector<int>& Hash, int key) {
    int idx = getHashIndex(key);

    if (Hash[idx] == key)
        return idx;

    int i = 1;
    while (Hash[(idx + i * i) % 10] != 0) {
        int probeIdx = (idx + i * i) % 10;

        if (Hash[probeIdx] == key)
            return probeIdx;

        i++;
        if (i == 10)
            break;
    }

    return -1; // key not found
}

int main() {
    vector<int> A = {23, 43, 13, 27};
    vector<int> Hash(10, 0);

    for (int i = 0; i < A.size(); i++) {
        Insert(Hash, A[i]);
    }

    // Display hash table
    for (int i = 0; i < Hash.size(); i++) {
        cout << i << " -> " << Hash[i] << endl;
    }

    return 0;
}
