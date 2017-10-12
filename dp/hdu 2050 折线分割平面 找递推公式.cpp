//http://blog.csdn.net/zhouhong1026/article/details/7854948
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		long long ans = (long long)1+(long long)(n*2-1)*n;
		printf("%lld\n",ans);
	}
}
