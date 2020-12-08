#include "../src/middleware.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int shouldAbleProcessAuthMiddleWare();
int shouldAbleProcessRoleMiddleWare();
int shouldAbleProcessRequestMiddleWare();

int main(){
    int isAllPassed=1;

    if(shouldAbleProcessAuthMiddleWare()==-1){
        printf("Test failed : In Chain of Responsibility Pattern : --> shouldAbleProcessAuthMiddleWare \n");
        isAllPassed=0;
    }

    if(shouldAbleProcessRoleMiddleWare()==-1){
        printf("Test failed : In Chain of Responsibility Pattern : --> shouldAbleProcessRoleMiddleWare \n");
        isAllPassed=0;
    }

    if(shouldAbleProcessRequestMiddleWare()==-1){
        printf("Test failed : In Chain of Responsibility Pattern : --> shouldAbleProcessRequestMiddleWare \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
        printf("All tests are passed : In Chain of Responsibility Pattern \n");
    }
}

int shouldAbleProcessAuthMiddleWare(){
    User* user=getUser("Amuthan","ADMIN",1);
    
    MiddleWare*  middleware=getAuthMiddleWare("Amuthan");
    if(middleware->process(middleware,user)!=0) return -1;
    return 0;
}

int shouldAbleProcessRoleMiddleWare(){
    User* user=getUser("Amuthan","ADMIN",1);
    
    MiddleWare*  middleware=getRoleMiddleWare("ADMIN");
    if(middleware->process(middleware,user)!=0) return -1;
    return 0;
}

int shouldAbleProcessRequestMiddleWare(){
    User* user=getUser("Amuthan","ADMIN",1);
    MiddleWare*  middleware=getRequestLimitMiddleWare(0);
    if(middleware->process(middleware,user)!=-1) return -1;
    return 0;
}


