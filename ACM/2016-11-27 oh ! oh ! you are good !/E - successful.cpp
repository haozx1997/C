#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MaxInt 0x3f3f3f

using namespace std;


int main()

{
	freopen("1.in","r",stdin);
	int r,h;
	while(~scanf("%d%d",&r,&h))
	{
		int ans = h/r*2;
		double left = double(h%(r));
		if(left>=((double)r/2*sqrt(3)))
		{
			ans += 3;
		}
		else if(left>=((double)r/2))
		{
			ans += 2;
		}
		else
		{
			ans += 1;
		}
		printf("%d\n",ans);
	}
}
