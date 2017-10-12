#include<stdio.h>
#define ll long long

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}

ll mul(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;

    ll ret = 0;
    while(b){
        if(b&1){
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        b >>= 1;
        a <<= 1;
        if(a >= mod) a -= mod;
    }
    return ret;
}

ll china(int n, ll* a, ll* m) {
    ll M = 1, d, y, x = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) {
        ll w = M / m[i];
        exgcd(m[i], w, d, y);
        x = (x + mul(mul(y, w, M), a[i], M));
    }
    return (x + M) % M;
}

ll w[] = {23,28,33};

int main()
{
    ll  a[3];
    int d,Case = 0;
    while(scanf("%I64d%I64d%I64d%d",&a[0],&a[1],&a[2],&d),a[0]!=-1)
    {
        ll ans = china(3,a,w)-d;
        if(ans<=0)
        {
            ans+=21252;
        }
        printf("Case %d: the next triple peak occurs in %I64d days.\n",++Case,ans);
    }

}
