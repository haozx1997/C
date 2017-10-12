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

double C(double aa,double bb,double cc)
{
	return acos(((aa*aa)+(bb*bb)-(cc*cc))/(2*aa*bb));
}

int eq(double d1,double d2)
{
	if((d1-d2)<=0.00001&&(d1-d2)>=-0.00001)
	 return 1;
	return 0; 
}
	

int main()
{
	int T;
	scanf("%d",&T);
	for(int I = 0;I < T;I++)
	{
		int q1x,q1y,q2x,q2y,q3x,q3y,q4x,q4y;
		scanf("%d%d%d%d%d%d%d%d",&q1x,&q1y,&q2x,&q2y,&q3x,&q3y,&q4x,&q4y);
		double d12 = dis(q1x,q1y,q2x,q2y);
		double d23 = dis(q2x,q2y,q3x,q3y);
		double d34 = dis(q3x,q3y,q4x,q4y);
		double d41 = dis(q4x,q4y,q1x,q1y);
		double d13 = dis(q1x,q1y,q3x,q3y);
		double d24 = dis(q2x,q2y,q4x,q4y);
		double r1 = C(d12,d41,d24);
		double r2 = C(d12,d23,d13);
		
		if(eq(d12,d34)&&eq(d41,d23))
		{
			if(eq(d12,d23)&&eq(d34,d23))
			{
				if(eq(r1,r2))
				{
					printf("Case #%d: Square\n",I+1);
				}
				else
				{
					printf("Case #%d: Diamond\n",I+1);				
				}
			}
			else
			{
				if(eq(r1,r2))
				{
					printf("Case #%d: Rectangle\n",I+1);
				}
				else
				{
					printf("Case #%d: Parallelogram\n",I+1);				
				}
			}
		
			
		}
		else
		{
			printf("Case #%d: Others\n",I+1);
		}
		
			
	}	
}
