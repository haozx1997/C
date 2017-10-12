#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int abs(int n)
{
	if(n > 0)
		return n;
	return -n;	
}

int main() 
{
//	freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int a[2020];
		for(int i = 0;i < 2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+2*n);
//		for(int i = 0;i < 2*n;i++)
//		{
//			printf("a %d\n",a[i]);
//		}		
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
		//	printf("%d %d\n",a[2*n-i-1] , a[i]);
			ans += (a[2*n-i-1] - a[i]);
		}		
		printf("%d\n",ans);
		
				
	 } 
	return 0;
}
