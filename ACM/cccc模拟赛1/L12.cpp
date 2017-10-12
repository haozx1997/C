#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

char bal[1000010];

int main()
{
	while(~scanf("%s",bal))
	{
		int len = strlen(bal);
		int med = 0;
		int f = 0;
		for(int i = 0;i < len;i++)
		{
			if(bal[i]<='9'&&bal[i]>='0')
			{
				f = 1;
				 
			}
			if(bal[i] == '^')
			{
				med = i;
			}
		}
		if(!f)
		{
			printf("balance\n");
			continue;
		}
	
		long long left = 0;
		for(int i = 0;i < med;i++)
		{
			if(bal[i]<='9'&&bal[i]>='0')
			{
				
				left += ((bal[i]-'0')*(med-i));
			}
		}
		long long right = 0;
		for(int i = med+1;i < len;i++)
		{
			if(bal[i]<='9'&&bal[i]>='0')
			{
				right += ((bal[i]-'0')*(i-med));
			}
		}
		
		if(left>right)
		{
			printf("left\n");
			
		}else if(left<right)
		{
			printf("right\n");
			
		}else if(left==right)
		{
			printf("balance\n");
			
		}
	}
	return 0;
}
