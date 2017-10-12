#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
#define PI acos(-1.0)
#define ITER set<int>::iterator
const int Mod = 1e9 + 7;
const int maxn = 1e5 + 10;

struct Node
{
    bool operator < (Node t){return x < t.x;}
    double x,y;
    int l,r;
}a[maxn];
int b[maxn];
bool check(Node p1,Node p2,Node p3)
{
    return p1.y * abs(p2.x - p3.x) > p2.y * abs(p1.x - p3.x);
}
double dis(Node x,Node y)
{
    return sqrt((1.0 *x.x - y.x) * (x.x - y.x) + (1.0 *x.y - y.y) * (x.y - y.y));
}
int main()
{
    int Tcase;scanf("%d",&Tcase);
    for(int ii = 1; ii <= Tcase; ii ++)
    {
        int n;scanf("%d",&n);
        for(int i = 1;i <= n;i ++)scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a + 1 ,a + n + 1);
        int pos1 = 1,pos2 = n;
        for(int i = 1;i <= n;i ++)if(a[i].y > a[pos1].y)pos1 = i;
        for(int i = n;i >= 1; i --)if(a[i].y > a[pos2].y)pos2 = i;
        a[1].l = a[2].l = 1;
        for(int i = 3;i <= n; i ++)
        {
            if(check(a[i - 1],a[a[i - 1].l],a[i]))a[i].l = i - 1;else a[i].l = a[i - 1].l;
        }
        a[n].r = a[n - 1].r = n;
        for(int i = n - 2;i >= 1; i --)
        {
            if(check(a[i + 1],a[a[i + 1].r],a[i]))a[i].r = i + 1;else a[i].r = a[i + 1].r;
        }

//        for(int i = 1;i <= n; i ++)cout << i << " -> " << a[i].l << " " << a[i].r << endl;

        printf("Case #%d:\n",ii);
        int q;scanf("%d",&q);
        while(q --)
        {
            double x;scanf("%lf",&x);
            int pos = lower_bound(a + 1 ,a + n + 1,(Node){x,0,0,0}) - a;
//            cout << pos << endl;
            if(pos == 1)
            {
                if(check(a[1],a[pos1],(Node){x,0,0,0})){printf("%.8f\n",(PI - atan(1.0 * a[1].y/(a[1].x - x)) )/PI * 180);}
                else {printf("%.8f\n",(PI - atan(1.0 * a[pos1].y/(a[pos1].x - x)) )/PI * 180);}
            }
            else if(pos == n + 1)
            {
                if(check(a[n],a[pos2],(Node){x,0,0,0})){printf("%.8f\n",(PI - atan(1.0 * a[n].y/(x - a[n].x ))) /PI * 180 );}
                else { printf("%.8f\n",(PI - atan(1.0 * a[pos2].y/(x - a[pos2].x)) )/PI * 180);}
            }
            else
            {
                Node t1,t2,t3 = (Node){x,0,0,0};
                if(check(a[pos - 1],a[a[pos - 1].l],(Node){x,0,0,0}))t1 = a[pos - 1];else t1 = a[a[pos - 1].l];
                if(check(a[pos],a[a[pos].r],(Node){x,0,0,0}) )t2 = a[pos];else t2 = a[a[pos].r];
//                cout << t1.x << " " << t1.y << " " << t2.x << " " << t2.y << endl;
                double p1 = dis(t1,t3),p2 = dis(t2,t3),p3 = dis(t1,t2);
//                cout << (p1 * p1 + p2 * p2 - p3 * p3) / (2 * p1 * p2)<< endl;
                double ans = acos( 1.0 *(p1 * p1 + p2 * p2 - p3 * p3)/(2.0 * p1 * p2) );
                ans = ans / PI * 180;
                printf("%.8f\n",ans );
            }
        }
    }
    return 0;
}
