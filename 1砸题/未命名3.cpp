
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
	double x,y,v;
	double l;
	bool operator < (const node& aa )const
	{
		return l<aa.l;
	}
}p[51000];

vector<node> u,d;
vector<node> :: iterator it;
vector<node> :: reverse_iterator rit;




double cc (node a,node b)
{
	
	return a.x*b.y-b.x*a.y;

}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		ll sum = 0;
		scanf("%d",&n);
		u.clear();d.clear();
		for(int i = 1;i <= n;i++ )
		{
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].v);
			p[i].l =  ( p[i].x * 1.0 / sqrt(1.0 *p[i].x*p[i].x+1.0 * p[i].y*p[i].y) );
			if(p[i].y>=0)
			{
				u.push_back(p[i]);
			}
			else
			{
				
				d.push_back(p[i]);
			}
			sum+=p[i].v;
		}
		
		
		//a.x*b.y-b.x*a.y
		sort(u.begin(),u.end());
		sort(d.begin(),d.end());
//		for(it = u.begin();it!=u.end();it++)
//		{
//			printf("%d %d\n",(*it).x,(*it).y);
//		}
		
//		puts("FFF");
		for(rit = d.rbegin();rit!=d.rend();rit++)
		{
			u.push_back(*rit);
		}
		
		
		
		
		
		//sort(p+1,p+1+n);
//		for(it = u.begin();it!=u.end();it++)
//		{
//			printf("%d %d\n",(*it).x,(*it).y);
//		}
		
	
		ll ans = 0;
		int cl = 0,cr = 0;
		ll sum1 = u[cr].v;
		ll sum2 = 0ll;
		
//		for(int i =0;i < n;i++)
//		{
//			printf("%d %.2f %.2f %.2f\n",i,u[i].x,u[i].y,u[i].v);
//		}
		/*
2
2
1 1 1
1 -1 1
3
1 1 1
1 -1 10
-1 0 100

*/
		while(cl<n)
		{
			while(cc(u[cl],u[cr])<0||cl == cr)
			{
			//	printf("%d %d %d %.2f\n",cl,cr,(cr+1)%n,cc(u[cl],u[(cr+1)%n]));
				if(cc(u[cl],u[(cr+1)%n])>=0)
				{
					break;
				}
				cr = (cr+1)%n;
				sum1 += u[cr].v;
			}
	//		printf("%d %d %lld\n",cl,cr,sum1*(sum-sum1));
			ans = max(ans,sum1*(sum-sum1));
			sum1 -= u[cl].v;
			cl++;	 
			
		}
		printf("%I64d\n",ans);
		
			
			
			

	}




 return 0;
}

/*
2
20

5 1 1
5 2 1
5 3 1
5 4 1
5 5 1

-5 1 1
-5 2 1
-5 3 1
-5 4 1
-5 5 1

5 -1 1
5 -2 1
5 -3 1
5 -4 1
5 -5 1

-5 -1 1
-5 -2 1
-5 -3 1
-5 -4 1
-5 -5 1
2
10


5 -1 1
5 -2 1
5 -3 1
5 -4 1
5 -5 1

-5 -1 1
-5 -2 1
-5 -3 1
-5 -4 1
-5 -5 1

10


-5 1 1
-5 2 1
-5 3 1
-5 4 1
-5 5 1

5 1 1
5 2 1
5 3 1
5 4 1
5 5 1




*/	




