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
	printf("������������������");
	scanf("%d%d",&a,&b);
    printf("%d��%d�����Լ��Ϊ��%d\n",a,b,gcd (a,b) );
    return 0;
}
