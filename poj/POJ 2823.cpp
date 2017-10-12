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
const int N = 1e6 + 5;
struct SegTree {
    int l, r, mid;
    int sum, Max, Min;
}T[N << 2];
int n, m, t, c, l, r;
int xxx = 0;
void build(int p, int l, int r) {
/*
8 3
1 3 -1 -3 5 3 6 7

*/	
    int ls = p << 1, rs = (p << 1)|1;
    T[p].l = l, T[p].r = r, T[p].mid = (l + r) >> 1;
    if(l == r) {
    //	printf("\n	$$%d$$	\n",xxx++);
        scanf("%d", &T[p].sum);
     //   printf("\n qwe  %d \n",T[p].sum);
        T[p].Max = T[p].Min = T[p].sum;
        return ;
    }
    build(ls, l, T[p].mid);
    build(rs, T[p].mid + 1, r);
 //   T[p].sum = (T[ls].sum + T[rs].sum);
    T[p].Min = min(T[ls].Min, T[rs].Min);
    T[p].Max = max(T[ls].Max, T[rs].Max);
}

void update_add(int p, int l, int r, LL val) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
    	
   // 	puts("qwe");
        T[p].Min += val;
        T[p].Max += val;
  //      T[p].sum += (r - l + 1) * val;
        
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
 //   T[p].sum = (T[ls].sum + T[rs].sum);
    T[p].Min = min(T[ls].Min, T[rs].Min);
    T[p].Max = max(T[ls].Max, T[rs].Max);
}



pair<int,int> query(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
    // sum   
	//	return T[p].sum;
    // max   
	//	return T[p].Max;
    // min   
	//	return T[p].Min;
      return make_pair(T[p].Max,T[p].Min); 
        
    }

    if(r <= T[p].mid) {
        return query(ls, l, r);
    }
    else if(l > T[p].mid) {
        return query(rs, l, r);
    }
    else {
    //sum	
   //     return query(ls, l, T[p].mid) + query(rs, T[p].mid + 1, r);
    //max    
    //    return max(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
    //min    
    //    return min(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
       return make_pair(max(query(ls, l, T[p].mid).first , query(rs, T[p].mid + 1, r).first),min(query(ls, l, T[p].mid).second , query(rs, T[p].mid + 1, r).second));  
    }
}

int mmin[1001100];
int mmax[1001100];


int main()
{
    
    int len;
    while(~scanf("%d%d", &n,&len)) {
        xxx = 0;
      //  puts("wtf");
        build(1, 1, n);//在此输入n个数 query(1, i, r));
        for(int i = 0;i <= n-len;i++ )
        {
        	pair<int,int> qqq = query(1, i+1, i+len);
        	mmin[i] = qqq.second;
        	mmax[i] = qqq.first;
        	
		}
		printf("%d",mmin[0]);
		for(int i = 1;i <= n-len;i++ )
        {
        	printf(" %d",mmin[i]);
        	
		}
		printf("\n%d",mmax[0]);
		for(int i = 1;i <= n-len;i++ )
        {
        	printf(" %d",mmax[i]);
		}
		puts("");
        
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
