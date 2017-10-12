#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()
{
char s[1000];
	int T;
	scanf("%d",&T);getchar();
	while(T--)
	{
		 
	 	gets(s);
		int ans = 0;
		if ((s[0]>='A'&&s[0]<='Z')||(s[0]>='a'&&s[0]<='z'))
		{
			ans++;
		}
		for(int i = 0;i < strlen(s)-1;i++)
		{
			if(s[i] == ' '&&((s[i+1]>='A'&&s[i+1]<='Z')||(s[i+1]>='a'&&s[i+1]<='z')))
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	
	}
	
}

