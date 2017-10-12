#include<stdio.h>


int exgcd(int a, int b, int &x, int &y) {  
    if(!b) {  
        x = 1; y = 0;  
        return a;  
    }  
    int ret = exgcd(b, a%b, y, x);  
    y -= a/b*x;  
    return ret;  
}  
  
// ??????  
int china(int n, int a[], int m[]) {  
    int M = 1;  
    for(int i = 0;i < n; i++) M *= m[i];  
    int ret = 0;  
    for(int i = 0;i < n; i++) {  
        int w = M/m[i], x, y;  
        int d = exgcd(w, m[i], x, y);  
        ret = (ret + x*w*a[i])%M;  
    }  
    return (ret + M)%M;  
}  
  
int x[55];  
int main() 
{  
    init();  
    int t, n;  
    scanf("%d", &t);  
    while(t--) {  
        scanf("%d", &n);  
        for(int i = 0;i < 5;i ++) {  
            // ?Bell(n) % ??????  
            x[i] = pow_mod(i, n, Md[i]);  
        }  
        int ans = china(5, x, Md);  
        printf("%d\n", ans);  
    }  
}  
