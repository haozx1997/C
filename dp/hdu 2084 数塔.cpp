#include<bits/stdc++.h>

using namespace std;

int n;
int a[111][111];
int d[111][111];

int dp(int i,int j)
{
	if(d[i][j] != 0)
	{
		return d[i][j];
	}
	return d[i][j] = a[i][j] + (i == n ? 0 : max(dp(i+1,j),dp(i+1,j+1)));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",dp(1,1));
	}
}
