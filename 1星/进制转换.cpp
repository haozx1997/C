#include<stdio.h>
#include<string.h>

char num[10];
char boom[] = {"0123456789ABCDEFGHIJK"};

int moob(char c)// 
{
	if(c>'9')
	 return c-'A'+10;
	return c - '0';
}
int issym(char *n)//是否对称 
{
	for(int i = 0;i < strlen(n);i++)
	{
		if(n[i] != n[(strlen(n)-i-1)])
		 return 0;
	}
	return 1;
}
void ttt(int n,int to)//十进制的 n到to进制 
{
	
	int nn = n;
	for(int i = 0;;i++)
	{
		int now = nn%to;
		nn /= to;
		num[i] = boom[now];
		if(!nn)
		{
			num[++i] = '\0';
			break;
		}
		
	}
	int len = strlen(num) ;
	for(int i = 0;i < len/2;i++)
	{
		char t = num[i];
		num[i] = num[len-1-i];
		num[len-1-i] = t;
	}
//	puts(num);
}

int xy(int x ,int y)//x的y次 
{
	int xx = x;
	if(y == 0&& x!= 0)
	 return 1;
	for(int i = 1;i < y;i++)
	{
		x *= xx;
	 } 
	 return x;
 } 

int ttten(char *n,int to)//to进制到十进制 
{
	int ans = 0;
	for(int i = 0;i < strlen(n);i++)
	{
	//	printf("ê?????%d %d\n",ans,xy(to,i));
		
		ans += moob(n[(strlen(n)-1-i)])*xy(to,i);
		
	}
	
	
	return ans;
}

int main()
{
	int to;
	while(scanf("%d",&to) != EOF)
	{
		for(int i = 1;i<=300;i++)
		{
			int ii = i*i;
			ttt(ii,to);
			if(issym(num))
			{
				ttt(i,to);
				printf("%s ",num);
				ttt(ii,to);
				printf("%s\n",num);
				
			}
		}
	//	printf("is %d\n",issym(num));
//		printf("ê????? %d\n",ttten(num,to));
	
		
	}
}



/*
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=121584#overview
A - 猪数
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit
 
Status
 
Practice
 
FZU 1548
Description
在猪的世界里有一种数叫猪数，猪是这么定义猪数的：给定一个进制B(2<=B<=20，B用十进制表示)，在这个进制下，这个数的平方从左向右念和从右像左念都一样，用‘A’,‘B’……表示10，11等等。

例如：B=10时，121就是一个猪数，因为121的平方14641满足条件。

你的任务是编写一个程序，求出所有大于等于1小于等于300的猪数。

Input
输入包含多组测试数据，请处理到EOF结束。
每组测试数据，由一行组成，为一个单独的整数B(B用十进制表示)。

Output
对每组数据输出：每行两个数字，第二个数是第一个数的平方，且第一个数是猪数。(注意:这两个数都应该在B那个进制下)

Sample Input
10
15
Sample Output
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
2 4
3 9
4 11
8 44
C 99
11 121
14 191
22 484
29 6B6
44 1331
51 1AA1
88 4CC4
99 6226
101 10201
111 12321
121 14641
131 16B61
 
