#include "middleware.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

User* getUser(char* userName,char* role,int requests){
    User* user=(User*) malloc(sizeof(User));

    int nameLength=strlen(userName);
    char* username=(char*)malloc(nameLength);
    strcpy(username,userName);

    int roleLength=strlen(role);
    char* rolename=(char*)malloc(roleLength);
    strcpy(rolename,role);

    user->requests_count=requests;
    user->role=rolename;
    user->userName=username;

    return user;
}

int processNext(MiddleWare* middleware,User* user){
     if(middleware->next==NULL){
        return 0;
     }
     return middleware->next->process(middleware->next,user);
}

int processRoleMiddleWare(MiddleWare* middleware,User* user){
    printf("Running role middleware \n");
    if(strcmp(((RoleMiddleWare*)middleware)->supportedRoles,user->role)!=0){
        return -1;
    }
    return processNext(middleware,user);
}

int processAuthMiddleWare(MiddleWare* middleware,User* user){
    printf("Running auth middleware \n");
    if(strcmp(((AuthMiddleWare*)middleware)->existingUsers,user->userName)!=0){
        return -1;
    }
    return processNext(middleware,user);
}

int processRequestLimitMiddleWare(MiddleWare* middleware,User* user){
    printf("Running request limit middleware \n");
    if(((RequestLimitMiddleWare*)middleware)->requests<user->requests_count){
        return -1;
    }
    user->requests_count+=1;
    return processNext(middleware,user);
}


MiddleWare* getRoleMiddleWare(char* supportedRoles){
    RoleMiddleWare* roleMiddleWare=(RoleMiddleWare*) malloc(sizeof(RoleMiddleWare));
    roleMiddleWare->next=NULL;

    int supportedRolesLength=strlen(supportedRoles);
    char* rolename=(char*)malloc(supportedRolesLength);
    strcpy(rolename,supportedRoles);

    roleMiddleWare->supportedRoles=rolename;
    roleMiddleWare->process=processRoleMiddleWare;
    return (MiddleWare*)roleMiddleWare;
}

MiddleWare* getAuthMiddleWare(char* userList){
    AuthMiddleWare* authMiddleWare=(AuthMiddleWare*) malloc(sizeof(AuthMiddleWare));
    authMiddleWare->next=NULL;

    int length=strlen(userList);
    char* usernames=(char*)malloc(length);
    strcpy(usernames,userList);

    authMiddleWare->existingUsers=usernames;
    authMiddleWare->process=processAuthMiddleWare;
    return (MiddleWare*)authMiddleWare;
}

MiddleWare* getRequestLimitMiddleWare(int maximumLimit){
    RequestLimitMiddleWare* requestLimitMiddleWare=(RequestLimitMiddleWare*) malloc(sizeof(RequestLimitMiddleWare));
    requestLimitMiddleWare->next=NULL;
    requestLimitMiddleWare->requests=maximumLimit;
    requestLimitMiddleWare->process=processRequestLimitMiddleWare;
    return (MiddleWare*)requestLimitMiddleWare;
}
