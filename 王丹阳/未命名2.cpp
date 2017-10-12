#include<stdio.h>
#define N 20
int main()
{
        int a[N]={5,83,74,2,61,39,18,29,90,78,58,8,26,11,42,51,36 16 31 22},i,j,t;        
    for(i=0;i<N-1;i++) 
    for(j=0;j<N-1-i;j++)
    if(a[j]>a[j+1]) 
{t=a[j];a[j]=a[j+1];a[j+1]=t;}
for(i=0;i<N;i++)
