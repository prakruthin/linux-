// #include<stdio.h>
// #include<string.h>
// #include<assert.h>
#include "mystring.h"
int Mystrlen(const char* src)
{
	const char* p = src;
	assert(src != NULL);
 
	while(*(p++) != '\0');
	return p - src - 1;
}
 
// Copy the source string to destination string
char* Mystrcpy(char* dest, const char* src)
{

	int i = 0;
	assert(dest != NULL && src != NULL);
 
	if(dest && src)
	{
		while((*(dest + i) = *(src + i)) != '\0')
			i++;
		*(dest + i) = '\0';
	}
	//return dest;
	return strcpy(dest,src);
}
 
// concatenate the two string.
char* Mystrcat(char *dest, const char *src)
{
	char* new;
	new= strcat(dest,src);
	/*
	assert(dest != NULL && src != NULL);
	while(*(dest++) != '\0');
	dest--;
	while((*dest++ = *src++) != '\0');
	*/
	return new;

}
 
// compare the two string 
int Mystrcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	while(*str1 != '\0' && *str2 != '\0')
	{
		if(*str1 > *str2)
			return 1;
		else if(*str1 == *str2)
		{
			*str1++;
			*str2++;
		}
		else
		{
			return -1;
		}
	}
 
	if(*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	else
		return 0;
 
}
