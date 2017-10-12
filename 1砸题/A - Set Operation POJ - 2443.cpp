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
#include<stdio.h>
#include<bitset>
#include<string.h>

#define ll long long
using namespace std;

bitset<1010>b[10010],y;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(b,0,sizeof(b));
		for(int i = 0; i < n;i++ )
		{
			int an;
			scanf("%d",&an);
			for(int j = 0 ;j<an;j++)
			{
				int w;
				scanf("%d",&w);
				b[w][i] = 1;
			}
		}
		int m,l,r;
		scanf("%d",&m);
		for(int i = 0;i < m;i++)
		{
			scanf("%d%d",&l,&r);
	//		cout << b[l].to_string()<<" "<< b[r].to_string()<<endl;
			y = b[l]&b[r];
			if(y.any())
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
		
		}
		
	}




 return 0;
}


