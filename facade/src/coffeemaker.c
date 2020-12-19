#include "coffeemaker.h"

void addmilk(Glass* glass){
    printf("Adding milk in glass %d \n",glass->glassNumber);
}

void heat(Glass* glass){
    printf("Heating the glass %d \n",glass->glassNumber);
}

void addCoffeePowder(Glass* glass){
    printf("Adding coffee powder in glass %d \n",glass->glassNumber);
}

void makeCoffee(Glass* glass,CoffeeMaker* coffeeMaker){
    coffeeMaker->milkvendor->addMilk(glass);
    coffeeMaker->heater->heat(glass);
    coffeeMaker->coffeePowder->addCoffeePowder(glass);
}

MilkVendor* getMilkVendor(){
    MilkVendor* milkVendor=(MilkVendor*)malloc(sizeof(MilkVendor));
    milkVendor->addMilk=addmilk;
    return milkVendor;
}

Heater* getHeater(){
    Heater* heater=(Heater*)malloc(sizeof(Heater));
    heater->heat=heat;
    return heater;
}

CoffeePowder* getCoffeePowder(){
    CoffeePowder* coffeePowder=(CoffeePowder*)malloc(sizeof(CoffeePowder));
    coffeePowder->addCoffeePowder=addCoffeePowder;
    return coffeePowder;
}

CoffeeMaker* getCoffeeMaker(){
    CoffeeMaker* coffeeMaker=(CoffeeMaker*)malloc(sizeof(CoffeeMaker));
    coffeeMaker->milkvendor=getMilkVendor();
    coffeeMaker->heater=getHeater();
    coffeeMaker->coffeePowder=getCoffeePowder();
    coffeeMaker->makeCoffee=makeCoffee;
    return coffeeMaker;
}

Glass* getGlass(int glassNumber){
    Glass* glass=(Glass*)malloc(sizeof(Glass));
    glass->glassNumber=glassNumber;
    return glass;
}
