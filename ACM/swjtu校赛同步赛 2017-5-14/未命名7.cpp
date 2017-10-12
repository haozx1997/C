#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n ;
	while(~scanf("%d",&n))
	{
		int ans = 0,a;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			ans += (a*(i+1));
		}
		printf("%d\n",ans);
	}





 return 0;
}


