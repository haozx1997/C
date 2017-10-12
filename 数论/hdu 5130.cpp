#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    double x,y;
}p[600];
double r;
int n;
double multi(node a,node b)//�������
{
    return a.x*b.y-a.y*b.x;
}
int get_sign(node a,node b)//�ж�������˷���
{
    if(multi(a,b)>0)
        return 1;
    return -1;
}
double dis(node a,node b)//��������
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dis_line(node a,node b)//��ԭ�㵽ֱ��ab�ľ���
{
    return fabs(multi(a,b))/dis(a,b);
}
double get_angle(double a,double b,double c)//���c�Խǵ�ֵ
{
    return (a*a+b*b-c*c)/(2.0*a*b);
}
node get_point(node a)//��a����ԭ��������Բ�Ľ�������
{
    node ans;
    double k;
    if(a.x!=0)//б�ʴ���
    {
        k=a.y/a.x;
        ans.x=fabs(r)/sqrt(1.0+k*k);
        if(a.x<0) ans.x=-ans.x;//�ж�ans.x�ķ���
        ans.y=k*ans.x;
    }
    else//б�ʲ�����
    {
        ans.x=0;
        if(a.y>0) ans.y=r;//�ж�ans.y�ķ���
        else ans.y=-r;
    }
    return ans;
}
double get_area(node a,node b,node o)//��a,b,o�������γɵ���������Բ�ཻ���������
{
    int sign=get_sign(a,b);//�ж���������ķ���
    double ans=0;
    double oa=dis(o,a),ob=dis(o,b),ab=dis(a,b);
    double l=dis_line(a,b);
    if(oa==0||ob==0)//��һ�߱߳�Ϊ0�����Ϊ0
        return 0;
    //��һ�����,���㶼��Բ��
    if(oa<=r&&ob<=r)
    {
        ans=fabs(multi(a,b))/2.0;//�ཻ�����Ϊ������oab�����
        return sign*ans;
    }
    //�ڶ������,���㶼��Բ����Բ�ĵ�ֱ��ab������ڰ뾶
    else if(oa>=r&&ob>=r&&l>=r)
    {
        node t1=get_point(a);//oa��Բ�Ľ���
        node t2=get_point(b);//ob��Բ�Ľ���
        double d=dis(t1,t2);
        double ang=acos(get_angle(r,r,d));//��t1ot2
        ans=fabs(ang*r*r/2.0);//�ཻ�����Ϊ����ot1t2�����
        return sign*ans;
    }
    //���������,���㶼��Բ����Բ�ĵ�ֱ�߾���С�ڰ뾶��������oab��һ�׽��Ƕ۽Ǽ�ֱ��ab��Բû�н���
    else if(oa>=r&&ob>=r&&l<=r&&(get_angle(ab,oa,ob)<=0||get_angle(ab,ob,oa)<=0))
    {
        node t1=get_point(a);//oa��Բ�Ľ���
        node t2=get_point(b);//ob��Բ�Ľ���
        double dist=dis(t1,t2);//�߶�t1t2����
        double ang=acos(get_angle(r,r,dist));//��t1ot2
        ans=fabs(ang*r*r/2.0);//�ཻ�����Ϊ����ot1t2�����
        return sign*ans;
    }
    //���������,���㶼��Բ����ԭ�㵽ֱ��ab����С�ڰ뾶��������oab�׽Ǿ�Ϊ��Ǽ�ֱ��ab��Բ����������
    else if(oa>=r&&ob>=r&&l<=r&&get_angle(ab,oa,ob)>0&&get_angle(ab,ob,oa)>0)
    {
        node c,d;//c,dΪֱ��ab��Բ����������
        if(a.x!=b.x)//ֱ��abб�ʴ���
        {
            double k=(a.y-b.y)/(a.x-b.x);//ֱ��abб��
            double h=a.y-k*a.x;//ֱ��ab�ؾ�
            //��һԪ���η�����Բ��ֱ��ab�Ľ���
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
        }
        else//ֱ��abб�ʲ�����
        {
            c.x=a.x;
            d.x=a.x;
            c.y=sqrt(r*r-a.x*a.x);
            d.y=-sqrt(r*r-a.x*a.x);
        }
        node t1=get_point(a);//oa��Բ�Ľ���
        node t2=get_point(b);//ob��Բ�Ľ���
        double d1=dis(c,d);//�߶�cd����
        double d2=dis(t1,t2);//�߶�t1t2����
        double ang1=acos(get_angle(r,r,d1));//��cod
        double ang2=acos(get_angle(r,r,d2));//��t1ot2
        double s1=fabs(ang1*r*r/2.0);//С����ocd���
        double s2=fabs(ang2*r*r/2.0);//С������ot1t2���
        double s3=fabs(multi(c,d))/2.0;//������ocd���
        ans=s2+s3-s1;//�ཻ�����Ϊ������ocd������������������֮��
        return sign*ans;
    }
    //���������,a����Բ��,b����Բ��
    else if(oa>=r&&ob<=r)
    {
        node c,d,e;//c,d����Ϊֱ��ab��Բ����������,e��Ϊ����ab����֮����Ǹ�����
        if(a.x!=b.x)//ֱ��abб�ʴ���
        {
            double k=(a.y-b.y)/(a.x-b.x);//ֱ��abб��
            double h=a.y-k*a.x;//ֱ��ab�ؾ�
            //��һԪ���η�����Բ��ֱ��ab�Ľ���
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
            //����ӦΪc,d�����к��������(a.x,b.x)����֮�����һ��
            if(a.x<=c.x&&c.x<=b.x||a.x>=c.x&&c.x>=b.x) e=c;
            else e=d;
        }
        else//ֱ��abб�ʲ�����
        {
            c.x=d.x=a.x;
            c.y=-sqrt(r*r-a.x*a.x);
            d.y=sqrt(r*r-a.x*a.x);
            //����ӦΪc,d���������������(a.y,b.y)����֮�����һ��
            if(a.y<=c.y&&c.y<=b.y||a.y>=c.y&&c.y>=b.y) e=c;
            else e=d;
        }
        node t1=get_point(a);//oa��Բ�Ľ���
        double dist=dis(t1,e);//�߶�t1e����
        double ang=acos(get_angle(r,r,dist));//��eot1
        double s1=fabs(ang*r*r/2.0);//����oet1���
        double s2=fabs(multi(b,e))/2.0;//������obe���
        ans=s1+s2;//�ཻ�����������obe�����������oet1���
        return sign*ans;
    }
    //���������,b����Բ��,a����Բ��
    else if(ob>=r&&oa<=r)
    {
        node c,d,e;//c,d����Ϊֱ��ab��Բ����������,e��Ϊ����ab����֮����Ǹ�����
        if(a.x!=b.x)//ֱ��abб�ʴ���
        {
            double k=(a.y-b.y)/(a.x-b.x);//ֱ��abб��
            double h=a.y-k*a.x;//ֱ��ab�ؾ�
            //��һԪ���η�����Բ��ֱ��ab�Ľ���
            double a0=1.0+k*k;
            double b0=2.0*k*h;
            double c0=h*h-r*r;
            c.x=(-b0+sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            c.y=k*c.x+h;
            d.x=(-b0-sqrt(b0*b0-4.0*a0*c0))/(2.0*a0);
            d.y=k*d.x+h;
            //����ӦΪc,d�����к��������(a.x,b.x)����֮�����һ��
            if(a.x<=c.x&&c.x<=b.x||a.x>=c.x&&c.x>=b.x) e=c;
            else e=d;
        }
        else//ֱ��abб�ʲ�����
        {
            c.x=d.x=a.x;
            c.y=-sqrt(r*r-a.x*c.x);
            d.y=sqrt(r*r-a.x*a.x);
            //����ӦΪc,d���������������(a.y,b.y)����֮�����һ��
            if(a.y<=c.y&&c.y<=b.y||a.y>=c.y&&c.y>=b.y) e=c;
            else e=d;
        }
        node t1=get_point(b);//oa��Բ�Ľ���
        double dist=dis(t1,e);//�߶�t1e����
        double ang=acos(get_angle(r,r,dist));//��eot1
        double s1=fabs(ang*r*r/2.0);//����oet1���
        double s2=fabs(multi(a,e))/2.0;//������oae���
        ans=s1+s2;//�ཻ�����������oae�����������oet1���
        return sign*ans;
    }
}
int main()
{
    int n;
    int cas = 0;
    while(scanf("%d",&n)!=EOF)
    {
        double k;
        scanf("%lf",&k);
        for(int i=0;i<n;i++)
        {
            double px,py;
            scanf("%lf%lf",&px,&py);

            p[i].x = px;
            p[i].y = py;

        }
        p[n].x = p[0].x ;
        p[n].y = p[0].y ;
        node ca;
        node cb;
        scanf("%lf%lf",&ca.x,&ca.y);
        scanf("%lf%lf",&cb.x,&cb.y);
        double d,e,f;
        double k2 = (double)k*k;
        d = 2.0*((double)k2*ca.x-cb.x)/(k2-1);
        e = 2.0*((double)k2*ca.y-cb.y)/(k2-1);
        f = ((k2*ca.x-cb.x*cb.x)/(k2-1)+(k2*ca.y-cb.y*cb.y)/(k2-1));

        double Cx = d/(double)2;
        double Cy = e/(double)2;
  //      printf("aaaaaaaaaaa%lf %lf %lf\n",d,e,f);
        r = sqrt(d*d+e*e-4*f)/2;
  //      printf("aaaaaaaaaaa%lf %lf %lf\n",d/(double)2,e/(double)2,r);
        for(int i=0;i<=n;i++)
        {

            p[i].x -= Cx;
            p[i].y -= Cy;

        }

        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            node o;
            o.x=o.y=0;
            ans+=get_area(p[i],p[j],o);
        }
        printf("Case %d: %f\n",++cas,fabs(ans));
    }
    return 0;
}
