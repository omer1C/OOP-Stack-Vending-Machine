#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H


#include "DispenserType.h"
#include "CashRegister.h"

class VendingMachine {
private:
    DispenserType waterDis;
    DispenserType colaDis;
    DispenserType grapesDis;
    CashRegister counter;

public:
    VendingMachine();
    void sellProduct(char product);
    DispenserType* getBeverage(char beverage);
    ~VendingMachine();

};
#endif
