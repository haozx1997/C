#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct nope
{
	int x,step;
}a,next;

int map[9999999];
int n,k;

int bfs()
{
	queue<nope> q;
	a.step = 0;
	a.x = n;
	while(!q.empty())
	{
		q.pop();
	}
	q.push(a);
	map[n] = 1;
	while(!q.empty())
	{
		a = q.front();
//		printf("%d\n",a.x);
		q.pop();
		
		{
			next = a;
			next.step++;
			next.x++;
			if(next.x == k)
			{
				return next.step;
			}
			if(map[next.x] == 0&&next.x>=0&&next.x<k*3)
			{
				map[next.x] = 1;
				q.push(next);
			}
		}
		
		{
			next = a;
			next.step++;
			next.x--;
			if(next.x == k)
			{
				return next.step;
			}
			if(map[next.x] == 0&&next.x>=0&&next.x<k*3)
			{
				map[next.x] = 1;
				q.push(next);
			}
		}
		
		{
			next = a;
			next.step++;
			next.x *= 2;
			if(next.x == k)
			{
				return next.step;
			}
			if(map[next.x] == 0&&next.x>0&&next.x<k*3)
			{
				map[next.x] = 1;
				q.push(next);
			}
		}
	}
	
}



int main()
{
	memset(map,0,sizeof(map));
	while(~scanf("%d%d",&n,&k))
	{
		memset(map,0,sizeof(map));
		if(n == k)
		{
			printf("0\n");
			continue;
		}
		
		if(n > k)
		{
			printf("%d\n",n-k);
			continue;
		}
		
		printf("%d\n",bfs());
	}
}
