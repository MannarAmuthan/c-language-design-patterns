#include "../src/factory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int shouldCallProperFactoryMethod();

int fakeMethodcalled=0;

int fakeNoodleMethod(){
    fakeMethodcalled=1;
}

int main(){
    int isAllPassed=1;
    if(shouldCallProperFactoryMethod()==-1){
        printf("Test failed : In Abstract factory Pattern : --> shouldCallProperFactoryMethod \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Abstract factory Pattern \n");
    }
}

int shouldCallProperFactoryMethod(){
    IndianFoodFactory* indianFactory=getIndianFoodFactory();
    indianFactory->createNoodles=fakeNoodleMethod;

    makeNoodleWith(indianFactory);

    if(fakeMethodcalled==0) return 1;
    return -1;
}
