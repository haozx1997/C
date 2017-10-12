#include<stdio.h>
int i,n;
double a[3003],c[3003],sum;

int main()
{
	int T,b;
	scanf("%d",&T);
	while(T--)
	{
	
		scanf("%d",&n);
		scanf("%lf",&a[0]);
		scanf("%lf",&a[n+1]);
		for(i=1;i<n+1;i++)
		 scanf("%lf",&c[i]);
		sum=n*a[0]+a[n+1]; 
		for(i=1;i<=n+1;i++)
		 sum-=2*(n+1-i)*c[i];
		sum =sum/(n+1);
		printf("%.2f\n",sum);
		if(T)printf("\n");
	}
	return 0;
}
