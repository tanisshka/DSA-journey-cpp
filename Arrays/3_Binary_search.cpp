#include<iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

public:
    Array(int size=10) {
        this->size = size;
        A = new int[size];
    }

    void create() {
        cout << "Enter length: ";
        cin >> length;
        if (length > size) {
            cout << "Length entered is out of bounds. Hence length is set to " << size << endl;
            length = size;
        }
        for (int i = 0; i < length; i++) {
            cout << "Value: ";
            cin >> A[i];
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << A[i] << "\t";
        }
        cout << endl;
    }

    int Binary_search(int key) {
        int l = 0;
        int h = length - 1;
        int mid;
        while (l <= h) {
            mid = (l + h) / 2;
            if (A[mid] == key) {
                return mid;
            }
            else if (A[mid] < key) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return -1;
    }

    // Recursive Binary Search (Helper + Wrapper)
    int Recursive_Binary_Search_Helper(int A[], int l, int h, int key) {
        if (l > h)  
            return -1;

        int mid = (l + h) / 2;

        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            return Recursive_Binary_Search_Helper(A, mid + 1, h, key);
        else
            return Recursive_Binary_Search_Helper(A, l, mid - 1, key);
    }

    int Recursive_Binary_Search(int key) {
        return Recursive_Binary_Search_Helper(A, 0, length - 1, key);
    }

    ~Array() {
        delete[] A;
    }
};

int main() {
    Array arr(15);
    arr.create();
    arr.display();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    cout << "Choose search method:\n1. Iterative\n2. Recursive\nChoice: ";
    int choice;
    cin >> choice;

    int index;
    if (choice == 1)
        index = arr.Binary_search(key);
    else
        index = arr.Recursive_Binary_Search(key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
