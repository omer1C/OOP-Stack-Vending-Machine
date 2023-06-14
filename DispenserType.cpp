#include "DispenserType.h"

DispenserType::DispenserType(int numberOfItems, int cost) {
    this->numberOfItems = numberOfItems; // Assigning number of items
    this->cost = cost;  // Assigning cost
}

int DispenserType::getNoOfItems() const {
    return numberOfItems;
}

int DispenserType::getCost() const {
    return cost;
}

void DispenserType::makeSale() {
    if (numberOfItems > 0) {  // Making sure item is not sold out
        numberOfItems--;  // Decreasing amount of items
    }
}

DispenserType::~DispenserType() {}  // Empty Destructor
