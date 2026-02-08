#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 10
#define PRIME 7     // must be < TABLE_SIZE

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return PRIME - (key % PRIME);
}

void Insert(vector<int>& Hash, int key) {
    int idx = hash1(key);

    if (Hash[idx] != 0) {
        int i = 1;
        while (Hash[(idx + i * hash2(key)) % TABLE_SIZE] != 0) {
            i++;
            if (i == TABLE_SIZE) {
                cout << "Hash table is full\n";
                return;
            }
        }
        idx = (idx + i * hash2(key)) % TABLE_SIZE;
    }

    Hash[idx] = key;
}

int Search(vector<int>& Hash, int key) {
    int idx = hash1(key);

    if (Hash[idx] == key)
        return idx;

    int i = 1;
    while (Hash[(idx + i * hash2(key)) % TABLE_SIZE] != 0) {
        int probeIdx = (idx + i * hash2(key)) % TABLE_SIZE;

        if (Hash[probeIdx] == key)
            return probeIdx;

        i++;
        if (i == TABLE_SIZE)
            break;
    }

    return -1;
}

int main() {
    vector<int> Hash(TABLE_SIZE, 0);
    vector<int> A = {23, 43, 13, 27, 33};

    for (int key : A) {
        Insert(Hash, key);
    }

    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " -> " << Hash[i] << endl;
    }

    int key = 27;
    int pos = Search(Hash, key);

    if (pos != -1)
        cout << "Key " << key << " found at index " << pos << endl;
    else
        cout << "Key not found\n";

    return 0;
}
