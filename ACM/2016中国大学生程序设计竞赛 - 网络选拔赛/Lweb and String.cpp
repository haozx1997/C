#include<stdio.h>
#include<set>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
	int T;
	char s[100010];
	scanf("%d",&T);
	set<char> c;
	
	for(int t = 0;t < T;t++)
	{
		c.clear();
		scanf("%s",s);
		int len = strlen(s);
		for(int i = 0;i < len ;i++)
		{
			c.insert(s[i]);
		}
		printf("Case #%d: %d\n",t+1,c.size());
	}
}
