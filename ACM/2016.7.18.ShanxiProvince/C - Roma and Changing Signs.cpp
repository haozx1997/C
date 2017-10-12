#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#define ll long long

using namespace std;


int main()
{
	
	int n,k;
	
	
 	scanf("%d%d",&n,&k);
	
		int a_;
	int sum = 0;
	int a[10100];
	int ai = 0;
			int min = 5000000;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a_);
		
		if(a_>0)
		{
			sum +=a_;
			if(a_<min)
			{
				min = a_;
			}
		}
		else if(a_==0)
		{
			a[ai++] = 0;
			min = 0;
		}
		else 
		{
			a[ai++] = 0-a_;
		}
		
	}
	
	sort(a,a+ai);
	
	if(ai == 0)
	{
		if(k%2)
		 sum -=min*2;
		 
	}
	else 
	{
			if(ai==k)
	{
//		printf("11111\n");
		for(int i = 0;i<ai;i++)
		{
			sum+=a[i];
		}
	}
	else if(ai>k)
	{
//		printf("2222\n");
		for(int i = 0;i<k;i++)
		{
			sum+=a[ai-i-1];
//				printf("%d\n",sum);

		}
		for(int i = 0;i<ai-k;i++)
		{
			sum-=a[i];
//				printf("%d\n",sum);

		}
		
	}
	else
	{//ai<k
//		printf("33333\n");
		for(int i = 0;i<ai;i++)
		{
			sum+=a[i];
		}
		if((k-ai)%2)
		sum -= a[0]*2;
	}
	}
	printf("%d\n",sum);
	
	
}
