#ifndef _PUBLISHER_H
#define _PUBLISHER_H

#include "subcriber.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _publisher{
  char* publisher_name;  
  int current_subsrcribers;
  Subscriber *subscribers;
}
Publisher;

void addSubscriber(Publisher *publisher,Subscriber *subscriber){
    int next_index=publisher->current_subsrcribers;
   if(publisher->subscribers==NULL){
      publisher->subscribers=(Subscriber*) malloc(sizeof(Subscriber));
   }
   else{
      realloc(publisher->subscribers,(next_index*sizeof(Subscriber))+1);
   }
   publisher->subscribers[next_index]=*subscriber;
   publisher->current_subsrcribers+=1;    
}

void releaseUpdate(Publisher* publisher,int version){
    int size=publisher->current_subsrcribers;
    for(int index=0;index<size;index++){
        Subscriber subscriber=publisher->subscribers[index];
        subscriber.getUpdate(&subscriber,version);
    }
}

Publisher* getPublisher(char* publisher_name){
   Publisher* publisher=(Publisher*) malloc(sizeof(Publisher));
   publisher->publisher_name=publisher_name;
   publisher->current_subsrcribers=0;
   publisher->subscribers=NULL;
   return publisher;
}

#endif