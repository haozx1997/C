#include<stdio.h>
int fun(int x)//ÉùÃ÷+¶¨Òå 
{
	x = x + 1;
	return x;	
}
int main()
{
	int a = 2;
	printf("%d\n",a);
	printf("%d\n",fun(a)); 
	printf("%d\n",a); 
	return 0;
}


