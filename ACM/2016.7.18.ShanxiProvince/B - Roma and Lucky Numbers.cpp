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
	int ans = 0;

	for(int i = 0 ;i<n;i++)
	{
		char s[500];
		scanf("%s",s);
		int ans_ = 0;
		for(int i = 0; i<strlen(s);i++)
		{
			if(s[i] == '4'||s[i] == '7')
			ans_++;
			
		}
		if(ans_<=k)
		 ans++;
	}
	printf("%d\n",ans);
}
