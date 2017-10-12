#include<stdio.h>
#include<string.h>
int main()
{
	int i,b=0,t=1;
	char a[4];
	scanf("%s",a);
	for(i=3;i>=0;i--)
	printf("%c",a[i]);
	for(i=1,b=a[0]-'0';i<4;i++)
	{
		 
		 
		 b=b*10+(a[i]-'0');

	
	}
		printf("\n%d",b);
}
