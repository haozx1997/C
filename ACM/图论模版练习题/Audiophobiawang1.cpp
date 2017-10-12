#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
const int DMAXN = 105;  
const int EMAXN = 1005;  
int c, s, q, x, y, val;  
int p[DMAXN], u[EMAXN], v[EMAXN], r[EMAXN], dis[EMAXN];  
int cmp(const int i, const int j)  
{  
    return dis[i] < dis[j];  
}  
int find(int i)  
{  
    return p[i] == i ? i : (p[i] = find(p[i]));  
}  
void Kruskal()  
{  
    int px, py;  
    for(int i=1; i<=c; i++)  
        p[i] = i;  
    for(int i=0; i<s; i++)  
    {  
        int e = r[i];  
        int xx = find(u[e]);  
        int yy = find(v[e]);  
        if(xx != yy)  
            p[xx] = yy;  
        px = find(x); // ??x??  
        py = find(y); // ??y??  
        if(px == py) // ??????,?????????  
        {  
            val = dis[e];  
            return ;  
        }  
    }  
}  
int main()  
{  
 
    int fx, fy, wi, ff = 0, t = 0;  
    while(scanf("%d%d%d", &c, &s, &q))  
    {  
        if(!c && !s&& !q)  
            break;  
        if(ff)  
            puts("");  
        for(int i=0; i<s; i++)  
        {  
            scanf("%d%d%d", &fx, &fy, &wi);  
            u[i] = fx;  
            v[i] = fy;  
            dis[i] = wi;  
            r[i] = i;  
        }  
        sort(r, r+s, cmp);  
        printf("Case #%d\n", ++t);  
        for(int i=0; i<q; i++)  
        {  
            val = -1;  
            scanf("%d%d", &x, &y);  
            Kruskal();  
            if(val > 0)  
                printf("%d\n", val);  
            else  
                printf("no path\n");  
        }  
        ff = 1;  
    }  
    return 0;  
}  

