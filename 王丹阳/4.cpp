#include<stdio.h>
#include<string.h>

int wordnum(char *s)
{
	int ans = 0;
	for(int i = 0;i<strlen(s);i++)
	{
		if((s[i] == ' '&&s[i+1] != ' ')||s[i] == '.')
		{
			ans++;
		}
		
	}
	
	
	return ans;
}
int main()
{
	char s[100];
	gets(s);
	
	printf("%d\n",wordnum(s));
}
