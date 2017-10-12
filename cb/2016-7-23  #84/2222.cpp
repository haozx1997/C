#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


long long er(int nn)
{
	long long ans = 1;
	for(int i = 0;i<nn;i++)
	{
		ans *=2;
	}
	return ans;
}
int main()
{
	long long n[35];
	for(int i = 0;i<35;i++)
	{
		n[i] = er(i);
		
	}
	for(int i = 0;i<35;i++)
	{
		printf("%lld %d\n",n[i],i);
		
	}
	
}
