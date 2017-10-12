#include<stdio.h>
#define ll long long

ll gcd(ll a ,ll b )
{
	return !b ? a : gcd( b , a%b );
}

ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}

int main()
{
	ll m,n;
	while(~scanf("%I64d%I64d",&m,&n))
	{
		printf("%I64d\n",lcm(m,n));
	}
 } 
