#include<stdio.h>
int f(int n)
{
	if(n>0&&n<4)
	 return 1;
	return f(n-3)+f(n-1);
 } 
 int main()
 {
 	int n;
 	while(scanf("%d",&n),n)
 	 printf("%d\n",f(n+2));
 		
	 
 }
