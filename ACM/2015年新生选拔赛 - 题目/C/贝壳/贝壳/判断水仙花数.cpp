#include <stdio.h>
main ()
{
	int A=370,a,b,c,d;
	
		a=A/100;
	    b=A%100/10;
	    c=A%10;
	    printf("%d %d %d\n",a,b,c);
	    d=a*a*a+b*b*b+c*c*c;
	    printf("%d\n",d);
	    if(A==a*a*a+b*b*b+c*c*c)
	        printf("%d\n",A);
		
}
