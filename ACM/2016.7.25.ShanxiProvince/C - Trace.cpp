#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


double S(int r)
{
	return (double)r*r*3.1415926535898;
}

int main()
{
	int n;
	int r[1010];
	while(~scanf("%d",&n))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&r[i]);
		}
		sort(r,r+n);
		double ans = 0;
		if(n%2)
		{
			for(int i = n-1;i >=0;i--)
			{
				if(i%2)
				{
					ans -= S(r[i]);
				}
				else
				{
					ans += S(r[i]);
				}
			}
		}
		else
		{
			for(int i = n-1;i >=0;i--)
			{
				if(i%2)
				{
					ans += S(r[i]);
				}
				else
				{
					ans -= S(r[i]);
				}
			}			
			
		}
		printf("%.10f\n",ans);
	}
}
