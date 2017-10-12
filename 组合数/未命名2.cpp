#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1000 + 10;
int n,m;
int head[maxn * 10];
struct Edge
{
    Edge(){}
    Edge(int x,int y):to(x),next(y){}
    int to;
    int next;
}edge[maxn];
int dfn[maxn];
int low[maxn];
int stacks[maxn];
int top;
bool vis[maxn];
int ans;
int col[maxn];
int maze[maxn];
vector<int>v[maxn];
struct Node
{
    int x,y;
}a[maxn * 10];
void tarjan(int x,int &len)
{
    dfn[x] = len;
    low[x] = len;
    vis[x] = true;//记录x是否在栈中
    stacks[++top] = x;
    for(int i = head[x]; i != -1; i = edge[i].next)
    {
        int vs= edge[i].to;
        if(!dfn[vs])
        {
            len ++;
            tarjan(vs,len);
            low[x] = min(low[x],low[vs]);
        }
        else if(vis[vs])low[x] = min(low[x],dfn[vs]);
    }
    if(dfn[x] == low[x])
    {
        maze[ ++ans] = x;;
        vis[x] = false;
        col[x] = ans;
        while(stacks[top --] != x)//先减是为了防止出现一个点成联通的情况
        {
            col[stacks[top + 1]] = ans;
            vis[stacks[top + 1]] = false;
        }
    }
}
int in[maxn];
int main()
{
    int Tcase;
    scanf("%d",&Tcase);
    for(int ii = 1; ii <= Tcase; ii ++)
//    while( ~ scanf("%d%d",&n,&m))
    {
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        for(int i = 0; i <= maxn; i ++)
        v[i].clear();
        ans = 0;
        memset(vis,false,sizeof(vis));
        top = 0;
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(col,0,sizeof(col));
        memset(maze,0,sizeof(maze));
        for(int i = 1; i <= m; i ++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i].x = x;
            a[i].y = y;
            edge[i] = Edge(y,head[x]);
            head[x] = i;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(!dfn[i])
            {
                int len = 1;
                tarjan(i,len);
            }
        }
//        for(int i = 1; i <= ans; i ++)
//        cout << maze[i] << endl;
        for(int i = 1; i <= m; i ++)
        {
            int x = a[i].x,y = a[i].y;
            if(col[x] != col[y])
            {
                v[x].push_back(y);
                in[y] ++;
            }
        }
        bool flag = true;
        int kk = ans;
        while(kk --)
        {
            int t = 0;
            for(int i = 1; i <= ans; i ++)
            {
                int x = maze[i];
                if(in[x] == 0)
                {
                    t ++;
                    in[x] --;
                    for(int j = 0; j < v[x].size(); j ++)
                    {
                        int y = v[x][j];
                        in[y] --;
                    }
                }
            }
            if(t > 1)
            {
                flag = false;
                break;
            }
        }

        if(flag)cout << "I love you my love and our love save us!" << endl;
        else cout << "Light my fire!" <<endl;
    }
    return 0;
}

/*
6 6
1 2
2 3
3 1
3 4
4 5
2 6

*/
