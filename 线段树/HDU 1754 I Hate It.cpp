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
typedef long long LL;
const int N = 2e5 + 10;
struct SegTree {
    int l, r, mid;
    LL sum, Max, Min;
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

void update_add(int p, int l, int r, LL val) {
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
void update(int p, int l, int r, LL val) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
        T[p].Min = val;
        T[p].Max = val;
        T[p].sum = (r - l + 1) * val;
        
        return ;
    }
    
    if(r <= T[p].mid) {
        update(ls, l, r, val);
    }
    else if(l > T[p].mid) {
        update(rs, l, r, val);
    }
    else {
        update(ls, l, T[p].mid, val);
        update(rs, T[p].mid + 1, r, val);
    }
    T[p].sum = (T[ls].sum + T[rs].sum);
    T[p].Min = min(T[ls].Min, T[rs].Min);
    T[p].Max = max(T[ls].Max, T[rs].Max);
}



LL query(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
    // sum   
	//	return T[p].sum;
    // max   
		return T[p].Max;
    // min   
	//	return T[p].Min;
        
        
    }

    if(r <= T[p].mid) {
        return query(ls, l, r);
    }
    else if(l > T[p].mid) {
        return query(rs, l, r);
    }
    else {
    //sum	
    //    return query(ls, l, T[p].mid) + query(rs, T[p].mid + 1, r);
    //max    
        return max(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
    //min    
    //    return min(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
        
    }
}

int main()
{
    int n, m, t, c, l, r;
    LL val;
    char ch[5];
    while(~scanf("%d%d", &n,&m))
	 {
        build(1, 1, n);
        while(m--) {
            scanf("%s %d %d", &ch, &l, &r);
            if(ch[0] == 'U') {
                
                update(1, l, l, r);
            }
            
            else {
                printf("%lld\n", query(1, l, r));
            }
        }
    }
    return 0;
}
