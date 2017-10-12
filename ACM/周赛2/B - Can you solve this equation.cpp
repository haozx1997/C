#include<stdio.h>
#include<math.h>
double y;
double x;
double l,r,m;
double yy(double xx)
{
return 8 * pow(xx, 4) + 7 * pow(xx, 3) + 2 * pow(xx, 2) + 3 * xx + 6;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	 {
	 	int i,f;
	 	l=0.00;r=100;f=0;
	 	scanf("%lf",&y);
	 	for(i=200;i>0;i--)
	 	{
	 		
	 		m=((l+r)/2);
	 		if((yy(m)-y<0.000001&&yy(m)-y>0)||(y-yy(m)<0.000001&&y-yy(m)>0)||y-yy(m)==0) {f=1;break;}
	 		if(yy(m)>y)r=m;
	 		if(yy(m)<y)l=m;
		 }
		 if(f)
		 printf("%.4f\n",m);
		 else printf("No solution!\n");
	 }
}
