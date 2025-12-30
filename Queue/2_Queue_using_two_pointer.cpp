#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int rear;
    int front;
    int* Q;

public:
    Queue(int n);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int n) {
    size = n;
    rear = -1;
    front = -1;
    Q = new int[size];
}

Queue::~Queue() {
    delete[] Q;
}

bool Queue::isEmpty() {
    return front == rear;
}

bool Queue::isFull() {
    return rear == size - 1;
}

void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    rear++;
    Q[rear] = x;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }
    front++;
    return Q[front];
}

void Queue::display() {
    cout << "Queue elements: ";
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue q(5);   // create queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(50);
    q.enqueue(60);   // this may cause overflow depending on usage

    q.display();

    return 0;
}
