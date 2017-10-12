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
		int ans1,ans2;
		scanf("%d%d",&b,&e);
		if((b+e)%2)
		{
			printf("impossible\n");
			continue;
		}
		
		ans1 = (b+e)/2;
		ans2 = ans1-e;
		if(ans2<0)
		{
			printf("impossible\n");
			continue;
		}
		printf("%d %d\n",ans1,ans2);
	}
}
