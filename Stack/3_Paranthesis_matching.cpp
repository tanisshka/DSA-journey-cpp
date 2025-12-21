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

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

//Valid Paranthesis chexker function
bool isValidParanthesis(char *exp) {
    Stack st(strlen(exp));

    for (int i = 0; exp[i] != '\0'; i++) {

      
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            st.push(exp[i]);
        }

        
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (st.isEmpty()) {
                return false;
            }

            char topChar = st.pop();

            if (!isMatching(topChar, exp[i])) {
                return false;
            }
        }
    }

    return st.isEmpty();
}


// ---------------- MAIN ----------------

int main()
{
    // Simple parenthesis matching (only '(' and ')')
    char exp1[] = "((a+b)*(c-d))";
    char exp2[] = "((a+b)*(c-d)))";
    char exp3[] = "(((a+b)*(c-d))";

    cout << "Simple Parenthesis Matching:\n";
    cout << "exp1: " << isBalanced(exp1) << endl; // 1
    cout << "exp2: " << isBalanced(exp2) << endl; // 0
    cout << "exp3: " << isBalanced(exp3) << endl; // 0

    cout << endl;

    // Advanced parenthesis matching: (), {}, []
    char exp4[] = "{[()]}";
    char exp5[] = "{[(])}";
    char exp6[] = "((a+b)*[c-d])";
    char exp7[] = "{(a+b)*[c-d]}";

    cout << "Advanced Parenthesis Matching:\n";
    cout << "exp4: " << isValidParanthesis(exp4) << endl; // 1
    cout << "exp5: " << isValidParanthesis(exp5) << endl; // 0
    cout << "exp6: " << isValidParanthesis(exp6) << endl; // 1
    cout << "exp7: " << isValidParanthesis(exp7) << endl; // 1

    return 0;
}
