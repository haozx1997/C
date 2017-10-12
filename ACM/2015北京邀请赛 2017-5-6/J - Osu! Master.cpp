#include<stdio.h>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int cn;
		int ans = 0;
		char s[10];
		for(int i = 0; i < n;i++)
		{
			scanf("%s",s);
			if(s[0] == 'C'||s[0] == 'B')
			{
				scanf("%d",&cn);
				if(cn == 1)
				{
					ans++;
				}
			}
			if(s[0] == 'S')
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}




 return 0;
}


