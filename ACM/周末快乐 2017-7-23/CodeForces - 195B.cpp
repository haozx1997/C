#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int c = ceil((double)n/m);
		
		
		for(int i =0 ;i < c;i++)
		{
			int l,r;int F = 0;
			if(m%2)
			{
				printf("%d\n",(m+1)/2);
				n--;
				if(n == 0)
				{
					break;
				}
				
				l = (m+1)/2-1;
				r = (m+1)/2+1;
				
				while(r<=m)
				{
					printf("%d\n",l);
					l--;
					n--;
					if(n == 0)
					{
						F = 1;
						break;
					}
					printf("%d\n",r);
					n--;
					if(n == 0)
					{
						F = 1;
						break;
					}
					r++;
				}
				if(F)
				{
					break;
				}
				
			}
			else
			{
				l = (m)/2;
				r = (m)/2+1;
				
				while(r<=m)
				{
					printf("%d\n",l);
					l--;
					n--;
					if(n == 0)
					{
						F = 1;
						break;
					}
					printf("%d\n",r);
					n--;
					if(n == 0)
					{
						F = 1;
						break;
					}
					r++;
				}
				if(F)
				{
					break;
				}
			}
		}
		
	}




 return 0;
}


