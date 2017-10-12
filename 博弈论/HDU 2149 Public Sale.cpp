#include<stdio.h>
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(m>=n)
		{
			for(int i = n;i <= m ;i++)
			{
				printf("%d%c",i," \n"[i==m]);
			}
			continue;
		}
		if((n%(m+1))==0)
		{
			printf("none\n");
			continue;
		}
		while(n>(m+1))
		{
			n -= (m+1);
		}
		printf("%d\n",n);
	}
}
