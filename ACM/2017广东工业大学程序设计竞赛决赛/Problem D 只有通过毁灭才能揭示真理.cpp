#include<bits/stdc++.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		long long sum = 0;
		int r = a/30;
		sum = (long long)a*b+r*c;
		printf("%lld\n",sum);
				
	}
}
