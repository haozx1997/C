#include<bits/stdc++.h>
#define ll long long
#define ffff  lower_bound 

using namespace std;

double a[10010010];

int main()
{
	ll q = 8,qs = 8,qb = 2;
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	a[4] = 2;
	a[5] = 2;
	a[6] = 4;
	a[7] = 5;
	a[8] = 8;
	
	ll fff  = 1e5;
	for(int i = 9;i<=fff;i++)
	{
		
		
		if((i-q) == 1)
		{
			a[i] = (double)qs+(double)(2*qb-1)*0.5;
		}
		else if((i-q) == 2)
		{
			a[i] = (double)qs+(double)qb*2;
		}
		else if((i-q) == 3)
		{
			a[i] = (double)a[i-1]+(double)(2*(qb+1)-1)*0.5;
		}
		else if((i-q) == 4)
		{
			a[i] = (double)qs+(double)qb*2+((double)qb+1)*2;
				q = i;
				qs = a[i];
				qb = qb+1;
		}
		
	
		
	 } 
//	printf("%.2f\n",a[100000]);
	 int Tcase;

	 scanf("%d",&Tcase);
	 while(Tcase--)
	 {
	 	double mm;
	 	scanf("%lf",&mm);
	 	int ans = ffff(a,a+100000,mm) - a;
	 	printf("%d\n",ans);
	 	
	 }
	 




 return 0;
}


