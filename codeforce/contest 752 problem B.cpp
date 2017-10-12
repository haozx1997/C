/*											 *\
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
\*											 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s1[2000];
char s2[2000];

map<char,char>t;
map<char,char>::iterator it;


int main()
{	
	while(~scanf("%s%s",s1,s2))
	{
		int len = strlen(s1);
		t.clear();
		int F = 0;
		int ss = 0;
		for(int i = 0; i < len;i++)
		{
			
			if(t[s1[i]] == 0&&t[s2[i]] == 0)
			{
				t[s1[i]] = s2[i];
				t[s2[i]] = s1[i];
				if(s1[i]!=s2[i])
				ss++;
			}
			else
			{
				if(t[s1[i]] != s2[i]||t[s2[i]] != s1[i])
				{
					F = 1;
					break;
				}
			}
		}
		
		if(F == 0)
		{
			printf("%d\n",ss);
			for(it = t.begin(); it != t.end();it++)
			{
				if(it->first==it->second)
				{
					continue;
				}
				printf("%c %c\n",it->first,it->second);
				t.erase(it->second);
			}
		}
		else
		{
			puts("-1");
		}
		
		
	}


 return 0;
}


