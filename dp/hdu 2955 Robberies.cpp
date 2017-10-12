#include<bits/stdc++.h>

using namespace std;
double av;
		double v[500];
		int aj;
		int j[500];
		int n;
int dp[111][111];
int d(int i,int vv)
{
	if(dp[i][vv]!=0)
	{
		return dp[i][vv];
	}
	
	
	return dp[i][vv] = max(d(i-1,vv),d(i-1,vv-v[i])+j[i]);
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(v,0,sizeof(v));
		memset(j,0,sizeof(j));
		memset(dp,0,sizeof(dp));
		
		
		scanf("%lf%d",&av,&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d%lf",&j[i],&v[i]);
		}
		
		printf("%d\n",d(n-1,0));
		
	}




 return 0;
}


