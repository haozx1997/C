#include<stdio.h>

int main()
{
	int n[5] = {1,2,3,4,5};
	int* p = n;
	for(int i = 0;i < 5;i++)
	{
		printf("%d 的地址 %lld \n",n[i],n+i);//个int 是4个字节
		
	}
	for(int i = 0;i < 5;i++)
	{
		printf("%lld 这个地址的变量的值%d \n",p+i,*(p+i));
		
	}
	for(int i = 0;i < 5;i++)
	{
		printf("%d\n",p[i]);
		
	}	
	
	
}
