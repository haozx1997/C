#include<stdio.h>
#define ll long long

ll gcd(ll a,ll b)
{
	return !b ? a : gcd(b,a%b);
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) 
{
	ll ret, tmp; 
	if (!b) 
	{
		x = 1;
		y = 0;
		return a;  
	} 
	ret = extended_gcd(b, a % b,x, y); 
	tmp = x;
	x = y; 
	y = tmp - a / b * y;
	return ret; 
} 

int main()
{
	ll x,y,m,n,l;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l))
	{
		ll a,b,c,t;
		a = n - m;
		b = l;
		c = x - y;
		t = gcd(a,b);
		if((c%t))
		{
			printf("Impossible\n");
			continue;
		}
		a /= t;
		b /= t; 
		c /= t;
		extended_gcd(a,b,x,y);
		x=((c*x)%b+b)%b;
		if(!x) x = b;
		printf("%I64d\n",x);
	}
}
 
