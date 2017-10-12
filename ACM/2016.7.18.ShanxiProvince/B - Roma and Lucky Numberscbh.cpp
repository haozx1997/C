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
	int a[100010];
	int a_;
	int _i =0;
	int n,k;
	scanf("%d%d",&n,&k);
	int sum = 0;
	
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a_);
		if(a_<0)
		 _i++;
		a[i] = a_; 
	}
	sort(a,a+n);
	if(k<=_i)
	{
		for(int i = 0;i<k;i++)
		{
			a[i] = 0-a[i];
		}
	}
	else
	{
		for(int i = 0;i<k-_i;i++)
		{
			a[i] = 0-a[i];
		}sort(a,a+n);
		if(!(k-_i)%2)
		{
			a[0] = 0-a[0];	
		}
	}
	
	for(int i = 0;i<n;i++)
	{
		
		sum+=a[i];
	}
	printf("%d\n",sum);
}
