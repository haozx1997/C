/*
abc
def
adebcf

qqq
www
qqqwww

asd
asf
asfasd




*/


#include<stdio.h>
#include<string.h>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;


int main()
{
	char a[2020];
	while(~scanf("%s",a))
	{
		char b[2020];
		char c[2020];
		
		scanf("%s",b);
		scanf("%s",c);
		int a_i=0;
		int b_i=0;
		int f= 0;
		if((strlen(a)+strlen(b))!=strlen(c))
		{
			printf("No\n");
			continue;
		}
		for(int i = 0; i<strlen(c);i++)
		{
			if(a[a_i] == c[i])
			{
				a_i++;
				continue;
			}
			else
			{
				if(b[b_i] == c[i])
				{
					b_i++;
					continue;
				}
				else
				{
					f=1;
					break;
				}
			}
		}
		
		
		if(f)
		{
			f = 0;
			a_i = strlen(a)-1;
			b_i = strlen(b)-1;
			for(int i = strlen(c)-1; i>=0;i--)
			{
				
				
				if(a[a_i] == c[i])
				{
					a_i--;
					continue;
				}
				else
				{
					if(b[b_i] == c[i])
					{
						b_i--;
						continue;
					}
					else
					{
						f=1;
						break;
					}
				}
			}
			
			
			if(f)
			printf("No\n");
			else
			printf("Yes\n");
		}
		else
		{
			printf("Yes\n");
		}
		
	}
}
