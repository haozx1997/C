#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[10010];

int main()
{
	int n;
	
	while(~scanf("%d",&n))
	{int sum = 0;
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int ave =round((double)sum/n);
		
		ll ans = 0ll;
	//	printf("	%d\n",ave);
		for(int i = 0 ; i < n;i++)
		{
			ll ai = ((ll)a[i]-ave)*((ll)a[i]-ave);
			ans+=ai;
		}
		printf("%I64d\n",ans);
		
		
	}

/*
2
4 8
3
1 1 3

3
4 2 5

4
-100 -100 -100 -100


*/


 return 0;
}


