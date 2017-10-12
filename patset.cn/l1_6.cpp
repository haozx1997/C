#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()

{
	int n;
	scanf("%d",&n);
	int ans1 = 0;
	int ans2 = 0;
	int num;
	for(int i  = 0;i<n;i++)
	{
		scanf("%d",&num);
		if(num%2)
		{
			ans1++;
		}
		else
		 ans2++;
	}
	printf("%d %d\n",ans1,ans2);
}
