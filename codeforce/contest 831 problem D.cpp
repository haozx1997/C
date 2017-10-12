#include<bits/stdc++.h>

using namespace std;

struct node
{
	long long pz;
	long long d;
	bool operator < (const node& dd) const
	{
		return dd.d<d;
	}
}a[3000];


long long k,n;
long long r;
long long dis(long long pp,long long kk)
{
	if(pp>r)
	{
		if(pp>=kk&&kk>=r)
		{
			return pp-r;
		}
		else if(kk<r)
		{
			return pp-kk+(r-kk);
		}
		else//kk>pp
		{
			return kk-r+(kk-pp);
		}
	}
	if(pp<r)
	{
		if(pp<=kk&&kk<=r)
		{
			return r-pp;
		}
		else if(kk>r)
		{
			return kk - pp+(kk - r);
		}
		else//kk<pp
		{
			return r-kk+(pp-kk);
		}
	}
}
int main()
{
	long long an = 0;
	while(~scanf("%I64d%I64d%I64d",&k,&n,&r))
	{
		for(long long i = 0;i < k;i++)
		{
			scanf("%I64d",&a[i].pz);
			a[i].d = abs(a[i].pz - r);
			
		}
		sort(a,a+k);
		
		for(long long i = 0;i < k;i++)
		{
			printf("%I64d\n",a[i].d);
		}
		
		set<long long> S;
		set<long long> :: iterator it;
		
		long long b;
		for(long long i = 0;i < n;i++)
		{
			scanf("%I64d",&b);
			S.insert(b);
			
		}
		long long now;
		long long ans = 0;
		
		long long kmin;
		for(long long i = 0;i < k;i++)
		{
			long long pmin = 100000000000000000; 
			now = a[i].pz;
			for(it = S.begin();it != S.end();it++)
			{
				long long kp = *it;
				if(dis(now,kp)<=pmin)
				{
					pmin = dis(now,kp);
					kmin = kp;
				}
				
			}
		//	printf("%I64d %I64d\n",kmin,pmin);
			ans = max(ans,pmin);
			S.erase(kmin);
			
		}
		
		printf("%I64d\n",ans);
		
	}
	



 return 0;
}


