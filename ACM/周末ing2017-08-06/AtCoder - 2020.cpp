#include<bits/stdc++.h>
#define ll long long
using namespace std;


char s[100100];

int main()
{
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		int n = len;
		int F= 0;
		for(int i = 0;i < len-2;i++)
		{
			if(s[i] == s[i+1])
			{
				printf("%d %d\n",i+1,i+2);
				F = 1;
				break;
			}
			if(s[i] == s[i+2])
			{
				printf("%d %d\n",i+1,i+2+1);
				F = 1;
				break;
			}
			
		}
		
		if(!F)
		{
			if(s[n-1] == s[n-2])
			{
				printf("%d %d\n",n-1,n);
				F = 1;
			}
		}
		
		if(!F)
		{
			printf("-1 -1\n");
		}
	}
/*
needed 
atcoder
Sample Output 

The string s2s3s4s5 = eede is unbalanced. There are also other unbalanced substrings. For example, the output 2 6 will also be accepted.

Sample Input 2







*/



 return 0;
}


