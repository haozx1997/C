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

//一维 
int c[500050];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int val)//是加val的值 不是更新成val的值！！！ 
{
	while(x<=n)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}


//int Lowbit(int x) //2^k
//{
//    return x & (-x);
//}
//
//struct fenwick
//{
//	int fa[100100];
//	int fn;//数组大小          //一定要赋值 
//	void update(int t, int val)//位置，值 
//	{
//		for(int i = t;i <= fn ;i += Lowbit(i))
//		{
//			fa[i] += val;
//		}
//	}
//	int getsum(int x)
//	{
//		int ans=0;
//	    for(int i=x; i>0; i-=Lowbit(i))
//	        ans += fa[i];
//	    return ans;
//	}
//	 
//}fen;


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

//二维 

int cc[2048][2048];
int ccn;
void update2(int x,int y,int val)
{
	for(int i = x;i <= ccn; i += lowbit(i))
	{
		for(int j = y; j <= ccn ;j += lowbit(j))
		{
			cc[i][j] += val;
		}
	}
}
int sum2(int x,int y)
{
	int ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
	{
		for(int j = y; j > 0; j -= lowbit(j))
		{
			ans += cc[i][j];
		}
	}
	return ans;
}
int sum5(int x1,int y1,int x2,int y2)//区间和 
{
	
	int s1,s2,s3,s4,s5;
	s1 = sum2(x1-1,y1-1);
	s2 = sum2(x2,y1-1);
	s3 = sum2(x1-1,y2);
	s4 = sum2(x2,y2);
//	printf("%d %d %d %d    %d %d %d %d\n",x1,y1,x2,y2,s1,s2,s3,s4);
	s5 = s4 - s3 - s2 + s1;
	return s5;
}
int main()
{
	n =10;
	for(int i = 1;i <= 10;i++)
	{
		update(i,1);
	}
	for(int i = 1;i <= 10;i++)
	{
		update(i,-1);
	}
	
	for(int i = 1;i <= 10;i++)
	{
		printf("!%d %d\n",i,getsum(i));
	}
//	ccn = 3;
//	memset(cc,0,sizeof(cc));
//	for(int i = 1;i <= 3;i++ )
//	{
//		for(int j = 1;j <= 3;j++ )
//		{
//			update2(i,j,1);
//			printf("%d %d %d\n",i,j,sum2(3,3));
//		 } 	
//	 } 
//	 for(int i = 1;i <= 3;i++ )
//	{
//		for(int j = 1;j <= 3;j++ )
//		{
//			update2(i,j,2);
//			printf("%d %d %d\n",i,j,sum2(3,3));
//		 } 	
//	 } 
//	 
	
 } 
