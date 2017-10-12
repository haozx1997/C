#include<bits/stdc++.h>

using namespace std;

set<long long> s;
int n;
long long a[50];
long long nn;
void dfs(int ii,long long en)
{
//	nn++;
	if(ii == n)
	{
		s.insert(en);
	//	printf("set %d  %lld\n",ii,en);
		return;
	}
	dfs(ii+1,en+a[ii+1]);
	dfs(ii+1,en-a[ii+1]);
	
}

int main()
{
	
	while(~scanf("%d",&n))
	{
	//	nn = 0;
		s.clear();
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld",&a[i]);
		}
		a[n+1] = (long long)0;
		dfs(0,(long long)0);
		printf("%d\n",s.size());
	//	printf("%lld\n",nn);
	}




 return 0;
}


