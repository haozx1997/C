#include<stdio.h>
int main()
{
	int i = 1;
	int* ip = &i;
	printf("%d\n",i);
	*ip = 2;
	printf("%d\n",i);
 } 
