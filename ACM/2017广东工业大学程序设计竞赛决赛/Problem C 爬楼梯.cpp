#include<bits/stdc++.h>
int mod = 10007;
int sum = 0;

int solve(int l,int j,int all)
{
	
	if(l>=all)
	{
		if(l == all)
		{
			sum++;
			sum %= mod;
		}
		return 0;
	}
	for(int i = 0;l+j*i <= all;i++)
	{
		if(j+1<5)
			solve(l+j*i,j+1,all);
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int n;
		int l;
		sum = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&l);
			solve(0,1,l);
		}
		printf("%d\n",sum);
				
	}
}
