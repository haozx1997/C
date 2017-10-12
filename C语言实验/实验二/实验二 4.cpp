#include<stdio.h>
#include <iostream>
main()
{
	int a,b,c,d,e;  /*输入四个整数，要求按由小到大的顺序输出*/
	scanf("%d,%d,%d,%d",&a,&b,&c,&d);
	if(a<b)
	  {
	    e=a;
	    a=b;
	    b=e;
	  }
	if(b<c)
    {
	  	e=b;
	  	b=c;
	  	c=e;
	  	if(a<b)
	       {
	        e=a;
	        a=b;
	        b=e;
	       }
    }
    if(c<d)
    {
    	e=c;
    	c=d;
    	d=e;
    	if(b<c)
         {
	  	   e=b;
	  	   b=c;
	  	   c=e;
	  	   if(a<b)
	         {
	         e=a;
	         a=b;
	         b=e;
	         }
         }
    	
	}
	printf("%d<%d<%d<%d",d,c,b,a);
}
    
