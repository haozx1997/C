#include<stdio.h>
main()
{
	int s,a,b,c,d,e;/*输入一个5位数，判断它是不是回文数。例如12321是回文数，个位与万位相同，十位与千位相同*/
	scanf("%d",&s);
	a=s/10000;
	b=s%10000/1000;
	c=s%1000/100;
	d=s%100/10;
	e=s%10;
	if(a==e&&b==d)
	   printf("Yep");
	else
	   printf("Nope");
}
