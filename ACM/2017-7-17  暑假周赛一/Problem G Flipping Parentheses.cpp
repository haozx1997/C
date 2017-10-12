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
const int N = 4e5 + 5;
struct SegTree {
    int l, r, mid;
    int Min;
}T[N << 2];

set<int>SSS;

char s[400000];
int now;
void build(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    T[p].l = l, T[p].r = r, T[p].mid = (l + r) >> 1;
    if(l == r) {
    	if(s[l-1] == '(')
    	{
    		now++;
		}
		else
		{
			now--;
			SSS.insert(l);
		//	printf("	%d\n",l);
		}
        T[p].Min = now;
        return ;
    }
    build(ls, l, T[p].mid);
    build(rs, T[p].mid + 1, r);
    T[p].Min = min(T[ls].Min, T[rs].Min);
}

void update_add(int p, int l, int r, int val) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
        T[p].Min += val;
        
        return ;
    }
 //   puts("	WTF");
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
    T[p].Min = min(T[ls].Min, T[rs].Min);
}


 int n,q;
int query(int p, int l, int r) {
    int ls = p << 1, rs = (p << 1)|1;
    if(T[p].l == l && T[p].r == r) {
		return T[p].Min;
        
        
    }

    if(r <= T[p].mid) {
        return query(ls, l, r);
    }
    else if(l > T[p].mid) {
        return query(rs, l, r);
    }
    else {
        return min(query(ls, l, T[p].mid) , query(rs, T[p].mid + 1, r));
        
    }
}

int findmaxmin()
{
	int l = 1,r = n;
	while(l!=r)
	{
		int mid = (l+r)/2;
		if(query(1, mid, n)<2)
		{
			l = mid+1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}


int main()
{
   
    
    
    while(scanf("%d%d", &n,&q)) 
	{
		SSS.clear();
		now = 0;
//		for(int i = 0;  i  <n;i++)
//		{
//			printf("%d",i+1);
//		}
//		printf("\n");
        scanf("%s",s);
        build(1, 1, n);
        while(q--) 
		{
		printf("%s\n",s);
        	int c,ans;
            scanf("%d", &c);
            c--;
            if(s[c] == '(') {
                s[c] = ')';
                SSS.insert(c+1);
                ans = *SSS.begin();
                SSS.erase(SSS.begin());
                s[ans-1] = '(';
                printf("	%d\n",ans);
                if(ans != c+1)
				update_add(1, ans, c+1, 2);//区间+= 而不是单点 而不是= 
				
            }
            
            else {
            	for(int i = 1 ; i <= n;i++)
            	{
            		printf("%d",query(1, i, i));
				}
				puts("");
            	update_add(1, c+1, n, 2);
            	for(int i = 1 ; i <= n;i++)
            	{
            		printf("%d",query(1, i, i));
				}
				puts("");
            	s[c] = '(';
            	SSS.erase(c+1);
            	ans = findmaxmin();
            	s[ans - 1] = ')';
            	SSS.insert(ans);
            	printf("	%d\n",ans);
            	update_add(1, ans, n, -2);
            	
            	
         //   printf("%lld\n", query(1, l, r));
            }
        }
    }
    return 0;
}

/*
6 3
((()))
4
3
1



20 9
()((((()))))()()()()
15
20
13
5
3
10
3
17
18

*/
