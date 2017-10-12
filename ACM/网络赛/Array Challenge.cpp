#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define PI acos(-1.0)
#define ITER set<int>::iterator
const int Mod = 1e9 + 7;
const int maxn = 1e5 + 10;

ll h[maxn];
ll b[maxn];
ll a[maxn];

void Init()
{
    h[0] = 2;h[1] = 3;h[2] = 6;
    for(int i = 3; i <= 20; i ++)
    {
        h[i] = 4 * h[i - 1] + 17 * h[i - 2] - 12 * h[i - 3] - 16;
    }
    for(int i = 1; i < 20;i ++)
    {
        b[i] = 3 * h[i + 1] * h[i] + 9 * b[i + 1] * b[i - 1] + 9 * h[i] * h[i] +
        27 * h[i]* h[i - 1] - 18 * h[i + 1] - 126 * h[i] - 81 * h[i - 1] + 192;
    }
    for(int i = 1; i < 20; i ++)
    {
        ll t = 1;int temp = i;while(temp --)t *= 4;
        a[i] = (ll)sqrt((ll)b[i] + (ll)t);
    }
    for(int i = 1; i <= 20; i ++)
        cout << i << " " << h[i] << " " << b[i] << " " << a[i] <<  endl;
}

int main()
{
    Init();
}

