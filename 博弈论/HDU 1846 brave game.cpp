#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		int n,m;
		scanf("%d%d",&n,&m);
		if(m>=n)
		{
			printf("first\n");
			continue;
		}
		if((n%(m+1))==0)
		{
			printf("second\n");
			continue;			
		}
		printf("first\n");
		
	}
	return 0;
}
 
