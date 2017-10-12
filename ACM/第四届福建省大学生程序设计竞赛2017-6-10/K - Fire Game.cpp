#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

struct node
{
	int x,y,step;
};
int maz[111];
int mazn;
char s[500][500];
int vis[500][500];

int n,m;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int check(int x,int y)
{
	if(x>=n||x<0||y<0||y>=m)
	{
		return 0;
	}
	if(s[x][y] == '.')
	{
		return 0;
	}
	if(vis[x][y])
	{
		return 0;
	}
	return 1;
}


int bfs(int x,int y)
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	while(!q.empty())
	{
		q.pop();
	}
	node a,next;
	if(!check(x,y))
	{
		return 0;
	}
	char c;
	if(s[x][y] == '#')
	{
		c = '0' + mazn;
		mazn++;
	}
	else
	{
		c = s[x][y];
	}
	a.x = x;
	a.y = y;
	a.step = 0;
	vis[x][y] = 1;
	q.push(a);
	int maxs = 0;
	while(!q.empty())
	{
		a = q.front();
		q.pop();
	//	printf("%d %d %d\n",a.x,a.y,a.step);
		maxs = max(maxs,a.step);
		
		for(int i = 0;i < 4;i++)
		{
			next = a ;
			next.x = a.x+dir[i][0];
			next.y = a.y+dir[i][1];
			if(check(next.x,next.y))
			{
				next.step = a.step+1;
				s[next.x][next.y] = c;
				vis[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
//	printf("%d max%d\n",c-'0',maxs);
	maz[c-'0'] = min(maz[c-'0'],maxs);
}
int bfs2(int x1,int y1,int x2,int y2)
{
	if(s[x1][y1]!='0'||s[x2][y2]!='0')
	{
		return 100100;
	}
//	printf("%d %d %d %d\n",x1,y1,x2,y2);
//	puts("WTF");
	memset(vis,0,sizeof(vis));
	queue<node> q1;
	while(!q1.empty())
	{
		q1.pop();
	}
	queue<node> q2;
	while(!q2.empty())
	{
		q2.pop();
	}
	
	node a1,next1,a2,next2;
	
	char c = '0';
	a1.x = x1;
	a1.y = y1;
	a1.step = 0;
	vis[x1][y1] = 1;
	a2.x = x2;
	a2.y = y2;
	a2.step = 0;
	vis[x2][y2] = 1;
	
	q1.push(a1);
	q2.push(a2);
	
	int maxs = 0;
	while((!q1.empty())||(!q2.empty()))
	{
		if(!q1.empty())
		{
			a1 = q1.front();
			q1.pop();
//			printf("111  %d %d %d\n",a1.x,a1.y,a1.step);
			maxs = max(maxs,a1.step);
			for(int i = 0;i < 4;i++)
			{
				next1 = a1 ;
				next1.x = a1.x+dir[i][0];
				next1.y = a1.y+dir[i][1];
				if(check(next1.x,next1.y))
				{
					next1.step = a1.step+1;
					s[next1.x][next1.y] = c;
					vis[next1.x][next1.y] = 1;
					q1.push(next1);
				}
			}
		}
		if(!q2.empty())
		{
			a2 = q2.front();
			q2.pop();
//			printf("222  %d %d %d\n",a2.x,a2.y,a2.step);
			maxs = max(maxs,a2.step);
			for(int i = 0;i < 4;i++)
			{
				next2 = a2 ;
				next2.x = a2.x+dir[i][0];
				next2.y = a2.y+dir[i][1];
				if(check(next2.x,next2.y))
				{
					next2.step = a2.step+1;
					s[next2.x][next2.y] = c;
					vis[next2.x][next2.y] = 1;
					q2.push(next2);
				}
			}
		}
		
	}
//	printf("%d max%d\n",c-'0',maxs);
	return maxs;
}

int main()
{	
	int T;
	scanf("%d",&T);
	for(int II = 0;II < T;II++)
	{
		memset(vis,0,sizeof(vis));
		
		for(int i = 0;i < 10;i++)
		{
			maz[i] = 1001000;
		}
		mazn = 0;
		scanf("%d%d",&n,&m);
		int o = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s[i]);
			
		}
		int FF = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				bfs(i,j);
				if(mazn>2)
				{
					FF = 1;
					break;
				}
			}
			if(FF)
			{
				break;
			}
		}
		int ans = 0;
//	printf("mazn %d\n",mazn);
		for(int i = 0;i < mazn;i++)
		{
//	printf("%d %d\n",i,maz[i]);
			ans = max(ans,maz[i]);
		}
		if(mazn == 1)
		{
//			for(int i = 0;i < n;i++)
//			{
//				printf("%s\n",s[i]);
//			}
			ans = 100100;
			int xx[500],yy[500];
			int ten = 0;
			for(int i = 0;i < n;i++)
			{
				for(int j = 0;j < m;j++)
				{
					
					if(s[i][j] == '0')
					{
						xx[ten] = i;
						yy[ten++] = j;
					}
				}
			}
			int x1,x2,y1,y2;
			for(int i = 0;i < ten;i++)
			{
				for(int j = i+1;j < ten;j++)
				{
					ans = min(bfs2(xx[i],yy[i],xx[j],yy[j]),ans);
				}
			}
			
			
			
		}

		
		if(FF||mazn == 0)
		{
			printf("Case %d: -1\n",II+1);
		}
		else
		{
			printf("Case %d: %d\n",II+1,ans);
		}
		
	}





 return 0;
}



