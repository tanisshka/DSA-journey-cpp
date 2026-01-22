#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Min_Heap {
private:
    int *H;
    int size;
    int length;

public:
    // Constructor
    Min_Heap(int size) {
        this->size = size;
        length = 1;  // Start at 1 for 1-based indexing
        H = new int[size + 1];
    }

    // Copy Constructor
    Min_Heap(const Min_Heap& other) {
        size = other.size;
        length = other.length;
        H = new int[size + 1];
        for (int i = 1; i < length; i++) {
            H[i] = other.H[i];
        }
    }

    // Copy Assignment Operator
    Min_Heap& operator=(const Min_Heap& other) {
        if (this != &other) {
            delete[] H;
            size = other.size;
            length = other.length;
            H = new int[size + 1];
            for (int i = 1; i < length; i++) {
                H[i] = other.H[i];
            }
        }
        return *this;
    }

    // Insert a key into the heap
    void InsertKey(int key) {
        if (length == size) {
            cout << "Heap Overflow: Cannot insert " << key << endl;
            return;
        }
        
        int i = length;
        // Bubble up
        while (i > 1 && key < H[i / 2]) {
            H[i] = H[i / 2];
            i = i / 2;
        }
        H[i] = key;
        length++;
    }

    // Create heap from a vector
    void CreateHeap(vector<int> A) {
        for (int x : A) {
            InsertKey(x);
        }
    }

    // Delete the minimum element (root)
    void deleteKey() {
        if (length == 1) {
            cout << "Heap Underflow: Heap is empty\n";
            return;
        }
        
        int x = H[1];  // Store the min element
        H[1] = H[length - 1];  // Move last element to root
        length--;
        
        // Heapify down
        int i = 1;
        int j = 2 * i;
        
        while (j < length) {
            // Choose the smaller child
            if (j + 1 < length && H[j + 1] < H[j]) {
                j = j + 1;
            }
            
            // If child is smaller than parent, swap
            if (H[j] < H[i]) {
                swap(H[i], H[j]);
                i = j;
                j = 2 * i;
            } else {
                break;
            }
        }
        
        H[length] = x;  // Place deleted element at end (for sorting)
    }

    // Extract minimum element
    int extractMin() {
        if (length == 1) {
            cout << "Heap is empty\n";
            return -1;
        }
        
        int min = H[1];
        H[1] = H[length - 1];
        length--;
        
        // Heapify down
        int i = 1;
        int j = 2 * i;
        
        while (j < length) {
            if (j + 1 < length && H[j + 1] < H[j]) {
                j = j + 1;
            }
            
            if (H[j] < H[i]) {
                swap(H[i], H[j]);
                i = j;
                j = 2 * i;
            } else {
                break;
            }
        }
        
        return min;
    }

    // Heap Sort (sorts in ascending order)
    void Heap_Sort() {
        int original = length;
        for (int i = 1; i < original; i++) {
            deleteKey();
        }
        length = original;  // Restore length for printing
    }

    // Get minimum element without removing
    int getMin() {
        if (length > 1) {
            return H[1];
        }
        cout << "Heap is empty\n";
        return -1;
    }

    // Check if heap is empty
    bool isEmpty() {
        return length == 1;
    }

    // Get current size of heap
    int getSize() {
        return length - 1;
    }

    // Print the heap
    void Print() {
        if (length == 1) {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 1; i < length; i++) {
            cout << H[i] << " ";
        }
        cout << endl;
    }

    // Print heap structure (level by level)
    void PrintStructure() {
        if (length == 1) {
            cout << "Heap is empty" << endl;
            return;
        }
        
        int level = 0;
        int nodes_in_level = 1;
        int i = 1;
        
        while (i < length) {
            cout << "Level " << level << ": ";
            for (int j = 0; j < nodes_in_level && i < length; j++, i++) {
                cout << H[i] << " ";
            }
            cout << endl;
            level++;
            nodes_in_level *= 2;
        }
    }

    // Destructor
    ~Min_Heap() {
        delete[] H;
    }
};

int main() {
    cout << "=== Min Heap Implementation Demo ===" << endl << endl;
    
    // Create a min heap with capacity 15
    Min_Heap heap(15);
    
    // Test 1: Insert elements one by one
    cout << "Test 1: Inserting elements" << endl;
    heap.InsertKey(50);
    heap.InsertKey(30);
    heap.InsertKey(20);
    heap.InsertKey(15);
    heap.InsertKey(10);
    heap.InsertKey(8);
    heap.InsertKey(16);
    
    cout << "Heap after insertions: ";
    heap.Print();
    cout << "Minimum element: " << heap.getMin() << endl;
    cout << "Heap size: " << heap.getSize() << endl << endl;
    
    // Test 2: Print heap structure
    cout << "Test 2: Heap Structure" << endl;
    heap.PrintStructure();
    cout << endl;
    
    // Test 3: Extract minimum
    cout << "Test 3: Extract Minimum" << endl;
    int min = heap.extractMin();
    cout << "Extracted: " << min << endl;
    cout << "Heap after extraction: ";
    heap.Print();
    cout << endl;
    
    // Test 4: Create heap from vector
    cout << "Test 4: Create new heap from vector" << endl;
    Min_Heap heap2(20);
    vector<int> arr = {45, 23, 67, 12, 89, 34, 5, 78, 90, 15};
    heap2.CreateHeap(arr);
    cout << "Heap created from vector: ";
    heap2.Print();
    cout << "Minimum: " << heap2.getMin() << endl << endl;
    
    // Test 5: Heap Sort
    cout << "Test 5: Heap Sort" << endl;
    cout << "Before sorting: ";
    heap2.Print();
    heap2.Heap_Sort();
    cout << "After sorting:  ";
    heap2.Print();
    cout << endl;
    
    // Test 6: Test overflow
    cout << "Test 6: Test Overflow" << endl;
    Min_Heap smallHeap(3);
    smallHeap.InsertKey(10);
    smallHeap.InsertKey(20);
    smallHeap.InsertKey(30);
    smallHeap.InsertKey(40);  // This should cause overflow
    cout << endl;
    
    // Test 7: Test underflow
    cout << "Test 7: Test Underflow" << endl;
    Min_Heap emptyHeap(5);
    emptyHeap.deleteKey();  // This should cause underflow
    cout << endl;
    
    // Test 8: Copy constructor
    cout << "Test 8: Copy Constructor" << endl;
    Min_Heap heap3(10);
    heap3.InsertKey(25);
    heap3.InsertKey(15);
    heap3.InsertKey(35);
    
    Min_Heap heap4 = heap3;  // Copy constructor
    cout << "Original heap: ";
    heap3.Print();
    cout << "Copied heap:   ";
    heap4.Print();
    
    return 0;
}