#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	
//	int n = 9; 
//	int k = 4;
	for(int n = 3;n <= 10;n++)
	{
		for(int k = 0;k <= n;k++)
		{
			for(int i=1;i<=n;i++)
				a[i]=i;
			long long ans=0;
			do
			{
				int good = 0;
				for(int i=1;i<=n;i++)
				{
					if(abs(a[i]-i) == 1)
					{
						good++;
					}
				}
				if(good == k)
				{
					ans++;
	//				for(int i=1;i<=n;i++)
	//				{
	//					printf("%d ",a[i]);
	//					
	//				}printf("\n");
				}
		
			}
			while(next_permutation(a+1, a + n+1)) ;//顺序过 看7行 一定注意范围 
			printf("%d %d %d\n",n,k,ans);
		}
		printf("\n");
	}
	
	 
}
