#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
long long z[100000];
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
	for(a=2;a<100000;a++)
	  {
		if(isz(a))
		{
			z[ii++] = a;
		}
	  }  
	long long n ;
	int zz = 0; 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n == 1)
		 {
		 	printf("1=1\n");
		 	continue;
		 }
		printf("%lld=",n);
		zz = 0; 
		if(isz(n))
		{
			printf("%lld\n",n);
			continue;
		}
		int f = 0;
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
		long long lll = n/z[zz];
		printf("*%lld\n",lll);
	}
}
