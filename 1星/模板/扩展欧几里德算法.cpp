#include<srdio.h>
#define ll long long

ll gcd(ll a ,ll b )
{
	return !b ? a : gcd( b , a%b );
}


void e_gcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
	}
	else
	{
		e_gcd(b, a%b, y,x);
		y -= x*(a/b);
	}
 } 

int main()
{
	ll m,n;
	while(~scanf("%I64d%I64d",&m,&n))
	{
		
	}
 } 
