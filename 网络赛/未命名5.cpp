#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define PI acos(-1.0)
#define ITER set<int>::iterator
const int Mod = 998244353;
const int maxn = 5e6 + 10;
const int N = 2;

ll pows(ll x,ll n)
{
    ll ret = 1;
    while(n){if(n & 1)ret = ret *x % Mod;n >>= 1;x =  x * x % Mod;}
    return ret;
}
int main()
{
    ll n,m;
    while( ~ scanf("%lld%lld",&n,&m))
    {
        ll k = m ;if( (n - k) % 2 || m > n ){puts("0");continue;}
        ll temp = 1;ll a = n - k ,b = n + k - 2;
        bool flag = false;if(a > b){ll t = a;a = b;b = t;flag = true;}
        for(ll i = a + 2;i <= b; i += 2)
        temp = temp * i % Mod;
        ll t = 1;
        for(ll i = 1; i <= k; i ++)t = t * i % Mod;
        ll ans = n % Mod * pows(t,Mod - 2);
        if(flag)ans = ans * pows(temp,Mod - 2) % Mod;else ans = ans * temp % Mod;
        if((n - k)/2 % 2)
            ans = -ans;
        printf("%lld\n",(ans % Mod + Mod) % Mod );
    }
    return 0;
}

