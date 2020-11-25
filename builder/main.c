#include "src/StringBuilder.h"
#include "stdio.h"

int main(){
     char str[]="Hi";
     StringBuilder* stringBuilder;
    
     stringBuilder=getStringBuilder(str);
     stringBuilder=stringBuilder->append(stringBuilder,"I am ");
     stringBuilder=stringBuilder->append(stringBuilder,"created by ")->append(stringBuilder,"Appending ")->append(stringBuilder," and reverse ")->reverse(stringBuilder);
     printf("%s",stringBuilder->str);
}