#include<bits/stdc++.h>

using namespace std;
long long n,a,b;

long long d[111];

long long dp(int i)
{
	if(i == 0||i == 1)
	{
		return 0;
	}
	if(i == 2)
	{
		return 1;
	}
	if(i == 3)
	{
		return 2;
	}
	
	if(d[i] != 0)
	{
		return d[i];
	}
	return d[i] = dp(i-1)+dp(i-2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		memset(d,0,sizeof(d));
		scanf("%d%d",&a,&b);
		
		printf("%lld\n",dp(b-a+1));
	}
}
