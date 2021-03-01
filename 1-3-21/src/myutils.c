int isPrime(int num) 
{
    int i;
    
    for(i=2; i<=num/2; i++)  
    {  
        /*  
         * If the number is divisible by any number  
         * other than 1 and self then it is not prime 
         */  
        if(num%i == 0)  
        {
            return 0;
        }  
    } 
    
    return 1; 
}
int isArmstrong(int num) 
{
    int lastDigit, sum, originalNum, digits;
    sum = 0;
    
    originalNum = num;

    /* Find total digits in num */
    digits = (int) log10(num) + 1;

    /*
     * Calculate sum of power of digits
     */
    while(num > 0)
    {
        // Extract the last digit
        lastDigit = num % 10;

        // Compute sum of power of last digit
        sum = sum + round(pow(lastDigit, digits));

        // Remove the last digit
        num = num / 10;
    }
    
    return (originalNum == sum);
}

int factorial(int n)
{
   int c;
   int result = 1;
 
   for( c = 1 ; c <= n ; c++ )
         result = result*c;
 
   return ( result );
}