#include<stdio.h>
main()
{
	int a;            /***����һ������������Ϊż������������ֵ������Ϊ����������ƽ��ֵ***/
	scanf("%d",&a);
	if(a%2)
	   a=a*a;
	else a=a*a*a;
	printf("%d",a);
 } 
