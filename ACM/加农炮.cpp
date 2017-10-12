#include<stdio.h>
long J(long a)
{   
    int i,sum=0;
    for(i=1;i<=a;i++)
	 sum=sum+i; 
	return(sum);
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	 {
	  	printf("%d",J(n));
	  printf("\n");
	 } 
	return 0 ;
}
