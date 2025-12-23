#include <iostream>
#include <cstring>
using namespace std;

class Stack {
private:
    int size;
    int top;
    char* s;

public:
    Stack(int stackSize) {
        size = stackSize;
        top = -1;
        s = new char[size];
    }

    ~Stack() {
        delete[] s;
    }

    void push(char x) {
        if (top == size - 1) return;
        s[++top] = x;
    }

    char pop() {
        if (top == -1) return '\0';
        return s[top--];
    }

    char stackTop() {
        if (top == -1) return '\0';
        return s[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperand(char ch) {
    return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

char* infixToPostfix(char* infix) {
    Stack st(strlen(infix));
    char* postfix = new char[strlen(infix) + 1];

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        // Operand
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        // Opening parenthesis
        else if (infix[i] == '(') {
            st.push(infix[i++]);
        }
        // Closing parenthesis
        else if (infix[i] == ')') {
            while (!st.isEmpty() && st.stackTop() != '(') {
                postfix[j++] = st.pop();
            }
            st.pop(); // remove '('
            i++;
        }
        // Operator
        else {
            while (!st.isEmpty() && precedence(infix[i]) <= precedence(st.stackTop())) {
                postfix[j++] = st.pop();
            }
            st.push(infix[i++]);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}
