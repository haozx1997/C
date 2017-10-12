#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<queue>
#include<math.h>

using namespace std;



int main()
{
	int n,m;
	int a[2000];
	while(~scanf("%d%d",&n,&m))
	{
		memset(a,0,sizeof(a));
		a[1]  =1;
		while(n!=1)
		{
			a[n] = 1;
			n/=2;
		}
		while(m!=1)
		{
			if(a[m] == 1)
			{
				break;
			}
			else
			{
				m/=2;
				
			}
		}
//		for(int i=0;i<15;i++)
//		{
//			printf("a[%d] %d\n ",i,a[i]);
//		}
		int ans = 0;
		for(int i = m;i>=1;i--)
		{
			ans += a[i]; 
		}
		printf("%d\n",m);
	}
	return 0;
}






