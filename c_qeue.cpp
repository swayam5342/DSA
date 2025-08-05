#include <iostream>
using namespace std;

class CQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    CQueue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
        capacity = size;
    }
    ~CQueue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
    }
    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        return value;
    }
    void display() {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, const char** argv) {
    CQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    q.enqueue(6);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    return 0;
}