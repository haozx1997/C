#include<stdio.h>
//????????
//24 29 34 0           1
//24 29 34 1           21252
//24 29 34 2           21251
//0  0  0  0           21252
long long W[] = {(long long)23,(long long)28,(long long)33};

long long ext_euclid(long long a, long long b, long long &x, long long &y) 
{
 	long long ret, tmp; 
	  if (!b) 
	  { 
		x = 1;
		y = 0;
		return a;
	  } 
	  ret = ext_euclid(b, a % b, x, y); 
 	  tmp = x;
	  x = y;
	  y = tmp - a / b * y;
      return ret; 
} 


long long China(long long B[],long long W[],long long k)   
   {      
       long long i;   
       long long d,x,y,a=0,m,n=1;   
       for(i=0;i<k;i++)   
       n*=W[i];   
       for(i=0;i<k;i++)   
       {
          m=n/W[i];   
          d=ext_euclid(W[i],m,x,y);   
          a=(a+y*m*B[i])%n;   
       }   
       if(a>0)
	   return a;   
       else
	   return(a+n);   
   } 



int main()
{
	long long b[3],d;
	int Case =  0 ;
	while(scanf("%I64d%I64d%I64d%I64d",&b[0],&b[1],&b[2],&d),(b[0]!=-1))
	{
		long long ans = China(b,W,(long long)3)-d;
		if(ans <= 0)
		{
			ans += 21252;
		}
		printf("Case %d: the next triple peak occurs in %I64d days.\n",++Case,ans);
	}
}


