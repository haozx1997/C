#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
long long z[10000000];
long long isz(long long a)
{
	if(a==1||a==0)
	 return 0;
	for(long long i = 2;i*i<=a;i++)
	{
		if(!(a%i))
		 return 0;
	}
	return 1;
}


int main()
{
	long long a,b,ii= 0;
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[ii]=a;
 	        
		  	ii++;
		  } ;
	  }  
	long long n ;
	long long zz = 0; 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld=",n);
		zz = 0; 
		if(isz(n))
		{
			printf("%lld\n",n);
			continue;
		}
		long long f = 0;
		while(1)
		{
			
			if(!(n%z[zz]))
			{if(f)
			{
				printf("*");
			}
				f = 1;
				printf("%lld",z[zz]);
				
				if(isz(n/z[zz]))
				{
					break;
				}
				n /=z[zz];
			}
			else 
			{
				zz++;
			}
		}
		printf("*%lld\n",n/z[zz]);
	}
}
