#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(m==3||m==4||m==6||n==3||n==4||n==6) 
		{
			printf("Yes\n");
			continue;
		}
		int t;
		if(m<n) {t=m;m=n;n=t;}
		double a,b;
		a=180-(360/(double)n);
		b=180-(360/(double)m);
		
		int f=0;		
		for(int i=1;i<n;i++)
		 {
		 	double x;
		 	x = 360-a*i;
		 	while(x>-1)
		 	{
		 		x-=b;
		 		
		 		if(fabs(x)<0.0001)
		 		{
		 			f=1;break;
				 }
			 }
			 if(f) break;
		 	
		 }
		 if(!f) printf("No\n");
		 else printf("Yes\n");
		
	}
	
	
	return 0;
}
