#include "stdio.h" 
main ()
{
	char c; 
	int sum;  
	sum=0;
	while((c=getchar())!='\n') 
	if(c>='0'&&c<='9') sum=sum+c-48;
    printf("%d\n",sum);
 } 
