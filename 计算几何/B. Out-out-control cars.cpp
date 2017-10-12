/**
 *               ii.                                         ;9ABH,
 *              SA391,                                    .r9GG35&G
 *              &#ii13Gh;                               i3X31i;:,rB1
 *              iMs,:,i5895,                         .5G91:,:;:s1:8A
 *               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
 *                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
 *                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
 *               :SB9s:,............................,,,.,,,SASh53h,1G.
 *            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
 *          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
 *        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
 *       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
 *      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
 *      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
 *      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
 *      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
 *     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
 *     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
 *    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
 *   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
 *  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
 *  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
 *  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
 *  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
 *  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
 *   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
 *    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
 *     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
 *      ,8X5;   .     .......                                       ,;iihS8Gi
 *         1831,                                                 .,;irrrrrs&@
 *           ;5A8r.                                            .:;iiiiirrss1H
 *             :X@H3s.......                                .,:;iii;iiiiirsrh
 *              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
 *             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
 *             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
 *            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
 *            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
 */
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
	point2d pp[1010];
	int size;
};
long long isbanana(point2d p1,point2d p2,point2d p3,point2d p4);
long long fun(point2d a,point2d b,point2d c,point2d d);
int isclw(point2d a,point2d b,point2d c);
point2d  line_cross(point2d a,point2d b,point2d c,point2d d);
polygon p_h(polygon po,point2d a,point2d b);
polygon p_hop(polygon po,point2d a,point2d b);
void see(polygon pol);
int  ispolcer(polygon pol);
double dis(point2d a,point2d b);
void see_p(point2d a);

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
 double dis(point2d a,point2d b)
{
	return fabs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 }
//两线段是否平行
int isl_l(point2d aa,point2d bb,point2d cc,point2d dd)
{
	point2d ab = aa-bb;
	point2d cd = cc-dd;


	if(cd*ab)
	{
		return 0;
	}
	return 1;
 }
//int main()
//{
//
//	point2d a,b,c,d;
//	while(~scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y))
//	{
//		scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
//		printf("is %d\n",isl_l(a,b,c,d));
//
//	}
//}

//两线段是否香蕉(包括边界香蕉)，快速排斥&&跨立实验
long long isbanana(point2d aa,point2d bb,point2d cc,point2d dd)
{
	
	
//	printf("1 %.2f %.2f %.2f %.2f \n",aa.x,aa.y,bb.x,bb.y);
//	printf("2 %.2f %.2f %.2f %.2f \n",cc.x,cc.y,dd.x,dd.y);
	
	
	long long f1,f2;
    f1=fun(aa,bb,cc,dd);
    f2=fun(cc,dd,aa,bb);
    if((f1==1&&f2==1)||f1==0||f2==0||(f1==0&&f2==0))
       return 1;
    else
       return 0;
}
long long fun(point2d a,point2d b,point2d c,point2d d)
{
    point2d p[3];
    long long flag,m,n;
    p[0].x=b.x-a.x;
    p[0].y=b.y-a.y;
    p[1].x=c.x-a.x;
    p[1].y=c.y-a.y;
    p[2].x=d.x-a.x;
    p[2].y=d.y-a.y;
    m=(p[0].x*p[1].y-p[0].y*p[1].x);
    n=(p[0].x*p[2].y-p[0].y*p[2].x);
    if((m%1000)!=0)
        m=m%1000;
    else
    {
        while((fabs((double)m/10))>10)
            m=m/10;
    }
    if((n%1000)!=0)
        n=n%1000;
    else
    {
        while((fabs((double)n/10))>10)
            n=n/10;
    }
    if(n*m<0)
        flag=1;
    else if(m*n==0)
    {
        if((c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x))&&(c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y))||(d.x>=min(a.x,b.x)&&d.x<=max(a.x,b.x))&&(d.y>=min(a.y,b.y)&&d.y<=max(a.y,b.y)))
            flag=0;
        else
            flag=-1;
    }
    else
        flag=-1;
    return flag;
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
 
 
int is_in(point2d a,point2d b,point2d c,point2d d,point2d in)//abcd为矩形 
{
//	printf("1 %.2f %.2f %.2f %.2f \n",a.x,a.y,b.x,b.y);
//	printf("2 %.2f %.2f %.2f %.2f \n",c.x,c.y,d.x,d.y);
//	printf("in %.2f %.2f % \n",in.x,in.y);
	
	if(isclw(a,b,in) == 0)
	{
		return 1;
	}
	if(isclw(b,c,in) == 0)
	{
		return 1;
	}
	if(isclw(c,d,in) == 0)
	{
		return 1;
	}
	if(isclw(a,d,in)==  0)
	{
		return 1;
	}
	if(isclw(a,in,b)!=isclw(d,in,c))
	{
		
		if(isclw(c,in,b)!=isclw(d,in,a))
		{
			return 111;
		}
	
	}
	return 0;
	
	
	
 } 

//int main()
//{
//	point2d a,b,c;
//	a = point2d(0,0);
//	b = point2d(1,0);
//	c = point2d(1,-1);
//	printf("%d\n",isclw(a,b,c));
//}

//两直线焦点
point2d  line_cross(point2d a,point2d b,point2d c,point2d d)
{
	double a1,b1,c1,a2,b2,c2;
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






//int main()
//{
//	point2d a[4];
//	point2d b[4];
//	point2d c[4];
//	point2d d[4];
//	a[0] = point2d(0,0);
//	a[1] = point2d(-4,-4);
//	a[2] = point2d(-1,0);
//	a[3] = point2d(0,-1);
//	b[0] = point2d(-1,0);
//	b[1] = point2d(1,0);
//	b[2] = point2d(0,1);
//	b[3] = point2d(0,4);
//	c[0] = point2d(1,4);
//	c[1] = point2d(4,1);
//	c[2] = point2d(1,1);
//	c[3] = point2d(4,4);
//	d[0] = point2d(4,4);
//	d[1] = point2d(1,1);
//	d[2] = point2d(5,4);
//	d[3] = point2d(7,1);
//
//	point2d cross = line_cross(a[0],a[1],a[2],a[3]);
//	printf("%.2f %.2f\n",cross.x,cross.y);
//
//
////	point2d e = point2d(3,1);
////	isbanana(a[0],a[1],a[2],a[3]);
////	isbanana(b[0],b[1],b[2],b[3]);
////	isbanana(e,c[1],c[2],c[3]);
////	isbanana(d[0],d[1],d[2],d[3]);
//
//
//
//
//}
//

int main()
{
	int T,TT = 1;
	scanf("%d",&T);
	while(T--)
	{
		point2d a[4];
    	point2d b[4];
    	double f1x,f1y;
    	double f2x,f2y;
    	
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&f1x,&f1y);
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&b[0].x,&b[0].y,&b[1].x,&b[1].y,&b[2].x,&b[2].y,&f2x,&f2y);
		printf("Case #%d: ",TT++);
		
		f2x-=f1x;
		f2y-=f1y;
		int F = 0;
//		printf("%.2f %.2f\n",f2x,f2y);
		
	//int isbanana(point2d aa,point2d bb,point2d cc,point2d dd)	
		for(int i = 0; i < 3;i++)
		{
			point2d dd;
			dd.x = b[i].x+f2x*1e9;
			dd.y = b[i].y+f2y*1e9;
			if(isbanana(a[0],a[1],b[i],dd))
			{
				F = 1;
				break;
			}
			if(isbanana(a[1],a[2],b[i],dd))
			{
				F = 1;
				break;
			}
			if(isbanana(a[2],a[0],b[i],dd))
			{
				F = 1;
				break;
			}
			
		}
		if(F)
		{
			printf("YES\n");
		}
		else
		{
			for(int i = 0; i < 3;i++)
			{
				point2d dd,dd1;
				dd.x = b[i].x+f2x*1e9;
				dd.y = b[i].y+f2y*1e9;
				dd1.x = b[(i+1)%3].x+f2x*1e9;
				dd1.y = b[(i+1)%3].y+f2y*1e9;
				
				if(is_in(b[i],b[(i+1)%3],dd1,dd,a[0]))
				{
				//	printf("is %d\n",is_in(b[i],b[(i+1)%3],dd1,dd,a[0]));
					F = 1;
					break;
				}
				if(is_in(b[i],b[(i+1)%3],dd1,dd,a[1]))
				{
					F = 1;
					break;
				}
				if(is_in(b[i],b[(i+1)%3],dd1,dd,a[2]))
				{
					F = 1;
					break;
				}
				
				
			}
			
			if(F)
			{
				puts("YES");
			}
				else
				{
					puts("NO");
							}			
		}
		
	}

/*
6

0 1 2 1 1 3 1 0
9 2 10 4 8 4 -1 0

0 1 2 1 1 3 2 0
9 2 10 4 8 4 3 0

0 1 2 1 1 3 0 0
0 4 1 6 -1 6 1 -2

0 1 2 1 1 3 2 0
9 2 10 4 8 4 0 3 

0 1 2 1 1 3 0 0
9 2 10 4 8 4 0 3 

0 1 2 1 1 3 1 1
9 2 10 4 8 4 -1 1 



*/


 return 0;
}


