#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

class Stack {
private:
    StackNode* top;

public:
    Stack();
    void push(int value);
    void pop();
    bool isEmpty();
    int peek();
    ~Stack();
};
#endif
