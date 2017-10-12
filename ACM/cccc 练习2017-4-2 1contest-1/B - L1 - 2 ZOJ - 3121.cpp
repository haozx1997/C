#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int n;
	char s[1010][1010];
	while(~scanf("%d",&n))
	{
		memset(s,0,sizeof(s));
		for(int i = 0;i < n;i++)
		{
			scanf("%s",s[i]);
		}
		
//		for(int i = 0;i < n;i++)
//		{
//			for(int j = 0;j < strlen(s[i]);j++)
//			{
//				printf("%c",s[i][j]);
//			}
//			printf("\n");
//		}
		int f = 0;
		for(int i = 0;i < n;i++)
		{
			if(s[i][0] == '_')
			{
				f++;
			}
			else
			{
				break;
			}
		}
		for(int j = strlen(s[0])-1;j > 0;j--)
		{
			for(int i = n-1;i >= 0;i--)
			{
				if(s[i][j] == '_')
				{
					printf(" ");
					continue;
				}
				if(s[i][j] == '\\')
				{
					printf("\n");
					continue;
				}
				
				printf("%c",s[i][j]);
			}
			
		}
		for(int i = n-1;i>=f;i--)
		{
			
			{
				if(s[i][0] == '_')
				{
					printf(" ");
					continue;
				}
				if(s[i][0] == '\\')
				{
					printf("\n");
					continue;
				}
				
				printf("%c",s[i][0]);
			}
		}
		printf("\n\n");
		
	}
}
