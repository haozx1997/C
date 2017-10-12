#include<stdio.h>
int gcd(int a,int b)
{
	int y,t;
	if(b>a)
	 {
	 	t=a;
	 	a=b;
	 	b=t;
	 }
	while(a%b)
	 {
	 	y=a%b;
	 	a=b;
	 	b=y;
	 }
	return b;
}
int main()
{
	int a,b;
	printf("请输入两个正整数：");
	scanf("%d%d",&a,&b);
    printf("%d与%d的最大公约数为：%d\n",a,b,gcd (a,b) );
    return 0;
}
