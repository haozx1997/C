#include<stdio.h>
int main()
{
	int a[5],i,j,k,t;
	for(i=0;i<5;i++)
	  scanf("%d",&a[i]);
	for(i=0;i<4;i++)
	 {
	 	k=i;
	 	for(j=i+1;j<5;j++)
	 	  if(a[j]>a[k])k=j;
	 	if(k!=i)
	 	  {
		   t=a[i];a[i]=a[k];a[k]=t;
		   }
	 }
	 for(i=0;i<5;i++)
	  printf("%d ",a[i]);
	 
}
