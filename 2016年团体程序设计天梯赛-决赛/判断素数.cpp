#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#define ll long long

using namespace std;

int isz(ll x)
{
	if( x == 1||x ==0)
	 return 0;
	for(ll i = 2;i*i<=x;i++)
	{
		if(!(x%i))
		 return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll xx;
		scanf("%lld",&xx);
		if(isz(xx))
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
}



