#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<queue>
#include<math.h>

using namespace std;



int main()
{
	int NN;
	scanf("%d",&NN);
	while(NN--)
	{
		int n;
		int ans[100100];
		int an = 0;
		scanf("%d",&n);
		printf("%d=",n);
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		int y = 2;
		while(n!=1)
		{
			if((n%y) == 0)
			{
				ans[an++] = y;
				n /= y;
			 } 
			else
			{
				y++; 	
			 } 
			
			
		}
		for(int i = 0;i< an-1;i++)
		{
			printf("%d*",ans[i]);
		}
		printf("%d\n",ans[an-1]);
	}
	return 0;
}






