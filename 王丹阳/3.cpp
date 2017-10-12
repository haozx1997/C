#include<stdio.h>
#include<string.h>
int mystr(char *t)
{
	int sum = 0;
	int len = strlen(t);
	for(int i = 0;i<len;i++)
	{
		sum += t[i] - '0';
	}
	return sum;
}

int main()
{
	char t[100];
	scanf("%s",t);
	printf("%d\n",mystr(t));
}
