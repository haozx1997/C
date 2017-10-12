#include<bits/stdc++.h>

using namespace std;

int d[100];

int dp(int n)
{
	if(d[n] != 0)
	{
		return d[n];
	}
	if(n == 1)
	{
		return 0;
	}
	if(n == 2)
	{
		return 1;
	}
	if(n == 3)
	{
		return 2;
	}
	return d[n] = dp(n-1)+dp(n-2);
	
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(d,0,sizeof(d));
		int n;
		scanf("%d",&n);
		printf("%d\n",dp(n));
		
	}
}

