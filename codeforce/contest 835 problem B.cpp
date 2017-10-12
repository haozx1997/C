#include<bits/stdc++.h>

using namespace std;

char s[1001000];
int main()
{	
	long long n;
	while(~scanf("%I64d",&n))
	{
		long long sum = 0ll;
		scanf("%s",s);
		int len = strlen(s);
		char c;
		for(int i = 0; i < len;i++)
		{
			c = s[i];
			sum += (long long)c-'0';
		}
		if(sum>=n)
		{
			printf("0\n");
			continue;
		}
		int r = n - sum;
		sort(s,s+len);
		int ans = 0;
//		printf("%d\n",r);
		for(int i = 0;i < len;i++ )
		{
			ans++;
			r -= (9 - (s[i]-'0'));
			if(r <= 0)
			{
				break;
			}
//			printf("%d\n",r);
		}
		printf("%d\n",ans);
	}





 return 0;
}


