#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#define ll long long

using namespace std;

int isz(char *ss)
{
	
	if((ss[0]<='9'&&ss[0]>='0')||ss[0]!='+')
	{
		for(int i = 1;i< strlen(ss);i++)
	{
		if(ss[i]>'9'||ss[i]<'0')
		 return 0;
	}
	return 1;
	 } 
	return 0;
	
	
}

int main()
{
	char s1[100000];
	char s2[100000];
	char s[100000];
	gets(s);
	int med;
	int f = 0;
	int len  = strlen(s);
	for(int i = 0;i < len;i++)
	{
		
		if(f)
		{
			if(s[i] == ' ')
			{
				
				med = i + 1;
			}
			else
			{
				break;
			}
		}
		else 
		{
			if(s[i] == ' ')
			{
				
				s[i] = '\0';
				med = i + 1;
				f = 1;
			}
		}
	}
	strcat(s1,s);
	strcat(s2,s+med);
	
	if(isz(s1))
	 printf("%s + ",s1);
	else 
	 printf("? + ");
	if(isz(s2)) 
	 printf("%s = ",s2);
	else 
	 printf("? = ");
	if(isz(s1)&&isz(s1))
	{
		
		printf("%d\n",atoi(s1)+atoi(s2));
	 } 
	 else
	 {
	 	printf("?\n");
	   }  
	
}
