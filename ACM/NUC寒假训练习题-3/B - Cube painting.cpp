#include<stdio.h>
#include<string.h>
int main()
{
	char s[13];
	while(scanf("%s",s)!=EOF)
	{
		int i,j;
		char s1[7],s2[7];
		for(i=0;i<6;i++)
		 s1[i]=s[i];
		for(i=6;i<12;i++)
		 s2[i-6]=s[i];		 
		 //s2[6] = '\0'; 
			
		printf("%s\n",s2);
		puts(s2);
		printf("%d",strlen(s2));			
	}
}
