#include<stdio.h>
int main()
{
	int a,b,i=0,n;//zhishu
	int z[1000];
	for(a=2;a<1000;a++)
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
	int t,x,p,q,c;
	 scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%d",&x);
		for(p=0;z[p]<x;p++)
		 for(q=p;z[q]<x;q++)
		 if(x==((z[p])+(z[q])))
		  c++;
		printf("%d\n",c);
	 } 
	    
	return 0 ;
 } 
