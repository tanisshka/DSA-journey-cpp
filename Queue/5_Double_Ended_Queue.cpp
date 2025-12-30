#include <iostream>
using namespace std;

class DEQueue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    DEQueue(int size);
    ~DEQueue();
    bool isEmpty();
    bool isFull();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    void display();
};

DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

DEQueue::~DEQueue() {
    delete[] Q;
}

bool DEQueue::isEmpty() {
    return front == rear;
}

bool DEQueue::isFull() {
    return rear == size - 1;
}

void DEQueue::enqueueRear(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear++;
    Q[rear] = x;
}

void DEQueue::enqueueFront(int x) {
    if (front == -1) {
        cout << "Cannot insert at front" << endl;
        return;
    }
    Q[front] = x;
    front--;
}

int DEQueue::dequeueFront() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    front++;
    return Q[front];
}

int DEQueue::dequeueRear() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    int x = Q[rear];
    rear--;
    return x;
}

void DEQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot display" << endl;
        return;
    }
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main() {
    DEQueue dq(5);

    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueRear(30);

    dq.display();

    cout << "Deleted from front: " << dq.dequeueFront() << endl;
    dq.display();

    dq.enqueueFront(5);   
    dq.display();

    cout << "Deleted from rear: " << dq.dequeueRear() << endl;
    dq.display();

    return 0;
}
