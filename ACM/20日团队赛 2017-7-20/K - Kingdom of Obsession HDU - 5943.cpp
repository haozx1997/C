#include<bits/stdc++.h>

using namespace std;
bool check(long long x)
{
	for(long long i=2;i*i<=x;i++)
	if(x%i==0) return false;
	return true;
}


int main()
{
	long long n,m;
	int T;
	
	
	scanf("%d",&T);
	for(int II= 0 ;II < T;II++)
	{
		scanf("%I64d%I64d",&n,&m);
		long long end = n+m;
		long long beg = max(m+1,n+1);
		int F = 0;
		while(beg <= end)
		{
			if(check(beg))
			{
				F++;
				if(F == 2)
				{
					break;
				}
			}
			beg++;
		}
		printf("Case #%d: ",II+1);
		if(F == 2)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
		
		
		
	}



 return 0;
}
/*
2 14

*#*#*#*#*#*#*#
*#*#*#*#*#*#*#
2 14

#*#*#*#*#*#*#*
#*#*#*#*#*#*#*

3 14

*#*#*#*#*#*#*#
*#*#*#*#*#*#*#
*#*#*#*#*#*#*#
3 14

#*#*#*#*#*#*#*
#*#*#*#*#*#*#*
#*#*#*#*#*#*#*

3 14

*#*#*#*#*#*#*#
*#*#*#*#*#*#*#
*******###****

3 14

#*#*#*#*#*#*#*
#*#*#*#*#*#*#*
*#*#*#*#*#*#*#



*/

