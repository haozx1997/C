#include<stdio.h>
//????????
//24 29 34 0           1
//24 29 34 1           21252
//24 29 34 2           21251
//0  0  0  0           21252
long long W[] = {(long long)23,(long long)28,(long long)33};

long long ext_gcd(long long a, long long b, long long &x, long long &y) 
{
 	long long ret, tmp; 
	  if (!b) 
	  { 
		x = 1;
		y = 0;
		return a;
	  } 
	  ret = ext_gcd(b, a % b, x, y); 
 	  tmp = x;
	  x = y;
	  y = tmp - a / b * y;
      return ret; 
} 


long long China(long long B[],long long m[],long long k)  //B ำเสý 
   {      
       long long i;   
       long long d,x,y,a=0,Mi,M=1;   
       for(i=0;i<k;i++)   
       M*=m[i];   
       for(i=0;i<k;i++)   
       {
          Mi=M/m[i];   
          d=ext_gcd(m[i],Mi,x,y);   
          a=(a+y*Mi*B[i])%M;   
       }   
       if(a>0)
	   return a;   
       else
	   return(a+M);   
   } 



int main()
{
	long long n,b[200],w[200];
	while(~scanf("%I64d",&n))
	{
		for(int i = 0 ;i < n; i++)
		{
			scanf("%I64d%I64d",&b[i],&w[i]);
		}
		printf("%I64d\n",China(w,b,n));
	}
}


