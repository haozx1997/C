#include<bits/stdc++.h>

using namespace std;



int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n == -1)
		{
			break;
		}
		double c = 3-(double)n/360*12;
		while(c >= 12)
		{
			c -= 12;
		}
		while(c < 0)
		{
			c += 12;
		}
		
		
		if(c == (int)c)
		{
			printf("Exactly %d o'clock\n",(int)c);
		}
		else
		{
			int cc = (int)c+1;
			while(cc >= 12)
			{
				cc -= 12;
			}
			while(c < 0)
			{
				cc += 12;
			}
			printf("Between %d o'clock and %d o'clock\n",(int)c,cc);
		}
	}
}

