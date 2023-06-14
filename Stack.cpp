#include "Stack.h"
#include <climits>
#include <iostream>

using namespace std;


Stack::Stack() {
    top = NULL; // Initialize the top pointer to null
}

void Stack::push(int value) { // Creating a new Node with value
    StackNode* newNode = new StackNode(value);
    newNode->setNext(top); // Setting the next pointer to top node
    top = newNode; // Update top
}

void Stack::pop() {
    if (isEmpty()) { // Checking if Stack is empty
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Removing "<< top->getData()<< endl;
    StackNode* temp = top;
    top = top->getNext(); // Move the top pointer to the next node
    delete temp; // Delete old top
}

bool Stack::isEmpty() {
    return (top == NULL);
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    return top->getData();
}

Stack::~Stack() {
    // Deallocate the memory used by stack nodes
    while (!isEmpty()) { // Deleting all nodes until reaching Null
        StackNode* temp = top;
        top = top->getNext();
        delete temp;
    }
}
