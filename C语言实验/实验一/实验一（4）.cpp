#include <stdio.h>
main ( )
{
	double m,x=2.5,y=4.7;
    int a=7;
	m=x+a%3*(int)(x+y)%2/4;
	printf("%f\n",m);
	return 0;
} 
