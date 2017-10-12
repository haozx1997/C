#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

//const ll M = 1000000007;
ll n,m,k;
ll dp[1100000][5];

ll solve(ll u,ll v)
{
//	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for(int i = 1;i <= n;i++)
	{
		ll sum = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%M;
		dp[i][2] = sum;
		
		if(i<=u)
		{
			dp[i][0] = sum;
		}
		else if(i == u+1)
		{
			dp[i][0] = (sum-1)%M;
		}
		else
		{
			dp[i][0] = (sum - dp[i-1-u][1] - dp[i-1-u][2])%M;
		}
		
		if(i<=v)
		{
			dp[i][1] = sum;
		}
		else if(i == v+1)
		{
			dp[i][1] = (sum-1)%M;
		}
		else
		{
			dp[i][1] = (sum - dp[i-1-v][0] - dp[i-1-v][2])%M;
		}
		
		
	}
	
	return (dp[n][0]+dp[n][1]+dp[n][2])%M;
}

int main()
{
	while(~scanf("%lld%lld%lld",&n,&m,&k))
	{
		ll ans1,ans2,ans;
		ans1 = solve(n,k);
		ans2 = solve(m-1,k);
		ans = ((ans1 - ans2)%M+M)%M;
		
		printf("%lld\n",ans);
	//	printf("%lld\n",ans1);
	//	printf("%lld\n",ans2);
	}
}
