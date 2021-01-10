#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/state.h"


int shouldChangeStateToStartState();
int shouldChangeStateToStopState();

int main(){
    int isAllPassed=1;
    if(shouldChangeStateToStartState()==-1){
        printf("Test failed : In State Pattern : --> shouldChangeStateToStartState \n");
        isAllPassed=0;
    }

    if(shouldChangeStateToStopState()==-1){
        printf("Test failed : In State Pattern : --> shouldChangeStateToStopState \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In State Pattern \n");
    }
}

int shouldChangeStateToStartState(){
    Context* context=getContext();

    State* startState=getStartState();

    startState->doOperation(startState,context);

    if(strcmp(context->state->stateName,"Start State")!=0) return -1;
    return 0;
}

int shouldChangeStateToStopState(){
    Context* context=getContext();

    State* stopState=getStopState();

    stopState->doOperation(stopState,context);

    if(strcmp(context->state->stateName,"Stop State")!=0) return -1;
    return 0;
}
