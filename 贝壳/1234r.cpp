#include<stdio.h>
int main()
{
	int a;
	while(~scanf("%d",&a))
	{
		printf("%d\n",a<<1);//乘二 
		printf("%d\n",a>>1);//除二 
		printf("%d\n",a<<1|1);// |1意思是加一 
		
	}
 } 
