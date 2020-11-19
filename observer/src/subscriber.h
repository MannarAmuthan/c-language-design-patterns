#ifndef _SUBSCRIBER_H
#define _SUBSCRIBER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _subscriber{
  char* user_name;  
  void (*getUpdate)(struct _subscriber*,int);
}Subscriber;

void update(Subscriber* subscriber,int version);

Subscriber* getSubscriber(char* name);

#endif