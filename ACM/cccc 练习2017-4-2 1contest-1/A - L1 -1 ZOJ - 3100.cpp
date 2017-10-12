#include<stdio.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int max = -100;
		int min = 1000000;
		int sum = 0;
		int a;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			if(a>max)
			{
				max = a;
			}
			if(a<min)
			{
				min = a;
			}
			sum +=a;
		}
		sum -= max;
		sum -= min;
		printf("%d\n",sum/(n-2));
	}
}

