#include<bits/stdc++.h>

using namespace std;

char ans[3001000];
char t[3001000];
int x;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(ans,0,sizeof(ans));
//		for(int i = 0;i < 10;i++)
//		{
//			ans[i] = 'a';
//		}
//		ans[10] = 0;
		int len = 0;
		int tlen = 0;
		int k;
		for(int i = 0;i < n;i++)
		{
			scanf("%s%d",t,&k);
			tlen = strlen(t);
			for(int j = 0; j <k;j++)
			{
				scanf("%d",&x);
				len = max(len,x+tlen-1);
				x--;
				int nowlen = strlen(ans+x);
				
				if(nowlen>tlen)
				{
					continue;
				}
				else
				{
					char o = ans[x+tlen];
					strcpy(ans+x+nowlen,t+nowlen);
					ans[x+tlen] = o;

				}
				


//				int ii = x;
//				
//				ii += nowlen;
//				
//				
//				for(int jj = nowlen;jj<tlen;jj++)
//				{
//					if(ans[ii] == 0)
//					{
//						ans[ii] = t[jj];
//					}
//					ii++;
//				}
				
				
				
			}
		//	puts(ans);
		}
		for(int i = 0;i < len;i++)
		{
			if(ans[i] == 0)
			{
				printf("a");
			}
			else
			{
				printf("%c",ans[i]);
			}
		}
		
		printf("\n");
		
	}




 return 0;
}


