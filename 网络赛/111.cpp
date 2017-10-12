//http://blog.sina.com.cn/s/blog_71dbfe2e0101f7zb.html
//http://dev.gameres.com/Program/Abstract/Geometry.htm#Ê¸Á¿µÄ¸ÅÄî

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


struct point2d//µãÒ²ÊÇÏòÁ¿
{
	double x,y;
	point2d(double x=0,double y=0):x(x),y(y){}
};


struct polygon//¶à±ßÐÎ µãµÄ¼¯ºÏ;
{
	point2d pp[1010];
	int size;
};
int isbanana(point2d p1,point2d p2,point2d p3,point2d p4);
int fun(point2d a,point2d b,point2d c,point2d d);
int isclw(point2d a,point2d b,point2d c);
point2d  line_cross(point2d a,point2d b,point2d c,point2d d);
polygon p_h(polygon po,point2d a,point2d b);
polygon p_hop(polygon po,point2d a,point2d b);
void see(polygon pol);
int  ispolcer(polygon pol);
double dis(point2d a,point2d b);
void see_p(point2d a);

//ÖØÔØ
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
double operator / (point2d a,point2d b)
{
	point2d p0;
	p0.x  =0.0;
	p0.y  =0.0;
	
	return dis(a,0)/dis(b,0);
}

//¡Á³Ë
//Ê¸Á¿²æ»ý£º
//
//¡¡¡¡¼ÆËãÊ¸Á¿²æ»ýÊÇÓëÖ±ÏßºÍÏß¶ÎÏà¹ØËã·¨µÄºËÐÄ²¿·Ö¡£
//ÉèÊ¸Á¿P = ( x1, y1 )£¬Q = ( x2, y2 )£¬ÔòÊ¸Á¿²æ»ý¶¨ÒåÎªÓÉ(0,0)¡¢
//p1¡¢p2ºÍp1+p2Ëù×é³ÉµÄÆ½ÐÐËÄ±ßÐÎµÄ´ø·ûºÅµÄÃæ»ý£¬¼´£ºP ¡Á Q = x1*y2 - x2*y1£¬
//Æä½á¹ûÊÇÒ»¸ö±êÁ¿¡£ÏÔÈ»ÓÐÐÔÖÊ P ¡Á Q = - ( Q ¡Á P ) ºÍ P ¡Á ( - Q ) = - ( P ¡Á Q )¡£
//Ò»°ãÔÚ²»¼ÓËµÃ÷µÄÇé¿öÏÂ£¬±¾ÎÄÏÂÊöËã·¨ÖÐËùÓÐµÄµã¶¼¿´×÷Ê¸Á¿£¬
//Á½µãµÄ¼Ó¼õ·¨¾ÍÊÇÊ¸Á¿Ïà¼Ó¼õ£¬¶øµãµÄ³Ë·¨Ôò¿´×÷Ê¸Á¿²æ»ý¡£
//¡¡¡¡²æ»ýµÄÒ»¸ö·Ç³£ÖØÒªÐÔÖÊÊÇ¿ÉÒÔÍ¨¹ýËüµÄ·ûºÅÅÐ¶ÏÁ½Ê¸Á¿Ïà»¥Ö®¼äµÄË³ÄæÊ±Õë¹ØÏµ£º
//¡¡¡¡Èô P ¡Á Q > 0 , ÔòPÔÚQµÄË³Ê±Õë·½Ïò¡£
//¡¡¡¡Èô P ¡Á Q < 0 , ÔòPÔÚQµÄÄæÊ±Õë·½Ïò¡£
//¡¡¡¡Èô P ¡Á Q = 0 , ÔòPÓëQ¹²Ïß£¬µ«¿ÉÄÜÍ¬ÏòÒ²¿ÉÄÜ·´Ïò¡£
double operator * (point2d a,point2d b)
{
	return a.x*b.y-b.x*a.y;

}

//¡¤³Ë
double pdp(point2d a,point2d b)
{
	return a.x*b.x+a.y*b.y;
 }
 double dis(point2d a,point2d b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 }
//Á½Ïß¶ÎÊÇ·ñÆ½ÐÐ
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

//Á½Ïß¶ÎÊÇ·ñÏã½¶(°üÀ¨±ß½çÏã½¶)£¬¿ìËÙÅÅ³â&&¿çÁ¢ÊµÑé
int isbanana(point2d aa,point2d bb,point2d cc,point2d dd)
{
	int f1,f2;
    f1=fun(aa,bb,cc,dd);
    f2=fun(cc,dd,aa,bb);
    if((f1==1&&f2==1)||f1==0||f2==0||(f1==0&&f2==0))
       return 1;
    else
       return 0;
}
int fun(point2d a,point2d b,point2d c,point2d d)
{
    point2d p[3];
    int flag,m,n;
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

//clockwise;Ò²¿ÉÒÔÅÐ¶Ïa b cÊÇ·ñÔÚÍ¬Ò»Ö±Ïß»òcÔÚabÄÇÒ»²à
// abÓÐË³Ðò
int isclw(point2d a,point2d b,point2d c)
{
	double ans = (a-b)*(b-c);
	if(ans<0)//²æ³Ë< 0 ÎªË³Ê±Õë·µ»Ø1
	 return 1;
	if(ans==0)//Í¬Ò»Ö±Ïß
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

//Á½Ö±Ïß½¹µã
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

//Ò»¸ö¶à±ßÐÎÓëÒ»¸ö°ëÆ½ÃæµÄ½»¼¯ polygon & half
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
 //¶à±ßÐÎÓÐÎÞºË
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
/*

P1,P2,P3 ???????,  

d1 = - (P2–P1)·(P1–P3)    // ??????:?????;  
d2 = - (P3–P2)·(P2–P1)    // ?????  
d3 = - (P1–P3)·(P3–P2)      

c1 = d2*d3  
c2 = d3*d1  
c3 = d1*d2  
c = c1 + c2 + c3

?,??????????:  
Radius = 1/2 sqrt( (d1+d2)*(d2+d3)*(d3+d1)/c )   
Center = {(c2+c3)P1 + (c3+c1)P2 + (c1+c2)P3}/2c

*/
//
int main()
{
    point2d p1,p2,p3,p,c;
    point2d a1,a2;
    double k1,k2,xx,yy;
    
    int n;
    scanf("%d",&n);
    while(n--)
    {
    	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p.x,&p.y);
    	a1 = (p1+p2)/2;
    	a2 = (p1+p3)/2;
    	k1 = (p2.x-p1.x)/(p2.y-p1.y);
    	k1 = (p3.x-p1.x)/(p3.y-p1.y);
    	c.x  = (a2.y+a1.x*k1-a1.y-a2.x*k2)/(k1-k2);
    	c.y = (k1*a2.y - k2*a1.y + a1.x*k1*k2 - a2.x*k1*k2 )/(k1-k2);
    	
    	double rrr = dis(c,p1);
    	double ddd = dis(p,c);
//    	printf("%.2f %.2f %.2f %.2f \n");
    	if(dis(ddd,rrr)<0.00000001)
    	{
    		printf("Accepted\n");
		}
		else
		{
			printf("Rejected\n");
		}
    	


    }

}

