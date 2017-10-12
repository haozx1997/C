#include<stdio.h>
long long YHsTriangle(int n,int m)
{
	long long a[40][40],i,j;
	for(i=0;i<35;i++)
	 {
	 	a[i][0]=1;
	 	a[i][i]=1;
	 }
	 for(i=2;i<35;i++)
	   for(j=1;j<i;j++)
	    a[i][j]=a[i-1][j-1]+a[i-1][j];
	return a[n][m];
 } 
int main()
{
	printf("我大杨辉三角！！！还有谁！！！\n");
	int i,j;
	for(i=0;i<35;i++)
	   {
	   for(j=0;j<=i;j++)
	     printf("%lld ",YHsTriangle(i,j));
	   printf("\n");
	   }
	return 0;
	    
}
