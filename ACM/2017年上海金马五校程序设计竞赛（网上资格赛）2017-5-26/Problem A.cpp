#include<bits/stdc++.h>

using namespace std;

int main()
{
	char s[1010];
	while(~scanf("%s",s))
	{
		int now,ans = 0;
		int l = 0;
		int len = strlen(s);
		for(int i = 0;i < len;i++)
		{
			if(s[i] == '(')
			{
				l++;
				ans = max(ans,l);
			}
			else
			{
				l--;
			}
			if(l<0)
			{
				break;
			}
		}
		if(l == 0)
		{
			printf("YES %d\n",ans);
		}
		else
		{
			printf("NO\n");
		}
		
		
	 } 




 return 0;
}


