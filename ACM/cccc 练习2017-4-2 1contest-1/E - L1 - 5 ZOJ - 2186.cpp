#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int a[10];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	{
		for(int i = 0;i< 3;i++)
		{
			if(a[i]<=168)
			{
				printf("CRASH %d\n",a[i]);
				return 0;
			}
			
		}
		printf("NO CRASH\n");
	}
}
