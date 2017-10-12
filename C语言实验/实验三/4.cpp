#include<stdio.h>
#include<stdlib.h>
main()
{ //计算S = A! + B! + C!的值。其中，A、B、C的值由键盘输入。
	long fun(int);
	int s,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	s=fun(a)+fun(b)+fun(c);
	printf("%d!+%d!+%d!=%d\n",a,b,c,s);
	system("pause");
	return 0;
}
long fun(int n)
{

	if(n==1||n==0)
	 n=1;
	else
	 n=n*(n-1);
	return n;
	
}
