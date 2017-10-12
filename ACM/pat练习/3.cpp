#include<stdio.h>
#include<string.h>

int  main()
{
	int lala[20];
	char n[2000];
	scanf("%s",n);
	memset(lala,0,sizeof(lala));
	for(int i = 0;i<strlen(n);i++)
	{
		lala[n[i]-'0']++;
		
	}
	for(int i = 0;i<10;i++)
	{
		if(lala[i])
		{
			printf("%d:%d\n",i,lala[i]);
		}
	}
}
