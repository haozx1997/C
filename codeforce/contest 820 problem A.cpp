#include<bits/stdc++.h>

using namespace std;

int main()
{
	int c, v0, v1, a , l ;
	while(~scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l))
	{
		int ans = 0;
		int now = 0;
		while(1)
		{
			now += v0;
			ans++;
			if(now>=c)
			{
				break;
			}
			v0+=a;
			v0 = min(v0,v1);
			now-=l;
		}
		printf("%d\n",ans);
	}
 return 0;
}
/*
5 5 10 5 4
12 4 12 4 1
15 1 100 0 0
*/

