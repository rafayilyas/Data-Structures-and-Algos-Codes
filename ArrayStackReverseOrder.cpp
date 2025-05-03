#include <iostream>
#include <string>
using namespace std;

#define SIZE 100  // Maximum size of the stack

char stack[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char value) {
    if (top == SIZE - 1) {
        cout << "Stack is full!\n";
    } else {
        stack[++top] = value;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return '\0'; // Return null character if empty
    } else {
        return stack[top--];
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Take string input

    // Push each character of the string onto the stack
    for (int i = 0; i < input.length(); i++) {
        push(input[i]);
    }

    // Pop each character from the stack to print it in reverse order
    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
