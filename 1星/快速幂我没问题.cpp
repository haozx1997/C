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
			yaoyuan = (yaoyuan*a)%mod;//快速乘有毒，勿用！ 
		}
		a = (a*a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}



int main()
{





 return 0;
}


