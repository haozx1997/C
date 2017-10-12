#include<stdio.h>
int a[40][40];
int YHsTriangle(int n,int m)
{
	int i,j;
	for(i=0;i<40;i++)
	 {
	 	a[i][0]=1;
	 	a[i][i]=1;
	 }
	 for(i=2;i<40;i++)
	   for(j=1;j<i;j++)
	    a[i][j]=a[i-1][j-1]+a[i-1][j];
	return a[n][m];
 } 
 
void print(int nn)
{
	int i,j;
	for(i=0;i<nn;i++)
	   {
	   for(j=0;j<=i;j++)
	     {
	     	printf("%d",a[i][j]);
	     	if(j!=i)
	     	 printf(" ");
		 }
	   printf("\n");
	   }
	 printf("\n");  
}
 
int main()
{
	int num;
	YHsTriangle(38,38);
	while(scanf("%d",&num))
	{
	
		
		print(num);
	}
	return 0;
	    
}
