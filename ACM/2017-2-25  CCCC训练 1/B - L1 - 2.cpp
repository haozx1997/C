#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int main()
{
	int nn;
//	printf("%d",' ');
	scanf("%d",&nn); 

	while(nn--)
	{
		int n;
		int m = 0;
		scanf("%d",&n);
		int a[10100];
		int b[10100];
		
		for(int i = 0; i< n;i++)
		{
			scanf("%d",&a[i]);
		 } 
		sort(a,a+n);
		int pre = 100000;
		for(int i = 0; i< n;i++)
		{
			if(a[i] != pre)
			{
				b[m++] = a[i];
			}
			pre  = a[i] ;
		 } 
		printf("%d ",m);
		for(int i = 0;i< m;i++)
		{
			printf("%d ",b[i]);
		 } 
		 printf("\n");
	}
 }
