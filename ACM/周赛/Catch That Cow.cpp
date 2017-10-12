#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int x;
	int step;
	int last;
};
int n,k;
int map[1000005];
int ans;
int i=0;
struct node pass[10000][10000];
int check(int xx)
{
	if(xx>k||xx<0||map[xx])
	 return 0;
	return 1;
}

int bfs(int x)
{

	queue<node> Q;
	node a,next;
	a.x=x;
	a.step=0;;
	map[x]=1;
	Q.push(a);
	while(!Q.empty())
	{
		a=Q.front();
		Q.pop();
		if(a.x==k)
		 return a.step;
		next=a; 
		next.x=a.x+1;
		 
		if(check(next.x))
		 {
		 	map[next.x]=1;
		 	pass[next.step][next.x].step=next.step=a.step+1;
		 	pass[next.step][next.x].last=a.x;
		 	pass[next.step][next.x].x=next.x;
		 	printf("步数 %d 数值%d上一步%d\n",next.step,next.x,a.x);
		 	Q.push(next);
		 }
		next.x=a.x-1;
		 
		if(check(next.x))
		 {
		 	map[next.x]=1;
		 	pass[next.step][next.x].step=next.step=a.step+1;
		 	pass[next.step][next.x].last=a.x;
		 	pass[next.step][next.x].x=next.x;
		 	printf("步数 %d 数值%d上一步%d\n",next.step,next.x,a.x);
		 	Q.push(next);
		 }
		next.x=a.x*2;
		 
		if(check(next.x))
		 {
		 	pass[next.step][next.x].step=next.step=a.step+1;
		 	pass[next.step][next.x].last=a.x;
		 	pass[next.step][next.x].x=next.x;
		 	printf("步数 %d 数值%d上一步%d\n",next.step,next.x,a.x);
		 	Q.push(next);
		 }
			
	}
	return -1;
	
}




int main()
{
	
	while(scanf("%d%d",&n,&k))
	{
		memset(map,0,sizeof(map));
		ans=bfs(n);
		printf("%d\n",ans);	

		while(ans)
		 {
		 	printf("%d\n",pass[ans][k].x);
		 	k=pass[ans][k].last;
		 	ans--;
		 }
	    printf("%d",n);

	}
}
