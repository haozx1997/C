#include<stdio.h>
long long gcd(long long x,long long y)
{
	 return !y? x : gcd(y,x%y);
}
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long a[105];
		long long ans;
		for(int i=0;i<n;i++)
		 scanf("%lld",&a[i]);
		 int i;
		 ans=a[0]*a[1]/gcd(a[0],a[1]);
		for(i=2;i<n;i++) 
		{
			ans=ans*a[i]/gcd(ans,a[i]);
			
		}
		printf("%lld\n",ans);
	}
 } 
