#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	int step;
};
int n,k;

int i;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m[7][7]={
{1,1,1,1,1,1,1},
{1,0,1,1,1,1,1},
{1,0,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,1,1,1,0,1},
{1,0,1,1,1,0,1},
{1,1,1,1,1,1,1}
};
int check(int xx,int yy)
{
	if(m[xx][yy])
	 return 0;
	return 1;
}

int bfs()
{
	queue<node> q;
	node a,next,last;
	a.x=1;
	a.y=1;
	a.step=0;
	m[1][1]=1;
	q.push(a);
	while(!q.empty())
	 {
	 	
	 	a=q.front();
	 	printf("aa%d   %d\n",a.x,a.y);
	 	q.pop();
	 	if(a.x==5&&a.y==5)
	 	 return a.step;
	 	
		for(i=0;i<4;i++)
		 {next=a;
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
	  return -2;
	

}




int main()
{
	
	int j;
	for(i=0;i<7;i++)
	  {
	  	for(j=0;j<7;j++)
	  	  printf("%d",m[i][j]);
	  	  printf("\n");
	  }
	
		
	    i=bfs();
	printf("%d",i);

}
