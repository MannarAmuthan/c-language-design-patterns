#include <stdio.h>
#include "src/publisher.h"
#include "src/subscriber.h"

int main(){
    Publisher *appOne,*appTwo;
    Subscriber *userOne,*userTwo;

    appOne=getPublisher("App One");
    appTwo=getPublisher("App Two");

    userOne=getSubscriber("User One");
    userTwo=getSubscriber("User Two");
    
    addSubscriber(appOne,userOne);
    addSubscriber(appTwo,userOne);
    addSubscriber(appTwo,userTwo);

    releaseUpdate(appOne,1);
    releaseUpdate(appTwo,2);
}