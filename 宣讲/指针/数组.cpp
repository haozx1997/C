#include<stdio.h>

void all_add(int *a,int num_a)
{
	for(int i = 0 ;i < num_a;i++)
	{
		a[i]++;
	}
	return ;
}
void all_add_(int a[],int num_a)
{
	for(int i = 0 ;i < num_a;i++)
	{
		a[i]++;
	}
	return ;
}

int main()
{
	int n[5] = {1,2,3,4,5};
	all_add(n,5);
	for(int i = 0;i < 5;i++)
	{
		printf("%d ",n[i]);
	}
	printf("\n");
	all_add_(n,5);
	for(int i = 0;i < 5;i++)
	{
		printf("%d ",n[i]);
	}
	
}
