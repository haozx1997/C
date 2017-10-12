#include<stdio.h>
#include<string.h>
int main()
{
	int T,i;
	char str[101];
	scanf("%d",&T);
	for(;T;T--)
	{
		   for(i=0;;i++)
		   {
		   scanf("%s",str);
		   	if(getchar()=='\n') break;
		   }
		   for(i=0;i<strlen(str);i++)
		    str[i]=str[i]+32;
		   for(i=0;i<strlen(str);i++)
		   printf("%c",str[i]);
		   printf("\n");
	}
	return 0;
}  
