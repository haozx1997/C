#include <stdio.h>
main ( )
{
	int a,b,c,d;
	scanf("%d,%d",&a,&b);
	if(a==b)
	   printf("%d",a);
	else
	    {
		if(a>b)
	       c=a,a=b,b=c;
        }
    d=a;
    while(a%d||b%d)
	     d--;
    printf("%d",d);
		   
}
