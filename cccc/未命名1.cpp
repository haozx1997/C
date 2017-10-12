#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[200],b[200];
	for(int i = 0;i<n;i++)
	{
		scanf("%d/%d",&a[i],&b[i]);
	}
	for(int i = 0;i<n;i++)
	{
		printf("%d/%d",a[i],b[i]);
	}
}
