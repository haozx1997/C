#include<stdio.h>
main()
{
	int s,a,b,c,d,e;/*����һ��5λ�����ж����ǲ��ǻ�����������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ*/
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
