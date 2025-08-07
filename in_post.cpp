#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    for (char ch : infix) {
        if (isspace(ch)) continue;
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else if (isOperator(ch)) {
            while (!st.empty() && st.top() != '(' &&
                    (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string reverseAndSwap(string s) {
    reverse(s.begin(), s.end());
    for (char& ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return s;
}

string infixToPrefix(string infix) {
    string revInfix = reverseAndSwap(infix);
    string postfix = infixToPostfix(revInfix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
