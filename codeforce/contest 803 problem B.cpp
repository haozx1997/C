#include<bits/stdc++.h>
#define ll long long
using namespace std;


int a[200200];
ll ai;
int X = INT_MAX;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n;i++ )
		{
			scanf("%I64d",&ai);
			if(ai)
			{
				a[i] = X;
			}
			else
			{
				a[i] = 0;
			}
		}
		int now = X;
		for(int i = 0; i < n;i++ )
		{
			
			if(a[i] != X||now!=X)
			{
				if(a[i])
				{
					a[i] = ++now;
				}
				else
				{
					now = 0;
				}
			}
		}
//		printf("%d",a[0]);
//		for(int i = 1; i < n;i++ )
//		{
//			printf(" %d",a[i]);
//		}
//		puts("");
		int F = 0;
		for(int i = n-1; i >=0 ;i-- )
		{
			if(a[i] == 0)
			{
				F = 1;
				now = 0;
			}
			if(F)
			{
				if(a[i])
				{
					a[i] = min(++now,a[i]);
				}
				else
				{
					now = 0;
				}
			}
		}
		printf("%d",a[0]);
		for(int i = 1; i < n;i++ )
		{
			printf(" %d",a[i]);
		}
		puts("");
		
	}




 return 0;
}


