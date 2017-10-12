#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	char s[300];
	while(1)
	{
		gets(s);
		if(s[0] == '#')
		{
			break;
		}
		int sum = 0;
		for(int i = 0;i < strlen(s);i++)
		{
			if(s[i] == ' ')
			{
				continue;
			}
			sum += ((i+1)*(s[i]-'A'+1));
		}
		printf("%d\n",sum);
	}
}

