#include <stdio.h>
main ()
{
	int A,a,b,c,d;
	for(A=100;A<1000;A++)
	{
		a=A/100;
	    b=A%100/10;
	    c=A%10;
	    if(A==a*a*a+b*b*b+c*c*c)
	        printf("%d ",A);
	}
	

}
