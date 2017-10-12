#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char lr[200200];
	long long a[200200];
	
	scanf("%s",lr);
	for(int i = 0;i < n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	int f = 1;
	
	long long ans;
	for(int i = 0;i < n-1;i++)
	{
		if(f)
		{
			if((lr[i] == 'R')&&(lr[i+1] == 'L'))
			 {
			 	ans = (a[i+1]-a[i])/2;
			 	f = 0;
			 }
		}
		else
		{
			if((lr[i] == 'R')&&(lr[i+1] == 'L'))
			 {
			 	if((a[i+1]-a[i])/2<ans)
			 	 {
			 	 	ans = (a[i+1]-a[i])/2;
				  }
			 }
		}
	}
	if(f)
	 {
	 	printf("-1\n");
	 	return 0;
	  } 
	printf("%I64d\n",ans);
	
}
