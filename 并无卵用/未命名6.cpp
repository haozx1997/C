#include<iostream>   
#include<string>   
#include<iomanip>   
#include<algorithm>   
#include<bits/stdc++.h>
using namespace std;   
  
#define MAXN 9999  
#define MAXSIZE 10  
#define DLEN 4  
int a[3][3];
int b[2][3] = {{1,2,3},{4,5,6}};
int main()
{
for(int i =0; i  < 3;i++)
{
	for(int j = 0 ;j < 3;j++)
	{
		a[i][j] = i*10+j;
	}
}
printf("%d\n",a[1][3]);
printf("%d\n",b[0][3]);

/*
5 2
8 1
1024 1024




*/


 return 0;
}


