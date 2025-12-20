#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int stackSize);
    ~Stack();

    void push(char x);
    char pop();
    bool isEmpty();
};

// Constructor
Stack::Stack(int stackSize)
{
    size = stackSize;
    top = -1;
    s = new char[size];
}

// Destructor
Stack::~Stack()
{
    delete[] s;
}

// Push
void Stack::push(char x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    s[++top] = x;
}

// Pop
char Stack::pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return s[top--];
}

// Check empty
bool Stack::isEmpty()
{
    return top == -1;
}

// ---------------- Parenthesis Matching ----------------

bool isBalanced(char *exp)
{
    Stack st(strlen(exp));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st.isEmpty())
            {
                return false;
            }
            st.pop();
        }
    }

    return st.isEmpty();
}

// ---------------- MAIN ----------------

int main()
{
    char exp1[] = "((a+b)*(c-d))";
    char exp2[] = "((a+b)*(c-d)))";
    char exp3[] = "(((a+b)*(c-d))";

    cout << isBalanced(exp1) << endl; // 1
    cout << isBalanced(exp2) << endl; // 0
    cout << isBalanced(exp3) << endl; // 0

    return 0;
}
