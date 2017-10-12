#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[1010][1010];

int d1[1010][1010];
int dp1(int i,int j)
{
	if(d1[i][j]!=-1)
	{
		return d1[i][j];
	}
	if(i>n||i<1||j>m||j<1)
	{
		return 0;
	}
	return d1[i][j] = a[i][j] + max(dp1(i-1,j),dp1(i,j-1));
}

int d2[1010][1010];
int dp2(int i,int j)
{
	if(d2[i][j]!=-1)
	{
		return d2[i][j];
	}
	if(i>n||i<1||j>m||j<1)
	{
		return 0;
	}
	return d2[i][j] = a[i][j] + max(dp2(i-1,j),dp2(i,j+1));
}

int d3[1010][1010];
int dp3(int i,int j)
{
	if(d3[i][j]!=-1)
	{
		return d3[i][j];
	}
	if(i>n||i<1||j>m||j<1)
	{
		return 0;
	}
	return d3[i][j] = a[i][j] + max(dp3(i+1,j),dp3(i,j-1));
}

int d4[1010][1010];
int dp4(int i,int j)
{
	if(i>n||i<1||j>m||j<1)
	{
		return 0;
	}
	if(d4[i][j]!=-1)
	{
		return d4[i][j];
	}
	
	return d4[i][j] = a[i][j] + max(dp4(i+1,j),dp4(i,j+1));
}


int main()
{
	
	while(~scanf("%d%d",&n,&m))
	{
		memset(d1,-1,sizeof(d1));
		memset(d2,-1,sizeof(d2));
		memset(d3,-1,sizeof(d3));
		memset(d4,-1,sizeof(d4));
		memset(a,0,sizeof(a));
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		dp1(n,m);
		dp2(n,1);
		dp3(1,m);
		dp4(1,1);
		
		int ans = 0;
		
//		for(int i = 1;i <= n;i++)
//		{
//			for(int j = 1;j <= m;j++)
//			{
//				printf("%d %d||",d1[i-1][j]+d2[i][j+1]+d3[i][j-1]+d4[i+1][j],d1[i][j-1]+d2[i-1][j]+d3[i+1][j]+d4[i][j+1]);
//			}
//			printf("\n");
//		}
//		for(int i = 1;i <= n;i++)
//		{
//			for(int j = 1;j <= m;j++)
//			{
//				printf("%d %d %d %d||",d1[i][j],d2[i][j],d3[i][j],d4[i][j]);
//			}
//			printf("\n");
//		}
		
		for(int i = 2;i < n;i++)
		{
			for(int j = 2;j < m;j++)
			{
				ans = max(ans,d1[i-1][j]+d2[i][j+1]+d3[i][j-1]+d4[i+1][j]);
				ans = max(ans,d1[i][j-1]+d2[i-1][j]+d3[i+1][j]+d4[i][j+1]);
				
			}
		}
		printf("%d\n",ans);
		
		
	}
}
