#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	char s[1001010];
	while(~scanf("%s",s))
	{
		if(s[0] == '0')return 0;
		
		
		long long num =0;
		int len = strlen(s);
		while(len!=1)
		{
			int num =0;
			for(int i = 0;i < len;i++)
			{
				num += (long long)s[i]-'0';
			}
			sprintf(s,"%lld",num);
			len = strlen(s);
		}
		printf("%s\n",s);
	}
}
