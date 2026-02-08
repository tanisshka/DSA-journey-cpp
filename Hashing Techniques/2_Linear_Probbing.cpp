#include <iostream>
#include <vector>
using namespace std;

int getHashIndex(int key)
{
    return key % 10;
}

int LinearProbe(vector<int> &Hash, int key)
{
    int idx = getHashIndex(key);
    int i = 0;

    while (Hash[(idx + i) % 10] != 0)
    {
        i++;
    }

    return (idx + i) % 10;
}

void Insert(vector<int> &Hash, int key)
{
    int idx = getHashIndex(key);

    if (Hash[idx] != 0)
    {
        idx = LinearProbe(Hash, key);
    }

    Hash[idx] = key;
}

int Search(vector<int> &Hash, int key)
{
    int idx = getHashIndex(key);
    int start = idx;

    while (Hash[idx] != 0)
    {
        if (Hash[idx] == key)
            return idx;

        idx = (idx + 1) % 10;

        if (idx == start)
            return -1;   // table fully scanned
    }

    return -1;
}

/* Display */
void Display(vector<int> &Hash)
{
    for (int i = 0; i < 10; i++)
        cout << i << " : " << Hash[i] << endl;
}

int main()
{
    vector<int> A = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    vector<int> Hash(10, 0);

    // Insert elements
    for (int x : A)
        Insert(Hash, x);

    cout << "Hash table after insertion:\n";
    Display(Hash);

    // Search test cases
    int searchKeys[] = {23, 29, 50};

    cout << "\nSearch results:\n";
    for (int key : searchKeys)
    {
        int idx = Search(Hash, key);
        if (idx != -1)
            cout << "Key " << key << " found at index " << idx << endl;
        else
            cout << "Key " << key << " not found\n";
    }

    return 0;
}
