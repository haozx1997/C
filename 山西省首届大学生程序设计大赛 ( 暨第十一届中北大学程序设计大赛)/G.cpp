#include<stdio.h>

int gcd(int a,int b)
{
	return !b? a:gcd(b,a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t = 0;t<T;t++)
	{
		int l,h;
		scanf("%d%d",&l,&h);
		int s = gcd(l,h);
		
		int ans = l*h/(s*s);
		printf("case %d: %d\n",t+1,ans);
		
	}
}
