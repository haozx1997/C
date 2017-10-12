#include<stdio.h>
int main()
{
	int n,i;
	long long a,b,c;
	while(scanf("%d",&n),n!=-1)
	 {
	 	a=1;b=1;
	 	if(n==1||n==2)
	 	 {
	 	 	printf("1\n");
	 	 	continue;
		  }
	 	if(!n)
		 {
	 	 	printf("0\n");
	 	 	continue;
		  }
		for(i=0;i<n-2;i++)
		 {
		 	c=a+b;
		 	a=b;
		 	b=c;
		 }
		 printf("%I64d\n",c);
	 }
 } 
