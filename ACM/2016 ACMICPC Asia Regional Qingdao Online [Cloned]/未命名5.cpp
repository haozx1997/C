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
	ll n,m;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		
		if(m == 0ll)
		{
			printf("0\n");
			continue;
		}
		
		if(m <= 1ll)
		{
			printf("0\n");
			continue;
		}
		if(m <= 2ll)
		{
			printf("1\n");
			continue;
		}
		if(n == m)
		{
			printf("2\n");
			continue;
		}
		if((m - n)<=2)
		{
			printf("2\n");
			continue;
		}
		if(n == 0ll)
		{
			ll x = 1ll;
			ll y = x+1;
			m = m-x-y;
			ll ans = 2;
			ans += (m)/2;
			printf("%I64d\n",ans);
			continue;
			
			
		}
		
		
		ll x = (n+1)/2;
		ll y = x+1;
		m = m-x-y;
		ll ans = 2;
		ans += (m)/2;
		printf("%I64d\n",ans);
		
		
		
		
		
		
	}	




 return 0;
}


