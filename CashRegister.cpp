#include "CashRegister.h"

CashRegister::CashRegister() {  // Constructor
    cashOnHand = 0;
}

CashRegister::CashRegister(int amount) { // Constructor given amount
    cashOnHand = amount;
}

int CashRegister::getCurrentBalance() const {
    return cashOnHand;
}

void CashRegister::acceptAmount(int amount) { // Adding given amount to Register
    cashOnHand += amount;
}

void CashRegister::ResetCounter(){
    cashOnHand = 0;
}

CashRegister::~CashRegister() {}  // Empty Destructor
