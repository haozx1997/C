#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<10;i++)
	 {
	    for(k=0;k<9-i;k++)
	 	    printf(" ");
	 	for(j=0;j<i*2-1;j++)
	 	    printf("%d",i);          	
	 	printf("\n");
	 }
}
