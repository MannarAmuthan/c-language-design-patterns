#include "subscriber.h"


Subscriber* getSubscriber(char* name){
    Subscriber* subscriber=(Subscriber*)malloc(sizeof(Subscriber));
    subscriber->user_name=name;
    subscriber->getUpdate=update;
    return subscriber;
}

void update(Subscriber* subscriber,int version){
  printf("Get updated for subscriber %s for version %d \n",subscriber->user_name,version);
}