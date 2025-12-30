#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int rear;
    int* Q;

public:
    Queue(int n);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
};  

Queue::Queue(int n) {
    size = n;
    rear = -1;
    Q = new int[size];
}

Queue::~Queue() {
    delete[] Q;
}

bool Queue::isEmpty() {
    return rear == -1;
}

bool Queue::isFull() {
    return rear == size - 1;
}

void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    Q[++rear] = x;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1;   
    }

    int pop = Q[0];
    for (int i = 0; i < rear; i++) {
        Q[i] = Q[i + 1];
    }
    rear--;
    return pop;
}

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
}
