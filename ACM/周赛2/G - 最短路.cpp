#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int sho;
int i,abc[101][101];
int n,m;
int a,b;

struct node
{
	int x;
	int time;
};


void bfs()
{
	queue<node> Q;
	while(!Q.empty())
	 Q.pop();
	node one,next;
	one.time=0;
	one.x=1;
	Q.push(one);
	while(!Q.empty())
	{
		one=Q.front();
		if(one.x==n)
		 if(sho>one.time) 
		  sho=one.time;
		Q.pop();
		
		
		for(i=1;(one.x)+i<=n;i++)
		 {
		 	next=one;
		 	if(abc[one.x][(one.x)+i])
		 	 {
		 	 	next.x=one.x+i;
		 	 	next.time+=abc[one.x][(one.x)+i];
		 	 	Q.push(next);
			  }
		 	 
		 }
		 
	}
}

int main()
{
	
	while(scanf("%d%d",&n,&m),n)
	{
		sho=10000000;
		for(i=0;i<m;i++)
		 {  
		 	scanf("%d%d",&a,&b);
		    scanf("%d",&abc[a][b]);
		    if(a>b) abc[b][a]=abc[a][b];
		    
		    
		 }
		bfs();
		printf("%d\n",sho); 
	}
}
