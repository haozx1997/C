#include<stdio.h>
int gcd(int a,int b)//greatest common divisor
{
	return !a ? b : gcd(b % a, a);
}
int  lcm(int a ,int b)//lowest common multiple
{

	return (long long)a*b/gcd(a,b);//没long long 10^18
                                // int 10^9
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[101000];
		for(int i = 0 ; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		if(n == 1)//先没这个
		{
			printf("%d\n",a[0]);
			continue;
		}
		int ans = lcm(a[0],a[1]);
		for(int i = 2 ;i < n;i++)
		{
			ans = lcm(ans,a[i]);
		}
		printf("%d\n",ans);
	}
 }
