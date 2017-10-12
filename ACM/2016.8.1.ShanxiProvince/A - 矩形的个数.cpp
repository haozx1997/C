#include<stdio.h>
#include<string.h>
#include<math.h>
long long howmy(long long n)
{
	long long ans = (1+n)*n/2;
	
	return ans;
}


int main()
{
	long long a,b;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		long long aa = howmy(a)*howmy(b);
		printf("%I64d\n",aa);
	}
	return 0;
}
