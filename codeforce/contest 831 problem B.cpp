#include<bits/stdc++.h>

using namespace std;


char s1[100];
char s2[100];
char s[1100];


int main()
{
	while(~scanf("%s%s%s",s1,s2,s))
	{
		int len = strlen(s);
		
		for(int i = 0;i<len;i++)
		{
		
			char c = s[i];
			if(c>='0'&&c<='9')
			{
				printf("%c",c);
				continue;
			}
			if(c>='a'&&c<='z')
			{
				for(int j = 0;j < 26;j++)
				{
					if(s1[j] == c)
					{
						printf("%c",s2[j]);
						break;
					}
				}
				continue;
			}
			if(c>='A'&&c<='Z')
			{
				
				for(int j = 0;j < 26;j++)
				{
					if(s1[j] == (c+32))
					{
						printf("%c",s2[j]-32);
						break;
					}
				}
				continue;
			}
		}
		puts("");
	}




 return 0;
}

/*
qwertyuiopasdfghjklzxcvbnm
veamhjsgqocnrbfxdtwkylupzi
TwccpQZAvb2017
mnbvcxzlkjhgfdsapoiuytrewq
asdfghjklqwertyuiopzxcvbnm
7abaCABAABAcaba7



*/

