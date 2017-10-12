#include <stdio.h>
main ( )
{
	int a,b,c,d;
	scanf("%d,%d",&a,&b);
	if(a>b)
	   c=a,a=b,b=c;
    d=b;
    while(d%a||d%b)
	     d++;
    printf("%d",d);
		   
}
