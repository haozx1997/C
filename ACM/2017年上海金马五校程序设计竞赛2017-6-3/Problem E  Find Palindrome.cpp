#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxa = 111111*2;
int p[maxa*2];
#define max(a,b) a>b?a:b;
#define min(a,b) a<b?a:b;
int rebuild(int n, char* a, char* str){
for(int i = 0 ;i < n; i++){
a[i*2+1] = '#';
a[i*2+2] = str[i];
}
a[2*n+1] = '#';
a[2*n+2] = 0;
a[0] = '$';
return 2*n+2;
}
int manachar(int n, char* a){
int mx = 0, id = 0;
int ans = 0;
// printf("%s\n", a);
for(int i = 0; i < n; i++){
if(mx > p[i]){
int i2 = 2*id - i;
p[i] = min(mx - i, p[i2]);
}else p[i] = 0;
while(a[i-p[i]-1] == a[i+p[i]+1]){
p[i]++;
}
ans = max(ans, p[i]);
if(p[i] +i > mx){
id = i;
mx = p[i]+i;
}
}
return ans;
}
char str[maxa*2];
char a[maxa*2];
int main(){
while(scanf("%s", &str)!=EOF){
int n = strlen(str);
n = rebuild(n,a, str);
// printf("fuck");
printf("%d\n", manachar(n, a));
}
}

