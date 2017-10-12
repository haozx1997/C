#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
ll gcd( ll a,ll b)
{
	return !b ? a : gcd(b,a%b);
 } 
int main()
{
/*
81 36
36 81
21 24
*/ 
	while(~scanf("%I64d%I64d",&a,&b))
	{
		ll ans = 0ll;
		if(a>=b)
		{
			
			ans = b/gcd(a,b);
		}
		else
		{
			ans = (b-a)/gcd(a,b);
			ans ++;
		}
		printf("%I64d\n",ans);
	}



 return 0;
}


