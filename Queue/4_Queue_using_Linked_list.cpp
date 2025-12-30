#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue() {
    front = rear = nullptr;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::enqueue(int x) {
    Node* t = new Node{x, nullptr};

    if (isEmpty()) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Cannot delete. Queue is empty" << endl;
        return -1;
    }

    Node* temp = front;
    int x = temp->data;
    front = front->next;

    if (front == nullptr)   // queue became empty
        rear = nullptr;

    delete temp;
    return x;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty! Cannot display" << endl;
        return;
    }

    Node* p = front;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    q.display();

    return 0;
}
