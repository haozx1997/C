#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>

using namespace std;


int main()
{
	int t;
	int a;
	scanf("%d",&t);
	set<int> s;
	while(t--)
	{
		s.clear();
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			s.insert(a);
		}
		printf("%d ",s.size());
		set<int>::iterator it;
		for(it = s.begin();it!=s.end();it++)
		{
			printf("%d ",*it);
		}
		printf("\n");
	}
}
