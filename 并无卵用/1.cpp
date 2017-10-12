
int main()
{
	int T,i;
	char str[101];
	scanf("%d",&T);
	getchar();//³Ôµô»º´æÇøµÄ\n 
	for(;T;T--)
	{
		   
		   gets(str);
		   for(i=0;i<strlen(str);i++)
		    str[i]=str[i]+32;
		   puts(str);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>  
