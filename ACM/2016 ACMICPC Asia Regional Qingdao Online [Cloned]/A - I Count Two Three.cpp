#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef set<int>::iterator ITER;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)

const int maxn = 1e5 + 10;
//const int Mod = 1e9 + 7;
//const int N = 2;

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
bool read(int &x,bool &flag)
{
    char ch = getchar();x = 0;flag = false;
    if(ch == EOF)return false;
    while(ch < '0' || ch > '9')ch = getchar();
    int cnt = 0;
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';cnt ++;ch = getchar();}
    if(cnt > 7)flag = true;
    return true;
}
int in[maxn];
int a[maxn];
int n,m;
vector<int>g[maxn];
bool vis[maxn];
void dfs(int u)
{
    vis[u] = true;
    for(int i = 0; i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(!vis[v])
            dfs(v);
    }
}
int main()
{
    int Tcase;scanf("%d",&Tcase);
    while(Tcase --)
    {
        clr(vis,false);
        scanf("%d%d",&n,&m);
        for(int i = 0; i<= n; i ++)g[i].clear();
        for(int i = 1; i <= n; i ++)
            scanf("%d",&a[i]);
        int ans = 0;clr(in,0);
        for(int i = 1;i <= m; i ++)
        {
            int x,y;scanf("%d%d",&x,&y);in[x]++;in[y] ++;g[x].push_back(y);g[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(in[i] % 2)cnt ++;
        }
        if( (cnt != 2 && cnt != 0) || !m)
        {
            puts("Impossible");continue;
        }
        for(int i = 1; i <= n; i ++)
			if(in[i])
				{
					dfs(i);
					break;
				}
        bool flag = false;
        for(int i = 1; i <= n; i ++)
            if(!vis[i]  && in[i])
				flag = true;
        if(flag)
        {
            puts("Impossible");continue;
        }
        for(int i = 1; i <= n; i ++)
        if(((in[i] + 1) / 2 % 2))
        {
            ans ^= a[i];
//            cout <<a[i] << endl;
/*
10
10 5
1 1 1 1 1 1 1 1 1 1 
1 2
3 4
5 6 
7 8
9 10


10 10
1 2 3 4 5 6 7 8 9 0 
1 2
3 4
5 6 
7 8
9 10
2 3
4 5 
6 7 
8 9 
10 1

10 9
1 2 3 4 5 6 7 8 9 0 
1 2
3 4
5 6 
7 8
9 10
2 3
4 5 
6 7 
8 9 







*/


        }

        printf("%d\n",ans);
    }
    return 0;
}
