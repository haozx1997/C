#include<stdio.h>
int main()
{
	char a[128],b[128];
	scanf("%s,%s",a,b);
	int i=0;
	for(;i<128;i++)
	    if(a[i]>b[i])
	     {printf("a��");break;}
		else
		    {
		    if(a[i]<b[i])
		      {printf("b��");break;}
	    	}	 
	return 0;	  
}
