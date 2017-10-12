#include<stdio.h> 
#include<algorithm>

using namespace std;

int main()
{
	//freopen("1.txt","r",stdin);
	int n,k,n2;
	while(~scanf("%d%d",&n,&k))
	{
		k -= (n*2);
		int ans = k - n;
		if(ans<=0)
		{
			printf("%d\n",-ans);
		}
		else
		{
			printf("0\n");
		}
	}

}
