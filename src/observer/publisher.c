#include "publisher.h"
void addSubscriber(Publisher *publisher,Subscriber *subscriber){
    int next_index=publisher->current_subsrcribers;
   if(publisher->subscribers==NULL){
      publisher->subscribers=(Subscriber*) malloc(sizeof(Subscriber));
   }
   else{
      publisher->subscribers=(Subscriber*)realloc(publisher->subscribers,(next_index*sizeof(Subscriber))+1);
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

