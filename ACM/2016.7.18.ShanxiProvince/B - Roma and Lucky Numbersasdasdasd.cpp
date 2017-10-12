#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cmath>  
using namespace std;  
  
int main()  
{  
    int n,k;  
    int i,j;  
    int length;  
    int sum;  
    int count,cn;  
    char s[100][12];  
    scanf("%d %d",&n,&k);  
    for(i=0;i<n;i++)  
    {  
        scanf("%s",&s[i]);  
    }  
    count=0;  
    for(i=0;i<n;i++)  
    {  
        length=strlen(s[i]);  
        cn=0;  
        for(j=0;j<length;j++)  
        {  
            if(s[i][j]=='4'||s[i][j]=='7')  
            {  
                cn++;  
            }  
        }  
        if(cn<=k)  
        {  
            count++;  
        }  
    }  
    printf("%d\n",count);  
  
    return 0;  
}  
