#include "stdio.h" 
main ()
{
	char c;
	while((c=getchar())!='\n') 
	{
		if(c>='A'&&c<='Z') 
		printf("%c",c+32);
		else
		if(c>='a'&&c<='z') 
		printf("%c",c-32);
	}
}
