#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct bula
{
	int x,y;
	int step;
	int _;
}
int n,m,t;
int ax,ay,bx,by;
char map[500][500];
int vis[500][500];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int check(int xx,int yy)
{
	if((vis[xx][yy] == 0)&&((map[xx][yy] == '*')||(map[xx][yy] == '#'&&`)))
	 return 0;
	return 1;
}

int bfs()
{
	queue<bula> q;
	bula a,next;
	a.x = ax;
	a.y = ay;
	a.step = 0;
	a._ = t;
	q.push(a);
	vis[a.x][a.y] = 1;
	while(!q.empty())
	{
		
	}
}



int main()
{

	memset(vis,0,sizeof(vis));
	scanf("%d%d%d",&n,&m,&t);
	for(int i = 0;i < n;i++)
	{
		scanf("%s",map[i]);
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(map[i][j] == '@')
			{
				ax = i;ay = j;
			}
			if(map[i][j] == '+')
			{
				bx = i;by = j;
			}
			
		}
	}
	
	printf("%d\n",bfs());
	for(int i = 0;i< n;i++)
	printf("%s\n",map[i]);
	printf("%d %d \n%d %d \n",ax,ay,bx,by);
}
