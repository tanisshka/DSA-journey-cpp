#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int col;
    int data;
    Node *next;
};

class Sparse_Matrix
{
private:
    int rows, cols;
    Node **A; // Array of row head pointers

public:
    // Constructor
    Sparse_Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        A = new Node *[rows];
        for (int i = 0; i < rows; i++)
        {
            A[i] = nullptr;
        }
    }

    // Insert non-zero element at (row, col) in sorted order
    void insert(int row, int col, int value)
    {
        if (value == 0 || row < 0 || row > rows || col < 0 || col > cols)
            return;

        Node *newNode = new Node{col, value, nullptr};

        // Case 1: Empty row OR insert at beginning
        if (A[row] == nullptr || col < A[row]->col)
        {
            newNode->next = A[row];
            A[row] = newNode;
            return;
        }

        // Case 2: Insert in sorted position
        Node *temp = A[row];
        while (temp->next != nullptr && temp->next->col < col)
        {
            temp = temp->next;
        }

        // If same column exists → update value
        if (temp->next != nullptr && temp->next->col == col)
        {
            temp->next->data = value;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display sparse representation
    void displaySparse()
    {
        cout << "\nSparse Representation:\n";
        for (int i = 0; i < rows; i++)
        {
            cout << "Row " << i << ": ";
            Node *temp = A[i];
            while (temp != nullptr)
            {
                cout << "(col=" << temp->col
                     << ", val=" << temp->data << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    // Display full matrix
    void displayMatrix()
    {
        cout << "\nFull Matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            Node *p = A[i];
            for (int j = 0; j < cols; j++)
            {
                if (p != nullptr && j == p->col)
                {
                    cout << p->data << " ";
                    p = p->next;
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    Sparse_Matrix add(const Sparse_Matrix &other)
    {
        // Dimension check
        if (rows != other.rows || cols != other.cols)
        {
            throw invalid_argument("Matrix dimensions must match");
        }

        Sparse_Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            Node *p = this->A[i];
            Node *q = other.A[i];

            while (p != nullptr && q != nullptr)
            {
                if (p->col == q->col)
                {
                    int sum = p->data + q->data;
                    if (sum != 0)
                        result.insert(i, p->col, sum);
                    p = p->next;
                    q = q->next;
                }
                else if (p->col < q->col)
                {
                    result.insert(i, p->col, p->data);
                    p = p->next;
                }
                else
                {
                    result.insert(i, q->col, q->data);
                    q = q->next;
                }
            }

            // Copy remaining nodes
            while (p != nullptr)
            {
                result.insert(i, p->col, p->data);
                p = p->next;
            }

            while (q != nullptr)
            {
                result.insert(i, q->col, q->data);
                q = q->next;
            }
        }

        return result;
    }

    // Destructor
    ~Sparse_Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            Node *temp = A[i];
            while (temp != nullptr)
            {
                Node *del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] A;
    }
};

// Main function
int main() {
    Sparse_Matrix A(3, 4);
    Sparse_Matrix B(3, 4);

    A.insert(0, 1, 5);
    A.insert(1, 2, 8);
    A.insert(2, 3, 6);

    B.insert(0, 1, 3);
    B.insert(1, 0, 4);
    B.insert(2, 3, 2);

    Sparse_Matrix C = A.add(B);

    cout << "\nMatrix A:";
    A.displayMatrix();

    cout << "\nMatrix B:";
    B.displayMatrix();

    cout << "\nMatrix A + B:";
    C.displayMatrix();

    return 0;
}

