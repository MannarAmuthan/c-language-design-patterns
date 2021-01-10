#include "state.h"
#include <stdlib.h>
#include <string.h>

void setState(Context* context,State* state){
   context->state=state;
}
void doOperation(State* state,Context* context){
   context->setState(context,state);
}
Context* getContext(){
  Context* context=(Context*)malloc(sizeof(Context));
  context->state=NULL;
  context->setState=setState;
  return context;
}

State* getStartState(){
  StartState* state=(StartState*)malloc(sizeof(StartState));
  state->doOperation=doOperation;
  char name[]="Start State";
  state->stateName=(char*)malloc(strlen(name));
  strcpy(state->stateName,name);
  return (State*)state;
}

State* getStopState(){
  StopState* state=(StopState*)malloc(sizeof(StopState));
  state->doOperation=doOperation;
  char name[]="Stop State";
  state->stateName=(char*)malloc(strlen(name));
  strcpy(state->stateName,name);
  return (State*)state;
}