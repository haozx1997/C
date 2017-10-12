#include<stdio.h>
#include<string.h>

int main() 
{
//	freopen("1.in","r",stdin);
	int n;
	scanf("%d",&n);
	char s[1100];
	while(~scanf("%s",s))
	{
		scanf("%s",s);
		scanf("%s",s);
		if(s[9] == '?')
		{
			printf("-_-\n");
			continue;
		}
		if(s[9] == '.')
		{
			printf("Orz\n");
			continue;
		}
		if(s[9] == '!')
		{
			printf("W");
			int len = strlen(s+9);
			for(int i = 0 ;i < len;i++)
			{
				printf("o");
			}
			printf("w!\n");
			continue;
		}
		
		


	 } 
	return 0;
}
