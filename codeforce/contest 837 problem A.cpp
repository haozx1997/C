#include<bits/stdc++.h>
#define ll long long
using namespace std;


char s[20000];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		getchar();
		gets(s);
		int now = 0;
		int ans = 0;
		for(int i =0 ;i < n;i++)
		{
			if(s[i] == ' ')
			{
				now = 0;
			}
			else
			{
				if(s[i] < 'a')
				{
					now++;
				}
			}
			ans = max(ans,now);
		}
		printf("%d\n",ans);
	}



 return 0;
}


