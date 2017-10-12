#include<stdio.h>

int extended_gcd(int a, int b, int &x, int &y) 
{
 	int ret, tmp; 
	  if (!b) 
	  { x = 1; y = 0; return a; } 
	  ret = extended_gcd(b, a % b, x, y); 
 	tmp = x; x = y; y = tmp - a / b * y;
      return ret; 
} 



int China(int B[],int W[],int k)   
   {      
       int i;   
       int d,x,y,a=0,m,n=1;   
       for(i=0;i<k;i++)   
       n*=W[i];   
       for(i=0;i<k;i++)   
       {
          m=n/W[i];   
          d=extended_gcd(W[i],m,x,y);   
          a=(a+y*m*B[i])%n;   
       }   
       if(a>0)
	   return a;   
       else
	   return(a+n);   
   } 
int main()
{
	int a[2]={8,11};
	int m[2]={7,9};
	
	
	printf("%d",China(a,m,2)   );
}

