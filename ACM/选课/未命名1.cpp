#include<stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,m,i;
	int f[1005];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int min;
		for(i=0;i<m;i++)
		{
			scanf("%d",&f[i]);
		}
		sort(f,f+m);
		min=f[m-1];
		for(i=0;i<m-n+1;i++)
		{
			if((f[i+n-1]-f[i])<min) min=(f[i+n-1]-f[i]);
		}
		printf("%d\n",min);
	}

}
