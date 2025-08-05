#include <iostream>
using namespace std;


template <typename T>
class Stack {
    int top;
    T* arr;
    int capacity;

public:
    Stack(int size) {
        top = -1;
        capacity = size;
        arr = new T[capacity];
    }
    ~Stack() {
        delete[] arr;
    }
    void push(T x) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }
    T peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};