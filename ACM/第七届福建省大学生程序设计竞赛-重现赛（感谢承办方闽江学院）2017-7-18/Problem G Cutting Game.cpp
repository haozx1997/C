#include<stdio.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int I = 0; I < T;I++)
	{
		int n;
		int ans = 0;
		scanf("%d",&n);
		while(1)
		{
			if(n == 1)
			{
				break;
			}
			n /= 2;
			ans++;
		}
		printf("Case %d: %d\n",I+1,ans+1);
	}




 return 0;
}


