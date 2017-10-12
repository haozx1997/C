#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		vector <int > v;
		v.clear();
		int min = 1e5+5;
		int max = -1e5+5; 
		int a;
		for(int i = 0;i < n ;i++)
		{
			scanf("%d",&a);
			if(a<min) min = a;
			if(a>max) max = a;
			
			v.push_back(a);
		}
		int ans = 0;
		int ansn = 0;
		int num = 0;
		for(int i = min;i<=max;i++)
		{
			num = count(v.begin(),v.end(),i);
		//	printf("%d\n",num);
			if(num>ans)
			 {
			 	ans = num;
			 	ansn = i;
			 }
			 else if(num == ans&&i<ansn)
			 {
			 	ans = num;
			 	ansn = i;
			 }
		}
		printf("%d %d\n",ansn,ans);
	}
	return 0;
}
