#include<stdio.h>
#include<string.h>
int check(char *s1,char *s2)
{
	if(strcmp(s1,s2))
 	  return 2;
 	int  f = 1;
	for(int i = 0;i<strlen(s1);i++)
	{
		if(s1[i]>='a'&&s1[i]<='z')
			f=0;		
	}
	if(f)
	{
		return 1;
	}
	f = 1;
	for(int i = 0;i<strlen(s1);i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z')
			f=0;		
	}
	if(f)
	{
		return 11;
	}
	f = 1;
	for(int i = 0;i<strlen(s1);i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
			f=0;		
	}
	if(f)
	{
		return 111;
	}
  	return 0 ;
  }

int main()
{
	char s1[100];
	char s2[100];
	scanf("%s",s1);
	scanf("%s",s2);
	
	printf("%d",check(s1,s2));
}
