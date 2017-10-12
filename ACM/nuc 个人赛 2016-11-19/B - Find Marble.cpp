#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define MaxInt 0x3f3f3f

using namespace std;

int map[100100];

int main()

{
	int n,e,s;
	while(scanf("%d%d%d",&n,&s,&e)!=EOF)
	{
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&map[i]);
		}
		int t = 0;
		while(t < n+10)
		{
			
			if(s == e)
			{
				break;
			}
			s = map[s];
			t++;
		}
		if(t<n+5)
		{
			printf("%d\n",t);
		}
		else
		{
			printf("-1\n");
		}
		
	}
}
