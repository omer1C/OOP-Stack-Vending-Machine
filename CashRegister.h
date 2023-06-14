#ifndef CASHREGISTER_H
#define CASHREGISTER_H

class CashRegister {
private:
    int cashOnHand;

public:
    CashRegister();
    explicit CashRegister(int amount);
    int getCurrentBalance() const;
    void acceptAmount(int amount);
    void ResetCounter();
    ~CashRegister();
};
#endif
