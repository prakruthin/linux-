#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include<stdio.h>
#include<string.h>

int Mystrlen(const char* src);
void Mystrcpy(char* dest, const char* src);
void Mystrcat(char *dest, const char *src);
int Mystrcmp(const char *str1, const char *str2);

#endif