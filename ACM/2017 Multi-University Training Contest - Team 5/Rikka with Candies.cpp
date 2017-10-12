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

int main()
{

	int T ,n,m,q;
	int a[1000],b[1000];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		{
			for(int i =0; i  <n;i++)
			{
				scanf("%d",&a[i]);
				
				
			}
			for(int i =0; i  <m;i++)
			{
				scanf("%d",&b[i]);
				
			}
			
			
			
			for(int ii =0; ii  <q;ii++)
			{
				int qn;
				scanf("%d",&qn);
				int ans = 0;
				for(int i =0;i < n;i++)
				{
					for(int j = 0; j  <m;j++)
					{
				//		printf("%d %d %d\n",a[i],a[j],a[i]%a[j]);puts("sad");
						if((a[i]%b[j])==qn)
						{
							ans++;
						}
					}
				}
			printf("%d\n",ans);
			
			}
			
			
		}
	}



 return 0;
}


