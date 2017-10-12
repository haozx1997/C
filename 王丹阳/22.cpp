#include<stdio.h>
#include<string.h>
int ATO(char*s)
{
	int ans= 0;
	for(int i = 0;i<strlen(s);i++)
	{
		ans += s[i] - '0';
		ans *=10;
	}
	ans /=10;
	return ans;
}

int main()
{
	char s[100];
	scanf("%s",s);
	printf("%d",ATO(s));
}
