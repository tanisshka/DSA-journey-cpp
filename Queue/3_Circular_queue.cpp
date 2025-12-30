#include <iostream>
using namespace std;

class Circular_Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    Circular_Queue(int n);
    ~Circular_Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    void display();
};

Circular_Queue::Circular_Queue(int n) {
    size = n;
    front = 0;
    rear = 0;
    Q = new int[size];
}

Circular_Queue::~Circular_Queue() {
    delete[] Q;
}

bool Circular_Queue::isEmpty() {
    return front == rear;
}

bool Circular_Queue::isFull() {
    return (rear + 1) % size == front;
}

void Circular_Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    rear = (rear + 1) % size;
    Q[rear] = x;
}

int Circular_Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }
    front = (front + 1) % size;
    return Q[front];
}

void Circular_Queue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty. Cannot display." << endl;
        return;
    }
    int i = (front + 1) % size;
    do {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main() {
    Circular_Queue cq(5); // effective capacity = 4

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cout << "Dequeued: " << cq.dequeue() << endl;

    cq.display();

    cq.enqueue(50);
    cq.enqueue(60); // works due to circular nature

    cq.display();

    return 0;
}
