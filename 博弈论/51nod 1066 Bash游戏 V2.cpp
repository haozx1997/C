#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d",&n);
		k = n%7;
		printf("%s\n",(k == 0||k == 2) ? "B" : "A");

	}
}
