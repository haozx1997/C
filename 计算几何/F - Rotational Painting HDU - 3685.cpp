//http://blog.sina.com.cn/s/blog_71dbfe2e0101f7zb.html
//http://dev.gameres.com/Program/Abstract/Geometry.htm#ʸ���ĸ���

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)


int sgn(double x)
{
    if(fabs(x) < 1E-8)return 0;
    if(x < 0)return -1;
    else return 1;
}

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


struct point2d//��Ҳ������
{
	double x,y;
	point2d(double x=0,double y=0):x(x),y(y){}
	
	void print()
	{
		printf("ppp  %.2f %.2f\n",this->x,this->y);
	}
};


struct polygon//����� ��ļ���;
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

//����
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
//����
//ʸ�������
//
//��������ʸ���������ֱ�ߺ��߶�����㷨�ĺ��Ĳ��֡�
//��ʸ��P = ( x1, y1 )��Q = ( x2, y2 )����ʸ���������Ϊ��(0,0)��
//p1��p2��p1+p2����ɵ�ƽ���ı��εĴ����ŵ����������P �� Q = x1*y2 - x2*y1��
//������һ����������Ȼ������ P �� Q = - ( Q �� P ) �� P �� ( - Q ) = - ( P �� Q )��
//һ���ڲ���˵��������£����������㷨�����еĵ㶼����ʸ����
//����ļӼ�������ʸ����Ӽ�������ĳ˷�����ʸ�������
//���������һ���ǳ���Ҫ�����ǿ���ͨ�����ķ����ж���ʸ���໥֮���˳��ʱ���ϵ��
//������ P �� Q > 0 , ��P��Q��˳ʱ�뷽��
//������ P �� Q < 0 , ��P��Q����ʱ�뷽��
//������ P �� Q = 0 , ��P��Q���ߣ�������ͬ��Ҳ���ܷ���
double operator * (point2d a,point2d b)
{
	return a.x*b.y-b.x*a.y;

}

//����
double pdp(point2d a,point2d b)
{
	return a.x*b.x+a.y*b.y;
 }
 double dis(point2d a,point2d b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 }
//���߶��Ƿ�ƽ��
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

//���߶��Ƿ��㽶(�����߽��㽶)�������ų�&&����ʵ��
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

//clockwise;Ҳ�����ж�a b c�Ƿ���ͬһֱ�߻�c��ab��һ��
// ab��˳��
int isclw(point2d a,point2d b,point2d c)
{
	double ans = (a-b)*(b-c);
	if(ans<0)//���< 0 Ϊ˳ʱ�뷵��1
	 return 1;
	if(ans==0)//ͬһֱ��
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

//��ֱ�߽���
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

//һ���������һ����ƽ��Ľ��� polygon & half
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
 //��������޺�
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

/*
* ��͹����Graham�㷨
* ��ı��0~n-1
* ����͹�����Stack[0~top-1]Ϊ͹���ı��
*/
point2d list[50500];
int Stack[50500],top;
//�����list[0]�ļ�������
bool _cmp(point2d p1,point2d p2)
{
    double tmp = (p1-list[0])*(p2-list[0]);
    if(sgn(tmp) > 0)return true;
    else if(sgn(tmp) == 0 && sgn(dis(p1,list[0]) - dis(p2,list[0])) <= 0)
        return true;
    else return false;
}
void Graham(int n)// �ı���list[]��ֵ(����list) lsit ��0��ʼ 
{
    point2d p0;
    int k = 0;
    p0 = list[0];
//�����±ߵ�һ����
    for(int i = 1; i < n; i++)
    {
        if( (p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x) )
        {
            p0 = list[i];
            k = i;
        }
    }
    swap(list[k],list[0]);
    sort(list+1,list+n,_cmp);
    if(n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return;
    }
    if(n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return ;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for(int i = 2; i < n; i++)
    {
        while(top > 1 && sgn((list[Stack[top-1]]-list[Stack[top-2]])*(list[i]-list[Stack[top-2]])) <=0)
            top--;
        Stack[top++] = i;
    }
}
point2d bcenter(point2d pnt[], int n)//��������� �ѱ� void Graham(int n)�������͹�� ������Ϊlist[] lsit ��0��ʼ 
{
    point2d p, s;
    double tp, area = 0, tpx = 0, tpy = 0;
    p.x = pnt[0].x;
    p.y = pnt[0].y;
    for (int i = 1; i <= n; ++i)
    {
        // POINT: 0 ~ n-1
        s.x = pnt[(i == n) ? 0 : i].x;
        s.y = pnt[(i == n) ? 0 : i].y;
        tp = (p.x * s.y - s.x * p.y);
        area += tp / 2;
        tpx += (p.x + s.x) * tp;
        tpy += (p.y + s.y) * tp;
        p.x = s.x;
        p.y = s.y;
    }
    s.x = tpx / (6 * area);
    s.y = tpy / (6 * area);
    return s;
}

bool isd90(point2d j,point2d b1,point2d b2)//���Ƿ����90��
{
//	printf("	");j.print();
//	printf("	");b1.print();
//	printf("	");b2.print();
//	
	double jdb2 = (b1.x-b2.x)*(b1.x-b2.x)+(b1.y-b2.y)*(b1.y-b2.y);
	double b1db2 = (j.x-b2.x)*(j.x-b2.x)+(j.y-b2.y)*(j.y-b2.y);
	double b2db2 = (j.x-b1.x)*(j.x-b1.x)+(j.y-b1.y)*(j.y-b1.y);
//	double cosj = (double)(b1db2+b1db2-jdb2)/((double)2*sqrt(b2db2*b1db2));
//	printf("cos %.2f\n",cosj);
//	if(sgn(cosj)<=0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//	printf("%.2f %.2f %.2f\n",jdb2,b1db2,b2db2);
	if(sgn(jdb2-(b1db2+b2db2))>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
} 

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int n;
		scanf("%d",&n);
        for(int i = 0;i<n;i++)
        {
	    	scanf("%lf %lf",&list[i].x,&list[i].y);
        }
        point2d cter = bcenter(list,n);  
        Graham(n);
		
	//	cter.print();
		int ans =0;
		for(int i = 0;i < top;i++)
		{
	//		puts("\n\n\n");
			point2d nex = list[Stack[((i+1) == top) ? 0 : (i+1)]];
			point2d now = list[Stack[i]];
//			printf("%d  %d %d\n",i,isd90(now,nex,cter),isd90(nex,now,cter));
//			nex.print();
//			now.print();
//			
			if(isd90(now,nex,cter)||isd90(nex,now,cter))
			{
				
			}
			else
			{
				ans++;
			}
			
			
		}
		printf("%d\n",ans);
    }

}
/*
2
4
0 0
100 0
99 1
1 1
6
0 0
0 10
1 10
1 1
10 1
10 0
*/
