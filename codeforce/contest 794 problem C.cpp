#include<bits/stdc++.h>

using namespace std;

int main()
{
	char s1[400000];
	char s2[400000];
	while(~scanf("%s%s",s1,s2))
	{
	//	printf("awsd\n");
		int len = strlen(s1);
		multiset<char> ss1;
		multiset<char> ss2;
		multiset<char> ::iterator it;
		ss1.clear();
		ss2.clear();
		
		
		for(int i = 0;i < len;i++)
		{
			ss1.insert(s1[i]);
			ss2.insert(s2[i]);
			
		}
		
		char ans[400000];
		char s1now,s2now,now;
		ans[len] = '\0';
		int l = 0;
		int r = len - 1; 
		for(int i = 0;i < len;i++)
		{
			it = ss2.end();
			it--;
			s2now = *it;
			it = ss1.begin();
			s1now = *it;
			
			if(i%2)
			{
				it = ss2.end();
				it--;
				ss2.erase(it);
				now = s2now;
			}
			else
			{
				it = ss1.begin();
				ss1.erase(it);
				now = s1now;
			}//printf("wtf %c\n",ans[i]);
			if(s1now<=s2now)
			{
				ans[l++] = now;
			}
			else
			{
				ans[r--] = now;
			}
			printf("WTF %c  ^\n",now);
			printf("%s\n",ans);
		}
		printf("%s\n",ans);
	}


 return 0;
}


