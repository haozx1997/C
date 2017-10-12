#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,w,c,wi,ci;
		scanf("%d%d%d",&n,&w,&c);
		int wa = 0,ca = 0;
		for(int i = 0; i < n;i++ )
		{
			scanf("%d",&wi);
			wa += wi;
		}
		for(int i = 0; i < n;i++ )
		{
			scanf("%d",&ci);
			ca += ci;
		}
		if(w>=wa&&c>=ca)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}





 return 0;
}


