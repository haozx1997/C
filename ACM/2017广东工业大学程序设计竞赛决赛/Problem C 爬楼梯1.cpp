#include<bits/stdc++.h>
int mod = 10007;
int sum = 0;
int dp[50];
int solve()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i < 25;i++)
	{
		dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%mod;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	solve();
	while(T--)
	{
		int n;
		int l;
		sum = 1;
		scanf("%d",&n);
		for(int i = 0;i < n-1;i++)
		{
			scanf("%d",&l);
			sum *= dp[l];
			sum %= mod;
		}
		printf("%d\n",sum);
				
	}
}
