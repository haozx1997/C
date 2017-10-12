#include<bits/stdc++.h>

using namespace std;

int main()
{
	int pre ;
	int ans = 0;
	int a1,a2;
	int now;
	scanf("%d",&pre);
	while(~scanf("%d",&now))
	{
		if(ans<=(now-pre))
		{
			a1 = pre;
			a2 = now;
			ans = now - pre;
		}
	}

printf("%d %d %d\n",ans,pre,now);


 return 0;
}


