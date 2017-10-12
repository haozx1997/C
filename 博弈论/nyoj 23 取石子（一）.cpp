#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(m>=n)
		{
			printf("Win\n");
			continue;
		}
		if((n%(m+1))==0)
		{
			printf("Lose\n");
			continue;
		}
		printf("Win\n");
	}
}
