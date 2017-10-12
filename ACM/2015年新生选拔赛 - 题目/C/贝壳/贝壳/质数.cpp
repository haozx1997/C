#include<stdio.h>
int main()
{
	int a,b,i=0,n;
	int z[10000];
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
		  	i++;
		  } ;
	  }  
	for(n=0;n<i;n++)
	   printf("%d ",z[n]);    
	
 } 
