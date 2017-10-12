#include    <stdio.h>  
#include    <string.h>  
#include    <stdlib.h>  
#include    <math.h>  
#define ll long long   
ll *primarrrrr, *v;  
ll q = 1, p = 1;  
   
//π(n)  
ll pii(ll n, ll primarrrrr[], ll len)  
{  
    ll i = 0, mark = 0;  
    for (i = len - 1; i > 0; i--) {  
        if (primarrrrr[i] < n) {  
            mark = 1;  
            break;  
        }  
    }  
    if (mark)  
        return i + 1;  
    return 0;  
}  
   
//Φ(x,a)  
ll phhhi(ll x, ll a, ll m)  
{  
    if (a == m)  
        return (x / q) * p + v[x % q];  
    if (x < primarrrrr[a - 1])  
        return 1;  
    return phhhi(x, a - 1, m) - phhhi(x / primarrrrr[a - 1], a - 1, m);  
}  
   
ll primeppp(ll n)  
{  
    char *mark;  
    ll mark_len;  
    ll count = 0;  
    ll i, j, m = 7;  
    ll sum = 0, s = 0;  
    ll len, len2, len3;  
   
    mark_len = (n < 10000) ? 10002 : ((ll)exp(2.0 / 3 * log(n)) + 1);  
   
    //筛选n^(2/3)或n内的素数  
    mark = (char *)malloc(sizeof(char) * mark_len);  
    memset(mark, 0, sizeof(char) * mark_len);  
    for (i = 2; i < (ll)sqrt(mark_len); i++) {  
        if (mark[i])  
            continue;  
        for (j = i + i; j < mark_len; j += i)  
            mark[j] = 1;  
    }  
    mark[0] = mark[1] = 1;  
   
    //统计素数数目  
    for (i = 0; i < mark_len; i++)  
        if (!mark[i])  
            count++;  
   
    //保存素数  
    primarrrrr = (ll *)malloc(sizeof(ll) * count);  
    j = 0;  
    for (i = 0; i < mark_len; i++)  
        if (!mark[i])  
            primarrrrr[j++] = i;  
   
    if (n < 10000)  
        return pii(n, primarrrrr, count);  
   
    //n^(1/3)内的素数数目  
    len = pii((ll)exp(1.0 / 3 * log(n)), primarrrrr, count);  
    //n^(1/2)内的素数数目  
    len2 = pii((ll)sqrt(n), primarrrrr, count);  
    //n^（2/3)内的素数数目  
    len3 = pii(mark_len - 1, primarrrrr, count);  
   
    //乘积个数  
    j = mark_len - 2;  
    for (i = (ll)exp(1.0 / 3 * log(n)); i <= (ll)sqrt(n); i++) {  
        if (!mark[i]) {  
            while (i * j > n) {  
                if (!mark[j])  
                    s++;  
                j--;  
            }  
            sum += s;  
        }  
    }  
    free(mark);  
    sum = (len2 - len) * len3 - sum;  
    sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;  
   
    //欧拉函数  
    if (m > len)  
        m = len;  
    for (i = 0; i < m; i++) {  
        q *= primarrrrr[i];  
        p *= primarrrrr[i] - 1;  
    }  
    v = (ll *)malloc(sizeof(ll) * q);  
    for (i = 0; i < q; i++)  
        v[i] = i;  
    for (i = 0; i < m; i++)  
        for (j = q - 1; j >= 0; j--)  
            v[j] -= v[j / primarrrrr[i]];  
   
    sum = phhhi(n, len, m) - sum + len - 1;  
    free(primarrrrr);  
    free(v);  
    return sum;  
}  
   
int main()  
{  
    ll n;  
    ll count;  
    int h;  
    while(scanf("%I64d", &n)!=EOF)  
    {  
  
        p=1;  
        q=1;  
        if(n == 2)
        {
        	printf("1\n");
        	continue;
		}
        n++;
		 
        count = primeppp(n);  
        printf("%I64d\n",count);  
    }  
    return 0;  
}  
 
 
