#include<stdio.h>
int main()
{
	int i,j,sum=0;
	for(i=1;i<101;i++)
	 {
	 	for(j=1;j<=i;j++)
	 	 sum+=j;
	 }
	 printf("%d",sum);
 } 
