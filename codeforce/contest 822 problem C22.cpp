#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
#define INF 0x3f3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)

typedef pair<ll,ll> P;
typedef pair<ll,P> PS;
vector<PS>v;
ll n,m;
ll sum[maxn];
int main()
{
	freopen("2.out","r",stdin);
    while( ~ scanf("%I64d%I64d",&n,&m))
    {
        clr(sum,INF);
        v.clear();
        for(ll i = 1; i <= n; i ++)
        {
            ll l,r,cost;
            scanf("%I64d%I64d%I64d",&l,&r,&cost);
            v.push_back(make_pair(l,make_pair(-r,cost)));
            v.push_back(make_pair(r,make_pair(l,cost)));
        }
        sort(v.begin(),v.end());
        ll ans = INF;
        for(ll i = 0; i < v.size(); i ++)
        {
            PS t = v[i];
            P tt = v[i].second;
            ll l = t.first,r = tt.first;
            if(r < 0)//???
            {
                r = -r;
                if(r - l + 1 < m)ans = min(ans,sum[m - (r - l + 1)] + tt.second);
            }
            else
            {
                ll ts = l;l = r; r =ts;
                sum[r - l + 1] = min(sum[r - l + 1],tt.second);
            }
        }
        if(ans >= INF)
        puts("-1");
        else
        cout << ans << endl;
    }
    return 0;
}

