#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int n,sum = 0;
		scanf("%d",&n);
		getchar();
		
		n = abs(n);
		int i;
		for(i=1;;i++)
		{
			sum+=i;
			if(sum>=n&&!((sum-n)%2))
			 break;
			 
		}
		printf("%d\n",i);
		if(t) 
		printf("\n");
	}
 } 
