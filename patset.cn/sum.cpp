#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

int main()

{
	int a,b,ans,i;
	while(~scanf("%d%d",&a,&b))
	{
		ans = 0;
		i = 0;
		int aa=a,bb;
		for(;aa<=b;aa++)
		{
			printf("%5d",aa);
			ans+=aa;
			if(!((++i)%5))
			{
				printf("\n");
			}
		}
		printf("\n");
		printf("sum = %d",ans);
	}
	
}
