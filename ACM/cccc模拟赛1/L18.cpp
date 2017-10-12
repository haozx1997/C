#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()
{
	char s1[1010];
	char s2[1010];
	while(scanf("%s",s1),s1[0]!='#')
	{
		scanf("%s",s2);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int ans = 0;
		for(int i = 0;i < len1;i++)
		{
			int f = 0;
			for(int j = 0;j<len2;j++)
			{
				if(s1[i+j]!=s2[j]||i+j>=len1)
				{
					f = 1;
					break;
				}
				
			}
			if(!f)
			{
				ans++;
				i = i+len2-1;
				
			}
			
		}
		printf("%d\n",ans);
	}
}
