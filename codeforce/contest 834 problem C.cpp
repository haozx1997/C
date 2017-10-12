#include<bits/stdc++.h>
#define p3(a) pow((double)a,(double)1.0/3)
using namespace std;
const double O = 1e-10;

double abss (double x)
{
	if(x>=0)
		return x;
	return -x;	
}

int isz(double x)
{
	if(abss(x - round(x))<O)
	{
		return 1;
	}
	return 0;
}

long long a,b;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d",&a,&b);
		int F = 0;
		long long ab = (long long)a*b;
		long long ps = round(p3(ab));
		//	printf("%.12f\n",abss(ps - (int)ps));
//	printf("%d\n",ps);	
			{
				
				if((a%ps == 0)&&(b%ps == 0)&&(a/ps*b/ps == ps))
				{
					F = 1;
				}
				ps++;
				if((a%ps == 0)&&(b%ps == 0)&&(a/ps*b/ps == ps))
				{
					F = 1;
				}
				ps--;ps--;
				if(ps>0&&(a%ps == 0)&&(b%ps == 0)&&(a/ps*b/ps == ps))
				{
					F = 1;
				}
				
			}
			
			if(F)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		
//		d = (double)max(a,b);
//		x = (double)min(a,b);
//		int F = 0;
//		while(d!=x)
//		{
//			double m = (double)d/x;
//			if(!isz(m))
//			{
//				F = 1;
//				break;
//			}
//			a = d/m/m;
//			b = x/m;
//			d = (double)max(a,b);
//			x = (double)min(a,b);
//		}
//		if(F)
//		{
//			printf("No\n");
//			continue;
//		}
//		if(a == 1)
//		{
//			puts("Yes");
//			continue;
//		}
//		else
//		{
//			double ps = p3(a);
//		//	printf("%.12f\n",abss(ps - (int)ps));
//			if(abss(ps - round(ps))<O)
//			{
//				printf("Yes\n");
//			}
//			else
//			{
//				printf("No\n");
//			}
//		}
//		
		
	}

 return 0;
}


