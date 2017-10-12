#include<bits/stdc++.h>

using namespace std;

char s[100100];

int main()
{
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		char mm = 'a';
		char mmm = 'z';
		int nn = 0;
		int t = 0;
		
		while(1)
		{
			for(int i = t;i<len;i++)
			{
				if(s[i]>mm)
				{
					mm = s[i];
					nn = 0;
					t = i+1;
				}
				if(s[i] == mm)
				{
					nn++;
					t = i+1;
				}
				mmm = min(mmm,s[i]);
			}
			
			for(int i = 0;i < nn;i++ )
			{
				printf("%c",mm);
			}
			if(mmm == mm)
			{
				break;
			}
			mm = 'a';
			nn = 0;
		}
		puts("");
		
		
	}




 return 0;
}


