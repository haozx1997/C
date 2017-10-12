#include<bits/stdc++.h>

using namespace std;


struct node
{
	
	int v;
	int out;
	
}w[200][200];
int d[5][2]={{0,1},{1,0},{0,-1},{-1,0}}; 

struct nodee
{
	int x,y;
	int dir;
	int step;
	
}p[500500];

int r,c,n,t;
int ans[500][5];
int ox,oy;
int check(int x,int y)
{
	if(x<=r&&x>=1&&y<=c&&y>=1)
	{
		return 1;
	}
	return 0;
}
void see()
{
	for(int i = 1;i <= r;i++)
	{
		for(int j = 1;j <= c;j++)
		{
			printf("%d ",w[i][j].v);
		}
		printf("\n");
		
	}
	printf("\n");
}

void bfs()
{
	queue<nodee> q;
	nodee a,next;
	while(!q.empty())
	{
		q.pop();
	}
	for(int i = 0;i < 4;i++)
	{
		if(check(ox+d[i][0],oy+d[i][1]))
		{
			a.x = ox+d[i][0];
			a.y = oy+d[i][1];
			a.dir = i;
			a.step = 1;
			q.push(a);
		}
	}
	
	while(!q.empty())
	{
//		printf("%d %d %d %d\n",a.step,a.dir,a.x,a.y);
//		see();
		a = q.front();
		q.pop();
		int xx = a.x,yy = a.y,tt = a.step;
		if(w[a.x][a.y].v)
		{
			w[a.x][a.y].v++;
			if(w[a.x][a.y].v>4)
			{
				w[a.x][a.y].v = 0;
				w[a.x][a.y].out = a.step;
				for(int i = 0;i < 4;i++)
				{
					if(check(xx+d[i][0],yy+d[i][1])&&(tt+1)<=t)
					{
						next.x = xx+d[i][0];
						next.y = yy+d[i][1];
						next.dir = i;
						next.step = tt+1;
						q.push(next);
					}
				}
			}
		}
		else if(w[xx][yy].out!=tt)
		{
			
			if(check(xx+d[a.dir][0],yy+d[a.dir][1])&&(tt+1)<=t)
			{
				next.x = xx+d[a.dir][0];
				next.y = yy+d[a.dir][1];
				next.dir = a.dir;
				next.step = tt+1;
				q.push(next);
			}
		}
		

	}
	
}



int main()
{

	
	while(~scanf("%d%d%d%d",&r,&c,&n,&t))
	{
		memset(w,0,sizeof(w));
		memset(ans,0,sizeof(ans));
		
		int x,y,vv;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&x,&y,&vv);
			w[x][y].v = vv;
			ans[i][0] = x;
			ans[i][1] = y;
			
			
		}
		
		scanf("%d%d",&ox,&oy);
		bfs();
		for(int i = 1;i <= n;i++)
		{
			x = ans[i][0];
			y = ans[i][1];
			if(w[x][y].out == 0)
			{
				printf("1 %d\n",w[x][y].v);
			}
			else
			{
				printf("0 %d\n",w[x][y].out);
			}
			
			
		}
		
	}



 return 0;
}


