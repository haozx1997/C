#include<stdio.h>
int main()
{
	int n,i;
	while(scanf("%d",&n),n)
		while(n>1)
		{
			(n%2)?n=n*3+1:n=n/2;
			printf("%d ",n);
		}
	
 } 
