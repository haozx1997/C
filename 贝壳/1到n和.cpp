#include<stdio.h>
int main()
{
	int i,n,sum=0;
	printf("Please input the nature number n��");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	sum=sum+i;
	printf("sum is %d\n",sum);
	return 0;
 } 
