#include<stdio.h>
void swap1(int x,int y)//����+���� 
{
	int t;
	t = x;
	x = y;
	y = t;
	printf("swap1  x : %d y : %d\n",x,y);	
} 
void swap2(int* x,int* y)//����+���� 
{
	int t;
	t = *x;
	*x = *y;
	*y = t;	
	printf("swap2  x : %d y : %d\n",*x,*y);	
}
int main()
{
	int a = 1,b = 2;
	printf("������ a : %d b : %d\n",a,b);
	swap1(a,b); 
	printf("������ a : %d b : %d\n",a,b);
	swap2(&a,&b); 
	printf("������ a : %d b : %d\n",a,b);
	return 0;
}


