#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int n;
	
	
	while(~scanf("%d",&n))
	{
		int a,b;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			int add = a+b;
			add /= 2;
			
			if(a == b)
			{
				if(add%2)
				{
					printf("%d\n",a+b-1);
					continue;
				}
				else
				{
					printf("%d\n",a+b);
					continue;
				}
			}
			if((a-b) == 2)
			{
				if(add%2)
				{
					printf("%d\n",a+b);
					continue;
				}
				else
				{
					printf("%d\n",a+b-1);
					continue;
				}
			}
			printf("No Number\n");
		}
		
	
	}
}
