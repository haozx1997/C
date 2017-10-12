#include "stdio.h" 
main ()
{
	int a;
	scanf("%d",&a);
	if (a%400)
        {if (a%100)
             if (a%4)
		       printf("N");
		    else 
			printf("Y");
        else
        	printf("N");   
	    }
	else
       printf("Y");
}

