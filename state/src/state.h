#ifndef _STATE_H
#define _STATE_H

typedef struct state{
  void (*doOperation)(struct state*,void*);
  char* stateName;
}State;


typedef struct context{
  State* state;  
  void (*setState)(struct context*,State*);
}Context;

typedef struct state_start{
    void (*doOperation)(State*,Context*);
    char* stateName;
} StartState;

typedef struct state_stop{
    void (*doOperation)(State*,Context*);
    char* stateName;
} StopState;

State* getStartState();
State* getStopState();
Context* getContext();

#endif