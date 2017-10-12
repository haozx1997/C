#include<stdio.h>
#include<string.h>
#include<stack>
#include<stdlib.h>
using namespace std;
struct ev
{
	int x,y;
	int dir;
	int step;
	int prx,pry,prd;
};
int m[7][7]={
{1,1,1,1,1,1,1},
{1,0,1,1,1,0,1},
{1,0,1,1,1,0,1},
{1,0,0,0,0,0,1},
{1,0,1,1,1,0,1},
{1,0,1,1,1,0,1},
{1,1,1,1,1,1,1}
};
int dirc[4][2]={0,1,0,-1,1,0,-1,0};
int i;
int stp[10000][2];

stack<ev> s;
ev a,next;

void lal();
int dfs()
{
	if(s.empty()) 
	 return 0; 
	a=s.top();
	stp[a.step][0] = a.x;
	stp[a.step][1] = a.y;
	
	printf("dfs  坐标%d  %d 步数%d方向%d\n",a.x,a.y,a.step,a.dir);
	if(a.x==5&&a.y==5)
	  {
	  	i = a.step;
	  	lal();printf("asd\n");
	  	return 0;
	  }
		if(s.empty()) 
	 		return 0; 
	next=a;
	m[a.x][a.y]=1;
	while(a.dir!=4)
	 {
	 	next.x=a.x+dirc[a.dir][0];
	 	next.y=a.y+dirc[a.dir++][1];
	 	next.step=a.step+1;
	 	next.dir=0;
	 		if(s.empty()) 
	 			return 0; 
	 	if(!m[next.x][next.y])
	 	 {
	 	 	s.push(next);dfs();	
			  if(s.empty()) 
	 			return 0; 
		  }
	 }
	
	
	 	s.pop();dfs();
		if(s.empty()) 
			 return 0; 
	return 0;
}


void lal()
{
	
	while(!s.empty())
	{
//		a=s.top();
//		printf("lalal 坐标%d  %d 步数%d方向%d\n",a.x,a.y,a.step,a.dir);
		s.pop();
	}
//	exit(0);

	return ;
	
}


int main()
{
	a.x=1;
	a.y=1;
	a.step=0;
	a.dir=0;
	a.prx = -1;
	a.pry = -1;
	a.prd = -1;
	
	m[1][1]=1;
	s.push(a);
	printf("%d",a.step);
	dfs();
	printf("\n####\n%d\n",i);
	for(int j = 0;j < i;j++)
	{
		printf("%d %d\n",stp[j][0],stp[j][1]);
	}
}




