#include<bits/stdc++.h>

using namespace std;

int n;
int a[100100];
map <long long,int>aa;


int main()
{
	while(~scanf("%d",&n))
	{
	//	printf("FUCK!\n");
		memset(a,0,sizeof(a));
		aa.clear();
		long long sum = 0;
		long long s[100100];
		s[0] = (long long )0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum += (long long)a[i];
			s[i] = s[i-1] + (long long)a[i];
		}
		if(sum%(long long)2)
		{
			printf("NO\n");
			continue;
		}
		if(n == 1)
		{
			printf("NO\n");
			continue;			
		}
		long long l = (long long)0;
		long long r = (long long)0;
		long long ca;
		
		int F = 0;
		
		for(int i = 1;i <= n;i++)
		{
			if(aa[(long long)2*(long long)a[i]] == 1)
			{
				F = 1;
				break;
			}
			r = sum - s[i];
			ca = r - s[i];
			if(ca == 0)
			{
				F = 1;
				break;
			}
			if( ca > 0)
			{
				aa[ca] = 1;
			}
			
		}
		aa.clear();
		for(int i = n;i > 0;i--)
		{
			if(aa[(long long)2*(long long)a[i]] == 1)
			{
				F = 1;
				break;
			}
			r = sum - s[i];
			ca = s[i] - r;
			if(ca == 0)
			{
				F = 1;
				break;
			}
			if( ca > 0)
			{
				aa[ca] = 1;
			}
		
		}
		
		
		if(F)
		{
			printf("YES\n");
			continue;
		}
		else
		{
			printf("NO\n");
		}
		
	}

 return 0;
}


