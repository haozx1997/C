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
const int maxn = 1e6 + 10;
int a[maxn],cnt[maxn];

int main()
{
    int n,m;
    while( ~ scanf("%d",&n))
    {
        clr(cnt,0);for(int i = 1; i <= n; i ++)scanf("%d",&a[i]),cnt[a[i]] ++;
        int ans = 0;
        for(int i = 1; i < maxn - 5; i ++)
        {
            int t = (cnt[i] > 1) + (cnt[i + 1] > 1) + (cnt[i + 2] > 1);
            if(t <= 1)
            {
                if(cnt[i] == 1 && cnt[i + 1] == 1 && cnt[i + 2] == 1)ans ++,cnt[i] --,cnt[i + 1] --,cnt[i + 2] --;
                else
                {
                    ans += cnt[i] / 2,cnt[i] %= 2;
                    if(cnt[i] == 1 && (cnt[i + 1] && cnt[i + 2]))ans ++,cnt[i] --,cnt[i + 1] --,cnt[i + 2] --;
                }

            }
            else
            {
                ans += cnt[i]/ 2;cnt[i] %= 2;
                if(cnt[i] == 1 && (cnt[i + 1] % 2 || cnt[i + 2] % 2) )ans ++,cnt[i] --,cnt[i + 1] --,cnt[i + 2] --;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

