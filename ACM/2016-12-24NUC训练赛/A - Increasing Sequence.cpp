#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int d;
		int a[2020];
		scanf("%d",&d);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		 } 
		 int ans = 0;;
		for(int i = 1;i < n;i++) 
		{
			if(a[i-1]>=a[i])
			{
				int dif = a[i-1]-a[i]+1;
				int add = ceil((double)dif/d);
			//	printf("add %d\n",add);
				a[i] += d*add;
				ans+=add;
			}
			
				
				
				
			
		}
		printf("%d\n",ans);
	}
 } 
