#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<set>
#define ll long long
using namespace std;

set<char> se;

char s[100101];


int main()
{
	int n ;
	se.clear();
	int m[200];
	memset(m,0,sizeof(m));
	scanf("%d",&n);
	scanf("%s",s);
	for(int i = 0;i<n;i++)
	{
		se.insert(s[i]);
	}
	int head = 0;
	int tail = 0;
	int min = n;
	int len = 0;
	int msize = 1;
	m[s[0]] = 1;
	int size = se.size();

	while(tail<n)
	{

		if(msize==size)
		{
			len = tail - head + 1;
			m[s[head]]--;
			if(m[s[head]] == 0)
			 {
			 	msize--;
			 }
			head++;
			if(len<min) min = len;
		}
		else
		{
			
			tail++;
			if(m[s[tail]] == 0)
			 {
			 	msize++;
			 }
			m[s[tail]]++; 
		}
	}
	printf("%d\n",min);
}
