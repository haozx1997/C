#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

long long quick_mul(ll a,ll b)
{
	ll yaoyuan = 0;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan+a)%mod;
		}
		a = (a+a)%mod;
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
			yaoyuan = quick_mul(yaoyuan,a)%mod;
		}
		a = quick_mul(a,a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}


int main()
{
	ll n,m;
	int T = 1;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		printf("Case #%d: %I64d\n",T++,quick_pow(n,m));
	}




 return 0;
}


