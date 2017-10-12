#include<stdio.h>
int main()
{
	int n;
	char wu;
	int u,p,i;
	scanf("%d",&n);
	while(n--)
	 {
	 	for(;getchar()=='=';)
	 	 {
	 	 	scanf("%d",&u);
	 	 	printf("%d",u);
	 	 	if(getchar()=='V')
	 	 	 break;
		  }
		  getchar();
	 }
 } 
