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
	return 0;
}
	

double banana()
{
	double ans;
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
			ans = 0.000000;
		}
		else if(d<=dd_)
		{
			ans=pi*(double)(c2.r*c2.r);
					
		}
		else 
		{
			lwtg();
			ans = c1.s+c2.s-c1.ts;		
		}
		
		return ans;
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int TT = 0;TT<T;TT++)
	{
	//	c1.r = 0;c1.ran = 0;c1.s = 0;c1.ts = 0;c1.x = 0;c1.y = 0;
	//	c2.r = 0;c2.ran = 0;c2.s = 0;c2.ts = 0;c2.x = 0;c2.y = 0;		
		int c1x,c1y,c1r,c2x,c2y,c2r;
		scanf("%d%d",&c2r,&c1r);
		scanf("%d%d",&c2.x,&c2.y);
		scanf("%d%d",&c1.x,&c1.y);
		
		double ans1,ans2,ans3,ans4;
		c1.r = c1r;
		c2.r = c1r;
		ans1 = banana();
		c1.r = c2r;
		c2.r = c2r;
		ans2 = banana();
		c1.r = c1r;
		c2.r = c2r;
		ans3 = banana();
		c2.r = c1r;
		c1.r = c2r;
		ans4 = banana();
		
		
		
		//£¡£¡£¡£¡»· £¡£¡Ïã½¶µÄ´ð°¸ 
		printf("Case #%d: %.6f\n",TT+1,ans1+ans2-ans3-ans4);
		
		
			
	}	
}
