#include<bits/stdc++.h>

using namespace std;

int n,k;  
double a[400400];  
double sum=0;  
int main(){  
    scanf("%d%d",&n,&k);  
    a[0]=0;  
    double s=0;  
    for(int i=1;i<=n;i++){  
        scanf("%lf",a+i);  
        sum+=a[i];  
        if(i>=k){  
            sum-=a[i-k];  
            s+=sum;  
        }  
    }  
    double y=n-k+1;  
    s/=y;  
    printf("%.12f\n",s);  
} 


