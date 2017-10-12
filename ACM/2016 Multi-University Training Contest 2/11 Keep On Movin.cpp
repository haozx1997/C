#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;


int main()
{
	int  T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ai;
		int a[100100];
		int b[100100];
		int sum = 0;
		int bn = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			
			if(a[i]%2)
			 {
			 	a[i]--;
			 	b[bn++] = 1;
			 }
			 sum +=a[i];
		}
		if(bn == 0)
		{
			printf("%d\n",sum);
			continue;
		}
		sum = sum/2;
		int ans = sum/bn;		
		ans = 1+(ans*2);
		printf("%d\n",ans);
		
	}
}
