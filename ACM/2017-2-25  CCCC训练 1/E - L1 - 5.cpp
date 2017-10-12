#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<queue>
#include<math.h>

using namespace std;


int ch(char s)
{
	if(s<='9'&&s>='0')
	{
		return 1;
	}
	return 0;
 } 


int main()
{
	int NN;
	scanf("%d",&NN);
	getchar();
	while(NN--)
	{
		char s[1000];
		int ss[1000];
		int sn  =0;
		gets((s+1));
		s[0] = ' '; 
		int len = strlen(s);
		for(int i = 0;i < len;i++)
		{
			if(ch(s[i]) == 0&&ch(s[i+1]) == 1)
			{
				ss[sn++] = i+1;
			}
			if(ch(s[i]) == 1&&ch(s[i+1]) == 0)
			{
				s[i+1] = '\0';
			}
			
		}
		
		for(int i = 0;i<sn;i++)
		{
			int q ;
			sscanf((s+ss[i]),"%d",&q);
			printf("%d ",q);
		}
		printf("\n");
	}
	return 0;
}






