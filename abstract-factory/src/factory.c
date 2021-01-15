#include <stdio.h>
#include <stdlib.h>
#include "factory.h"

void createIndianNoodle(){
    printf("Create noodles with indian spices");
}

void createIndianTea(){
    printf("Create tea with indian black tea");
}

void createIndianSauce(){
    printf("Create sauce with chilly for india");
}

void createChinaNoodle(){
    printf("Create noodles with chinease spices");
}

void createChinaTea(){
    printf("Create tea with chinease red tea");
}

void createChinaSauce(){
    printf("Create sauce with soy for china");
}

void createEuropeNoodle(){
    printf("Create noodles with europe spices");
}

void createEuropeTea(){
    printf("Create tea with europe green tea");
}

void createEuropeSauce(){
    printf("Create sauce with sphegatti for europe");
}

IndianFoodFactory* getIndianFoodFactory(){
    IndianFoodFactory* factory=(IndianFoodFactory*)malloc(sizeof(IndianFoodFactory));
    factory->createNoodles=createIndianNoodle;
    factory->createTea=createIndianTea;
    factory->createSauce=createIndianSauce;
    return factory;
}

ChineaseFoodFactory* getChineaseFoodFactory(){
    ChineaseFoodFactory* factory=(ChineaseFoodFactory*)malloc(sizeof(ChineaseFoodFactory));
    factory->createNoodles=createChinaNoodle;
    factory->createTea=createChinaTea;
    factory->createSauce=createChinaSauce;
    return factory;
}

EuropeFoodFactory* getEuropeFoodFactory(){
    EuropeFoodFactory* factory=(EuropeFoodFactory*)malloc(sizeof(EuropeFoodFactory));
    factory->createNoodles=createEuropeNoodle;
    factory->createTea=createEuropeTea;
    factory->createSauce=createEuropeSauce;
    return factory;
}

void makeNoodleWith(FoodFactory* foodFactory){
    foodFactory->createNoodles();
    printf("\n");
}

void makeTeaWith(FoodFactory* foodFactory){
    foodFactory->createTea();
    printf("\n");
}

void makeSauceWith(FoodFactory* foodFactory){
    foodFactory->createSauce();
    printf("\n");
}