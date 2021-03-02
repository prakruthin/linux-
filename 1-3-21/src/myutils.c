#include"myutils.h"

 int multiplyNumbers(int n) {
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}
int prime(int n){
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i!=0)
			continue;
		else
			return 1;
	}
	return 0;
}
int checkpalindrome(char *s)
{
     int i,c=0,n=strlen(s);
    if(i<n/2)
    {
         if(s[i]==s[n-i-1])
    	c++;
    	i++;
    	checkpalindrome(s);
	}
	else
	{
		if(c==i)
        return 1;
        else
        return 0;
	}
 	 
 	
}
int sum(int N, ...)
{
    int loop,sum;
    va_list va; /*for argument list*/
     
    va_start(va,N); /*init with number of arguments*/
     
    /*access arguments & calculating sum*/
    sum=0;
    for(loop=0;loop<N;loop++){
        sum+=va_arg(va,int);
    }
     
    return sum;
}


 
