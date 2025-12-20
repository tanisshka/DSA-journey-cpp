#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int* s;

public:
    Stack(int stackSize);
    ~Stack();

    void push(int x);
    int pop();
    int peek(int index);
    bool isEmpty();
    bool isFull();
    void display();
    int stackTop();
};

// Constructor
Stack::Stack(int stackSize) {
    size = stackSize;
    top = -1;
    s = new int[size];
}

// Destructor
Stack::~Stack() {
    delete[] s;
}

// Push
void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    s[++top] = x;
}

// Pop
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return s[top--];
}

// Peek (1-based index from top)
int Stack::peek(int index) {
    if (index <= 0 || index > top + 1) {
        cout << "Invalid position!" << endl;
        return -1;
    }
    return s[top - index + 1];
}

// Check empty
bool Stack::isEmpty() {
    return top == -1;
}

// Check full
bool Stack::isFull() {
    return top == size - 1;
}

// Display stack
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack (Top -> Bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << s[i] << " ";
    }
    cout << endl;
}

// Return top element
int Stack::stackTop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s[top];
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.stackTop() << endl;

    cout << "Peek(1): " << st.peek(1) << endl; // top
    cout << "Peek(2): " << st.peek(2) << endl;
    cout << "Peek(3): " << st.peek(3) << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    st.display();

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;

    return 0;
}
