#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b,e;
		int sum = 0;
		int a;
		scanf("%d%d",&b,&e);
		for(int i =0;i<b;i++)
		{
			scanf("%d",&a);
			sum += a;
		}
		if(sum>e)
		{
			printf("Warning\n");
		}
		else
		{
			printf("Safe\n");
		}
	}
}
