//http://blog.sina.com.cn/s/blog_71dbfe2e0101f7zb.html
//http://dev.gameres.com/Program/Abstract/Geometry.htm#矢量的概念

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)

double max(double a,double b)
{
	if(a > b)
	 return a;
	return b ; 
}
double min(double a,double b)
{
	if(a < b)
	 return a;
	return b ; 
}



struct point2d//点也是向量 
{
	double x,y;
	point2d(double x=0,double y=0):x(x),y(y){}
};

struct polygon//多边形 点的集合; 
{
	point2d pp[200];
	int size; 
};
//重载
point2d operator + (point2d a,point2d b)
{
	return point2d(a.x+b.x,a.y+b.y); 
}

point2d operator - (point2d a,point2d b)
{
	return point2d(a.x-b.x,a.y-b.y); 
}

point2d operator * (point2d a,double b)
{
	return point2d(a.x*b,a.y*b); 
}

point2d operator / (point2d a,double b)
{
	return point2d(a.x/b,a.y/b); 
}
//×乘 
//矢量叉积：
//
//　　计算矢量叉积是与直线和线段相关算法的核心部分。
//设矢量P = ( x1, y1 )，Q = ( x2, y2 )，则矢量叉积定义为由(0,0)、
//p1、p2和p1+p2所组成的平行四边形的带符号的面积，即：P × Q = x1*y2 - x2*y1，
//其结果是一个标量。显然有性质 P × Q = - ( Q × P ) 和 P × ( - Q ) = - ( P × Q )。
//一般在不加说明的情况下，本文下述算法中所有的点都看作矢量，
//两点的加减法就是矢量相加减，而点的乘法则看作矢量叉积。
//　　叉积的一个非常重要性质是可以通过它的符号判断两矢量相互之间的顺逆时针关系：
//　　若 P × Q > 0 , 则P在Q的顺时针方向。
//　　若 P × Q < 0 , 则P在Q的逆时针方向。
//　　若 P × Q = 0 , 则P与Q共线，但可能同向也可能反向。
double operator * (point2d a,point2d b)
{
	return a.x*b.y-b.x*a.y; 
	
}

//·乘
double pdp(point2d a,point2d b)
{
	return a.x*b.x+a.y*b.y;
 } 
//两线段是否香蕉(包括边界香蕉)，快速排斥&&跨立实验 
int isbanana(point2d p1,point2d p2,point2d p3,point2d p4)
{
	double s1_xl,s1_xr,s1_yu,s1_yd;
	double s2_xl,s2_xr,s2_yu,s2_yd;
	s1_xl = min(p1.x,p2.x);
	s1_xr = max(p1.x,p2.x);
	s1_yd = min(p1.y,p2.y);
	s1_yu = max(p1.y,p2.y);
	s2_xl = min(p3.x,p4.x);
	s2_xr = max(p3.x,p4.x);
	s2_yd = min(p3.y,p4.y);
	s2_yu = max(p3.y,p4.y);
//	printf("%lf %lf %lf %lf\n",s1_xl,s1_xr,s1_yu,s1_yd);
//	printf("%lf %lf %lf %lf\n",s2_xl,s2_xr,s2_yu,s2_yd);
	double xl,xr,yu,yd;
	xl = max(s1_xl,s2_xl);
	xr = min(s1_xr,s2_xr);
	yd = max(s1_yd,s2_yd);
	yu = min(s1_yu,s2_yu);
//	printf("%lf %lf %lf %lf\n",xl,xr,yu,yd);
	if(xl>xr||yu<yd)
	{
		printf("no\n");
		return 0;
	}
	if(pdp(((p3-p1)*(p2-p1)),((p4-p1)*(p2-p1)))<0)
	 {
	 	printf("yes\n");
	 	return 1;
	 }
	printf("no\n");
		return 0;
}
//clockwise;也可以判断a b c是否在同一直线或c在ab那一侧
// ab有顺序 
int isclw(point2d a,point2d b,point2d c)
{
	double ans = (a-b)*(b-c);
	if(ans<0)//叉乘< 0 为顺时针返回1 
	 return 1;
	if(ans==0)//同一直线  
	 return 0;
	if(ans>0)
	 return -1;
	 
 } 
//int main()
//{
//	point2d a,b,c;
//	a = point2d(0,0);
//	b = point2d(1,0);
//	c = point2d(1,-1);
//	printf("%d\n",isclw(a,b,c));
//}
//求两直线交点
point2d  line_cross(point2d a,point2d b,point2d c,point2d d)
{
//	double a1,b1,c1,a2,b2,c2;
//	a1 = a.y - b.y;
//	b1 = b.x - a.x;
//	c1 = a.x*b.y - b.x*a.y;  //a*b;
//	a2 = c.y - d.y;
//	b2 = d.x - c.x;
//	c1 = c.x*d.y - d.x*c.y;//c*d; 
//	double dd = a1 * b2 - a2 * b1;
//	printf("dd %f\n",dd);
//	return point2d((b1*c2-b2*c1)/dd,(c1*a2-c2*a1)/dd);
//	a1 = (a.y - b.y) / (a.x - b.x);
//	b1 = a.y - a1*(a.x);
//	a2 = (c.y - d.y) / (c.x - d.x);
//	b2 = c.y - a1*(c.x);
//	double xx = (b1 - b2) / (a2 - a1);
//	double yy = a1*xx+b1;
//	return point2d(xx,yy);
//	double lamuda = (fabs((d-a)*(b-a)))/(fabs((c-a)*(b-a)));
//	double xx = c.x+lamuda*(d.x-c.x);
//	double yy = c.y+lamuda*(d.y-c.y);
// 	return point2d(xx,yy);
//  上边都TM不能用 
 	double s2 = fabs((d-a)*(b-a))/2;
 	double s1 = fabs((c-a)*(b-a))/2;
 	return point2d((d.x*s1+c.x*s2)/(s1+s2)
	 	,(d.y*s1+c.y*s2)/(s1+s2));  
}

//一个多边形与一个半平面的交集 polygon & half
polygon p_h(polygon po,point2d a,point2d b)
{
//	printf("po.size %d\n",po.size);
	 polygon ans;
	 ans.size = 0;
	 for(int i = 0;i < po.size;i++)
	 {
	 	if(isclw(a,b,po.pp[i])>=0)
	 	{
	 		ans.pp[ans.size++] = po.pp[i];
		 }
		else if(isclw(a,b,po.pp[i])<0
			&&isclw(a,b,po.pp[(i+1)%po.size])>0)
		{
			ans.pp[ans.size++] = line_cross(a,b,
				po.pp[i],po.pp[(i+1)%po.size]);
		 }	 
	 }
//	 printf("ans %d\n",ans.size);
	 return ans;
}


void see(polygon pol)
{
	printf("size %d\n",pol.size);
	for(int i = 0;i < pol.size;i++)
	 {
	 	printf("%.2f %.2f \n",pol.pp[i].x,pol.pp[i].y);
	 }
}
 //多边形有无核 
int  ispolcer(polygon pol)
{

	polygon now = pol;
	point2d a,b;
	for(int i = 0;i < pol.size;i++)
	{	
		
		now = p_h(now,pol.pp[i],pol.pp[(i+1)%pol.size]);
	//	printf("!ans %d",now.size);
	//	see(now);
		if(now.size == 0)
		 {
		 	return 0;
		 }
	//	printf("i %d\n",i);
	}
	
	return 1; 
 } 
 
 
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		polygon pol;
		pol.size = n;
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf",&pol.pp[i].x,&pol.pp[i].y);
		}
		if(ispolcer(pol))
		 printf("YES\n");
		else
		 printf("NO\n"); 
		
	}
}
 
 
