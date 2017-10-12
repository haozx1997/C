#include<stdio.h>
int main()
{
	long a[100][100],i,j,x,n;
	n=1;
	for(i=1;i<100;i++)
	 for(j=1;j<i+1;i++)
	 {
	 	a[i][j]=n*2;
	 	n++;
	 }
	 for(i=1;i<100;i++)
	 {
	 for(j=1;j<i+1;i++)
	  printf("%d",a[i][j]);
     printf("\n");
	 }
	return 0;
}
