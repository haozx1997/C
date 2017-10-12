#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define PI acos(-1.0)


const int maxn = 1e3 + 10;
const int Mod = 1e9 + 7;
string s;
int bits[maxn];
ll dp[maxn][10][2][2];
int a[4];
ll dfs(int pos,bool lead,bool flag1,bool flag2,int pre,bool flag)//flag1代表递减，flag2代表递增
{
//    if(pos < 0 )
//    {
//        for(int i = 2; i >= 0; i --)cout << a[i];puts("");
//    }
    if(pos < 0){if(lead && pre == 0)return 0;else return 1;}
    if(!flag && !lead && pre != -1 && dp[pos][pre][flag1][flag2] != -1)return dp[pos][pre][flag1][flag2];
    int up = flag ? bits[pos] : 9;
    ll ret = 0;
    for(int i = 0; i <= up; i ++)
    {
//        if(pos == 0 && i == 0 && a[1] == 2){cout << flag1 << " " << flag2 << " " << pre << endl;}
        a[pos] = i;
        if(flag1 && flag2 && i >= pre)
            ret = (ret + dfs(pos - 1,lead && i == 0,flag1,flag2,i,flag && i == up)) % Mod;
        else if(flag1 && !flag2)
            ret = (ret + dfs(pos - 1,lead && i == 0,flag1,i > pre ? true : false,i,flag && i == up)) % Mod;
        else if(!flag1 && flag2 && i >= pre)
        {
            ret = (ret + dfs(pos - 1,lead && i == 0,flag1,flag2,i,flag && i == up)) % Mod;
        }
        else if(!flag1 && !flag2)
        {
            bool t1 = false,t2 = false;
            if(lead){t1 = false,t2 = false;}
            else if(!lead && i < pre){t1 = true,t2 = false;}
            else if(!lead && i > pre){t1 = false;t2 = true;}
            ret = (ret + dfs(pos - 1,lead && i == 0,t1,t2,i,flag && i == up)) % Mod;
        }
    }
    if(!lead && !flag && pre != -1)dp[pos][pre][flag1][flag2] = ret;
    return ret;
}

ll calc()
{
    int len = 0;
    for(int i = s.size() - 1; i >= 0; i --)bits[len ++] = s[i] - '0';
    return dfs(len - 1,true,false,false,-1,true);
}
int main()
{
    clr(dp,-1);
    int Tcase;scanf("%d",&Tcase);
    while(Tcase --)
    {
        cin >> s;
        printf("%I64d\n",calc());
    }
    return 0;
}

