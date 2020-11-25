#ifndef _COMMAND
#define _COMMAND

typedef struct _commandable{
    void (*execute)(void*);
    void (*undo)(void*);
}
Command;

typedef struct _invoker{
    void (*invoke)(Command*);
    void (*undo)(Command*);
}
Invoker;

typedef struct move{
    void (*execute)(void*);
    void (*undo)(void*);
    int x,y;
}
Move;

typedef struct click{
    void (*execute)(void*);
    void (*undo)(void*);
    int isClicked;
}
Click;

Command* getMoveCommand();
Command* getClickCommand();
void invoke(Command* command);
void undo(Command* command);
Invoker* getInvoker();


#endif