#include"mystring.h"
#include<string.h>
int mystrlen( const char* s1)
{
    return strlen(s1);
}

char* mystrcpy(char* s1,char* s2)
{
    return strcpy(s1,s2);
}

char* mystrcat(char* s1, char* s2)
{
    return strcat(s1,s2);
}

int mystrcmp(const char* s1,const char* s2)
{
    return strcmp(s1,s2);
}
