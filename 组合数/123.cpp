#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000000 + 10;
#define INF 0x7fffffff
#define clr(x,y) memset(x,y,sizeof(x))
typedef long long ll;
#define eps 10e-10
const ll Mod = 1000000007;


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
		a = quick_mul(a,a);
		b>>=1; 
	}
	return yaoyuan;
}



ll gcd(ll a,ll b)
{
	return b == 0? a : gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

ll Lcm[1000111];

int main()
{
	int n =1000100;
//	for(ll n = 1;n<=nn;n++)
    {
    	Lcm[0] = 1ll;
    	for(ll i = 1ll;i <= n;i++)
    	{
    		Lcm[i] = lcm(i,Lcm[i-1]);
//    		if(i>1000000)
//		{
//			printf("%I64d\n",Lcm[i]);
//		}
		}
		
	}
	int T;
	scanf("%d",&T);
	ll q;
	for(int i =0)
	{
	//	scanf("%I64d",&q);
		
		q++;
		q = (ll)T;
		printf("T %d %I64d\n",T,Lcm[q]/q);
		
		
	}
	
	
    return 0;
}

