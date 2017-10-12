#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define PI acos(-1.0)


const int maxn = 2e6 + 20;
const int Mod = 1e9 + 7;
const int N = 2;

int vis[maxn];
bool vib[1010];
int a[1010];
char s[1010][2];
int n,m;
bool flag;
int T = 1e6 + 10;
void dfs(int u,int pos)
{
//    cout << u << endl;
     printf("%d\n",u);
	if(flag)return;
    vis[u + T] = true;
    if(u == m){flag = true;return;}
   if(pos == n + 1)return;
	
    if(s[pos][0] == 'N')
    {
        if(!vis[u + a[pos] + T])dfs(u + a[pos],pos + 1);
        if(!vis[u - a[pos] + T])dfs(u - a[pos],pos + 1);
        dfs(u,pos + 1);
    }
    else if(s[pos][0] == 'L')
    {
		if(!vis[u + a[pos] + T ])
			dfs(u + a[pos],pos + 1);
		dfs(u,pos + 1);
	}
    else 
	{
		if(!vis[u - a[pos] + T ])
			dfs(u - a[pos],pos + 1);
		dfs(u,pos + 1);
	}
}
int main()
{
    int Tcase;scanf("%d",&Tcase);
    while(Tcase --)
    {
        flag = false;
        scanf("%d%d",&n,&m);clr(vis,false);clr(vib,false);
        memset(a,0,sizeof(a));
        for(int i = 1; i <= n; i ++)scanf("%d",&a[i]);
        int l = 0,r = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%s",s[i]);
            if(s[i][0] == 'N')l -= a[i],r += a[i];
            else if(s[i][0] == 'L')r += a[i];
            else l -= a[i];
        }
//        cout << l << " " << r <<  " " << m << endl;
        if(m > r || m < l)
        {
            puts("no");continue;
        }
        dfs(0,1);
        if(flag)puts("yes");
		else puts("no");
		for(int i =(-50+T) ;i <(50+T);i++ )
		{
			printf("%d %d\n",i-T,vis[i]);
		}
    }
    return 0;
}

/*
20


10 10
1 2 3 4 5 6 7 8 9 0
L L L L L L L L L L 

10 55
1 2 3 4 5 6 7 8 9 0
L L L L L L L L L L 

10 -45
1 2 3 4 5 6 7 8 9 0
N N N N N N N N N N 

10 -45
1 2 3 4 5 6 7 8 9 0
D D D D D D D D D D 


 

10 36
1 2 3 4 5 6 7 8 9 0
L L L L L L L L L L 



6 -3
1 0 1 2 3 1
N L L L L D

6 -2
1 0 1 2 3 1
N L L L L D

6 -1
1 0 1 2 3 1
N L L L L D


6 0
1 0 1 2 3 1
N L L L L D

6 1
1 0 1 2 3 1
N L L L L D

6 2
1 0 1 2 3 1
N L L L L D

6 3
1 0 1 2 3 1
N L L L L D

6 4
1 0 1 2 3 1
N L L L L D

6 5
1 0 1 2 3 1
N L L L L D

6 6
1 0 1 2 3 1
N L L L L D

6 7
1 0 1 2 3 1
N L L L L D


6 8
1 0 1 2 3 1
N L L L L D


*/
