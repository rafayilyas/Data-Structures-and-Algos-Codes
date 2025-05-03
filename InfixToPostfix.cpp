#include <iostream>
#include <string>
using namespace std;

// Stack class using an array
class Stack {
    char stackArray[100]; // Array to store stack elements
    int top;              // To track the top of the stack
    int maxSize;          // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Stack is initially empty
        maxSize = 100;
    }

    // Push function to add elements to the stack
    void push(char ch) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        stackArray[++top] = ch;
    }

    // Pop function to remove elements from the stack
    char pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return -1; // Return an invalid character if stack is empty
        }
        return stackArray[top--];
    }

    // Peek function to check the top element of the stack
    char peek() {
        if (top == -1) {
            return -1; // Invalid character if stack is empty
        }
        return stackArray[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix) {
    Stack s;              // Stack using array
    string postfix = "";   // Resultant postfix expression
    
    for (int i = 0; i < infix.length(); i++) {
        char current = infix[i];

        // If the scanned character is an operand, add it to postfix
        if (isalnum(current)) {
            postfix += current;
        }
        // If the scanned character is '(', push it to the stack
        else if (current == '(') {
            s.push(current);
        }
        // If the scanned character is ')', pop and add to postfix until '(' is encountered
        else if (current == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Pop '(' from stack
        }
        // If the scanned character is an operator
        else if (isOperator(current)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(current)) {
                postfix += s.pop();
            }
            s.push(current); // Push the current operator
        }
    }

    // Pop all the remaining operators from the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
