#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define ll long long
using namespace std;



int main()
{
	int T;
	 scanf("%d",&T);
	 while(T--)
	 {
	 	int min  = 99999;
	 	ll s;
	 	int n,a[100100];
	 	scanf("%d%I64d",&n,&s);
	 	for(int i = 0;i < n;i++)
	 	{
	 		scanf("%d",&a[i]);
		 }
		int head = 0;
		int tail = 0;
		int len;
		ll sum = a[0];
		while(tail<n) 
		{
	//		printf("%lld %lld",head,tail);
			
			
			if(sum < s)
			{	
				
				tail++;
				sum += a[tail];
	//			printf("\n");
			}
			else if(sum >= s)
			{
				
				len = tail - head + 1 ;
				sum -= a[head];
				head++;
				
	//	printf(" %lld\n",len);
				if(len < min)
				{
					min = len;
				}
			}
			
		}
		if(min>n)
		 min = 0;
		printf("%d\n",min); 
		 
	 }
}

