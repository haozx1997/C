#include<stdio.h>
int fun(int x)//声明+定义 
{
	return x+1;	
}
int main()
{
	int a = 2;
	printf("%d\n",fun(1));//调用 
	printf("%d\n",1+1); 
	printf("%d\n",a); 
	return 0;
}


