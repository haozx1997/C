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
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int a[100100];
int d[100100][60];
int n;
void rmq_init() {
	for(int i = 0; i < n; i++)
		d[i][0] = a[i];
	for(int j = 1; ( 1<<j) <=n; j++) {
		for(int i = 0; i +(1<<j)-1<n; i++) {
			d[i][j] = min(d[i][j -1],d[i+(1<<(j-1))][j-1]);
		}
	}

}
int rmq(int l,int r) {
	int k = 0;
	while((1<<(k+1)) <= r-l+1) {
		k++;
	}
	return min(d[l][k],d[r-(1<<k)+1][k]);
}





int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(d,0,sizeof(d));

		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		rmq_init();
		int qn;
		scanf("%d",&qn);
		while(qn--) {
			/*
1
3
2 3 3
1
1 3
			*/
			int l,r;
			scanf("%d%d",&l,&r);
			l--,r--;
			int ans = a[l];
			int ne = l+1;
			while(ne<r&&ans) {
		//		printf("%d %d\n",ne,ans);
				int sm = r+1;
				int bl = ne,br = r;
				while(bl<=br) {
					int mid = (bl+br)/2;
					if(rmq(bl,mid)<=ans) {
						br = mid-1;
						sm = mid;
					} 
					else {
						bl = mid+1;
					}
				}
				
				if(sm<ne) {
					ne = sm+1;
					ans %= a[sm];
				}
				else
				{
					ne = sm;
					break;
				}
			}
			printf("%d\n",ans);
		}



	}





	return 0;
}
