#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;


int st1,st2,end1,end2;
struct chess
{
	int x,y;
	int step;
} ;

bool map[15][15];
int bfs()
{
	chess a,next;
	queue<chess> Q;
	a.x=st1;
	a.y=st2;
	a.step=0;
	Q.push(a);
	map[st1][st2]=1;
	while(!Q.empty())
	{
		a=Q.front();
		
		if(a.x==end1&&a.y==end2)
		 return a.step;
		Q.pop();
		next=a;
		next.x=a.x+1; next.y=a.y+2;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		
		next.x=a.x+2; next.y=a.y+1;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x+2; next.y=a.y-1;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x+1; next.y=a.y-2;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x-1; next.y=a.y-2;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x-2; next.y=a.y-1;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x-2; next.y=a.y+1;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		next.x=a.x-1; next.y=a.y+2;
		if(next.x>0&&next.x<10&&next.y>0&&next.y<11)
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
			Q.push(next); 
		}
		
		
	}
	

}

int main()
{
	while(scanf("%d%d%d%d",&st1,&st2,&end2,&end1)!=EOF)
  		{
  			

		int i;
		memset(map,0,sizeof(map));
		for(int i=0;i<11;i++)
		 map[i][0]=map[i][11]=1;
		for(int i=0;i<12;i++)
		 map[0][i]=map[10][i]=1; 
		 

		
		 st1++;st2++;end1++;end2++;
		
		printf("%d\n",bfs());
	
		  }
}






