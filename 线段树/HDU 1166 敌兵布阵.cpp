#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[200010];
//求和线段树
// 建树
void PushUP(int rt) {

       sum[rt] = sum[rt<<1] + sum[rt<<1|1];

}
void build(int l,int r,int rt) {
       if (l == r) {
              scanf("%d",&sum[rt]);
              return ;
       }
       int m = (l + r) >> 1;
       build(lson);
       build(rson);
       PushUP(rt);
}
//单点增减  查询
void update(int p,int add,int l,int r,int rt) {
       if (l == r) {
              sum[rt] += add;
              return ;
       }
       int m = (l + r) >> 1;
       if (p <= m) update(p , add , lson);
       else update(p , add , rson);
       PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
       if (L <= l && r <= R) {
              return sum[rt];
       }
       int m = (l + r) >> 1;
       int ret = 0;
       if (L <= m) ret += query(L , R , lson);
       if (R > m) ret += query(L , R , rson);
       return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int TT = 1; TT <= T;TT++)
	{
		printf("Case %d:\n",TT);
		int n;
		scanf("%d",&n);
		build(1,n,1);
		char ch[10];
		int a1,a2;
		while(1)
		{
			scanf("%s",ch);
			if(ch[0] == 'E')
			{
				break;
			}
			scanf("%d%d",&a1,&a2);
			switch(ch[0])
			{
				case 'Q' :
					printf("%d\n",query(a1,a2,1,n,1));
					break;
				case 'A' :
					update(a1,a2,1,n,1);
					break;
				case 'S' :
					update(a1,-a2,1,n,1);
					break;
					
			}
		}
		
	}
}
