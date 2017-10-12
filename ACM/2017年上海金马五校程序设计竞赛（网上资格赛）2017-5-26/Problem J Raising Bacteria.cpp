#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans = 1;
		while((n/2) != 0)
		{
			if(n%2)
			{
				ans++;
			}
			n /= 2;
		}
		printf("%d\n",ans);
	}



 return 0;
}


