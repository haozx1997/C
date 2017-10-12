#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s[200];
		scanf("%s",s);
		int la = 1;
		if(strlen(s) == 1 )
		{
			printf("%s\n",s);
			continue;
		}
		
		s[strlen(s)] = '!';
		s[strlen(s)+1] = '\0';
		
		for(int i = 1;i < strlen(s);i++)
		{
			if(s[i] == s[i-1])
			{
				la++;
				
			}
			else
			{
				if(la > 1)
				{
					printf("%d%c",la,s[i-1]);
				}
				else
				{
					printf("%c",s[i-1]);
				}
				la = 1;
				
			}
		}
		
		printf("\n");
		
	}
}
