#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,now;
	int a[5];
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		int F = 0;
		for(int i = 0 ; i < n;i++)
		{
			scanf("%d",&now);
			if(now == 25)
			{
				a[0]++;
			}
			if(now == 50)
			{
				a[1]++;
				a[0]--;
				if(a[0]<0)
				{
					F = 1;
				}
			}
			if(now == 100)
			{
				if(a[1])
				{
					a[1]--;
					a[0]--;
					if(a[1]<0)
					{
						F = 1;
					}
					if(a[0]<0)
					{
						F = 1;
					}
				}
				else
				{
					a[0]--;
					a[0]--;
					a[0]--;
					
					if(a[0]<0)
					{
						F = 1;
					}
				}
			}
			
		}
		if(F)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}




 return 0;
}


