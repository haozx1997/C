#include<bits/stdc++.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		c /= 4;
		c = c - (c - a/2) - (c - b);
		printf("%d\n",c);
				
	}
}
