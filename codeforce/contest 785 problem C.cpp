#include<stdio.h>
#include<algorithm>

#define ll long long
int main()
{
	long long n,m;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		ll l = 0ll;
		ll r = (long long)INT_MAX*2;
		ll ans;
		if(n<=m)
		{
			printf("%I64d\n",n);
			continue;
		}
		while(l<=r)
		{
			
			ll x = (l+r)/2;
			ll ccc;
	//		printf("%I64d\n",x);
			if(x%2)
			{
				ccc = (x+1)/2*x + m;
			}
			else
			{
				ccc = x/2*(x+1) + m;
			}
		//	printf("%I64d   %I64d   \n",x,n);
			if(ccc>=n)
			{
				ans = x;
				r = x-1;
			}
			else
			{
				l = x+ 1;
			}
			
			
		}
		
		printf("%I64d\n",ans+m);
		
	}
}
