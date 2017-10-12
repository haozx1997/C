#include<stdio.h> 
#include<algorithm>

using namespace std;

int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	while(~scanf("%I64d",&n))
	{
		long long a;
		long long sum = 0;
		
		for(int i = 0 ;i< n;i++)
		{
			scanf("%I64d",&a);
			sum += a;
		}
		if(sum%n)
		{
			printf("%d\n",n-1);
		}
		else
		{
			printf("%d\n",n);
		}
//		long long a[100100];
//		long long sum = 0;
//		long long resum = 0;
//		for(long long i = 0;i < n;i++)
//		{
//			scanf("%I64d",&a[i]);
//			sum += a[i];
//		}
//		
//		sort(a,a+n);
//		a[n] = 0;
//		for(long long i = n-1;i>=0;i--)
//		{
//			
//			if(!(sum%(i+1)))
//			{
//				printf("%I64d\n",i+1);
//				break;
//			}
//			else
//			{	sum -= a[i];
//				long long re = sum % (i);
//				resum += a[i];
//				if(re <= resum)
//				{
//					printf("%I64d\n",i);
//					break;
//				}
//			}
//		}
	}
	// 4 1 1 1 5
}
