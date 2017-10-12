#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	while(~scanf("%d",&T))
	{
		while(T--)
		{
			int n;
			scanf("%d",&n);
			int a[100100];
			int sum = 0;
			for(int i = 0;i < n;i++)
			{
				scanf("%d",&a[i]);
				sum += a[i];
				
			}
			int csum = (n*(n-1));
			if(csum != sum)
			{
				printf("F\n");
				continue;
			}
			sort(a,a+n);
			int max = (n-1)*2;
			if(a[n-1] == max && a[n-2] == max)
			{
				printf("F\n");
				continue;				
			}
			else if(a[0] == 0 && a[1] == 0)
			{
				printf("F\n");
				continue;				
			}
			else if(a[0] == 0 && a[1] == 1)
			{
				printf("F\n");
				continue;				
			}
			else printf("T\n");
		}
	}
}
