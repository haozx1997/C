#include<stdio.h>
int main()
{//12 2 3 4 21 2 3 4 23 2 3 4 45 2 3 4
	int a[4][4] ,i,j,t,max;
	for(i=0;i<4;i++)
	 for(j=0;j<4;j++)
	 scanf("%d",&a[i][j]);
	 for(i=0;i<4;i++)
	 {
	 for(j=0;j<4;j++)
	 printf("%5d",a[i][j]);
	printf("\n"); }
	for(i=0;i<4;i++)
	 {
	  for(j=0;j<3;j++)
	   {
	 	if(a[i][j]>a[i][j+1])
	 	 {
	 	 	t=a[i][j];
	 	 	a[i][j]=a[i][j+1];
	 	 	a[i][j+1]=t;
		  }
		  
	   }
	 printf("%5d",a[i][j]);
     }
}
