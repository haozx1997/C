#include<stdio.h>
#include<string.h>

int d(int n)
{
	return n%9;
}

int main()
{
//	freopen("1.in","r",stdin);
	int n = 0;
	//while(n++,n<300)
	{
		int ans = 0;
		for(int i = 1;i <= 200;i++)
		{
			printf("%d %d %d\n",i,d(i),i%9);
		}

		printf("%d   %d\n",n,ans);
	}
}
