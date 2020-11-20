#include "../src/StringBuilder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shouldAbleToAppend();
int shouldAbleToReverse();

int main(){
    int isAllPassed=1;
    if(shouldAbleToAppend()==-1){
        printf("Test failed : In Builder Pattern : --> shouldAbleToAppend \n");
        isAllPassed=0;
    }
    if(shouldAbleToReverse()==-1){
        printf("Test failed : In Builder Pattern : --> shouldAbleToReverse \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Builder Pattern \n");
    }
}

int shouldAbleToAppend(){
    char str[]="one";
    StringBuilder* stringBuilder;
    stringBuilder=getStringBuilder(str);

    stringBuilder=stringBuilder->append(stringBuilder,"two");

    if(strcmp(stringBuilder->str,"onetwo")!=0) return -1;
    return 0;
}

int shouldAbleToReverse(){
    char str[]="one";
    StringBuilder* stringBuilder;
    stringBuilder=getStringBuilder(str);

    stringBuilder=stringBuilder->reverse(stringBuilder);

    if(strcmp(stringBuilder->str,"eno")!=0) return -1;
    return 0;
}
