#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	int step;
};

int n,mm,x,y,k;
int i;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m[10][10];
int check(int xx,int yy)
{
	if(m[xx][yy]||xx<1||xx>n||yy<0||yy>mm)
	 return 0;
	return 1;
}
node last[100][100];


int bfs()
{
	queue<node> q;
	node a,next;
	a.x=1;
	a.y=1;
	a.step = 0;
	m[1][1]=1;
	q.push(a);
	while(!q.empty())
	 {
	 	
	 	a=q.front();

	 	q.pop();
	 	if(a.x==x&&a.y==y&&a.step == k)
	 	 return 1;
	 	next=a;
		for(i=0;i<4;i++)
		 {
		 	next.x=a.x+dir[i][0];
		 	next.y=a.y+dir[i][1];
		 	if(check(next.x,next.y)) 
		 	  {
		 	  	
		 	  	last[next.x][next.y]=a;
		 	  	next.step = a.step+1;
		 	  	q.push(next);
		 	  	
			   }
		  } 
	 }
	  return -2;
	

}
int pass[25][2];
char out[10][10];
int main()
{
	while(~scanf("%d%d%d%d%d",&n,&mm,&x,&y,&k))
	{
		memset(m,0,sizeof(m));
		bfs();
		last[1][1].x = -1;
		last[1][1].y = -1;
		for(int i =  1;i<=n;i++)
		{
			for(int j = 1;j <=mm;j++ )
			{
				out[i][j] = '*';
			}
		}
		out[1][1] = '.';
		out[x][y] = '.';
		int i,j;
		i = x;j = y;
		while(i != -1)
		{
			printf("%d %d\n",last[i][j].x,last[i][j].y);
			out[i][j] = '.';
			int ii = last[i][j].x;
			int jj = last[i][j].y;
			i = ii;j = jj;
		}
		for(int i =  1;i<=n;i++)
		{
			for(int j = 1;j <=mm;j++ )
			{
				printf("%c",out[i][j]);
			}
			printf("\n");
		}
		
		
	}



 return 0;
}



