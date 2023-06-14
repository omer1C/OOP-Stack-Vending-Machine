#ifndef DISPENSERTYPE_H
#define DISPENSERTYPE_H

class DispenserType {
private:
    int numberOfItems;
    int cost;

public:
    DispenserType(int numberOfItems, int cost);
    int getNoOfItems() const;
    int getCost() const;
    void makeSale();
    ~DispenserType();
};
#endif
