#include<stdio.h> 
#include<algorithm>

using namespace std;

long long abss(long long x)
{
	if(x>0)
		return x;
		return -x;
}

int main()
{
	//freopen("1.txt","r",stdin);
	long long n;
	while(~scanf("%I64d",&n))
	{
		long long a[300100];
		long long sum = 0;
		
		for(long long i = 1;i <= n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(long long i = 1;i <= n;i++)
		{
			sum += abss(a[i]-i);
		}
		
		printf("%I64d\n",sum);
		
		
		
	}

}
