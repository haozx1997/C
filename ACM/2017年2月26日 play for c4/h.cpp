#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;


int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		if(m == 1)
		{
			if((n%2)&&k == 1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			if(k>n)
			{
				printf("NO\n");
			}
			
			int rem = n/m;
			if(!(rem%2))
			{
				rem = n%m;
				if(!(rem%2))
				{
					rem = 0;
				}
				else
				{
					rem = 1;
				}
			}
			else if(rem == 0)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				int c = n/m;
				rem = n - m*c ;
				rem = m - rem;
			}
		//	printf("rem  %d\n",rem);
			 if(k<rem)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
	}
}
