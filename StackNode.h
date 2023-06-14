#ifndef STACKNODE_H
#define STACKNODE_H

class StackNode {
private:
    int data;
    StackNode* next;

public:
    explicit StackNode(int value);
    int getData() const;
    StackNode* getNext();
    void setNext(StackNode* node);
    ~StackNode();
};

#endif
