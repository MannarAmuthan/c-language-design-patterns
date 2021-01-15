#include "src/factory.h"

int main(){
    IndianFoodFactory* indianFactory=getIndianFoodFactory();
    ChineaseFoodFactory* chineaseFactory=getChineaseFoodFactory();
    EuropeFoodFactory* europeFactory=getEuropeFoodFactory();

    makeNoodleWith(indianFactory);
    makeTeaWith(chineaseFactory);
    makeSauceWith(europeFactory);
}