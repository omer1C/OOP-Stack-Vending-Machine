#include <iostream>
#include "Menu.h"
#include "VendingMachine.h"
#include "Stack.h"


using namespace std;

Menu::Menu() {  // Constructor
}


void Menu::mainMenu() {
    // Creating a new Machine and Stack.
    // Destructor will be called when we exit the main menu.
    VendingMachine newMachine;
    Stack newStack;

    char choice;
    bool ExitSelected;

    do {
        cout << "(1) Beverage Machine" << endl;
        cout <<"(2) Integer Stack" << endl;
        cout << "(3) Exit"<<endl;
        cin >> choice;
        switch (choice) {
            case '1':
                this->shopMenu(newMachine); // Going to ShopMenu
                break;
            case '2':
                this->stackMenu(newStack); // Going to StackMenu
                break;
            case '3':
                cout << "Goodbye!"<<endl;
                ExitSelected = true;
                break;
            default:
                cout<<"Invalid selection."<<endl;

        }
    } while (!ExitSelected);
}

void Menu::shopMenu(VendingMachine& newMachine) {
    bool ExitSelected = false;
    char choice;
    do {
        cout << "*** Beverage Machine ***" << endl;

        //Inventory details
        cout << "Inventory details" << endl;
        cout << "Water:       " <<  newMachine.getBeverage('w')->getNoOfItems()<<endl ;
        cout << "Cola:        " <<   newMachine.getBeverage('c')->getNoOfItems()<<endl;
        cout << "Grape juice: " << newMachine.getBeverage('g')->getNoOfItems()<<endl;

        //Menu options
        cout << "\nTo select an item, enter" << endl;
        cout << "1 For Water" << endl;
        cout << "2 For Cola" << endl;
        cout << "3 For Grape juice" << endl;
        cout << "4 To exit" << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                newMachine.sellProduct('w');
                break;
            case '2':
                newMachine.sellProduct('c');
                break;
            case '3':
                newMachine.sellProduct('g');
                break;
            case '4':
                cout << "Thank you!" << endl;
                ExitSelected = true;
                break;
            default:
                cout << "Invalid product selection." << endl;
        }
    } while (!ExitSelected);


}
void Menu::stackMenu(Stack& newStack) {
    char choice;
    bool ExitSelected = false;
    do {
        cout << "*** Manage your integer stack ***" << endl;

        //Menu options
        cout << "1 Push new element" << endl;
        cout << "2 Pop element" << endl;
        cout << "3 Show the first element" << endl;
        cout << "4 Check if empty" << endl;
        cout << "5 to exit" << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                cout<< "Please insert the new element: ";
                int value;
                cin>>value;
                newStack.push(value); // Pushing new stack node to Stack
                break;
            case '2':
                newStack.pop();  // Popping top stack node
                break;
            case '3':
                cout<<"The first element is: "<<newStack.peek()<<endl;
                break;
            case '4':
                if(newStack.isEmpty()){
                    cout<<"The stack is empty"<<endl;
                } else{
                    cout<<"The stack is not empty"<<endl;
                }
                break;
            case '5':
                ExitSelected= true;
                break;
            default:
                cout << "Invalid selection." << endl;
        }

    } while (!ExitSelected);
}

Menu::~Menu() {}  // Destructor - no Cleanup needed
