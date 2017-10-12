/*
i=b-a
m=floor(i*(1+sqrt(5.0))/2)
b=m+i
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

int check(long long a,long long b)
{
	if(a > b)
	{
		long long t = a;
		a = b;
		b = t;
	}
	long long i = b - a;
	long long m = floor(i*(1+sqrt(5.0))/2);
//	printf("%lld %lld\n",m,a);
	return (m == a);
 } 
int main()
{
	long long n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		printf("%d\n",!check(n,m));
	}
 } 
 
 
