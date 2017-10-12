#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;


int main()
{
	
	char s[200];
	int f = 0;
	while(gets(s))
	{
		if(s[0] != ' ')
			{
				s[0] -=32;
			}
		for(int i = 1;i < strlen(s);i++)
		{
			if(s[i] == ' ')
			{
				f = 1;
			}
			if(f&&s[i]!=' ')
			{
				s[i] -= 32;
				f = 0;
			}
		}
		puts(s);
		
		
	}
}
