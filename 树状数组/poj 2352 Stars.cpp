#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define N 32100
using namespace std;

int c[N];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int val)
{
	while(x<=32100)
	{
		c[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int level[N];
int main()
{
	while(~scanf("%d",&n))
	{
        memset(c, 0, sizeof(c));  
        memset(level, 0, sizeof(level)); 		
		int x,y;
		for(int i = 0; i < n ;i++)
		{
			scanf("%d%d",&x,&y);
			level[getsum(x+1)]++;
			update(x+1,1);
		}
		for(int i = 0; i < n ;i++)
		{
			printf("%d\n",level[i]);
		}
		
	}
}
