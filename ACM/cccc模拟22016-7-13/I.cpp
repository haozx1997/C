#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()

{
	int x,y;
	
	while(~scanf("%d%d",&x,&y))
	{
		if(x == y)
		{
			printf("%d\n",x);
			continue;
		}
		int xx= x;
	int xxx[1000];
	int x_i = 0;
	while(1)
	{
		xxx[x_i++] = xx;
		if(xx == 1) break;
		if(xx%2)
		{
			xx = (xx-1)/2;
		}
		else
		{
			xx /=2;
		}
		
	}
	int yy= y;
	int yyy[1000];
	int y_i = 0;
	while(1)
	{
		yyy[y_i++] = yy;
		if(yy == 1)break;
		if(yy%2)
		{
			yy = (yy-1)/2;
		}
		else
		{
			yy /=2;
		}
		
	}
	int max = x_i;
	if(y_i>x_i)
	 max  = y_i;
	for(int i = 0;;i++)
	{
		--y_i;--x_i;
		if(yyy[y_i]!=xxx[x_i])
		{
			break;
		}
	}
	printf("%d\n",yyy[y_i+1]);
	
	}
	
	
	
	
	
}
