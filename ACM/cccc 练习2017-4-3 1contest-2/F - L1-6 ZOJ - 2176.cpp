#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int n;
	
	
	while(~scanf("%d",&n))
	{
		if(n == -1)
		{
			break;
		}
		int v;
		int add = 0;
		int t = 0;
		int pre = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&v,&t);
			add += (v*(t - pre));
			pre = t;
		}
		printf("%d miles\n",add);
	}
}
