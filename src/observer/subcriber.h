#ifndef _SUBSCRIBER_H
#define _SUBSCRIBER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _subscriber{
  char* user_name;  
  void (*getUpdate)(struct _subscriber*,int);
}Subscriber;

void update(Subscriber* subscriber,int version);

Subscriber* getSubscriber(char* name){
    Subscriber* subscriber=(Subscriber*)malloc(sizeof(Subscriber));
    subscriber->user_name=name;
    subscriber->getUpdate=update;
    return subscriber;
}

void update(Subscriber* subscriber,int version){
  printf("Get updated for subscriber %s for version %d \n",subscriber->user_name,version);
}

#endif