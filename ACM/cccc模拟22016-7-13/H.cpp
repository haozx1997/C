#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<math.h>
 

using namespace std;
const double pi = acos(-1); 

struct cyc
{
	int x,y;
	int r;
	double ran;
	double s;
	double ts;
};
cyc t,c1,c2;
double d;

double dis(int x1,int y1,int x2,int y2)
{
	double ans1;
	double ans2;
	double ans;
	ans1 = (double)(x2-x1)*(x2-x1);
	ans2 = (double)(y2-y1)*(y2-y1);
	ans = sqrt(ans1 + ans2);
	return ans;
}
int abs(int a)
{
	if(a<0)
	 return 0 - a;
	return a; 
}

double findx()
{
	
	double x;
	c2.ran = acos(((c2.r*c2.r)+(d*d)-(c1.r*c1.r))/(double)(2*d*c2.r));
	c1.ran = acos(((c1.r*c1.r)+(d*d)-(c2.r*c2.r))/(double)(2*d*c1.r));
	
	x = c2.r*(double)sin(c2.ran);
	return x;
	
}
double lwtg()//long way to go
{	
	double xx = findx();
	c1.s = c1.r*c1.r*c1.ran;
	c2.s = c2.r*c2.r*c2.ran;
	c1.ts = c1.r*d*sin(c1.ran);
	
}
	

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	//	c1.r = 0;c1.ran = 0;c1.s = 0;c1.ts = 0;c1.x = 0;c1.y = 0;
	//	c2.r = 0;c2.ran = 0;c2.s = 0;c2.ts = 0;c2.x = 0;c2.y = 0;		
		scanf("%d%d%d",&c1.x,&c1.y,&c1.r);
		scanf("%d%d%d",&c2.x,&c2.y,&c2.r);
		if(c1.r<c2.r)
		{
			t = c1;c1 = c2;c2 = t;
		}
		d = dis(c1.x,c1.y,c2.x,c2.y);
	//	printf("dis = %.2f\n",d);
		double dd = (double)c1.r + c2.r;
		double dd_ = (double)abs(c1.r - c2.r);
		if(d>=dd)
		{
			printf("0.00\n");
		}
		else if(d<=dd_)
		{
			printf("%.2f\n",pi*(double)(c2.r*c2.r));;
					
		}
		else 
		{
			lwtg();
			printf("%.2f\n",c1.s+c2.s-c1.ts);		
		}
		
			
	}	
}
