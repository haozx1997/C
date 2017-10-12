#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int maxn = 30000 + 10;
int L,T,n;
P a[maxn];
P b[maxn];
int cnt[maxn];
int pos[maxn];
struct Node
{
    int x;string s;
}ans[maxn];
int main()
{
    int Tcase;
    scanf("%d",&Tcase);
    int TT = 1;
    while( Tcase --)
    {
        
        scanf("%d%d%d",&L,&T,&n);
        memset(cnt,0,sizeof(cnt));
        for(int i = 1; i <= n;i ++)
        {
            char s[3];
            scanf("%d%s",&a[i].first,s);
            a[i].second = i;
            if(s[0] == 'L')
                b[i].first = a[i].first - T,b[i].second = -1;
            else b[i].first = a[i].first + T,b[i].second = 1;
            cnt[b[i].first] ++;
        }
        sort(a + 1,a + n + 1);//puts("get it !");
        for(int i = 1; i <= n;i ++)
            pos[i] = a[i].second;
        sort(b + 1,b + n + 1);
        for(int i = 1; i <= n; i ++)
        {
            if(cnt[b[i].first] > 1)
                ans[pos[i]] = (Node){b[i].first,"Turning"};
            else
            {
                if(b[i].first < 0 || b[i].first > L)
                    ans[pos[i]] = (Node){b[i].first,"Fell off"};
                else
                ans[pos[i]] = (Node){b[i].first,b[i].second == -1 ? "L":"R"};
            }
        }printf("Case #%d:\n",TT++);
        for(int i = 1;i <= n; i ++)
        {
            if(ans[i].s[0] != 'F')
            cout << ans[i].x << " " << ans[i].s << endl;
            else cout << ans[i].s << endl;
        }
		puts("");
    }
    return 0;
}

