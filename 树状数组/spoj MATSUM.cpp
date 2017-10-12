#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 2100
#define ll long long
using namespace std;
int cc[N][N];
int ccn;
int num[N][N];
int lowbit(int x)
{
	return x&(-x);
}
void update2(int x,int y,int val)
{
	int tem = val;
	val -= num[x][y];
	num[x][y] = tem;
	for(int i = x;i < N; i += lowbit(i))
	{
		for(int j = y; j < N ;j += lowbit(j))
		{
			cc[i][j] += val;
		}
	}
}
int sum2(int x,int y)
{
	int ans = 0;
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
	int T;
	scanf("%d",&T);
	while(T--)
	{	
		scanf("%d",&ccn);
		int xx,yy,v,xxx,yyy;
		int s1,s2,s3,s4,s5;
		char C[10];
		
		for(int i = 0;i <= ccn;i++)
			for(int j = 0;j <= ccn;j++)
			{
				cc[i][j] = num[i][j] = 0;
			}
		while(scanf("%s",C))
		{
			if(C[0]=='E')
			 break;
			switch(C[1])
			{
				
				case 'E' :
					 int xx,yy,v;
					 scanf("%d%d%d",&xx,&yy,&v);
					 xx++;yy++;
					 update2(xx,yy,v);
					 break;
				case 'U' :
					 scanf("%d%d%d%d",&xx,&yy,&xxx,&yyy);
					 xx++;yy++;xxx++;yyy++;
					 s1 = sum2(xx-1,yy-1);
					 s2 = sum2(xx-1,yyy);
					 s3 = sum2(xxx,yy-1);
					 s4 = sum2(xxx,yyy);
					 s5 = s4 - s3 - s2 + s1;
				//	 printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);
					 printf("%d\n",s5);
					 break;
				
			}
	
		}
	}
}
