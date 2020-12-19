#ifndef _COFFEEMAKER
#define _COFFEEMAKER

#include <stdlib.h>
#include <stdio.h>

typedef struct glass{
   int glassNumber;
}Glass;

typedef struct milkvendor{
   void (*addMilk)(Glass*);
}MilkVendor;

typedef struct heater{
   void (*heat)(Glass*);
}Heater;

typedef struct coffee_powder{
   void (*addCoffeePowder)(Glass*);
}CoffeePowder;

typedef struct coffeemaker{
    MilkVendor* milkvendor;
    Heater* heater;
    CoffeePowder* coffeePowder;
    void (*makeCoffee)(Glass*,struct coffeemaker*);
}CoffeeMaker;

MilkVendor* getMilkVendor();
Heater* getHeater();
CoffeePowder* getCoffeePowder();

CoffeeMaker* getCoffeeMaker();
Glass* getGlass(int glassNumber);



#endif