
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=70000;
const double PI=acos(-1);
int main()
{
    int t;
    double x1,x2,y1,y2,r1,r2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(r1>r2) {r1=r1+r2;r2=r1-r2;r1=r1-r2;}
        double d;
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(d>=r1+r2) cout<<"0.00"<<endl;
        else if(d<=r2-r1) printf("%.2lf\n",r1*r1*PI);
        else
        {
            double a1,a2,s1,s2,s3;
            a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
            a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
            s1=a1*r1*r1;
            s2=a2*r2*r2;
            s3=r1*d*sin(a1);
            printf("%.2lf\n",s1+s2-s3);
        }
    }
    return 0;
}

