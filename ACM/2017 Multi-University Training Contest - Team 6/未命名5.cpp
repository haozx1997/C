/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

double abss(double x)
{
	if(x<0)
	{
		return -x;
	}
	return x;
}

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double dis2(double x1,double y1,double x2,double y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int main()
{
//	puts("asd");
	int T;
	for(int i = 0 ; i <10000;i++)
	{
		puts("asd");
	}
	scanf("%d",&T);
	while(T--)
	{
		double r,x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
		double b = (double)r/dis(x1,y1,0,0);
		double b2 = (double)r*r/dis2(x1,y1,0,0);
		double xx1 = x1*b2;
		double yy1 = y1*b2;
		double xx2 = x2*b2;
		double yy2 = y2*b2;
		
		double xm = (double)(xx1+xx2)/2.0;
		double ym = (double)(yy1+yy2)/2.0;
		
	//	printf("	%.7f\n",abss(dis(xm,ym,0,0)-r));
		
		double xr1 = x1*b;
		double yr1 = y1*b;
		double xr2 = x2*b;
		double yr2 = y2*b;
		
		
		if((abss(dis(xm,ym,0,0)-r))<=1e-7)
		{
			//printf("%.9f\n",dis(xx1,yy1,xx2,yy2));
			printf("%.9f\n",dis(xr1,yr1,xr2,yr2));
			
		}
		else if(dis(xm,ym,0,0)-r < 0)
		{
		//	printf("%.9f\n",dis(xx1,yy1,xx2,yy2));
			printf("%.9f\n",dis(xr1,yr1,xr2,yr2));
		}
		else
		{
			double z = dis(x1,y1,x2,y2)/2.0;
			double x = dis(x1,y1,0,0);
			double y = sqrt(x*x-z*z);
			double r_y = r-y;
			
	//		printf("%.5f %.5f %.5f %.5f \n",z,x,y,r_y);
			
			double ans = sqrt(z*z+r_y*r_y);
			printf("%.9f\n",ans*2);
		}
		
		
	}




 return 0;
}


