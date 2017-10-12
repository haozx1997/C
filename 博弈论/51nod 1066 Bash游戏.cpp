#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if((n%(k+1)) == 0)
		{
			printf("B\n");
		}
		else
		{
			printf("A\n");
		}
	}
}
