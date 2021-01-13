#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char names[2][20]={"User one","User two"};

void doSomethingValidUser(User* user){
   printf("Doing operation for: %s\n",user->name);
}

void doSomethingNullUser(){
   printf("This user is not registered \n");
}

User* getUser(char* name){
   User* user=NULL;
   for(int i=0;i<2;i++){
     if(strcmp(name,names[i])==0){
         user=(User*)malloc(sizeof(ValidUser));
         user->doSomething=doSomethingValidUser;
         user->name=(char*)malloc(strlen(name));
         strcpy(user->name,name);
         return user;
     }
   }
   user=(User*)malloc(sizeof(NullUser));
   user->doSomething=doSomethingNullUser;
   return user;
}