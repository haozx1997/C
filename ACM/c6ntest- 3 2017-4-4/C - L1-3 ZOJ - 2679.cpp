#include<bits/stdc++.h>

using namespace std;



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y,z;
		scanf("%d%d%d%d",&n,&x,&y,&z);
		int all = x*1000+y*100+z*10;
		int now = all;
		int F = 0;
		int i,j;
		for(j = 9;j > 0;j--)
		{
		//	printf("mmp %d %d %d\n",j,i,now/n);
			for(i = 9;i >= 0;i--)
			{
				now = all+j*10000+i;
		//		printf("now  %d\n",now);
				if(!(now%n))
				{
		//				printf("mmp %d %d %d\n",j,i,now/n);
					F = 1;
					break;
				}
			}
			if(F)
			{
				break;
			}
		}
		if(F)
		{
			printf("%d %d %d\n",j,i,now/n);
		}
		else
		{
			printf("0\n");
		}
	}
}

