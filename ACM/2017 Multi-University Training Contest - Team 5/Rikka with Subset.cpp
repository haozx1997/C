/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int b[20000];
int a[20000];
int dp[20000];
int tr[20000];

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 0;i <= m;i++ )
		{
			scanf("%d",&b[i]);
		}
		int an = 0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(tr,0,sizeof(tr));
		dp[0] = 1;
		for(int i = 1 ;i <= m;i++)
		{
			tr[i] = b[i] - dp[i];
			for(int j = 0;j < tr[i];j++)
			{
				a[an++] = i;
				for(int ii = m;ii >= i;ii-- )
				{
					dp[ii] += dp[ii - i];
				}
				
				
			}
			
			
		}
		printf("%d",a[0]);
		for(int i = 1;i < n;i++)
		{
			printf(" %d",a[i]);
		}
		
		puts("");
	}





 return 0;
}


