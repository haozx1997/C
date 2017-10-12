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
		int n,m;
		scanf("%d%d",&n,&m);
		int a[100010];
		int sum = 0;
		for(int i = 0;i < n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		for(int I = 0;I < m;I++)
		{
			int now;
			scanf("%d",&now);
			if(sum<now)
			 printf("1");
			else
			 printf("0"); 
		}
		printf("\n");
	}
 } 
