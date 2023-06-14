#include "StackNode.h"
#include <cstddef>

StackNode::StackNode(int value) {  // Constructor
    data = value;
    next = NULL;
}

int StackNode::getData() const {
    return data;
}

StackNode* StackNode::getNext() { // Returning Pointer to next Node
    return next;
}

void StackNode::setNext(StackNode* node) {
    next = node;
}

StackNode::~StackNode() {}
