#include<stdio.h>  
#include<math.h>  
int main ()  
{  
    long long n, m, a; 
	while(~scanf("%I64d%I64d%I64d", &n, &m, &a) ) 
    {
    	printf("%I64d\n",(long long)ceil(1.0*n/a)*(long long)ceil(1.0*m/a));  
	 } 
    
}  
