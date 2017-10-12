#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


int main()
{
	int n;
	int a[50][50];
	int l[50];
	int r[50];
	while(~scanf("%d",&n))
	{
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		
		
		for(int i = 0;i < n;i++)
		 {
		 	for(int j = 0;j < n;j++)
		 	{
		 		scanf("%d",&a[i][j]);
			 }
		 }
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
		 	{
		 		l[i] += a[i][j];
			 }
		 } 
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
		 	{
		 		r[i] += a[j][i];//´ó 
			 }
		 } 

		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
		 	{
		 		if(r[j]>l[i])
		 		 {
		 		 	ans++;
				  }
			 }
		 }
		 printf("%d\n",ans); 
		 
	}
}
