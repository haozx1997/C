#include "stdio.h" 
main ()
{//[设计型]编程求解：编写程序，输出从公元1000年至2100年所有闰年的年号。要求每输出15个年号换一行
	int y[1000];
	int y0=0,i;
	for(i=1000;i<=2100;i++)
	 {
	 	if (i%400)
        {if (i%100)
             if (i%4)
		       continue;
		    else 
			{
				y[y0]=i;
				y0++;
			}
        else
        	continue;   
	    }
	else
       {
			y[y0]=i;
			y0++;
		}
	 }
	 for(i=0;i<y0;i++)
	   {
	   	if(i%15==0) printf("\n");
	   	printf("%d ",y[i]);
	   }
	return 0;
}
	
