#include "../../src/observer/publisher.h" 
#include "../../src/observer/subscriber.h"
#include <stdio.h>

#include "../../src/observer/publisher.c"
#include "../../src/observer/subscriber.c"

int shouldAddSubsriberToThePublisher();
int shouldGetUpdatedWhenNewReleasedFromPublisher();

int main(){
    int isAllPassed=1;
    if(shouldAddSubsriberToThePublisher()==-1){
        printf("Test failed : In Observer Pattern : --> shouldAddSubsriberToThePublisher \n");
        isAllPassed=0;
    }
    if(shouldGetUpdatedWhenNewReleasedFromPublisher()==-1){
        printf("Test failed : In Observer Pattern : --> shouldGetUpdatedWhenNewReleasedFromPublisher \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
}

int shouldAddSubsriberToThePublisher(){
    return -1;
}

int shouldGetUpdatedWhenNewReleasedFromPublisher(){
    return -1;
}