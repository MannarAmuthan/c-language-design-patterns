#include <stdio.h>
#include "src/middleware.h"

int main(){
    User* user=getUser("Amuthan","ADMIN",1);

    MiddleWare*  authMiddleware=getAuthMiddleWare("Amuthan");
    MiddleWare*  roleMiddleware=getRoleMiddleWare("ADMIN");
    MiddleWare*  requestLimitMiddleware=getRequestLimitMiddleWare(1);

    authMiddleware->next=roleMiddleware;
    roleMiddleware->next=requestLimitMiddleware;

    if(authMiddleware->process(authMiddleware,user)==0){
        printf("User successfully make request \n");
    }
    
    if(authMiddleware->process(authMiddleware,user)!=0){
        printf("There is some error (exceeded request or check user credentials )\n");
    }
}