#include <stdio.h>  
#include <string.h>  
int main()
{

    char s[11];
	int c,i,a[8]={64,32,16,8,4,2,1,0};
	gets(s);
	while(gets(s),s[1]!='_')
	{
		c=0;
		for(i=6;i<11;i++)
		 s[i]=s[i+1];
		for(i=2;i<9;i++)
		 {
		 	if(s[i]=='o') c+=a[i-2];
		 }
		 printf("%c",c);
	}
	return 0;
 } 
