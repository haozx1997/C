#include<bits/stdc++.h>

using namespace std;



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int sum = 1;
		int a ;
		scanf("%d",&n);
		
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			sum += a;
		}
		sum -= n;
		printf("%d\n",sum);
	}
}

