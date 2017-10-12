#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
	long long n[10];
	while(~scanf("%I64d%I64d%I64d",&n[0],&n[1],&n[2]))
	{
		
		long long ans = (long long )0;
		sort(n,n+3);
		if(n[2]>(n[1]+n[0])*2)
		{
			ans = n[0]+n[1];
		}
		else
		{
			ans = (n[0]+n[1]+n[2])/3;
		}
		printf("%I64d\n",ans);
	}




 return 0;
}


