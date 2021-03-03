#include "Mystring.h"
#include "Bitmask.h"
#include "Myutils.h"
#include<stdio.h>
int main()
{
    char s1[]="mysore";
    char s2[]="bangalore";
    char s3[]="chennai";
    int l=mystrlen(s1);
    printf("%d\n",l);
    printf("%d\n",mystrcmp(s1,s2));
    mystrcpy(s1,s2);
    printf("%s\n",s1);
    mystrcat(s1,s3);
    printf("%s\n",s1);
    int b1=8;
    printf("%d\n",set(b1,3));
    printf("%d\n",reset(b1,4));
    printf("%d\n",flip(b1));
    printf("%d\n",query(b1));
    int n=9;
    //printf("Enter a positive integer: ");
    //scanf("%d",&n);
    printf("Factorial of %d = %d", n, multiplyNumbers(9));
    int num,res=0;
	//printf("\nENTER A NUMBER: ");
	//scanf("%d",&num);
	res=prime(9);
	if(res==0)
		printf("\n%d IS A PRIME NUMBER",num);
	else
		printf("\n%d IS NOT A PRIME NUMBER\n",num);
         
    char s[1000];  
   
    printf("Enter  the string: ");
    //gets(s); 
    if(checkpalindrome("snellens"))
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");
    
    printf("Sum of 10, 20 = %d\n",sum(2,10,20));
    printf("Sum of 10, 20, 30, 40 = %d\n",sum(4,10,20,30,30));
    printf("Sum of 10, 20, 30, 40, 50, 60 = %d\n",sum(6,10,20,30,30,40,50));


   
    return 0;
}