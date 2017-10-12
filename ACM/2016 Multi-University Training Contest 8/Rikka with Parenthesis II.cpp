#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		char c[100010];
		scanf("%s",c);
		if(n%2)
		{
			printf("No\n");
			continue;
		}
		int _l = 0;//×óÀ¨ºÅ 
		int if_have_back = 0;
		int l_ = 0;
		for(int i = 0;i < n;i++)
		{
			if(c[i] == '(')
			{
				_l++;
				if(i>0&&(c[i-1] == ')'))
				{
					if_have_back = 1;
				}
			}
			else
			{
				
				if(_l != 0)
				{
					_l--; 
				}
				else
				{
					l_++;
				}
			}
		}
		if((l_ == 0)&&(_l == 0))
		{
			if(if_have_back)
			{
				printf("Yes\n");
				continue;
			}
			else
			{
				printf("No\n");
				continue;
			}
		}
		else if((l_ == 1)&&(_l == 1))
		{
			printf("Yes\n");
			continue;
		}
		else if((l_ == 2)&&(_l == 2))
		{
			printf("Yes\n");
			continue;
		}
		
		printf("No\n");
	}
}


