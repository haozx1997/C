#include<stdio.h>
main()
{
	int a,b,c,d;
	scanf("%d,%d",&a,&b);
	if(a==b)
	   printf("none");
	else
	    {
		if(a>b)
	       c=a,a=b,b=c;
	    
	     d=a+1;
	     while(d<b)
	         {
	          if(d%7)
	             printf("%d\n",d);
	             d++;
             }
        }
	   
}
