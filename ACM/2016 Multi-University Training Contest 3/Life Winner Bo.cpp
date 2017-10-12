#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int p,n,m;
void k()
{
	int t = n;
	if(m > n) t = m;
	if(t%2) 
	 printf("G\n");
	else
	 printf("B\n"); 
}

void r()
{
	if(n == 1|| m == 1)
	 printf("B\n");
	else
	 printf("G\n"); 
}
 
void q()
{
	if(n == 1|| m == 1)
	 printf("B\n");
	else if(n == m)
	 printf("B\n");
	else 
	 printf("G\n"); 
	 
 } 
void kn()
{
	int sum = m+n+1;
	if (m<n)
	 {
	 	int TTT = n;
	 	n = m;
	 	m =TTT;
	 }
	if((sum%3)!=0)
	 {
	 	printf("D\n");
	 	return ;
	 }
	 if(m==n)
	 {
	 	printf("G\n");
	 	return ;
	 }
	 int h = sum/3;
	 if(h%2)
	 {printf(" n %d  %d\n",h,(h+h/2));
	 		printf(" m %d  %d\n",(h+h/2),(h+h/2+h/2));
	 		
	 	if(n<h||n>(h+h/2)||m<(h+h/2)||m>(h+h/2+h/2))
	 	{
	 		
	 		printf("D\n");
	 		
		 }
		 else
		 {
		 	printf("G\n");
		 	 
		 }
	 }
	 else
	 {printf(" n %d  %d\n",h,(h-1+h/2));
	 		printf(" m %d  %d\n",(h+h/2),(h+(h+h/2)-1+h/2));
	 		
	 	if(n<h||n>(h-1+h/2)||m<(h+h/2)||m>(h+(h+h/2)-1+h/2))
	 	{
	 		printf("D\n");
		 }
		  else
		 {
		 	printf("B\n");
		 	 
		 }
	 }
	 
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d%d%d",&p,&n,&m);
		
		switch(p)
		{
			case 1: k(); break;
			case 2: r(); break;
			case 3: kn(); break;
			case 4: q(); break;
			
		}
	}
}
