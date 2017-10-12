#include<bits/stdc++.h>

using namespace std;

int a[200];
int an[200];

int main()
{

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		memset(a,0,sizeof(a));
		memset(an,0,sizeof(an));
		
		scanf("%d",&n);
		int sum = 0;
		int maxn = 0;
		for(int i = 1;i < n;i++)
		{
			scanf("%d",&a[i]);
			maxn = max(maxn,a[i]); 
			an[a[i]]++;
			sum += a[i];
		}
		//double ave = (double)sum/(n-1)*3/4;
		double p = 0.0;
		double pm = 0.0;
		double ave = (double)sum/(n-1)*3.0/4;
			
		int num = (int)ave-2;
	//	printf("num %d\n",num);
		int ans;
		for(int i = 0;;i++)
		{
			int now = num+i;
			if(now>maxn||now>100)
			{
				break;
			}
			if(now<0)
			{
				continue;
			}
			
			int nowsum = sum+now;
			ave = (double)nowsum/(n)*3.0/4;
	//		printf("%d sum %d ave%.2f\n",now,nowsum,ave);
			if((double)now<=ave)
			{
				int F = 0;
				for(int j = now+1;(double)j<=ave;j++)
				{
					if(an[j]!=0)
					{
						F = 1;
						break;
					}
				}
				if(F)
				{
					continue;
				}
				p = (double)1/(an[now]+1);
		//		printf("!! %d %.2f\n",now,p);
				if(p>=pm)
				{
					pm = p;
					ans = now;
				}
			}
			
			
		}
		printf("%d %.2f\n",ans,pm);
		
	}



 return 0;
}


