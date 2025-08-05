
#include <iostream>
#include <string>

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


int main() {
    string expression;
    cout << "Enter postfix expression (space separated): ";
    getline(cin, expression);

    Stack<int> s(expression.length());
    string token = "";
    for (size_t i = 0; i <= expression.length(); ++i) {
        if (i < expression.length() && expression[i] != ' ') {
            token += expression[i];
        } else if (!token.empty()) {
            if (isdigit(token[0])) {
                s.push(stoi(token));
            } else if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (s.isEmpty()) { cout << "Error: Not enough operands\n"; return 1; }
                int b = s.peek(); 
                s.pop();
                if (s.isEmpty()) { cout << "Error: Not enough operands\n"; return 1; }
                int a = s.peek(); 
                s.pop();
                int result = 0;
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") {
                    if (b == 0) { cout << "Error: Division by zero\n"; return 1; }
                    result = a / b;
                }
                s.push(result);
            } else {
                cout << "Error: Invalid token '" << token << "'\n";
                return 1;
            }
            token = "";
        }
    }
    if (s.isEmpty()) {
        cout << "Error: No result\n";
        return 1;
    }
    int finalResult = s.peek(); s.pop();
    if (!s.isEmpty()) {
        cout << "Error: Too many operands\n";
        return 1;
    }
    cout << "Result: " << finalResult << "\n";
    return 0;
}