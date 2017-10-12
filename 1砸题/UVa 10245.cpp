#include<bits/stdc++.h>

using namespace std;

typedef pair<double,double> P;
P p[10010];


bool cy(P a,P b)
{
	return a.second<b.second;
}

double cp(P *a,int n)
{
	if(n <= 1)
		return 100001;
	int m = n/2;	
	double x = a[m].first;
	double d = min (cp(a,m),cp(a+m,n-m));
	inplace_merge(a,a+m,a+n,cy);
	vector<P>b;
	b.clear();
	for(int i = 0;i < n;i++)
	{
		if(fabs(a[i].first - x)>=d)
		{
			continue;
		}
		for(int j = 0; j <b.size();j++ )
		{
			double dx = a[i].first - b[b.size()-j-1].first;
			double dy = a[i].second - b[b.size()-j-1].second;
			if(dy>=d)
			{
				break;
			}
			d = min(d,sqrt(dx*dx+dy*dy));
		}
		b.push_back(a[i]);
	}
	return d;
}


int main()
{
	int n;
	while(~scanf("%d",&n),n)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf",&p[i].first,&p[i].second);
		}
		sort(p,p+n);
		double ans = cp(p,n);
		if(ans>=(double)10000)
		{
			puts("INFINITY");continue;
		}
		printf("%.4f\n",ans);
	 } 




 return 0;
}


