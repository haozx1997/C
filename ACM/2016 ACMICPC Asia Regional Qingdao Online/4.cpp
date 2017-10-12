#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define ll long long

using namespace std;

int main()
{
	ll l,r;
	while(~scanf("%I64d%I64d",&l,&r))
	{
	//	l = 5;r = 13;
		
			if(r<=2)
			{
				printf("1\n");
				continue;
			}
		
		if((r-l)<=2)
		{
			
			printf("2\n");
			continue;
		}
		r--;
	//	printf("%lf",(double)l/2+0.5);
		double m = (double)l/2+0.5;
		double endm = (double)r/2+0.5;
		//printf("%lf\n", endm-m+1);
		ll ans = ceil( endm-m+1);
		printf("%I64d\n",ans);
	 } 
}
