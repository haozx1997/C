#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
	int f[1010][1010];

int main()
{ 	
	int n;

	while(scanf("%d",&n),n)
	{

		int a[1010];
		memset(a,0,sizeof(a));
		 memset(f,0,sizeof(f));

		for(int i = 1;i<=n;i++)
		 {
		 	scanf("%d",&a[i]);
		 }
		 int m;
		 scanf("%d",&m);
		if(m<5) 
		{
			printf("%d\n",m);
			continue;
		}
		 sort(a+1,a+1+n);
		
		int v = m-5;
		for(int i = 1;i<n;i++)
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
		
		printf("%d\n",m - f[n-1][v] - a[n]);
	}
	return 0 ;
 } 
