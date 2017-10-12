#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n,d;
	while(~scanf("%d%d",&n,&d))
	{
		double maxx = 180 - (double)360/n;
		printf("1 2 ");
		if(maxx<=d)
		{
			printf("%d\n",3);
			continue;
		}
		double ev = maxx/(n-2);
		if(ev>d)
		{
			printf("%d\n",n);
			continue;
		}
		int need = d/ev;
		double a1 = (double)d - need*ev;
		double a2 = (double)(need+1)*ev - d;
		printf("%.2f %.2f %.2f %d \n",a1,a2,abs(ev-d),need);
		if(a1<a2)
		{
			if(abs(ev-d)<a1)
			{
				printf("%d\n",3);
			}
			else
			
			printf("%d\n",n - (need - 1));
		}
		else
		{
			if(abs(ev-d)<a2)
			{
				printf("%d\n",3);
			}
			else
			
			printf("%d\n",n - need);
		}
		
		
	}



 return 0;
}
/*
3 15
4 67
4 68
100000 1

*/

