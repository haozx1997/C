#include<stdio.h>
#include<string.h>

void fun(char*s)
{
	int len = strlen(s);
	char t = s[len-1];
	for(int i = len;i>0;i--)
	{
		s[i - 1] = s[i - 2];
	}
	s[0] = t;
}


int main()
{
	char s[100];
	scanf("%s",s);
	fun(s);
	printf("%s\n",s);
	
	
 } 
