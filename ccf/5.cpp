#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct ming
{
	int step;
	int x,y;
};
int n,m,t;
int r[10010],c[10010],a[10010],b[10010];
int map[200][200];

int bfs()
{
	struct ming a,next;
	queue<ming> q;
	a.x=0;
	a.y=0;
	q.push(a);
	map[0][0]=1;
	while(!q.empty())
	{
		a=q.front();
		if(a.x==n&&a.y==m)
		return a.step;
		q.pop();
		next=a;
		next.x=a.x;next.y=a.y+1;
		if(map[next.x][next.y]!=1)
		 {
		 	next.step=a.step+1;
		 	map[next.x][next.y]=1;
		 	q.push(next);
		 }
		
		next.x=a.x+1;next.y=a.y;
		if(map[next.x][next.y]!=1)
		 {
		 	next.step=a.step+1;
		 	map[next.x][next.y]=1;
		 	q.push(next);
		 }		
		next.x=a.x-1;next.y=a.y;
		if(map[next.x][next.y]!=1)
		 {
		 	next.step=a.step+1;
		 	map[next.x][next.y]=1;
		 	q.push(next);
		 }		
		
		next.x=a.x;next.y=a.y-1;
		if(map[next.x][next.y]!=1)
		 {
		 	next.step=a.step+1;
		 	map[next.x][next.y]=1;
		 	q.push(next);
		 }		
	}
	
	
}
int main()
{
	
	memset(map,0,sizeof(map));
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<=n+1;i++)
	  map[i][0]=map[i][m+1]=1;
	for(int i=0;i<=m+1;i++)
	   map[0][i]=map[n+1][i]=1;
	for(int i;i<t;i++)
	{
		scanf("%d%d%d%d",&r[i],&c[i],&a[i],&b[i]);
		map[r[i],c[i]]=1;
		
	}
	
	int ans;
	ans=bfs();
	printf("%d\n",ans);
}
