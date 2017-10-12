#include <stdio.h>
main ()
{
	int a=2,b=1,sum=0;
	for(;a<1000;a++)
	     { 
	        b=1,sum=0;
	     	while(b<a)
	            {
	             if(a%b==0)
	     	        sum=sum+b;
	     	        b++;
	            }
	        if(sum==a)
	           printf("%d\n",sum); 
	    }
		 
}
