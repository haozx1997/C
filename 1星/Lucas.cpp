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
ll pow_mod(ll x,ll n,ll mod_val)
{
    ll ans = 1;
    ll t = x % mod_val;
    while(n)
    {
        if(n & 1)
        ans = ans * t % mod_val;
        n >>= 1;
        t = t * t % mod_val;
    }
    return ans;
}
ll C(ll n,ll m,ll p)    
{
    if(n < m)
        return 0;
    ll ans = 1;
    for(ll i = 1; i <= m; i ++)
    {
        ans = ans * (n + 1 - i) % p;
        ll x = pow_mod(i%p,p - 2,p);
        ans = ans * x % p;
    }
    return ans;
}
ll Lucas(ll n,ll m,ll p)
{
    if(m == 0)
        return 1;
    return C(n%p,m%p,p) * Lucas(n/p,m/p,p);
}
ll n,m,p,i,j;
int main()
{
    while(~scanf("%I64d%I64d",&i,&j))
    {
    	printf("%I64d\n",Lucas(i,j,1e9+7));
	}
    return 0;
}

