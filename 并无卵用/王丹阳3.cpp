#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x<2)
	 printf("%d",x+1);
	if(x<4&&x>=2)
	 printf("%d",(x-2)*(x-2)+1);
	if(x>=4)
	 printf("%d",(x-2)*(x-2)+(x-1)*(x-1)*(x-1));
	return 0; 
	 
 } 
