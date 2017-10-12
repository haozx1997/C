#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x,y;
};
int n,k;

int i;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m[7][7];
int check(int xx,int yy)
{
	if(m[xx][yy])
	 return 0;
	return 1;
}
node last[5][5];

int bfs()
{
	queue<node> q;
	node a,next;
	a.x=1;
	a.y=1;

	m[1][1]=1;
	q.push(a);
	while(!q.empty())
	 {
	 	
	 	a=q.front();

	 	q.pop();
	 	if(a.x==5&&a.y==5)
	 	 return 1;
	 	next=a;
		for(i=0;i<4;i++)
		 {
		 	next.x=a.x+dir[i][0];
		 	next.y=a.y+dir[i][1];
		 	if(check(next.x,next.y)) 
		 	  {
		 	  	m[next.x][next.y]=1;
		 	  	last[next.x][next.y]=a;
		 	  	q.push(next);
		 	  	
			   }
		  } 
	 }
	  return -2;
	

}




int main()
{
	
	
	int pass[25][2];
	int j,p=0;
	for(i=1;i<6;i++)
	 for(j=1;j<6;j++)
	  {
	  	scanf("%d",&m[i][j]);
	  }
	memset(m[0],1,7);
	memset(m[6],1,7);
	for(i=0;i<6;i++)
	 m[i][0]=m[i][6]=1;	  

	  
    bfs();
	i=j=5;
    int m,n;

	while(last[i][j].x!=1||last[i][j].y!=1)
	{
		pass[p][0]=last[i][j].x;
		pass[p][1]=last[i][j].y;

		m=i;n=j;
		p++;
		i=last[m][n].x;
		j=last[m][n].y;
	}
	printf("(0, 0)\n");
	while(p--)
	{
		printf("(%d, %d)\n",--pass[p][0],--pass[p][1]);
	}
	printf("(4, 4)\n");	

}
