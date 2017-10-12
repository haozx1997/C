#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
long long  
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
	
	long long n ;
	long long zz = 0; 
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
		zz = 2; 
		if(isz(n))
		{
			printf("%lld\n",n);
			continue;
		}
		long long f = 0;
		while(1)
		{
			
			if(!(n%zz))
			{
				
				printf("%lld",zz);
				
				if(isz(n/zz))
				{
					break;
				}
				n /=zz;
			}
			else 
			{
				while(!(isz(++zz)));
			}
		}
		printf("%lld\n",n/zz);
	}
}
