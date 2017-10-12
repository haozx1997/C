#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int n;
int ans;
struct guojie
{
	int last;
	int step;
} ;
bool map[1000][1000];
void bfs()
{
	printf("!!\n");
	guojie a,next;
	queue<guojie> q;
	a.x=0;
	a.y=0;
	a.step=0;
	q.push(a);
	map[a.x][a.y]=1;
	while(!q.empty())
	{
		a=q.front();
		if(a.step>n)
		 return ;
		q.pop();
		next=a;
		next.x=a.x+1;next.y=a.y;
		if(next.step==n)
			 ans++;	
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;

			q.push(next);
		 
		 }
		next.x=a.x;next.y=a.y+1;
		if(next.step==n)
			 ans++;	
		if(!map[next.x][next.y])
		{
			next.step=a.step+1;
			map[next.x][next.y]=1;
		
			q.push(next);
		 
		 }
	 		  
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d",&n);
		ans=0;
		
		
		printf("!!\n");           
		bfs();
		ans+=a
		printf("%d\ns-1;
	}
}






