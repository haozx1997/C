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

int a[100100],b[100100];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,qn;
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < n;i++)
		{
			for(int j = i +1;j <n;j++)
			{
				if(a[i]>=a[j])
				{
					b[i] = j;
					break;
				}
			}
		}
		for(int i = 0; i < n;i++ )
		{
			printf("%d ",b[i]);
		}
		scanf("%d",&qn);
		while(qn--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l--,r--;
			int ans = a[l];
			for(int i = b[l]; i <=r;i = b[i] )
			{
				
				if(i == 0)
				{
					break;
				}
		//		printf("%d %d\n",i,a[i]);
				ans %= a[i];
				
			}
			printf("%d\n",ans);
			
		}
		
		
		
	}
/*

5
3
2 3 3
1
1 3

5 5 8 1 2 3 
4
1 2 
1 5



*/




 return 0;
}


