#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

struct one
{
	long long num;
	long long step;
};

long long x,k,t;
long long vis[1000111];
long long bfs()
{
	queue<one> q;
	while(!q.empty())
	{
		q.pop();
	}
	one now,next;
	now.num = 1;
	now.step = 0;
	vis[now.num] = 1;
	q.push(now);
	while(!q.empty())
	{
		now = q.front();
		if(now.num == x)
		{
			return now.step;
		}
		q.pop();
		for(long long i = 1;i <= t;i++)
		{
			next.num = now.num + i;
			next.step = now.step + 1;
			if(next.num<=x)
			{
				if(vis[next.num] == 0)
				{
					if(next.num == x)
					{
						return next.step;
					}
					q.push(next);
					vis[next.num] = 1;
				}
			}
		}
		next.num = now.num * k;
		next.step = now.step + 1;
		if(next.num<=x)
		{
			if(vis[next.num] == 0)
			{
				if(next.num == x)
				{
					return next.step;
				}
				q.push(next);
				vis[next.num] = 1;
			}
		}
	}
}
int main()
{
	long long T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d",&x,&k,&t);
		memset(vis,0,sizeof(vis));

		printf("%I64d\n",bfs());
	}
}
