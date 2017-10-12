#include<stdio.h>
main()
{
	int a;            /***输入一个整数，若其为偶数，求其立方值，若其为奇数，求其平方值***/
	scanf("%d",&a);
	if(a%2)
	   a=a*a;
	else a=a*a*a;
	printf("%d",a);
 } 
