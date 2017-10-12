#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;


void print(char *s1)
{
	long long ans = 0;
	for(int i = 0;i < strlen(s1);i++)
	{
		
		ans += (s1[i]-'0');
		if((i+1)!=(strlen(s1)))
		{
			ans *=10;
		}
	}
	
	printf("%lld ",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	char s[300];
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		int begin;
		int f = 0;
		for(int i = 0;i < len;i++)
		{
		//	printf("i %d\n",i);
			if(s[i]>='0'&&s[i]<='9'&&f==0)
			{
				begin = i;
				f = 1;
			}
			if(f == 1&&(s[i]<'0'||s[i]>'9'))
			{
				s[i] = '\0';
				print(s+begin);
				begin = 0;
				f = 0;
				continue;
			}
			if(f == 1&&(s[i+1]=='\0'))
			{
			
				print(s+begin);
				begin = 0;
				f = 0;
				continue;
			}
			
		}
		
		printf("\n");
	}
}
