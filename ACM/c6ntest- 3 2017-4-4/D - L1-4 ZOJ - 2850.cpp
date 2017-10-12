#include<bits/stdc++.h>

using namespace std;



int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if((m+n) == 0)
		{
			break;
		}
		int sum = 0;
		int a[50][50];
		for(int i = 0;i <= n+1;i++)
		{
			for(int j = 0;j <= m+1;j++)
			{
				a[i][j] = 1;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				scanf("%d",&a[i][j]);
				sum += a[i][j];
			}
		}
		
		int F = 0;
		
		if(sum == n*m)
		{
			F = 1;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(a[i][j] == 0)
				{
					if(a[i+1][j] == 0)
					{
						F = 1;
						break;
					}if(a[i-1][j] == 0)
					{
						F = 1;
						break;
					}if(a[i][j+1] == 0)
					{
						F = 1;
						break;
					}if(a[i][j-1] == 0)
					{
						F = 1;
						break;
					}
				}
			}
			if(F)
			{
				break;
			}
		}
		if(F)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}

