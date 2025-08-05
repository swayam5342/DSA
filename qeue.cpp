#include <iostream>


using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
        capacity = size;
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (rear == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear++] = value;
    }
    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        front++;
        return arr[front];
    }
};

int main(int argc, const char** argv) {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    return 0;
}