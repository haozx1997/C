#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
	return !b? a : gcd(b,a%b);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long a;
		scanf("%I64d",&a);
		long long go = a*4;
		long long gg = gcd(go,a+1);
		
		printf("%I64d\n",go/gg+1);
		
	}




 return 0;
}


