#ifndef _STRING_BUILDER
#define _STRING_BUILDER

typedef struct _string_builder{
    char* str;
    int size;
    struct _string_builder* (*append)(struct _string_builder*,char*);
    struct _string_builder* (*reverse)(struct _string_builder*);
}
StringBuilder;

StringBuilder* getStringBuilder(char* str);
StringBuilder* append(StringBuilder* stringBuilder,char* str);
StringBuilder* reverse(StringBuilder* stringBuilder);

#endif