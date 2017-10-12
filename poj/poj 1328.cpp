#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct node
{
	double l,r;
	bool operator < (const node& asd) const
	{
		return l<asd.l;
	}
}p[2000];
int n,m;
int pn;
int insert(int x,int y)
{
	double xx = (double)x;
	if(y == m)
	{
		p[pn].l = xx;
		p[pn].r = xx;
	}
	else
	{
		double ca = sqrt((double)m*m-(double)y*y);
		p[pn].l = xx - ca;
		p[pn].r = xx + ca;
	}
	pn++;
	
	return 0;
}

int main()
{
	int TT = 0; 
	while(~scanf("%d%d",&n,&m))
	{
		TT++;
		pn = 0;
		if(n == 0&&m == 0)
		{
			break;
		}
		int x,y;
		int F = 0;
		for(int i = 0 ;i < n;i++)
		{
			scanf("%d%d",&x,&y);
			if(y > m)
			{
				F = 1;
			}
			insert(x,y);
		}
		printf("Case %d: ",TT);
		if(F)
		{
			printf("-1\n");
			continue;
		}
		sort(p,p+pn);
		
//		for(int i =0;i < pn;i++)
//		{
//			printf("%.2f %.2f\n",p[i].l,p[i].r);
//			
//		}
		int ans = 0;
		double rmin = (double)100000000000000000;
		for(int i =0;i < pn;i++)
		{
			if(rmin<p[i].l)
			{
				ans++;
				rmin = p[i].r;
			}
			else
			{
				rmin = min(p[i].r,rmin);
				
			}
			
		}
		ans++;
		printf("%d\n",ans);
		
		
		
	}




 return 0;
}


