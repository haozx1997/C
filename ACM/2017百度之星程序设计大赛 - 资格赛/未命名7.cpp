#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int a[10];
	for(int i =0 ;i < 6;i++)
	{
		if(i < 3)
		{
			a[i] = 0;
		}
		else
		{
			a[i] = 1;
		}
	}
	for(int i =0 ;i < 6;i++)
		{
			printf("%d",a[i]);
		}
		puts("");
	do
	{
		for(int i =0 ;i < 6;i++)
		{
			printf("%d",a[i]);
		}
		puts("");

	}
	while(next_permutation(a, a + 6)) ;





 return 0;
}


