#include<stdio.h>
int main()
{
	int a,i,b;
	for(a=1,i=1;i<31;i++)
	   a=a*2;
	printf("%d\n",a);
	b=a;
	for(a=1,i=1;i<31;i++)
	   {
	   	a=a*2;
	   if(a==(b/2))
	      printf("%d",i);
	   }
	
}
