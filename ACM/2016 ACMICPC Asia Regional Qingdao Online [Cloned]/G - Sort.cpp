#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef set<int>::iterator ITER;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)

const int maxn = 1e5 + 10;
//const int Mod = 1e9 + 7;
//const int N = 2;

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
int n;ll m;
int a[maxn];
ll sum[maxn];
ll calc(ll k)
{
    ll ret = 0;
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i = 1; i <= n; i ++)
    {
        q.push(a[i]);
    }
    while(!q.empty())
    {
        int t = k;int temp = 0;
        while(t && !q.empty())
        {
            temp += q.top();q.pop();t --;
        }
        ret += 1ll * temp;
        if(q.empty())
            break;
        q.push(temp);
    }
//    cout << k << " " << ret << endl;
    return ret;
}
//1
//5 33
//1 2 3 4 5
int main()
{
    int Tcase;scanf("%d",&Tcase);
    while(Tcase --)
    {
        scanf("%d%I64d",&n,&m);
		sum[0] = 0;
        for(int i = 1; i <= n; i ++)
            scanf("%d",&a[i]);
        sort(a + 1,a + n + 1);
        for(int i = 1; i <= n; i ++)
            sum[i] = sum[i - 1] + 1ll * a[i];
        int l = 2,r = n;
        int ans;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(calc(mid) <= m)
            {
                ans = mid;r = mid - 1;
            }else l = mid + 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
