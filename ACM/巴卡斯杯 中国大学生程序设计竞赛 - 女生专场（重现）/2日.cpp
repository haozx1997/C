#include<stdio.h>
#include<string.h>



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("1");
		for(int i = 0;i<n-1;i++)
		 {
		 	printf("0");
		 }
		 printf("\n");
	}
}
