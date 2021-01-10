#include <stdio.h>
#include "src/state.c"

int main(){
    Context* context=getContext();

    State* startState=getStartState();
    State* stopState=getStopState();

    startState->doOperation(startState,context);

    printf("current state : %s \n",context->state->stateName);

    stopState->doOperation(stopState,context);

    printf("current state : %s \n",context->state->stateName);

}