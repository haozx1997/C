#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int ans = 1;
	scanf("%d",&n);
	int i = n;
	while(n--)
	{
		ans*=2;
	}
	printf("2^%d = %d\n",i,ans);
	system("pause");
}
