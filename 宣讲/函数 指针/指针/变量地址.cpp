#include<stdio.h>

int main()
{
	int a = 1;
	int c = 2;
	int e = 3; 
	printf("a��ַ %lld\n",&a);
	printf("c��ַ %lld\n",&c); 
	printf("e��ַ %lld\n",&e);
	int *a_p = &a;
	printf("a_p ��ָ��ֵ%d a_p��ֵ %lld\n",*a_p,a_p);
	printf("%lld\n",a_p-1);
	printf("%d\n",*(a_p-1));
	
}
