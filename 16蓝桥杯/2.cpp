#include<stdio.h>
int main()
{
	int age=1,i,j,sum;

		for(;age<100;age++)
		 {
		 	sum=0;
		 	for(i=age;;i++)
		 	 {
		 	 	sum+=i;
		 	 	if(sum>236) break;
		 	 	if(sum==236) printf("%d",age);
			  }
		 }
	
 } 
