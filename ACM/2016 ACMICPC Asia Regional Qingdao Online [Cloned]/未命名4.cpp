#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
long long l,r;
int main()
{
    while(scanf("%I64d%I64d",&l,&r)!=EOF)
    {
        if(l==r&&l==0ll) {printf("0\n");continue; }
        if(r<=1ll) {printf("0\n");continue; }
        
        if(r <= 2)
        {
        	{printf("1\n"); continue; }
		}
        if(l==r){printf("2\n"); continue; }
        if(l==0ll)
        {
            long long cnt = 1ll;
            r--;
            cnt += r/2ll;
            printf("%I64d\n",cnt);
            continue;
        }
        long long cnt = 2ll; double temp;
        temp = (double)l/2.0;
        double rr = (double)r-2*temp; rr-=1.0;
        cnt+=rr/2.0;
        //while(rr>1.0){rr-=2.0;cnt++;}
        printf("%I64d\n",cnt);
    }
    return 0;
}
