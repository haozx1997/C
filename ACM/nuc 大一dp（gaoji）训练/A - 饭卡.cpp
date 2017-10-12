#include<stdio.h>

#include<string.h>
#include<algorithm>
using namespace std;
		int a[1010];
		int f[1010][1010];
int main()
{	printf("!!!");
	int n;

	while(scanf("%d",&n),n)
	{
		int a[1010];
		int f[1010][1010];
		int sum = 0,max = 0;
		for(int i = 0;i<n;i++)
		 {
		 	scanf("%d",&a[i]);
		 	sum+=a[i];
		 }
		 int m;
		 scanf("%d",&m);
		 if(m-sum>=5)
		 {
		 	printf("%d\n",m-sum);
		 	continue;
		 }
		 sort(a,a+n);
		 memset(f,0,sizeof(f));
		int v = m-5;
		for(int i = 1;i<=n;i++)
		{
			for(int j = v;j>=a[i];j--)
			{
				if(f[i-1][j]<f[i-1][j-a[i]]+a[i])
				 {
				 	f[i][j] = f[i-1][j-a[i]]+a[i];
				 }
				 else
				    f[i][j] = f[i-1][j];
				      
			}
			
		}
		int ans = m - f[n][v] - a[n-1];
		printf("%d\n",ans);
	}
 } 
