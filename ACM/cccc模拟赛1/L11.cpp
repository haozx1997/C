#include <stdio.h>
#include <string.h>
int main ( )
{
	char s[100];
	while(~scanf("%s",s))
	{
	
	int nx = 0;
	int len = strlen(s);
	for(int i = 0;i < len;i++)
	{
		if(s[i]<='Z')
		 nx++;
	}
	if(nx>(len)/2)
	{
		for(int i = 0;i < len;i++)
		{	
		 if(s[i]>'Z')
		 s[i] -= 32;
		}
	}
	else
	{
		for(int i = 0;i < len;i++)
		{	
		 if(s[i]<='Z')
		 s[i] += 32;
		}
	}
	printf("%s\n",s);
}
	return 0;
}

