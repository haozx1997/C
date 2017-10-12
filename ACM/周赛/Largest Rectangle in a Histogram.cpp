#include<stdio.h>
int main()
{
	int n,i,j;
	int ll[100004],rr[100004];
	long long x,a[100004];
    scanf("%d",&n);
	
		for(i=1;i<=n;i++)
		 {
		 	scanf("%I64d",&a[i]);
		 	rr[i]=ll[i]=i;
		 }
		 a[0]=a[n+1]=-1;
		for(i=1;i<=n;i++)
		 {
		 	while(a[ll[i]-1]>=a[i]) ll[i]=ll[ll[i]-1];

		 }
		 for(i=n;i>=1;i--)
		 {
		 	while(a[rr[i]+1]>=a[i]) rr[i]=rr[rr[i]+1];

		 }
		
		 x=0;
		for(i=1;i<=n;i++)
		 {
		 	
		 	x=x>a[i]*(rr[i]-ll[i]+1)?x:a[i]*(rr[i]-ll[i]+1);
		 		
		  } 
		  printf("%I64d\n",x);
	return 0;
}
