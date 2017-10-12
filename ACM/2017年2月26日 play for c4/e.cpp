#include<stdio.h>
#include<string.h>

int main()
{
	int n;
//	printf("%d",' ');
	scanf("%d",&n); 
	getchar();
	while(n--)
	{
		char s[500];
		gets(s);
		int ans = 0;
		int len = strlen(s);
		if(s[0] != ' ')
		{
			if(s[0]<='z'&&s[0]>='a')
				{
					printf("%c",s[0]-('a'-'A'));
				}
				else
				{
					printf("%c",s[0]);
				}
		}
		int ii;
		for( ii = 0;ii<len-1;ii++)
		{
		//	printf("%d %d %d\n",ans,ii,len);
			if(s[ii] == ' '&&s[ii+1]!=' ')
			{
				if(s[ii+1]<='z'&&s[ii+1]>='a')
				{
					printf("%c",s[ii+1]-('a'-'A'));
				}
				else
				{
				
					printf("%c",s[ii+1]);
				}
			}
		}
		printf("\n");
	}
 }
