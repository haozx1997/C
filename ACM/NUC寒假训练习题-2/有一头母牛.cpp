#include<stdio.h>




int main()
{
	int n,i,a1,a2,a3,a4;
	while(scanf("%d",&n),n)
	 {
	 	a1=a2=a3=0;a4=1;
	 	for(i=0;i<n;i++)
	 	 {
	 	 	a4+=a3;a3=a2;a2=a1;
	 	 	a1=a4;
	 	 	
		  }
		  printf("%d\n",a1+a2+a3);
	 	
	 }
 } 
