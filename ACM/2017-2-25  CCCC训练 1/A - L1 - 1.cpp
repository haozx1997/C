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
			ans = 1;
		}
		int ii;
		for( ii = 0;ii<len-1;ii++)
		{
		//	printf("%d %d %d\n",ans,ii,len);
			if(s[ii] == ' '&&s[ii+1]!=' ')
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
 }
