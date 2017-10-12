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
const int maxn = 10000 + 10;
ll dp[maxn][70];
char s[maxn];
int cnt1[maxn];
int sum[maxn];
vector<int>g[7];
void Init()
{
    clr(cnt1,0);clr(sum,0);
    for(int S = 0;S < 1 << 6; S ++)
    {
        int cnt = 0;
        for(int i = 1;i <= 6;i ++)
        {
            if(S & (1 << (i - 1)))cnt ++;
        }
        g[cnt].push_back(S);
        for(int i = 1;i <= 4; i ++)
            if(S & (1 << (i - 1)))
            cnt1[S] ++,sum[S] += 1 << (i + 1);
    }
}
int n;
int read()
{
	char c;c = getchar();
	int len = 0;
	while(c!='\n')
	{
	    s[++ len] = c;
		c = getchar();
	}
	n = len;
	s[++ len] = 0; 
}

int main()
{
//    freopen("out.txt","r",stdin);
    Init();
    int Tcase;scanf("%d",&Tcase);getchar();
    while(Tcase --)
    {
        clr(dp,0);read();
        if(n == 1)
        {
            if(s[0] == '0' || s[0] == '2')puts("1");
            else puts("2");continue;
        }
        for(int S = 0; S < 1 << 6;S ++)
        {
            int cnt = 0;
            for(int i = 3; i <= 6; i ++)
            {
                if((1 << (i - 1)) & S)
                {
                    cnt ++;
                }
            }
            if(cnt == s[1] - '0')
            {
                dp[1][S] = 1;
            }
        }
        for(int i = 2; i <= n;i ++)
        {
            for(int j = 0; j < g[s[i] - '0'].size(); j ++)
            {
                int S = g[s[i] - '0'][j];
                int t = sum[S];
                if(s[i - 1] - '0' - cnt1[S] == 2)
                    dp[i][S] = dp[i - 1][3 + t];
                else if(s[i - 1] -'0' - cnt1[S] == 1)
                {
                    dp[i][S] = dp[i - 1][1 + t] + dp[i - 1][2 + t];
                    if(dp[i][S] >= Mod)dp[i][S] -= Mod;
                }
                else if(s[i - 1] -'0' - cnt1[S] == 0)
                    dp[i][S] = dp[i - 1][t];
            }
        }
        ll ans = 0;
        for(int S = 0; S < 1 << 4; S ++)
        {
            ans = (ans + dp[n][S]) % Mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
