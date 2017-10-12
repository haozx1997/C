#include<bits/stdc++.h>

using namespace std;

long long sswr(double x)
{
	if((x-(long long)x)>=0.5)
	{
		return x+1;
	}
	return x;
}

long long gcd(long long a,long long b)
{
	return b == 0? a : gcd(b,a%b);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long x,y,p,q;
		scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		if(q == p)
		{
			if(x == y)
			{
				printf("0\n");
			}
			else
			{
				printf("-1\n");	
			}
			continue;
		}
		if(p == 0)
		{
			if(x == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("-1\n");	
			}
			continue;
		}
		if((x*q) ==(y*p))
		{
			printf("0\n");
			continue;
		}
		p = p/gcd(p,q);
		q = q/gcd(p,q);
		
		long long ansy,ansx;
		long long yn = (long long)ceil((double)(y-x)/(q-p));
		long long xn = (long long)ceil((double)x/p);
		long long nn = max(yn,xn);
		
		ansy = nn*q;
		
		long long ans = ansy - y;
		printf("%lld\n",ans);
		
	}




 return 0;
}


