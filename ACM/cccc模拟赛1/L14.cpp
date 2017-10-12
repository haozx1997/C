#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int is(int n){
	
	int ans = n*n + n + 41;
	if(ans<0)
	{
		ans = 0-ans;
	}
	if(ans == 1||ans ==0)
	 return 0;
	int f = 0;
 	for(int i = 2;i<ans/2;i++)
	{
		if(!(ans%i))
		{
			f = 1;
			break;
		}
	}
	if(f)
	 return 0;
	return 1; 
	
}


int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y),(x||y))
	{
		if(x>y)
		{
			int t = x;
			x = y;
			y = t;
		}
		int f = 0;
		for(int i = x;i <= y;i++)
		{
			if(!(is(i)))
			{
				f = 1;
				break;
			}
		}
		if(f)
		{
			printf("Sorry\n");
		}
		else
		{
			printf("OK\n");
		}
	}
}
