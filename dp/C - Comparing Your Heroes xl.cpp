#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<string>
using namespace std;
#define clr(x,y) memset(x,y,sizeof y)
const int maxn = 1000000 + 10;
int n,m,k;
int in[maxn];
vector<int>v[maxn];
map<string,int>ms;
bool vis[maxn];
int ans;
int a[maxn];
void dfs(int len)
{
    if(len == k)
    {
        ans ++;
//        for(int i = 1; i<= k; i ++)
//            cout << a[i] << " ";
//        cout << endl;
        return;
    }
    for(int i = 1; i <= k; i ++)
    {
        if(!in[i] && !vis[i])
        {
            vis[i] = true;
            for(int j = 0; j < v[i].size(); j ++)
            {
                int u = v[i][j];
                in[u] --;
            }
            a[len + 1] = i;
            dfs(len + 1);
            for(int j = 0; j < v[i].size(); j ++)
            {
                int u = v[i][j];
                in[u] ++;
            }
            vis[i] = false;
        }
    }
}
int main()
{
    while( ~ scanf("%d",&n))
    {
        ans = 0;
        ms.clear();
        for(int i = 0; i < n; i ++)
            v[i].clear();
        k = 0;
        for(int i = 1; i <= n; i ++)
        {
            string x,y;
            cin>> x>> y;
            if(!ms[x])
                ms[x] = ++k;
            if(!ms[y])
                ms[y] = ++k;
            v[ms[x]].push_back(ms[y]);
            in[ms[y]] ++;
        }
        map<string,int>::iterator it;
//        for(it = ms.begin();it != ms.end();it ++)
//        {
//            cout << it -> first << " " << it -> second << endl;
//        }
//        cout << k << endl;
        clr(vis,false);
        for(int i = 1; i <= k; i ++)
        {
            if(!in[i] && !vis[i])
            {
                vis[i] = true;
                for(int j = 0; j < v[i].size(); j ++)
                {
                    int u = v[i][j];
                    in[u] --;
                }
                a[1] = i;
                dfs(1);
                for(int j = 0; j < v[i].size(); j ++)
                {
                    int u = v[i][j];
                    in[u] ++;
                }
                vis[i] = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

