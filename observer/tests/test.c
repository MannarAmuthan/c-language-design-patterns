#include "../src/subscriber.h"
#include "../src/publisher.h" 
#include <stdio.h>
#include <stdlib.h>

int shouldAddSubsriberToThePublisher();
int shouldGetUpdatedWhenNewReleasedFromPublisher();

int mock_update_called_with_version=0;
char* mock_update_called_for_suscriber="";

int main(){
    int isAllPassed=1;
    if(shouldAddSubsriberToThePublisher()==-1){
        printf("Test failed : In Observer Pattern : --> shouldAddSubsriberToThePublisher \n");
        isAllPassed=0;
    }
    if(shouldGetUpdatedWhenNewReleasedFromPublisher()==-1){
        printf("Test failed : In Observer Pattern : --> shouldGetUpdatedWhenNewReleasedFromPublisher \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Observer Pattern \n");
    }

}

void mock_update(Subscriber* subscriber,int version){
  mock_update_called_with_version=version;
  mock_update_called_for_suscriber=subscriber->user_name;
}

int shouldAddSubsriberToThePublisher(){
    Publisher *testPublisher;
    Subscriber *testSubscriber;
    testPublisher=getPublisher("Test Publisher");
    testSubscriber=getSubscriber("Test Subscriber");
    
    addSubscriber(testPublisher,testSubscriber);

    int subscriber_list_size=testPublisher->current_subsrcribers;
    Subscriber* subscriber_list=testPublisher->subscribers;
    if(subscriber_list_size!=1) return -1;
    if(subscriber_list->user_name!=testSubscriber->user_name) return -1;
    if(subscriber_list->getUpdate!=testSubscriber->getUpdate) return -1;
    return 1;
}

int shouldGetUpdatedWhenNewReleasedFromPublisher(){
    Publisher *testPublisher;
    Subscriber *testSubscriber;
    testPublisher=getPublisher("Test Publisher");
    testSubscriber=getSubscriber("Test Subscriber");
    testSubscriber->getUpdate=mock_update;
    addSubscriber(testPublisher,testSubscriber);

    releaseUpdate(testPublisher,10);
    
    if(mock_update_called_for_suscriber!="Test Subscriber") return -1;
    if(mock_update_called_with_version!=10) return -1;
    return 1;
}

