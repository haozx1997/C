#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		double c;
		double v[100010];
		scanf("%lld%lf",&n,&c);
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%*s%*s",&v[i]);
		}
		sort(v,v+n);
		long long qn;
		scanf("%lld",&qn);
		long long  k;
		double t;
		for(int i = 0;i < qn;i++ )
		{
			scanf("%lf%lld",&t,&k);
//			
			k--;
			k = n - k;
			printf("%.3lf\n",(double)sqrt(2*c*t+v[k]*v[k]));
		}
		
	}
}
