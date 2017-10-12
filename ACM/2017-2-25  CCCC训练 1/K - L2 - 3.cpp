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



int main()
{
	char s[10100];
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		int m = 0;
		int tree = 0;
		for(int i = 0;i<len;i++)
		{
			if(s[i] == 'd')
			{
				m++;
			}
			else
			{
				m--;
			}
			if(m>tree)
			{
				tree  = m;
			}
		}
		int u = 0;
		int btree = 0;
		int btreemax = 0;
		
		for(int i = 0;i<len;i++)
		{
			if(s[i] == 'u')
			{
				u++;
			}
			else
			{
				if(u <= 1)
				{
					btree++;
				}
				else
				{
					
					u-=1;
					btree-=(u);
				}
				u = 0;
				printf("u %d\n",btree);
				if(btree>btreemax)
				{
					btreemax = btree;
					}	
			}			
		}
		printf("%d => %d\n",tree,btreemax);
	}
}






