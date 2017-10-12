#include<bits/stdc++.h>

using namespace std;

map<char,int>ctn;

int a[6000];
int wo[1000100];

int main()
{
	int T;
	scanf("%d",&T);
	ctn['a'] = 2;
	ctn['b'] = 2;
	ctn['c'] = 2;
	ctn['d'] = 3;
	ctn['e'] = 3;
	ctn['f'] = 3;
	ctn['g'] = 4;
	ctn['h'] = 4;
	ctn['i'] = 4;
	ctn['j'] = 5;
	ctn['k'] = 5;
	ctn['l'] = 5;
	ctn['m'] = 6;
	ctn['n'] = 6;
	ctn['o'] = 6;
	ctn['p'] = 7;
	ctn['q'] = 7;
	ctn['r'] = 7;
	ctn['s'] = 7;
	ctn['t'] = 8;
	ctn['u'] = 8;
	ctn['v'] = 8;
	ctn['w'] = 9;
	ctn['x'] = 9;
	ctn['y'] = 9;
	ctn['z'] = 9;
	
	while(T--)
	{
		int n,k;
		memset(wo,0,sizeof(wo));
		scanf("%d%d",&n,&k);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		char nows[100];
		int now;
		for(int i = 0;i < k;i++)
		{
			scanf("%s",nows);
			int len = strlen(nows);
			for(int j = 0;j < len;j++)
			{
				nows[j] = (ctn[nows[j]]+'0');
				sscanf(nows,"%d",&now);
			}
			wo[now]++;
			
		}
		for(int i = 0;i < n;i++)
		{
			printf("%d\n",wo[a[i]]);
		}
		
	}




 return 0;
}


