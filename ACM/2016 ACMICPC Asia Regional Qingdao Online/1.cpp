#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;

int is2357(int num)
{
		while(!(num%2))
		{
			num /= 2;
		}
		while(!(num%3))
		{
			num /= 3;
		}
		while(!(num%5))
		{
			num /= 5;
		}
		while(!(num%7))
		{
			num /= 7;
		}	
		if(num == 1)
		return 1;
		return 0;
}

int pow(int x,int n)
{
	if(x == 0) return 0;
    if(n==0) return 1;
    else
    {
        while((n&1)==0)
        {
            n>>=1;
            x*=x;
        }
    }
    int result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
    if((n&1)!=0)
        result*=x;
    n>>=1;
    }
    return result;
}
 
long long a[100000];
int n2357[4] = {2,3,5,7};
int vis[35][20][15][13];
int nn[4];
int n = 0;
struct n2
{
	int v;
	int vv[4];
	
	
};
void bfs()
{
	queue<n2> q;
	n2 a1;
	a1.v = 1;
	a1.vv[0] = 0;
	a1.vv[1] = 0;
	a1.vv[2] = 0;
	a1.vv[3] = 0;
	
	q.push(a1);
	
	int num = 0;
	
	while(!q.empty())
	{
		n2 now = q.front();
		q.pop();
		puts("123\n");
		for(int i = 0;i < 4; i++)
		{
			now.v*=n2357[i];
			if(now.v<=1000000000)
			{
				now.vv[i]++;
				if(vis[now.vv[0]][now.vv[1]][now.vv[2]][now.vv[3]]==0)
				{
					vis[now.vv[0]][now.vv[1]][now.vv[2]][now.vv[3]]=1;
					q.push(now);
					a[n++] = now.v;
				}
			}
		}
	}
}
int main()
{
	memset(a,0,sizeof(a));
	n = 1;
	a[0] = 1;
	
	bfs();
	sort(a,a+n);
	for(int i = 0;i< n;i++)
	{
		printf("%d\n",a[i]);
	}
	
}
