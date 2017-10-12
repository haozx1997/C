#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>

using namespace std;
 
 int gcd(int a,int b)
 {
 	return b == 0? a : gcd(b,a%b);
 }
 
 
 int main()
 {
 	int t;
 	scanf("%d",&t);
 	while(t--)
 	{
 		int x,y;
 		scanf("%d%d",&x,&y);
 		if(y > x)
 		{
 			int tt = x;
 			x = y;
 			y = tt;
		 }
		 int ans = gcd(x,y);
 		printf("%d %d\n",ans,x*y/ans);
 		
 		
 		
 		
	 }
 }
