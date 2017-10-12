#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 1050
#define ll long long
using namespace std;

ll cc[N][N];
int ccn;
ll num[N][N];
int lowbit(int x)
{
	return x&(-x);
}
void update2(int x,int y,int val)
{
	if((num[x][y] + val)<0)
	 num[x][y] = 0;
	else 
	 num[x][y] += val;
	
	for(int i = x;i <= N; i += lowbit(i))
	{
		for(int j = y; j <= N ;j += lowbit(j))
		{
			cc[i][j] += val;
		}
	}
}
ll sum2(int x,int y)
{
	ll ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
	{
		for(int j = y; j > 0; j -= lowbit(j))
		{
			ans += cc[i][j];
		}
	}
	return ans;
}


int main()
{
	int t;
	while(~scanf("%d",&t))
	{	
		int xx,yy,v,xxx,yyy;
		ll s1,s2,s3,s4,s5;
		scanf("%d",&ccn);
		memset(cc,0,sizeof(cc));
		memset(num,0,sizeof(num));
		int C;
		while(scanf("%d",&C))
		{
			if(C==3)
			 break;
			switch(C)
			{
				
				case 1 :
					 int xx,yy,v;
					 scanf("%d%d%d",&xx,&yy,&v);
					 xx++;yy++;
					 update2(xx,yy,v);
					 break;
				case 2 :
					 scanf("%d%d%d%d",&xx,&yy,&xxx,&yyy);
					 xx++;yy++;xxx++;yyy++;
					 s1 = sum2(xx-1,yy-1);
					 s2 = sum2(xx-1,yyy);
					 s3 = sum2(xxx,yy-1);
					 s4 = sum2(xxx,yyy);
					 s5 = s4 - s3 - s2 + s1;
				//	 printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);
					 printf("%I64d\n",s5);
					 break;
				
			}
	
		}
	}
}
