#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/user.h"


int shouldGetValidUserObjectForValidUser();
int shouldGetNullUserObjectForInValidUser();

int main(){
    int isAllPassed=1;
    if(shouldGetValidUserObjectForValidUser()==-1){
        printf("Test failed : In Null object Pattern : --> shouldGetValidUserObjectForValidUser \n");
        isAllPassed=0;
    }

    if(shouldGetNullUserObjectForInValidUser()==-1){
        printf("Test failed : In Null object Pattern : --> shouldGetNullUserObjectForInValidUser \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Null object Pattern \n");
    }
}

int shouldGetValidUserObjectForValidUser(){
    User* userOne=getUser("User one");

    if(userOne->name==NULL) return -1;
    return 1;
}

int shouldGetNullUserObjectForInValidUser(){
    User* userOne=getUser("Random");
    if(userOne->name!=NULL) return -1;
    return 1;
}
