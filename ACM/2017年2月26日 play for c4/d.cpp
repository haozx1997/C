#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int abs(int a)
{
	if(a>0)
	{
		return a;
	}
	return -a;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		int a;
		int max = -100000;
		int min = 100000;
		
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			if(a>=max)
			{
				max = a;
			}
			 if(a<=min)
			{
				min = a;
			}
		}
		int dis = abs(min);
		if(abs(max)<abs(min))
		{
			dis = abs(max);
		}
		printf("%d\n",abs(dis)+abs(max-min));
//	//printf("mmmm  %d %d\n",min,max);
//		if(max>=0&&min<=0)
//		{
//			min = -min;
//			if(min<max)
//			{
//				printf("%d\n",min*2+max);
//			}
//			else
//			{
//				printf("%d\n",max*2+min);
//			}
//		}
//		else if(max>=0&&min>=0)
//		{
//			
//			printf("%d\n",max);
//			
//		}
//		else if(max<=0&&min<=0)
//		{
//			printf("%d\n",-min);
//		}
		
		
	}
}
