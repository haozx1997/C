#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    double x,y;
}p[55];
double r;
int n;
double multi(node a,node b)//向量叉乘 
{
    return a.x*b.y-a.y*b.x;
}
int get_sign(node a,node b)//判断向量叉乘符号 
{
    if(multi(a,b)>0)
        return 1;
    return -1;
}
double dis(node a,node b)//两点间距离 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dis_line(node a,node b)//求原点到直线ab的距离 
{
    return fabs(multi(a,b))/dis(a,b);
}
double get_angle(double a,double b,double c)//求边c对角的值 
{
    return (a*a+b*b-c*c)/(2.0*a*b);
}
node get_point(node a)//求a点与原点连线与圆的交点坐标 
{
    node ans;
    double k;
    if(a.x!=0)//斜率存在 
    {
        k=a.y/a.x;
        ans.x=fabs(r)/sqrt(1.0+k*k);
        if(a.x<0) ans.x=-ans.x;//判断ans.x的符号 
        ans.y=k*ans.x;  
    }
    else//斜率不存在 
    {
        ans.x=0;
        if(a.y>0) ans.y=r;//判断ans.y的符号 
        else ans.y=-r;
    }
    return ans;
}
double get_area(node a,node b,node o)//求a,b,o三点所形成的三角形与圆相交的有向面积 
{
    int sign=get_sign(a,b);//判断有向面积的符号 
    double ans=0;
    double oa=dis(o,a),ob=dis(o,b),ab=dis(a,b);
    double l=dis_line(a,b);
    if(oa==0||ob==0)//有一边边长为0则面积为0 
        return 0;
    //第一种情况,两点都在圆内 
    if(oa<=r&&ob<=r)
    {
        ans=fabs(multi(a,b))/2.0;//相交面积即为三角形oab的面积 
        return sign*ans;
    }
    //第二种情况,两点都在圆外且圆心到直线ab距离大于半径 
    else if(oa>=r&&ob>=r&&l>=r)
    {
        node t1=get_point(a);//oa与圆的交点 
        node t2=get_point(b);//ob与圆的交点 
        double d=dis(t1,t2);
        double ang=acos(get_angle(r,r,d));//角t1ot2 
        ans=fabs(ang*r*r/2.0);//相交面积即为扇形ot1t2的面积 
        return sign*ans;
    }
    //第三种情况,两点都在圆外且圆心到直线距离小于半径但三角形oab有一底角是钝角即直线ab与圆没有交点 
    else if(oa>=r&&ob>=r&&l<=r&&(get_angle(ab,oa,ob)<=0||get_angle(ab,ob,oa)<=0))
    {
        node t1=get_point(a);//oa与圆的交点 
        node t2=get_point(b);//ob与圆的交点 
        double dist=dis(t1,t2);//线段t1t2长度 
        double ang=acos(get_angle(r,r,dist));//角t1ot2 
        ans=fabs(ang*r*r/2.0);//相交面积即为扇形ot1t2的面积 
        return sign*ans;
    }
    //第四种情况,两点都在圆外且原点到直线ab距离小于半径且三角形oab底角均为锐角即直线ab与圆有两个交点 
    else if(oa>=r&&ob>=r&&l<=r&&get_angle(ab,oa,ob)>0&&get_angle(ab,ob,oa)>0)
    {
        node c,d;//c,d为直线ab与圆的两个交点 
        if(a.x!=b.x)//直线ab斜率存在 
        {
            double k=(a.y-b.y)/(a.x-b.x);//直线ab斜率 
            double h=a.y-k*a.x;//直线ab截距 
            //解一元二次方程求圆与直线ab的交点 
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
        }
        else//直线ab斜率不存在 
        {
            c.x=a.x;
            d.x=a.x;
            c.y=sqrt(r*r-a.x*a.x);
            d.y=-sqrt(r*r-a.x*a.x);
        }
        node t1=get_point(a);//oa与圆的交点 
        node t2=get_point(b);//ob与圆的交点 
        double d1=dis(c,d);//线段cd长度 
        double d2=dis(t1,t2);//线段t1t2长度 
        double ang1=acos(get_angle(r,r,d1));//角cod 
        double ang2=acos(get_angle(r,r,d2));//角t1ot2 
        double s1=fabs(ang1*r*r/2.0);//小扇形ocd面积 
        double s2=fabs(ang2*r*r/2.0);//小大扇形ot1t2面积 
        double s3=fabs(multi(c,d))/2.0;//三角形ocd面积 
        ans=s2+s3-s1;//相交面积即为三角形ocd面积加上两个扇形面积之差 
        return sign*ans;
    }
    //第五种情况,a点在圆外,b点在圆内 
    else if(oa>=r&&ob<=r)
    {
        node c,d,e;//c,d两点为直线ab与圆的两个交点,e点为介于ab两点之间的那个交点 
        if(a.x!=b.x)//直线ab斜率存在 
        {
            double k=(a.y-b.y)/(a.x-b.x);//直线ab斜率 
            double h=a.y-k*a.x;//直线ab截距
            //解一元二次方程求圆与直线ab的交点 
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
            //交点应为c,d两点中横坐标介于(a.x,b.x)两点之间的那一个 
            if(a.x<=c.x&&c.x<=b.x||a.x>=c.x&&c.x>=b.x) e=c;
            else e=d;               
        }
        else//直线ab斜率不存在 
        {
            c.x=d.x=a.x;
            c.y=-sqrt(r*r-a.x*a.x);
            d.y=sqrt(r*r-a.x*a.x);
            //交点应为c,d两点中纵坐标介于(a.y,b.y)两点之间的那一个 
            if(a.y<=c.y&&c.y<=b.y||a.y>=c.y&&c.y>=b.y) e=c;
            else e=d;
        }
        node t1=get_point(a);//oa与圆的交点 
        double dist=dis(t1,e);//线段t1e长度 
        double ang=acos(get_angle(r,r,dist));//角eot1 
        double s1=fabs(ang*r*r/2.0);//扇形oet1面积 
        double s2=fabs(multi(b,e))/2.0;//三角形obe面积 
        ans=s1+s2;//相交面积即三角形obe面积加上扇形oet1面积 
        return sign*ans;
    }
    //第五种情况,b点在圆外,a点在圆内 
    else if(ob>=r&&oa<=r)
    {
        node c,d,e;//c,d两点为直线ab与圆的两个交点,e点为介于ab两点之间的那个交点 
        if(a.x!=b.x)//直线ab斜率存在 
        {
            double k=(a.y-b.y)/(a.x-b.x);//直线ab斜率 
            double h=a.y-k*a.x;//直线ab截距
            //解一元二次方程求圆与直线ab的交点 
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
            //交点应为c,d两点中横坐标介于(a.x,b.x)两点之间的那一个 
            if(a.x<=c.x&&c.x<=b.x||a.x>=c.x&&c.x>=b.x) e=c;
            else e=d;               
        }
        else//直线ab斜率不存在 
        {
            c.x=d.x=a.x;
            c.y=-sqrt(r*r-a.x*c.x);
            d.y=sqrt(r*r-a.x*a.x);
            //交点应为c,d两点中纵坐标介于(a.y,b.y)两点之间的那一个 
            if(a.y<=c.y&&c.y<=b.y||a.y>=c.y&&c.y>=b.y) e=c;
            else e=d;
        }
        node t1=get_point(b);//oa与圆的交点 
        double dist=dis(t1,e);//线段t1e长度 
        double ang=acos(get_angle(r,r,dist));//角eot1 
        double s1=fabs(ang*r*r/2.0);//扇形oet1面积 
        double s2=fabs(multi(a,e))/2.0;//三角形oae面积 
        ans=s1+s2;//相交面积即三角形oae面积加上扇形oet1面积 
        return sign*ans;
    }
}
int main()
{
    while(scanf("%lf",&r)!=EOF)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            node o;
            o.x=o.y=0;
            ans+=get_area(p[i],p[j],o);
        }
        printf("%.2lf\n",fabs(ans));
    }
    return 0;
}
