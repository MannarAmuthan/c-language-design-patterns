#ifndef _USER
#define _USER

typedef struct user{
    char* name;
    void (*doSomething)(struct user*);
}User;

typedef struct valid_user
{
    void (*doSomething)(struct user*);
    char* name;
}ValidUser;


typedef struct null_user
{
    void (*doSomething)(struct user*);
}NullUser;


User* getUser(char* name);

#endif