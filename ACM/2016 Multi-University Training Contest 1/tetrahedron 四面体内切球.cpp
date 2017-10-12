#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
const double eps=1e-8;
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)

struct point//��Ҳ������ 
{
	double x,y,z;
	point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
	
};
double pdp(point a,point b);
double plen(point a);
double pplen(point a,point b);
point  pnv(point a,point b,point c);
double psurlen(point p,point s1,point s2,point s3);
int issur(point p,point s1,point s2,point s3);
int isline(point p,point s1,point s2) ;
double pllen(point p,point s1,point s2);
double S(point p1,point p2,point p3);
double v4(point p1,point p2,point p3,point p4);


//����
point operator + (point a,point b)
{
	return point(a.x+b.x,a.y+b.y,a.z+b.z); 
}

point operator - (point a,point b)
{
	return point(a.x-b.x,a.y-b.y,a.z-b.z); 
}

point operator * (point a,double b)
{
	return point(a.x*b,a.y*b,a.z*b); 
}

point operator / (point a,double b)
{
	return point(a.x/b,a.y/b,a.z/b); 
}
//���� 
point operator * (point a,point b)
{
	return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x); 
	
}
//����
double pdp(point a,point b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
 } 

//�������� AKA ģ�� 
double plen(point a)
{
	return sqrt(pdp(a,a));
}
//������� 
double pplen(point a,point b)
{
	return sqrt(fabs(pdp(a-b,a-b)));
 } 
//
//int main()
//{
//	point a = point(0,0,0);
//	point b = point(0,0,1);
//	point c = point(0,1,0);
//	point d = point(1,0,0);
//	point e = point(1,1,1);
//	
//	 printf("%.2f\n",pplen(a,e));
//}

//ƽ�淨���� Plane normal vector   ���߲�� 
point  pnv(point a,point b,point c)
{
	return (a-b)*(a-c);
}
//int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	point f = pnv(a,b,c);
//	 printf("%.2f %.2f %.2f\n",f.x,f.y,f.z);
//}

//�㵽ƽ��ľ���  p surface len�����������˵㣨��ƽ��������һ��ľ��룩���ԣ�������ģ���� 
double psurlen(point p,point s1,point s2,point s3)
{
	point f = pnv(s1,s2,s3);

	return fabs((pdp(f,p-s1))/plen(f)); 
	
 } 
//int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	
//	 printf("%.2f\n",psurlen(a,b,c,d)*3);// = ����3 (b,c,d)���ƽ���������Խ�������֮һ 
//	 
//}

// �ĵ㹲��  ��ƽ��ľ���==�� 
int issur(point p,point s1,point s2,point s3)
{
	if(isline(p,s1,s2)||isline(s3,s1,s2)
			||isline(p,s1,s3)||isline(p,s3,s2))
		return 1;//�������㹲��	 
	return zero(psurlen(p,s1,s2,s3));
}
//int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	point f = point(1,1,0);
//	
//	 printf("%d\n",issur(a,b,c,f));
//	 
//}

//���㹲�� ������������ ���Ϊ0  
int isline(point p,point s1,point s2) 
{
	return zero(plen((s1-s2)*(s2-p)));
}
// int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(2,2,2);
//	point e = point(1,1,1);
//	printf("%.2f\n",pllen(e,d,a));
//	 printf("%d\n",isline(e,d,a));
//	 
//} 

//�㵽ֱ�߾���  p line len�����������˵㣨����������һ��ľ��룩���ԣ�������ģ���� 
double pllen(point p,point s1,point s2)
{
	if(isline(p,s1,s2)) //����Ϊ�� 
	 return 0;
	point f = s1-s2;
	if(zero((pdp(f,p-s1))))//s1ΪͶӰ��Ļ� 
	 return plen(p-s1);
//	printf("%.2f\n",pdp(f,p-s1));
	return fabs((plen(f*(p-s1)))/plen(f)); //ֱ��p-s1 ���ֱ��s1-s2 ���� ֱ��s1-s2ģ�� 
	
 } 
// int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	point f = point(2,2,2);
//	
//	 printf("%.2f\n",pllen(d,b,c));
//	 
//}

//�������  square of surface
double S(point p1,point p2,point p3)
{
	if(isline(p1,p2,p3))
	 return 0;
//	 printf("%.2f %.2f\n",pplen(p2,p3),pllen(p1,p2,p3)*2);
	return fabs(pplen(p2,p3)*pllen(p1,p2,p3)/2); 
 } 
// int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	point f = point(2,2,2);
//	
//	 printf("%.2f\n",S(d,b,c)*2);
//	 
//}


//��������� V4
double v4(point p1,point p2,point p3,point p4)
{
	if(issur(p1,p2,p3,p4))
	 return 0;//����Ϊ�� 
	return S(p1,p2,p3)*psurlen(p4,p1,p2,p3)/3;//�׳˸�/3 
	return fabs(pdp((p2-p1)*(p3-p1),(p4-p1))/6);//��ϻ��������� 
 } 
// int main()
//{
//	point a = point(0,0,0);
//	point b = point(1,0,0);
//	point c = point(0,1,0);
//	point d = point(0,0,1);
//	point e = point(1,1,1);
//	point f = point(2,2,2);
//	printf("%f\n",pdp((b-a)*(c-a),(d-a))/6);
//	 printf("%f\n",v4(d,b,c,a));
//	 
//}



int main()
{
	point a,b,c,d;
	while(~scanf("%lf%lf%lf",&a.x,&a.y,&a.z))
	{
		scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
		scanf("%lf%lf%lf",&c.x,&c.y,&c.z);
		scanf("%lf%lf%lf",&d.x,&d.y,&d.z);
	//	printf("%d\n",issur(a,b,c,d));
		
		if(issur(a,b,c,d))
		 {
		 	printf("O O O O\n");
		 	continue;
		 }
		 double s1 = S(d,b,c);
		 double s2 = S(a,d,c);
		 double s3 = S(a,b,d);
		 double s4 = S(a,b,c);
		 double sum = s1+s2+s3+s4;
		 double r = 3*v4(a,b,c,d)/(sum);
		 double xx = (s1*a.x+s2*b.x+s3*c.x+s4*d.x)/sum;
		 double yy = (s1*a.y+s2*b.y+s3*c.y+s4*d.y)/sum;
		 double zz = (s1*a.z+s2*b.z+s3*c.z+s4*d.z)/sum;
		 printf("%.4f %.4f %.4f %.4f\n",xx,yy,zz,r);
	}
}
