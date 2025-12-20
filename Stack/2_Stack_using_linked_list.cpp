#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();

    void push(int x);
    int pop();
    int peek(int index);
    bool isEmpty();
    void display();
    int stackTop();
};

// Constructor
Stack::Stack() {
    top = nullptr;
}

// Destructor
Stack::~Stack() {
    Node* p = top;
    while (p) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}

// Push
void Stack::push(int x) {
    Node* temp = new Node{x, top};
    top = temp;
}

// Check empty
bool Stack::isEmpty() {
    return top == nullptr;
}

// Pop
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    Node* temp = top;
    int x = temp->data;
    top = top->next;
    delete temp;
    return x;
}

// Peek (1-based from top)
int Stack::peek(int index) {
    if (index <= 0) {
        cout << "Invalid position" << endl;
        return -1;
    }

    Node* p = top;
    for (int i = 1; i < index && p != nullptr; i++) {
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Invalid position" << endl;
        return -1;
    }

    return p->data;
}

// Display stack
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* p = top;
    cout << "Stack (Top → Bottom): ";
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Return top element
int Stack::stackTop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.stackTop() << endl;

    cout << "Peek(1): " << st.peek(1) << endl;
    cout << "Peek(2): " << st.peek(2) << endl;
    cout << "Peek(3): " << st.peek(3) << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    st.display();

    return 0;
}
