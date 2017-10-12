#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long a[100100];
		int up[100100];
		up[0] = 0;
		scanf("%d",&n);
		
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		int max = 0;
		memset(up,0,sizeof(up));
		for(int i = 0;i < n;i++)
		{	
			int len = 1;
			
			for(int j = i;j<n-1;j++)
			{
				
				if(a[j]<a[j+1])
				{
					len++;
				}
				else
				{
					break;
				}
			}
			if(len>max) 
			{
				max = len;
				for(int ii = i+1;ii<i+max;ii++)
				{
					up[ii] = 1;
				}
			}
			i += (len-1);
		}
//		printf("%d\n",max);
//		for(int i = 0;i < n;i++)
//		{
//			printf("%lld",a[i]);
//		}
//		printf("\n");
//		for(int i = 0;i < n;i++)
//		{
//			printf("%d",up[i]);
//		}
		
		long long c = 1;
		printf("1 ");
		for(int i = 1;i < n;i++)
		{
			if(up[i] == 1)
			{
				c++;
			}
			else
			{
				c = 1;
			}
			printf("%I64d ",c);
		}
		printf("\n");
	}
	
}
