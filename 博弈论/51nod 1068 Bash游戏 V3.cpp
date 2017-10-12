#include<stdio.h>
#include<string.h>
int main()
{
	long long T;
	char n[1100];
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%s",n);
		int len = strlen(n);
		int a = 0;
		for(int i = 0 ;i<len;i++)
		{
			a += n[i] -'0';
		}
		printf("%s\n",(a%3)?"A":"B");
	}
}
