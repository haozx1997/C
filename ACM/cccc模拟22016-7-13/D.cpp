#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<math.h>

using namespace std;
double abs(double a)
{
	if(a>0)
	 return a;
	return 0-a; 
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,a,b,da[1010];
		int fit = 0;
		double ave = 0;
		scanf("%d%d%d",&n,&a,&b);
		if(b < a)
 		{
 			int tt = a;
 			a = b;
 			b = tt;
		 }
		 int d;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&d);
			if(d<=b&&d>=a)
			{
				da[fit++] = d;
				ave += d;
			}
			
		}
		ave =(double)ave/fit; 
		double sum = 0;
		for(int i = 0;i < fit;i++)
		{
			
			double cha = ave - da[i];
			cha = cha*cha;
			
			sum += cha;
		}
		double kf = sqrt((double)sum);
		
		kf = (double)kf/fit;
		printf("%.2f %.2f\n",ave,kf);
		
		
		
		
		
	}
}
