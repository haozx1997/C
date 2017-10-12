#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct note
{
	int step;
	int x,y;
};
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int yk[202][202];
int mk[202][202];
char map [202][202];
int i,j;
int yi,yj,mi,mj;


int bfs1()
{
	
	queue<note> Q;
	while(!Q.empty()) Q.pop() ;
	note a,next;
	a.x=yi;
	a.y=yj;
	a.step=0;
	
	map[a.x][a.y]='#';
	Q.push(a);
	while(!Q.empty())
	{
		a=Q.front();
		Q.pop();
		
		next=a;
		for(i=0;i<4;i++)
		 {
		 	next.x=a.x+dir[i][0];
		 	next.y=a.y+dir[i][1];
		 	if(map[next.x][next.y]=='@')
		     {
		     	yk[next.x][next.y]=a.step+1;
		     	map[next.x][next.y]='0';
		     	if(map[next.x][next.y]!='#'&&map[next.x][next.y]!='1')
            {
            next.step=a.step+1;
		 	Q.push(next);
			}
		     	
			 }
		 	else if(map[next.x][next.y]!='#'&&map[next.x][next.y]!='1'&&map[next.x][next.y]!='0')
            {
            next.step=a.step+1;
            map[next.x][next.y]='1';
		 	Q.push(next);
			}
		 }
	}
}


int bfs2()
{
	queue<note> p;
	while(!p.empty()) p.pop() ;
	note aa,bbb;
	aa.x=mi;
	aa.y=mj;
	aa.step=0;
	map[aa.x][aa.y]='2';
	p.push(aa);
	while(!p.empty())
	{
		aa=p.front();
	
		p.pop();
		
		bbb=aa;
		for(i=0;i<4;i++)
		 {
		 	bbb.x=aa.x+dir[i][0];
		 	bbb.y=aa.y+dir[i][1];
		 	if(map[bbb.x][bbb.y]=='0')
		     {
		     	mk[bbb.x][bbb.y]=aa.step+1;
			 }
		 	if(map[bbb.x][bbb.y]!='#'&&map[bbb.x][bbb.y]!='2')
		 	{
			 map[bbb.x][bbb.y]='2';
			 bbb.step=aa.step+1;
		 	 p.push(bbb);
			 }
		 	
		 }
		 
	}
	
	
	
}
int main()
{
	int m,n,yt;
	char ch;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		 for(j=1;j<=m;j++)
		  {
		  	if(((ch=getchar())!='\n'))
		  	map[i][j]=ch;
		  	else map[i][j]=getchar();
		  	if(map[i][j]=='Y')
		  	{ yi=i;yj=j;}
			  if(map[i][j]=='M')
		  	{ mi=i;mj=j;}
		  }
		  for(i=0;i<=n+1;i++)
		   map[i][0]=map[i][5]='#';
		  for(j=0;j<=m+1;j++)
		   map[0][j]=map[5][j]='#';	
				
		bfs1();
			
		bfs2();
		int sum =1000;
		for(i=0;i<=n;i++)
		   
		  for(j=0;j<=m;j++)
		  if(yk[i][j]!=0)
		  if(sum>yk[i][j]+mk[i][j])sum=yk[i][j]+mk[i][j];
		 printf("%d\n",sum*11); 
		   		
			   
		   
		   
		   
		   
		   
		   	   

		
	}
}
