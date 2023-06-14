
#include "VendingMachine.h"
#include <iostream>
using namespace std;

VendingMachine::VendingMachine()  // Constructor - Automatically creating Stock
        : waterDis(10, 5), colaDis(5, 7), grapesDis(4, 6) {}


void VendingMachine::sellProduct(char product) {
    int cost;
    DispenserType* dispenser = NULL;
    bool ValidSelection = false;
    do {        // After getting product Choice from user - getting the cost and dispenser
        switch (product) {
            case 'w':
                dispenser = &waterDis;
                cost = waterDis.getCost();
                ValidSelection = true;
                break;
            case 'c':
                dispenser = &colaDis;
                cost = colaDis.getCost();
                ValidSelection = true;
                break;
            case 'g':
                dispenser = &grapesDis;
                cost = grapesDis.getCost();
                ValidSelection = true;
                break;
            default:
                cout << "Invalid product selection." << endl;

        }
    }while(!ValidSelection);


    int numItems = dispenser->getNoOfItems();
    if (numItems <= 0) {  // Checking if Item is sold out
        cout << "*********************************\n"
                "\n"
                "\n"
                "**Sorry, this item is sold out.**\n"
                "\n"
                "\n"
                "*********************************"<< endl;
        return;
    }

    cout << "Please deposit " << cost << " NIS"<<endl;
    // Todo: Fix paying process (Total needed amount - Cash in register)
    int payment ;
    int tempCounter = counter.getCurrentBalance();  // Saving amount before adding payment
    int totalRequired = counter.getCurrentBalance()+cost; // Required sum
    for(int i =0; i<2;i++){
        cin >> payment;
        counter.acceptAmount(payment); // Adding amount to counter

        if (counter.getCurrentBalance() < totalRequired) {
            if (i==1){ // Second try unsuccessful
                cout << "The amount is not enough. Collect what you deposited." << endl;
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
                cout << endl;
                counter.ResetCounter(); // Deal unsuccessful resetting counter
                counter.acceptAmount(tempCounter); // Setting old amount to counter
                return;
            } // first try unsuccessful
            cout << "Please deposit another "<< totalRequired-counter.getCurrentBalance()<< " NIS" << endl;
        } else{ break;}
    }

    dispenser->makeSale();
    cout << "Collect your item at the bottom and enjoy." << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << endl;
}

DispenserType* VendingMachine::getBeverage(char beverage){
    switch (beverage) {
        case 'w':
            return &this->waterDis;
        case 'c':
            return &this->colaDis;
        case 'g':
            return &this->grapesDis;
        default:
            cout<<"Error, please try again"<<endl;
    }
    return NULL;
}

VendingMachine::~VendingMachine(){} // Destructor - no Cleanup needed
