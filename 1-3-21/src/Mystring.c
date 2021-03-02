#include"Mystring.h"
#include<string.h>
int mystrlen( const char* str1)
{
    return strlen(str1);
}

char* mystrcpy(char* str1,char* str2)
{
    return strcpy(str1,str2);
}

char* mystrcat(char* str1, char* str2)
{
    return strcat(str1,str2);
}

int mystrcmp(const char* str1,const char* str2)
{
    return strcmp(str1,str2);
}
