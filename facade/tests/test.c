#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/coffeemaker.h"

int milkadded=0;
int powdered=0;
int heated=0;

void FakeAddmilk(Glass* glass){
    milkadded=1;
}

void FakeHeat(Glass* glass){
    heated=1;
}

void FakeAddCoffeePowder(Glass* glass){
    powdered=1;
}

int shouldCoffeemakerDoMilkVendingHeatingPowdering();

int main(){
    int isAllPassed=1;
    if(shouldCoffeemakerDoMilkVendingHeatingPowdering()==-1){
        printf("Test failed : In Facade Pattern : --> shouldCoffeemakerDoMilkVendingHeatingPowdering \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Facade Pattern \n");
    }
}

int shouldCoffeemakerDoMilkVendingHeatingPowdering(){
    CoffeeMaker* coffeemaker=getCoffeeMaker();
    Glass* glass=getGlass(1);
    coffeemaker->milkvendor->addMilk=FakeAddmilk;
    coffeemaker->heater->heat=FakeHeat;
    coffeemaker->coffeePowder->addCoffeePowder=FakeAddCoffeePowder;


    coffeemaker->makeCoffee(glass,coffeemaker);

    if(milkadded!=1) return -1;
    if(heated!=1) return -1;
    if(powdered!=1) return -1;
    
    return 0;
}
