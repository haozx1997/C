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
	int a[2000];
	memset(a,-1,sizeof(a));
	for(int i = 0; i< 1000;i++)
	{
		if(i%2)
		{
			a[i] = (i/2)+1;
		}
		
	}
	a[0] = 0;
	for(int i = 2; i< 1000;i++)
	{
		int ii = i;
		if(!(ii%2))
		{
			ii =(ii/2)-1;
			while(1)
			{
				if(ii%2)
				{
					a[i] = a[ii];	
					break;
				}
				else if(a[ii]!=-1)
				{
					a[i] = a[ii];	
					break;	
				}
				ii =(ii/2)-1;
			//	printf("%d\n",ii);
			}
			
		}
		
	}
	
	
	
		for(int i = 0; i< 1000;i++)
	{
		int sum = 0;
		for(int ii = 0; ii< i;ii++)
		{
			sum += a[ii];
		}
		
		printf("%5d  %5d   %5d",i,a[i],sum);
		if(a[i] == 0)
		{
			printf("         %d",i);
		}
		printf("\n");
	}
	
//	
//			for(int i = 0; i< 1000;i++)
//	{
//		
//		
//		printf("%d,",a[i]);
//		
//	}
			
	
	
}
