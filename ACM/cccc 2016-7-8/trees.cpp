#include<string.h>
#include<stdio.h>


int main()
{
	int sn;
	long long n,a,b;
	
	while(scanf("%lld",&n),n)
	{
		n++;
		scanf("%d",&sn);
		while(sn--)
		{
			scanf("%lld%lld",&a,&b);
			n -= (b-a+1);
		}
		printf("%lld\n",n);
		
		
		
		
		
		
	}
}
