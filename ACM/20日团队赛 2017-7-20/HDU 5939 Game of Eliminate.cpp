#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	int n,m,T;
	int abv,bot;
	char s[3000];
	scanf("%d",&T);
	for(int II= 0 ;II < T;II++)
	{
		abv = 0;
		bot = 3000;
		scanf("%d%d",&n,&m);
		for(int i =n ; i > 0;i--)
		{
			scanf("%s",s);
			for(int j = 0; j < m;j++)
			{
				if(s[j] == '*')
				{
					abv=max(abv,i);
					bot = min(bot,i); 
					break;
				}
			}
		}
		if(bot>2)
		{
			bot = 2;
		}
		//printf("%d %d\n",abv,bot);
		printf("Case #%d: %d\n",II+1,abv-bot+1);
		
	}



 return 0;
}


