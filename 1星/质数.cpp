#include<stdio.h>
int main()
{
	int a,b,i=0,n;
	int z[10000];
	int ifz[10000];//ÅĞ¶ÏÊÇ·ñËØÊı 
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
 	        ifz[z[i]]=1;
		  	i++;
		  } ;
	  }  
	for(n=0;n<i;n++)
	   printf("%d ",z[n]);  
	   printf("%d\n",n)  ;
	   
//	while(scanf("%d",&n),n)
//	 printf("%d\n",ifz[n]);
	    
	
 } 
