#include<bits/stdc++.h>

using namespace std;

int maim()
{
	int n;
	char s[1010][1010];
	while(~scanf("%d",&n))
	{
		getchar();
		memset(s,0,sizeof(s));
		for(int i = 0;i < n;i++)
		{
			gets(s[i]);
		}
		
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < strlen(s[i]);j++)
			{
				printf("%c",s[i][j]);
			}
			printf("\n");
		}
		
		
	}
}
