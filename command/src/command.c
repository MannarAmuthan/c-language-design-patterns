#include "command.h"
#include <stdlib.h>

void move_execute(Move* move_command){
    move_command->x=move_command->x+1;
    move_command->y=move_command->y+1;
}

void move_undo(Move* move_command){
    move_command->x=move_command->x-1;
    move_command->y=move_command->y-1;    
}

void click_execute(Click* click_command){
    click_command->isClicked=1;
}

void click_undo(Click* click_command){
    click_command->isClicked=0;   
}

Command* getMoveCommand(){
    Move* move=(Move*) malloc(sizeof(Move));
    move->execute=(void*)move_execute;
    move->undo=(void*)move_undo;
    move->x=0;
    move->y=0;
    return (Command*)move;
}

Command* getClickCommand(){
    Click* click=(Click*) malloc(sizeof(Click));
    click->execute=(void*)click_execute;
    click->undo=(void*)click_undo;
    click->isClicked=0;
    return (Command*)click;
}

Invoker* getInvoker(){
    Invoker* invoker=(Invoker*) malloc(sizeof(Invoker));
    invoker->invoke=(void*)invoke;
    invoker->undo=(void*)undo;
    void (*invoke)(Command*);
    void (*undo)(Command*);
    return invoker;
}

void invoke(Command* command){
    command->execute(command);
}

void undo(Command* command){
    command->undo(command);
}
