#include "../src/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int shouldAbleToInvokeCommand();
int shouldAbleToUndoCommand();

int main(){
    int isAllPassed=1;

    if(shouldAbleToInvokeCommand()==-1){
        printf("Test failed : In Command Pattern : --> shouldAbleToInvokeCommand \n");
        isAllPassed=0;
    }

    if(shouldAbleToUndoCommand()==-1){
        printf("Test failed : In Command Pattern : --> shouldAbleToUndoCommand \n");
        isAllPassed=0;
    }
    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Command Pattern \n");
    }
}

int shouldAbleToInvokeCommand(){
    Command *moveCommand,*clickCommand;
    moveCommand=getMoveCommand();
    clickCommand=getClickCommand();

    Invoker* invoker=getInvoker();

    invoker->invoke(moveCommand);
    invoker->invoke(clickCommand);

    if(!(((Move*)moveCommand)->x==1&&((Move*)moveCommand)->y==1)){
        return -1;
    }

    if(((Click*)clickCommand)->isClicked==0){
        return -1;
    }
    
    return 0;
}

int shouldAbleToUndoCommand(){
    Command *moveCommand,*clickCommand;
    moveCommand=getMoveCommand();
    clickCommand=getClickCommand();
    Invoker* invoker=getInvoker();
    invoker->invoke(moveCommand);
    invoker->invoke(clickCommand);

    invoker->undo(moveCommand);
    invoker->undo(clickCommand);



    if(!(((Move*)moveCommand)->x==0&&((Move*)moveCommand)->y==0)){
        return -1;
    }

    if(((Click*)clickCommand)->isClicked==1){
        return -1;
    }

    return 0;
}
