#include<stdio.h>
void ps(int n,int*a,int c)
{
	for(int i=0;i<c;i++) printf("%d",a[i]);
	printf("\n");
	int s=c?a[c-1]+1:0;
	for(int i=s;i<n;i++)
	{
		a[c]=i;
		ps(n,a,c+1);
		
	}
}
int main()
{
	int a[4]={};
	int i;
	int*p=a;
	for(i=0;i<4;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	ps(4,p,0);
	
}
