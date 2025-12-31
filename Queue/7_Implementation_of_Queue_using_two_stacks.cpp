//! Problem Statement: Implement Queue Using Two Stacks

// Design a queue data structure using two stacks.
// Implement the following operations:
// enqueue(x): Insert element x into the queue.
// dequeue(): Remove and return the front element of the queue.
// peek() (optional): Return the front element without removing it.
// isEmpty() (optional): Check whether the queue is empty.
// The implementation should use only stack operations (push, pop, top/peek, isEmpty) and no other data structures.


//! Algorithm: Queue Implementation Using Two Stacks
// Data Structures Used

// Stack S1 → used for enqueue (insertion)
// Stack S2 → used for dequeue (deletion)

// Both stacks are assumed to support:
// push, pop, top, and isEmpty.

//! Algorithm for Enqueue Operation
// To enqueue an element x into the queue:
// Push x onto stack S1.

//! Algorithm for Dequeue Operation
// If stack S2 is not empty:
// Pop and return the top element of S2.

// Else if stack S2 is empty:
// Check if stack S1 is also empty.

// If yes:
// Queue is empty.
// Return -1 or display “Queue is Empty”.

// If no:
// Transfer all elements from S1 to S2:
// While S1 is not empty:
// Pop the top element from S1.
// Push it onto S2.
// Pop and return the top element from S2.

#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    Queue() {}
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x) {
    s1.push(x);
}

int Queue::dequeue() {
    // Case 1: s2 is empty
    if (s2.empty()) {
        // Case 1.1: both stacks empty
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // Case 1.2: transfer from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // Case 2: s2 has elements
    int x = s2.top();
    s2.pop();
    return x;
}

int main() {
    Queue q;

    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);

    cout << q.dequeue() << endl; // 6
    cout << q.dequeue() << endl; // 3

    q.enqueue(4);
    q.enqueue(2);

    cout << q.dequeue() << endl; // 9
    cout << q.dequeue() << endl; // 5
    cout << q.dequeue() << endl; // 4
    cout << q.dequeue() << endl; // 2

    return 0;
}
