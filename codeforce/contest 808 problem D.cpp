#include<bits/stdc++.h>

using namespace std;

int n;
int a[100100];



int main()
{
	map<int,int> aa;
	while(~scanf("%d",&n))
	{
		aa.clear();
		long long sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			aa[a[i]] = 1;
			sum += (long long)a[i];
		}
		if(sum%2)
		{
			printf("NO\n");
			continue;
		}
		long long l = (long long)0;
		long long r = (long long)0;
		
		int F = 0;
		map<int,int> aan(aa);
		for(int i = 0;i < n;i++)
		{
			l += (long long)a[i];
			r = sum - l;
			long long ca = (r - l);
			if(ca == 0)
			{
				F = 1;
				break
			}
			if(ca < 0)
			{
				break;
			}
			if(ca%2)
			{
				
			}
			else
			{
				aan[i] = 0;
				ca /= 2;
				if(aan[ca] == 1)
				{
					F = 1;
					break;
				}
			}
			
			
		}
		if(F)
		{
			printf("YES\n");
			continue;
		}
		map<int,int> aan(aa);
		long long l = (long long)0;
		long long r = (long long)0;
		
		
		for(int i = n-1;i >= 0;i--)
		{
			r += (long long)a[i];
			long long l = sum - r;
			long long ca = (l - r);
			if(ca == 0)
			{
				F = 1;
				break
			}
			if(ca < 0)
			{
				break;
			}
			if(ca%2)
			{
				
			}
			else
			{
				aan[i] = 0;
				ca /= 2;
				if(aan[ca] == 1)
				{
					F = 1;
					break;
				}
			}
			
			
		}
		if(F)
		{
			printf("YES\n");
			continue;
		}
		
		
		
		
		
	}

 return 0;
}


