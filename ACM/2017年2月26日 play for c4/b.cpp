#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>

using namespace std;


int main()
{
	char s[100100];
	while(~scanf("%s",&s))
	{
		int len = strlen(s);
		int f = 1;
		for(int i = 0;i< len-1;i++)
		{
			if(s[i] == '0')
			{
				printf("%s\n",s+i+1);
				f = 0;
				break;
			}
			else
			{
				printf("%c",s[i]);
			}
		}
		if(f)
		{
			printf("\n");
		}
		
	}
}
