#ifndef _CHAIN_OF_RESPONSIBILITY
#define _CHAIN_OF_RESPONSIBILITY

typedef struct user
{
   char* role;
   char* userName;
   int requests_count;
}
User;

typedef struct middleware
{
   struct middleware *next;
   int (*process)(struct middleware *next,User *user);
}
MiddleWare;

typedef struct role_middleware
{
   MiddleWare *next;
   int (*process)(MiddleWare *next,User *user);
   char* supportedRoles;
}
RoleMiddleWare;

typedef struct auth_middleware
{
   MiddleWare *next;
   int (*process)(MiddleWare *next,User *user);
   char* existingUsers;
}
AuthMiddleWare;

typedef struct request_count_middleware
{
   MiddleWare *next;
   int (*process)(MiddleWare *next,User *user);
   int requests;

}
RequestLimitMiddleWare;

User* getUser(char* userName,char* role,int requests);

MiddleWare* getRoleMiddleWare(char* supportedRoles);
MiddleWare* getAuthMiddleWare(char* existingUsers);
MiddleWare* getRequestLimitMiddleWare(int maximumLimit);

#endif