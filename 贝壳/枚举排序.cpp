#include<stdio.h>
void ps(int n,int*a,int c)
{
	if(c==n)
	{
		for(int i=0;i<n;i++)printf("%d",a[i]);
		printf("\n");
	}
	else for(int i=1;i<=n;i++)
	 {
	 	int ok=1;
	 	for(int j=0;j<c;j++)
	 	 if(a[j]==i)ok=0;
	 	if(ok)
		 {
	 		a[c]=i;
	 		ps(n,a,c+1);
		 }
	 }
}
int main()
{
	int a[4]={1,2,3,4};
	int i;
	int*p=a;
	for(i=0;i<4;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	ps(4,a,0);
	
}
