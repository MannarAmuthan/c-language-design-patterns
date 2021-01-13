#include "src/user.h"

int main(){
     User* userOne=getUser("User one");
     userOne->doSomething(userOne);

     User* user=getUser("Non user");
     user->doSomething(user);
}