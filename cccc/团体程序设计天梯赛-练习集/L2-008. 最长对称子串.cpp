#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	char s[1010];
	gets(s);
		int len = strlen(s);
		int ans = 0;
		int anss = 0;
		for(int i = 0;i<len ;i++)
		{
			
			if(s[i] == s[i+1])
			{
				ans = 0;
				int l,r;
				for(l = i,r = i+1;l>=0&&r<len;l--,r++)
				{
					if(s[l] == s[r])
					{
						ans += 2;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				ans = 1;
				int l,r;
				for(l = i-1,r = i+1;l>=0&&r<len;l--,r++)
				{
					if(s[l] == s[r])
					{
						ans += 2;
					}
					else
					{
						break;
					}
				}
			}
			
			if(anss<ans) anss = ans;
		}
		printf("%d\n",anss);
		
	
}
