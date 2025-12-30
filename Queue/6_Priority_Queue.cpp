#include <iostream>
using namespace std;

class Priority_Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    Priority_Queue(int size);
    ~Priority_Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};

Priority_Queue::Priority_Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

Priority_Queue::~Priority_Queue() {
    delete[] Q;
}

bool Priority_Queue::isEmpty() {
    return front == rear;
}

bool Priority_Queue::isFull() {
    return rear == size - 1;
}

void Priority_Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }

    int i = rear;
    while (i >= 0 && Q[i] > x) {
        Q[i + 1] = Q[i];
        i--;
    }

    Q[i + 1] = x;
    rear++;
}

int Priority_Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }
    front++;
    return Q[front];
}

void Priority_Queue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty! Cannot display" << endl;
        return;
    }

    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main() {
    Priority_Queue pq(10);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(40);
    pq.enqueue(5);

    pq.display();   // expected: 5 10 20 30 40

    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;

    pq.display();   // expected: 20 30 40

    pq.enqueue(15);
    pq.enqueue(25);

    pq.display();   // expected: 15 20 25 30 40

    return 0;
}
