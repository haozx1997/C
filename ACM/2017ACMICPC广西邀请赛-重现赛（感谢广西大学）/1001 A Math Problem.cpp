#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e18+7;

long long quick_mul(ll a,ll b)
{
	ll yaoyuan = 0;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan+a);
		}
		a = (a+a);
		b>>=1; 
	}
	return yaoyuan;
}

long long quick_pow(ll a,ll b)
{
	ll yaoyuan = 1;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = quick_mul(yaoyuan,a);
		}
		a = quick_mul(a,a);
		b>>=1; 
	}
	return yaoyuan;
}



int main()
{
	ll n;
	while(~scanf("%I64d",&n))
	{
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		int ans =0;
		for(int i =1;i < 16;i++)
		{
			if(quick_pow((ll)i,(ll)i)<=n)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		printf("%d\n",ans);
		
		
		
	}




 return 0;
}


