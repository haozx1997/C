#include<bits/stdc++.h>

using namespace std;

char m[100][100];
int n;
struct node
{
	int x,y;
	int step;
};
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int vis[100][100];
int check(int xx,int yy)
{
	if(xx <= 0||yy <= 0||xx > n||yy > n)
		return 0;
	if(vis[xx][yy] == -1)
	{
		return -1;
		}
	if(vis[xx][yy] != -1)
	{
		return 1;
		}
			
	return 1;
}


int bfs()
{
	queue<node>q1;
	queue<node>q2;
	while(!q1.empty())
	{
		q1.pop();
	}
	while(!q2.empty())
	{
		q2.pop();
	}
	memset(vis,0,sizeof(vis));
	node a,next,last;
	a.x=1;
	a.y=1;
	a.step=0;
	vis[1][1] = 1;
	q1.push(a);
	while(1)
	{
		while(!q1.empty())
		{
			a=q1.front();
	//		printf("%d %d %d\n",a.x,a.y,a.step);
			q1.pop();
			if(a.x == n&&a.y == n)
			{
				return a.step;
			}
			
			for(int i=0;i<4;i++)
			{
				next=a;
			 	next.x=a.x+dir[i][0];
			 	next.y=a.y+dir[i][1];
			 	if(check(next.x,next.y) == -1) 
			 	{
			 	  	vis[next.x][next.y]=1;
			 	  	if(m[a.x][a.y] == '*'&&m[next.x][next.y] == '*')
			 	  	{
			 	  		q1.push(next);
					}
					else if(m[a.x][a.y] == '*'&&m[next.x][next.y] == '#')
			 	  	{
			 	  		next.step = a.step+1;
			 	  		q2.push(next);
					}else if(m[a.x][a.y] == '#')
					{
						next.step = a.step+1;
			 	  		q2.push(next);
					}
				}
				
			} 
		}
	//	printf("em\n");
		q1 = q2;
		while(!q2.empty())
		{
			q2.pop();
		}
	}
	
}

int main()
{
	
	while(~scanf("%d",&n))
	{
		for(int i = 1;i <= n;i++)
		{
			scanf("%s",&m[i][1]);
		}
//		for(int i = 0 ;i <= n;i++)
//		{
//			for(int j = 0; j <= n;j++)
//			{
//				printf("%c",m[i][j]);
//			}
//			printf("\n");
//		}
		
		
		printf("%d\n",bfs());
	}




 return 0;
}


