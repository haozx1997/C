#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N=0,n,i,j,t,a[55];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		 scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
		{
		
		 for(j=0;j<n-1-i;j++)
		 if(a[j]>a[j+1])
		 {
		 	t=a[j];a[j]=a[j+1];a[j+1]=t;
		 	N++;
		 }
	}
		
		printf("Optimal train swapping takes %d swaps.\n",N); 
	}
 } 
