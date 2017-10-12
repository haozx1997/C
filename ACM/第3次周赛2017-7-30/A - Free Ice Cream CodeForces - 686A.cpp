#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long x;
	while(~scanf("%d%I64d",&n,&x))
	{
		long long d;
		char s[10];
		int sad = 0;
		for(int i = 0; i < n;i++)
		{
			scanf("%s%I64d",s,&d);
			if(s[0] == '+')
			{
				x+=d;
			}
			else
			{
				if(d<=x)
				{
					x-=d;
				}
				else
				{
					sad++;
				}
			}
		}
		printf("%I64d %d\n",x,sad);
	 } 




 return 0;
}


