#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()
{
	char s[111];
	while(~scanf("%s",s))
	{
		if(strlen(s)>10)
		{
			printf("TAT\n");
			continue;
		}
		long long ago;
		sscanf(s,"%I64d",&ago);
		if(ago >= 4294967296||ago == 0)
		{
			printf("TAT\n");
			continue;			
		} else if(ago >= 65536)
		{
			printf("5\n");
			continue;			
		}else if(ago >= 256)
		{
			printf("4\n");
			continue;			
		}else if(ago >= 16)
		{
			printf("3\n");
			continue;			
		}else if(ago >= 4)
		{
			printf("2\n");
			continue;			
		}else if(ago >= 2)
		{
			printf("1\n");
			continue;			
		}else if(ago < 2)
		{
			printf("0\n");
			continue;			
		}
	}
}
