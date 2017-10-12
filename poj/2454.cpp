#include<stdio.h>
#include<algorithm>

#define ll long long
using namespace std;
int n;
struct node
{
	int i,v;
	bool operator < (const node& f) const
	{
		return v < f.v;
	}
}a[100100],w[100100],q[100100],t;

int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < 3*n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].i = i+1;
		}
		sort(a,a+n*3);
//		for(int i = 0;i < 3*n;i++)
//		{
//			printf("%d %d\n",a[i].i,a[i].v);
//		}
		
		for(int i = 0;i < n;i++)
		{
			printf("%d\n",a[i].i);
		}
		ll s1 = 0;
		ll s2 = 0;
		int ii = 0;
		for(int i = n; i < n*3;i+=2)
		{
			q[ii++] = a[i];
			s1 += a[i].v;
		}
		ii = 0;
		for(int i = n+1; i < n*3;i+=2)
		{
			w[ii++] = a[i];
			s2 += a[i].v;
		}
		while(s1<=500*n||s2<=500*n)
		{
			int qw = rand()%n;
			int wq = rand()%n;
			s1 -= q[qw].v;
			s2 += q[qw].v;
			s1 += w[wq].v;
			s2 -= w[wq].v;
			t = q[qw];
			q[qw] = w[wq];
			w[wq] = t;
		}
		for(int i = 0;i < n;i++)
		{
			printf("%d\n",q[i].i);
		}for(int i = 0;i < n;i++)
		{
			printf("%d\n",w[i].i);
		}
		
		
		
		
		
		
	}




 return 0;
}


