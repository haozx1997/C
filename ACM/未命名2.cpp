#include<stdio.h>
void paixu(int a[1001])
{
	int k,i;
	for(i=0;i<100;i++)
	 {
	 	k=i;
	 	for(j=i+1;j<100;j++)
	 	  if(a[j]>a[k])k=j;
	 	if(k!=i)
	 	  t=a[i];a[i]=a[k];a[k]=t;
	 }
}
int main()
{
	int a[1001],n,i;
	char name[1001][20];
	while(scanf("%d",n),n)
	{
		for(i=n;i;i--)
		 scanf("%d %s",a[i],name[i]);
		
		
	}
