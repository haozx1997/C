#include<stdio.h>//上下电梯 输入5 1 53 3 1 2 5 0 
#include<string.h>
#include<queue>
using namespace std;


int st,endd,all;
struct lift
{
	int num;
	int step;
} ;
int np[205];
bool map[205];
int bfs()
{
	lift a,next;
	queue<lift> q;
	a.num=st;
	a.step=0;
	q.push(a);
	map[st]=1;
	while(!q.empty())
	{
		a=q.front();
		if(a.num==endd)
		 return a.step;
		q.pop() ;
		next=a;
		next.num=a.num+np[a.num];
		if(!map[next.num]&&next.num>0&&next.num<=all)
		 {
		 	next.step=a.step+1;
		 	map[next.num]=1;
		 	q.push(next);
		 }
		
		next.num=a.num-np[a.num];
		if(!map[next.num]&&next.num>0&&next.num<=all)
		 {
		 	next.step=a.step+1;
		 	map[next.num]=1;
		 	q.push(next);
		 }
		 		 
		
	}
	
	return -1;
}

int main()
{
	
	while(scanf("%d",&all),all)
	{
		int i;
		memset(map,0,sizeof(map));

		scanf("%d%d",&st,&endd);
		for(i=1;i<=all;i++)
		{
			scanf("%d",&np[i]); 
		}
		
		printf("%d\n",bfs());
	}
}






