#include<stdio.h>
long long a[51];
int main()
{int i,n;
a[0]=0;a[1]=1;a[2]=1;
for(i=2;i<51;i++)
a[i]=a[i-1]+a[i-2];
while(scanf("%d",&n)&&n!=-1)
printf("%I64d\n",a[n]);
}
