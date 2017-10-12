#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

char s1[1000000];
char s2[1000000];



int main()
{
	
	while(~scanf("%s",s1))
	{
		scanf("%s",s2);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int f1 = -1;
		int f2 = -1;
		
		for(int i = 0;i < len1;i++)
		{
			if(s1[i] == '.')
			 {
			 	f1 = i;
			 }
		}
		for(int i = 0;i < len2;i++)
		{
			if(s2[i] == '.')
			 {
			 	f2 = i;
			 }
		}
		if(f1!=-1)
		{
			for(int i = len1 - 1;i >= f1;i--)
			{
				if(s1[i] == '0')
				{
					s1[i] = '\0';
				}
				else
				{
					if(s1[i] != '0'&&s1[i] != '.')
				{
					break;
				}
				if(s1[i] == '.')
				{
					s1[i] = '\0';
					break;
				}
				}
			}
		}
		if(f2!=-1)
		{
			for(int i = len2 - 1;i >= f2;i--)
			{
				if(s2[i] == '0')
				{
					s2[i] = '\0';
				}
				else
				{
					if(s2[i] != '0'&&s2[i] != '.')
				{
					break;
				}
				if(s2[i] == '.')
				{
					s2[i] = '\0';
					break;
				}
				}
			}
		}

		if((strcmp(s1,s2)))
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
