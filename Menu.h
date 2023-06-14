#include "VendingMachine.h"
#include "Stack.h"
class Menu{
public:
    Menu();
    void mainMenu();
    void shopMenu(VendingMachine& newMachine);
    void stackMenu(Stack& newStack);
    ~Menu();

}
;
