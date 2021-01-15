#ifndef _ABSTRACT_FACTORY
#define _ABSTRACT_FACTORY

typedef struct _food_factory{
  void (*createNoodles)();
  void (*createTea)();
  void (*createSauce)();
}FoodFactory;

typedef struct _indian_factory{
  void (*createNoodles)();
  void (*createTea)();
  void (*createSauce)();
}IndianFoodFactory;

typedef struct _chinease_factory{
  void (*createNoodles)();
  void (*createTea)();
  void (*createSauce)();
}ChineaseFoodFactory;

typedef struct _europe_factory{
  void (*createNoodles)();
  void (*createTea)();
  void (*createSauce)();
}EuropeFoodFactory;

IndianFoodFactory* getIndianFoodFactory();
ChineaseFoodFactory* getChineaseFoodFactory();
EuropeFoodFactory* getEuropeFoodFactory();

void makeNoodleWith(FoodFactory* foodFactory);
void makeTeaWith(FoodFactory* foodFactory);
void makeSauceWith(FoodFactory* foodFactory);

#endif