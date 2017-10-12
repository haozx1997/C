#include<bits/stdc++.h>

using namespace std;

struct node
{
	int a,b;
	double t;

	
}x[100100];

const double eps = 1e-6;


int n,p;
int main()
{
	while(~scanf("%d%d",&n,&p))
	{
		long long suma = 0;
	
		
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d",&x[i].a,&x[i].b);
			
			suma += (long long)x[i].a;
		
			
		}
		if(suma <= (long long)p)
		{
			printf("-1\n");
			continue;
		}
		double l = 0.0,r = 1e18;
		double mid;
	//	printf("%.10f\n",(r-l)<=eps);
		while((r-l)>=eps)
		{
			mid = (double)((double)r+l)/2;
	//		printf("%.10f\n",mid);
			double sumb = mid*p;
			int F = 0;
			for(int i = 0;i < n;i++)
			{
				double b = x[i].b - x[i].a*mid;
				if(b < 0) sumb += b;
				if(sumb < 0) 
				{
					F = 1;
					break;
				}
			}
			
			if(F)
			{
				r = mid-0.000001;
			}
			else
			{
				l = mid+0.000001;
			}
			
		}
		printf("%.10f\n",mid);
		
	}
	



 return 0;
}


