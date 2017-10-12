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
const int N = 1e5 + 5;
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
    	
    	puts("qwe");
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



LL query(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
    // sum   
		return T[p].sum;
    // max   
	//	return T[p].Max;
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
        return query(ls, l, T[p].mid) + query(rs, T[p].mid + 1, r);
    //max    
    //    return max(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
    //min    
    //    return min(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
        
    }
}

int main()
{
    int n, m, t, c, l, r;
    LL val;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        build(1, 1, n);//在此输入n个数 
        while(m--) {
            scanf("%d %d %d", &c, &l, &r);
            if(c == 1) {
                scanf("%lld", &val);
                update_add(1, l, r, val);//单点+= 而不是区间 而不是= 
            }
            
            else {
            	for(int i = 1; i < n;i++ )
            	{
            		printf("%d ",query(1, i, r));
				}
                printf("\n%lld\n", query(1, 4, 5));
            }
        }
    }
    return 0;
}
/*
1
10 10
1 2 3 4 5 6 7 8 9 10
1  1 10 100

2 1 10

*/
