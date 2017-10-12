#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x1,y1,x2,y2,x,y;
	while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x,&y))
	{
		int xc,yc;
		xc = abs(x1-x2);
		yc = abs(y1-y2);
		if(xc%x||yc%y)
		{
			printf("NO\n");
			continue;
		}
		int xx,yy;
		xx = xc/x;
		yy = yc/y;
		if((xx%2)&&(yy%2))
		{
			printf("YES\n");
			continue;
		}
		if(!(xx%2)&&!(yy%2))
		{
			printf("YES\n");
			continue;
		}
		
		printf("NO\n");
	}




 return 0;
}


