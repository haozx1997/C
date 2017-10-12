#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 100010

int c[N];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int val)
{
//	printf(" v               %d %d\n",x,val);
	while(x <= n)
	{
		c[x] += val;
		x += lowbit(x); 
	}
}
int sum(int x)
{
	int ans = 0;
	while( x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int isz(int x)
{
	if(x == 0 || x == 1 )
	 return 0;
	for(int i = 2;i*i <= x;i++)
		if(!(x%i)) 
		 return 0;
	return 1;
}


int main()
{
	int chn,b;
	int Case = 1;
	while(~scanf("%d%d%d",&n,&chn,&b))
	{
		
		if(!(n||chn||b))
		 return 0;
	//	if(Case!=1)
	//	 printf("\n"); 
		memset(c,0,sizeof(c)); 
		
		int sto[N];
		int f = 0;
		if(isz(b))
		 f = 1;
		for(int i = 1;i <= n;i++)
		{
			sto[i] = b;
			if(f)
			 {
			 	update(i,1);
			 }
		}
		printf("CASE #%d:\n",Case++);
		while(chn--)
		{
			int ch,sn,sell;
			scanf("%d%d%d",&ch,&sn,&sell);
			if(ch == 0)
			{
				int pre = sto[sn];
				sto[sn] += sell;
				int now = sto[sn];
				if((isz(pre) == 1)&&(isz(now) == 0))
				 {
				 	update(sn,-1);
		//		 	printf("%d  -1\n",now);
				 }
				else if((isz(pre) == 0)&&(isz(now) == 1))
				 {
				 	update(sn,1);
	//			 	printf("%d  1\n",now);
				 } 
			}
			else
			{
		//		printf("%d %d  ",sum(sn-1),sum(sell));
				printf("%d\n",sum(sell)-sum(sn-1));
			}
			
		}	
		printf("\n");
	}
}
