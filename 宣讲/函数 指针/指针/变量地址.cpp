#include<stdio.h>

int main()
{
	int a = 1;
	int c = 2;
	int e = 3; 
	printf("a地址 %lld\n",&a);
	printf("c地址 %lld\n",&c); 
	printf("e地址 %lld\n",&e);
	int *a_p = &a;
	printf("a_p 所指的值%d a_p的值 %lld\n",*a_p,a_p);
	printf("%lld\n",a_p-1);
	printf("%d\n",*(a_p-1));
	
}
