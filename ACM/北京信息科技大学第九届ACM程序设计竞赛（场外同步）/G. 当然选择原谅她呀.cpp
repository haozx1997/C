#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	int step;
};
int n,mm;


int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m[100][100];
int check(int xx,int yy)
{
	if(m[xx][yy])
	 return 0;
	if(xx<0||xx>=n||yy<0||yy>=mm)
	{
		return 0;
	 } 
	return 1;
}

int bfs()
{
	queue<node> q;
	node a,next,last;
	while(!q.empty())
	{
		q.pop();
	}
	a.x=0;
	a.y=0;
	a.step=0;
	m[0][0]=1;
	q.push(a);
	while(!q.empty())
	 {
	 	
	 	a=q.front();
	 //	printf("aa%d   %d\n",a.x,a.y);
	 	q.pop();
	 	if(a.x==(n-1)&&a.y==(mm-1))
	 	 return a.step;
	 	
		for(int i=0;i<4;i++)
		 {	next=a;
		 	next.x=a.x+dir[i][0];
		 	next.y=a.y+dir[i][1];
		 	if(check(next.x,next.y)) 
		 	  {
		 	  	m[next.x][next.y]=1;
		 	  	next.step=a.step+1;
		 	  	q.push(next);
			   }
		  } 
	 }
	  return -1;
	

}




int main()
{
	
	while(~scanf("%d%d",&n,&mm))
	{
		memset(m,0,sizeof(m));
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j<mm;j++)
			{
				scanf("%d",&m[i][j]);
			}
		}
		int ans=bfs();
		printf("%d\n",ans);
	}		
	

}
