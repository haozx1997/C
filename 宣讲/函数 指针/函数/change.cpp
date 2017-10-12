#include<stdio.h>
int b;
int change(int x) 
{
	return x+1;
}
void change2()
{
	b = b + 1;
	return;
}
int main()
{
	int a = 1;
	b = 10;
	a = change(a);
	change2();
	printf("%d\n",a);
	printf("%d\n",b);
	return 0;
}


