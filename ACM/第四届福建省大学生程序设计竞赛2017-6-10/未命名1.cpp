#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define FOR(x,start,y) for(ll x = start; x <= y; x ++)
#define SC(x) scanf("%d",&x)
const  ll Mod = 1e9 + 7;

const ll maxn = 100 + 10;
struct Matrix
{
    ll a[maxn][maxn];
};
ll n;
ll m;
void show(Matrix t)
{
    for(ll i = 0; i < n; i ++){
        for(ll j = 0; j < n; j ++)
        cout << t.a[i][j] << " ";
    cout << endl;
    }
}
Matrix Mul(Matrix a,Matrix b,ll mod_val)
{
    Matrix c;
    for(ll i = 0; i < n; i ++)
    {
        for(ll j = 0; j < n; j ++)
        {
            c.a[i][j] = 0;
            for(ll k = 0; k < n;k ++)
            {
                c.a[i][j] += a.a[i][k] * b.a[k][j] % mod_val;
                c.a[i][j] %= mod_val;
            }
        }
	}
    return c;
}
//Matrix pow_mod(Matrix p,ll ns,ll mod_val)
//{
//    Matrix ret;
//    Matrix t = p;
//    for(ll i = 0; i < n; i ++)
//    {
//    	ret.a[i][i] = 1;
//	}
//    while(ns)
//    {
//        if(ns & 1)
//        {
//            ret = Mul(ret,t,mod_val);
//        }
//        ns >>= 1;
//        t = Mul(t,t,mod_val);
//    }
//    return ret;
//}

ll a[maxn];
ll b[maxn];
int main()
{
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n)
    scanf("%lld",&b[i]),b[i] %= Mod;
    FOR(i,1,n)
    scanf("%lld",&a[i]),a[i] %= Mod;
    Matrix p;

    FOR(i,0,n - 1)
    {
        p.a[0][i] = a[i + 1];
    }
    FOR(i,1,n - 1)
    p.a[i][i - 1] = 1;
    
    Matrix t;
    for(ll i = 0; i < n; i ++)
    {
    	t.a[i][i] = 1;
	}
	ll ns = m - n;
    while(ns)
    {
        if(ns & 1)
        {
            t = Mul(t,p,Mod);
        }
        ns >>= 1;
        p = Mul(p,p,Mod);
    }
    
    ll ans = 0;
    FOR(i,0,n - 1)
    ans =( ans + t.a[0][i] * b[n - i] % Mod ) % Mod;
    printf("%lld\n",ans);
    return 0;
}

