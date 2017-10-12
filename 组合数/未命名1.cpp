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
		a = quick_mul(a,a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}




bool is_[maxn];
int prime[maxn];
int len = 0;
void Init()
{
    memset(is_,true,sizeof(is_));
    for(int i = 2; i < maxn; i ++)
    {
        if(is_[i])
        {
            prime[len ++] = i;
            for(int j = i * 2; j < maxn; j += i)
                is_[j] = false;
        }
    }
}



int main()
{

	
	int T;
	scanf("%d",&T);
	ll q;
	Init();
//	for(int  i=0; i <10;i++)
//	{
//		printf("%d %d\n",i,is_[i]);
//	}
	while(T--)
	{
		scanf("%I64d",&q);
		q++;
		ll ans = 1ll;
		for(ll i = 2ll;i <= q;i++)
		{
			if(!is_[i])
			{
				continue;
			}
		//	printf("%I64d %I64d %I64d\n",q,ans,i);
			ll ii = i;
			for(;ii<=q;ii*=i );
			ans *= (ii/i);
			
			ans %= mod;
		}
		
		
		ans = ans*quick_pow(q,mod-2);
		ans  = ans%mod;
		printf("%I64d\n",ans);
		
		
	}
	
	
    return 0;
}

