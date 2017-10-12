#include<stdio.h>

main()
{ 
   int a[10],i,j,s;
   for(i=0;i<10;i++)
      scanf("%d",&a[i]);
   for(i=0;i<10;i++)
        {
      	for(j=0,s=0;j<10;j++)
      	    { 
      	        s=s+(a[i]>=a[j]);
      	        if(s==10)
      	           printf("最大在%d\n",i);
      	    };
		}
    for(i=0;i<10;i++)
        {
      	for(j=0,s=0;j<10;j++)
      	    { 
      	        s=s+(a[i]<=a[j]);
      	        if(s==10)
      	           printf("最小在%d",i);
      	    };
		}
}
