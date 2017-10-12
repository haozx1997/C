#include<stdio.h>
#include<string.h>

int d(int n)
{
//	printf("         %d\n",n);
	if(n<=9)
	{
		return n;
	}
	char nn[20];
	int ans = 0;
	sprintf(nn,"%d",n);
	for(int i = 0;i < strlen(nn);i++)
	{
		ans += nn[i] - '0';
	}
	return d(ans);
}

int main()
{
//	freopen("1.in","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int ii = 1;ii <= n;ii++)
			{
				for(int iii = 1;iii <= n;iii++)
				{
					if(d(iii)==d(d(i)*d(ii)))
					{
						if(iii!=ii*i)
						{
							ans++;
						}
					}
				}
				
			}
		}

		printf("%d\n",ans);
	}
}
