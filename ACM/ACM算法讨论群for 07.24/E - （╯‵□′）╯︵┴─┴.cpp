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
	char s1[20];
	char s2[20];
	while(~scanf("%s%s",s1,s2))
	{
	
	
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	sort(s1,s1+len1);
	
	if(s1[0] == '0')
	{
		for(int i = 1;i < len1;i++)
		{
			if(s1[i] != '0')
			{
				s1[0] = s1[i];
				s1[i] = '0';
				break;
			}
		}
	}
	
	if(strcmp(s1,s2))
	 printf("WRONG_ANSWER\n");
	else
	 printf("OK\n");
}
	
}
