#include<stdio.h>
#include<string.h>

int main()
{
	char s1[10] = {"I`am a "};
	char s2[10] = {"student"};
	printf("%s\n",s1);
	printf("%s\n",s2);
	int len = strlen(s2);
	strcat(s1,s2);
	
	strcpy(s1,s2);
	int cmp = strcmp(s2,s1);
	printf("len = %d\n",len);
	printf("cmp = %d\n",cmp);
	printf("%s\n",s1);
	printf("%s\n",s2);
	
	
	
}
