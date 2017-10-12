//#pragma comment(linker, "/STACK:102400000, 102400000")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
const int N = 1e5 + 5;
struct SegTree {
    int l, r, mid;
    int sum, Max, Min;
}T[N << 2];

void build(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    T[p].l = l, T[p].r = r, T[p].mid = (l + r) >> 1;
    if(l == r) {
        scanf("%lld", &T[p].sum);
        T[p].Max = T[p].Min = T[p].sum;
        return ;
    }
    build(ls, l, T[p].mid);
    build(rs, T[p].mid + 1, r);
    T[p].sum = (T[ls].sum + T[rs].sum);
    T[p].Min = min(T[ls].Min, T[rs].Min);
    T[p].Max = max(T[ls].Max, T[rs].Max);
}

void update_add(int p, int l, int r, int val) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
        T[p].Min += val;
        T[p].Max += val;
        T[p].sum += (r - l + 1) * val;
        
        return ;
    }
    
    if(r <= T[p].mid) {
        update_add(ls, l, r, val);
    }
    else if(l > T[p].mid) {
        update_add(rs, l, r, val);
    }
    else {
        update_add(ls, l, T[p].mid, val);
        update_add(rs, T[p].mid + 1, r, val);
    }
    T[p].sum = (T[ls].sum + T[rs].sum);
    T[p].Min = min(T[ls].Min, T[rs].Min);
    T[p].Max = max(T[ls].Max, T[rs].Max);
}



int query(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
        return T[p].sum;
    }

    if(r <= T[p].mid) {
        return query(ls, l, r);
    }
    else if(l > T[p].mid) {
        return query(rs, l, r);
    }
    else {
        return query(ls, l, T[p].mid) + query(rs, T[p].mid + 1, r);
    }
}

int main()
{
    int n, m, t, c, l, r;
    char ch[10];
    
    scanf("%d", &t);
    for(int TT = 1; TT <= t;TT++) {
    		printf("Case %d:\n",TT);
        scanf("%d", &n);
        build(1, 1, n);
        while(1) {
        	scanf("%s",ch);
        	if(ch[0] == 'E')
        	{
        		break;
			}
            scanf("%d %d", &l, &r);
            if(ch[0] == 'A') {
               
                update_add(1, l, l, r);
            }
            
            else if(ch[0] == 'S') 
			{
                
                update_add(1, l, l,-r);
            } 
			else
			{
                printf("%d\n", query(1, l, r));
            }
        }
    }
    return 0;
}
