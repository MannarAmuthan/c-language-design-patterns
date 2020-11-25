#include "StringBuilder.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 

StringBuilder* append(StringBuilder* stringBuilder,char* str);
StringBuilder* reverse(StringBuilder* stringBuilder);

StringBuilder* getStringBuilder(char* str){
    StringBuilder* stringBuilder=(StringBuilder*)malloc(sizeof(StringBuilder));
    int len=strlen(str);
    stringBuilder->size=len;
    stringBuilder->str=(char*)malloc(len);
    strcpy(stringBuilder->str,str);
    stringBuilder->append=append;
    stringBuilder->reverse=reverse;
    return stringBuilder;
}

StringBuilder* append(StringBuilder* stringBuilder,char* str){
    char* strSource=stringBuilder->str;
    int len=strlen(str);
    int oldlen=strlen(strSource);
    stringBuilder->str=(char*)realloc(stringBuilder->str,len+oldlen);
    strcat(strSource,str); 
    return stringBuilder;
}

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}

StringBuilder* reverse(StringBuilder* stringBuilder){
    strrev(stringBuilder->str);
    return stringBuilder;
}

