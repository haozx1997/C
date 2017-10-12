#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	char s[100];
	char s1[100];
	
	while(~scanf("%s",s))
	{
		int n = 0;
		int len = strlen(s);
		for(int i = 0;i < len;i++)
		{
			switch(s[i])
			{
				case '0':
					s1[n++] = '0';
					break;
				case '1':
					s1[n++] = '1';
					break;
				case 'B':
					if(n)
					{
						n--;
					}
					else
					{
						
					}
					break;
					
			}
		}
		s1[n] = 0;
		//printf("%d\n",n);
		printf("%s\n",s1);
	}

/*

01B0

0BB1
*/


 return 0;
}


