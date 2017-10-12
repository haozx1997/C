#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

///////////////////记得按 for(int i = 1;i <= 10;i++)
///////////////////不要按 for(int i = 0;i < 10;i++)
///////////////////    ALL 

int Lowbit(int x) //2^k
{
    return x & (-x);
}

struct fenwick
{
	int fa[100100];
	int fn;//数组大小          //一定要赋值 
	void update(int t, int val)//位置，值 
	{
		for(int i = t;i <= fn ;i += Lowbit(i))
		{
			fa[i] += val;
		}
	}
	int getsum(int x)
	{
		int ans=0;
	    for(int i=x; i>0; i-=Lowbit(i))
	        ans += fa[i];
	    return ans;
	}
	 
}fen;


//int n;//一共多少个数
//int c[110101];
//void Update(int t,int val)
//{
//    for(int i=t; i<=n; i+=Lowbit(i))
//        c[i] += val;
//}
//int getSum(int x)
//{
//    int ans=0;
//    for(int i=x; i>0; i-=Lowbit(i))
//        ans += c[i];
//    return ans;
//}

int main()
{
	fen.fn =10;
	for(int i = 1;i <= 10;i++)
	{
		fen.update(i,1);
	}
	for(int i = 1;i <= 10;i++)
	{
		printf("!%d %d\n",i,fen.getsum(i));
	}
	for(int i = 1;i <= 10;i++)
	{
		fen.update(i,1);
	}
	
	for(int i = 1;i <= 10;i++)
	{
		printf("!%d %d\n",i,fen.getsum(i));
	}
	
 } 
