#include "stdio.h" 
main ()
{
	int a,b,c,sum;
	sum = 0;
	scanf ("%d,%d,%d",&a,&b,&c);
	if (a%2)
	  sum=sum+a;
	if (b%2)
	  sum=sum+b;
	if (c%2)
	  sum=sum+c;
	printf("%d\n",sum);
}
