#include <cstdio>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
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
//区间 最值 建树
void PushUP(int rt) {
       MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
} 
//成段 增减 区间更新 延迟更新
int col[maxn<<2];
int sum[maxn<<2];
void PushUp(int rt) {
       sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m) {
       if (col[rt]) {
              col[rt<<1] = col[rt<<1|1] = col[rt];
              sum[rt<<1] = (m - (m >> 1)) * col[rt];
              sum[rt<<1|1] = (m >> 1) * col[rt];
              col[rt] = 0;
       }
}
void build(int l,int r,int rt) {
       col[rt] = 0;
       sum[rt] = 1;
       if (l == r) return ;
       int m = (l + r) >> 1;
       build(lson);
       build(rson);
       PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
       if (L <= l && r <= R) {
              col[rt] = c;
              sum[rt] = c * (r - l + 1);
              return ;
       }
       PushDown(rt , r - l + 1);
       int m = (l + r) >> 1;
       if (L <= m) update(L , R , c , lson);
       if (R > m) update(L , R , c , rson);
       PushUp(rt);
} 

