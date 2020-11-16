#ifndef _PUBLISHER_H
#define _PUBLISHER_H

#include "publisher.h"
#include "subscriber.h"
#include <stdlib.h>

typedef struct _publisher{
  char* publisher_name;  
  int current_subsrcribers;
  Subscriber *subscribers;
}
Publisher;

void addSubscriber(Publisher *publisher,Subscriber *subscriber);
void releaseUpdate(Publisher* publisher,int version);
Publisher* getPublisher(char* publisher_name);

#endif