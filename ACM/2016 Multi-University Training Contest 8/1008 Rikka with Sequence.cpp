#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

///////////////////记得按 for(int i = 1;i <= 10;i++)
///////////////////不要按 for(int i = 0;i < 10;i++)
///////////////////    ALL 

//一维 
int c[100050];
int num[100050];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int val)//是加val的值 不是更新成val的值！！！ 
{
	while(x<=n)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}

void update_(int l,int r,int val)
{
	for(int i = r;i>0;i-=lowbit(i))
	{
		c[i] += val;
	}
	for(int i = l-1;i>0;i-=lowbit(i))
	{
		c[i] -= val;
	}
	
}
int getsum(int x)
{
	int ans=0;
	if(x == 0) 
	 return 0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(num,0,sizeof(num));
		
		int m;
		scanf("%d%d",&n,&m);
		int v;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&v);
			update(i,v);
			num[i] = v;
		}
		while(m--)
		{
			int ch;
			int l,r,x;
			int xx;
			int sum2;
			scanf("%d",&ch);
			switch(ch)
			{
				case 1 :
					scanf("%d%d%d",&l,&r,&x);
					update_(l,r,x);
					 break;
				case 2 :
					scanf("%d%d",&l,&r);
					
					for(int i = l;i<=r;i++)
					{
						xx = floor(sqrt(num[i]));
						update(i,(xx-num[i]));
						num[i] = xx;
					}
					 break;
				case 3 :
					scanf("%d%d",&l,&r);
					sum2 = getsum(r) - getsum(l-1);
					printf("%d\n",sum2);
					 break;
					 
			}
		}
	}
	return 0;
 } 
 
 
 
