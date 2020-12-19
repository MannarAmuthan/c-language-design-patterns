#include "src/coffeemaker.h"

int main(){
    //Without using facade Pattern
    MilkVendor* milkvendor=getMilkVendor();
    Heater* heater=getHeater();
    CoffeePowder* coffeePowder=getCoffeePowder();

    Glass* glass=getGlass(1);

    milkvendor->addMilk(glass);
    heater->heat(glass);
    coffeePowder->addCoffeePowder(glass);

    //With using facade pattern
    
    CoffeeMaker* coffeemaker=getCoffeeMaker();
    coffeemaker->makeCoffee(glass,coffeemaker);

}