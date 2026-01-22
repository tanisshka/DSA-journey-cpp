#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Max_Heap
{
private:
    int *H;
    int size;
    int length;

public:
    Max_Heap(int size)
    {
        this->size = size;
        length = 1;
        H = new int[size + 1]; // +1 for 1-based indexing
    }

    void InsertKey(int key)
    {
        if (length == size)
        {
            cout << "Overflow\n";
            return;
        }

        int i = length;
        while (i > 1 && key > H[i / 2])
        {
            H[i] = H[i / 2];
            i = i / 2;
        }
        H[i] = key;
        length++;
    }

    void CreateHeap(vector<int> A)
    {
        for (int x : A)
            InsertKey(x);
    }

    void deleteKey()
    {
        if (length == 1)
        {
            cout << "Underflow\n";
            return;
        }


        int x = H[1];
        H[1] = H[length - 1];
        length--;

        int i = 1;
        int j = 2 * i;

        while (j < length)
        {
            if (j + 1 < length && H[j + 1] > H[j])
                j = j + 1;

            if (H[j] > H[i])
            {
                swap(H[i], H[j]);
                i = j;
                j = 2 * i;
            }
            else
                break;
        }

        H[length] = x; // placed at end (sorted)
    }

    void Heap_Sort()
    {
        int original = length;
        for (int i = 1; i < original; i++)
            deleteKey();
        length = original;
    }

    void Print()
    {
        for (int i = 1; i < length; i++)
            cout << H[i] << " ";
        cout << endl;
    }

    ~Max_Heap()
    {
        delete[] H;
    }
};
int main()
{
    Max_Heap h(20);

    vector<int> A = {10, 20, 30, 25, 5, 40, 35};

    cout << "Creating Heap...\n";
    h.CreateHeap(A);

    cout << "Heap after creation:\n";
    h.Print();

    cout << "Applying Heap Sort...\n";
    h.Heap_Sort();

    cout << "After Heap Sort (sorted array):\n";
    h.Print();

    return 0;
}
