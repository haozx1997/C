#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


int enen(int n)
{
	char nn[100];
	sprintf(nn,"%d",n);
	int len = strlen(nn);
	for(int i = 1;i < len;i++)
	{
		if(nn[i-1]>nn[i])
		{
			return 0;
		}
	}
	return 1;
}

int main() 
{
//	freopen("1.in","r",stdin);
	int N;
	while(~scanf("%d",&N))
	{
		int n;
		int ans = 0;
		for(int i = 1; i <= N;i++)
		{
			ans += enen(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
