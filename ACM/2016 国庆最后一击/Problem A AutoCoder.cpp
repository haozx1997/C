#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define MaxInt 32767

using namespace std;

long long two[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long summ(long long nn)
{
	return (1+nn)*nn/2;
}
int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		int how0;
		for(int i = 30;i >= 0 ;i--)
		{
			if(n>(two[i]-2))
			{
				how0 = i;
				break;
			}
		}
		long long ans = 0;
		for(int i = 1; i <= how0; i++)
		{
			long long num = (two[i]-2-two[i-1]);
			num = n-num-1;
			num /=two[i];
		//	printf("num %lld   summ %lld\n",num,summ(num));
			ans += summ(num);
		}
		printf("%lld\n",ans);
		
	}
}
