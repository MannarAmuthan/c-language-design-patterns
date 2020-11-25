#include "src/command.h"
#include <stdio.h>

int main(){
    Command *moveCommand,*clickCommand;
    moveCommand=getMoveCommand();
    clickCommand=getClickCommand();

    Invoker* invoker=getInvoker();

    invoker->invoke(moveCommand);
    invoker->invoke(clickCommand);
    
    printf("Executing \n");
    printf("Move operation : x axis moved to : %d ,y axis moved to: %d\n",((Move*)moveCommand)->x,((Move*)moveCommand)->y);
    printf("Click command exected %d \n",((Click*)clickCommand)->isClicked);

    invoker->undo(moveCommand);
    invoker->undo(clickCommand);
    
    printf("Undoing \n");
    printf("Move operation undone: x axis :%d, y axis: %d \n",((Move*)moveCommand)->x,((Move*)moveCommand)->y);
    printf("Click undone %d \n",((Click*)clickCommand)->isClicked);
    
}