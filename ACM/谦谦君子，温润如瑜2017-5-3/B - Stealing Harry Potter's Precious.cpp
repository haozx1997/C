#include<bits/stdc++.h>

using namespace std;

struct node
{
	int x,y;
	int step;
};

int n,m,k;
char mi[200][200];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int vis[200][200];
int aim[10][10];
int find;
int fx,fy;
int ans;

int check(int xx,int yy)
{
	if(vis[xx][yy] == 1)
	{
		return 0;
	}
	if(mi[xx][yy] == '#')
	{
		return 0;
	}
	if(xx<1||xx>n||yy<1||yy>m)
	{
		return 0;
	}
	
	return 1;
	
}

int bfs(int sx,int sy,int ex,int ey)
{
	queue<node> q;
	while(!q.empty())
	{
		q.pop();
	}
	
	node a,next;
	a.x = sx;
	a.y = sy;
	
	a.step = 0;
	q.push(a);
	
	while(!q.empty())
	{
		a = q.front();
		vis[a.x][a.y] = 1;
		q.pop();
		if(a.x == ex&&a.y == ey)
			{
				
				return a.step;
			}
		
		
		next = a;
		for(int i = 0;i < 4;i++)
		{
			next.x=a.x+dir[i][0];
		 	next.y=a.y+dir[i][1];
		 	if(check(next.x,next.y))
		 	{
		 		vis[next.x][next.y] = 1;
		 		next.step++;
		 		q.pop();
			 }
		}
		
	}
	return -1;
}
int dis[10][10];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(mi,0,sizeof(mi));
		memset(vis,0,sizeof(vis));
		memset(aim,0,sizeof(aim));
		memset(dis,-1,sizeof(dis));
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				scanf("%c",&mi[i][j]);
				if(mi[i][j] == '@')
				{
					aim[0][0] = 1;
					aim[0][1] = i;
					aim[0][2] = j;
					
				}
			}
		}
		
		scanf("%d",&k);
		for(int i = 1;i <= k;i++)
		{
			scanf("%d%d",&aim[i][1],&aim[i][2]);
			
		}
		
		for(int i = 0;i <= k;i++)
		{
			for(int j = i+1;j <=k;j++)
			{
				dis[i][j] = bfs(aim[i][1],aim[i][2],aim[j][1],aim[j][2]);
				printf("%d %d %d\n",i,j,dis[i][j]);
			}
		}
		
	}




 return 0;
}


