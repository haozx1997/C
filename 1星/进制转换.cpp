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
int issym(char *n)//�Ƿ�Գ� 
{
	for(int i = 0;i < strlen(n);i++)
	{
		if(n[i] != n[(strlen(n)-i-1)])
		 return 0;
	}
	return 1;
}
void ttt(int n,int to)//ʮ���Ƶ� n��to���� 
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

int xy(int x ,int y)//x��y�� 
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

int ttten(char *n,int to)//to���Ƶ�ʮ���� 
{
	int ans = 0;
	for(int i = 0;i < strlen(n);i++)
	{
	//	printf("��?????%d %d\n",ans,xy(to,i));
		
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
//		printf("��????? %d\n",ttten(num,to));
	
		
	}
}



/*
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=121584#overview
A - ����
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit
 
Status
 
Practice
 
FZU 1548
Description
�������������һ������������������ô���������ģ�����һ������B(2<=B<=20��B��ʮ���Ʊ�ʾ)������������£��������ƽ������������ʹ��������һ�����á�A��,��B��������ʾ10��11�ȵȡ�

���磺B=10ʱ��121����һ����������Ϊ121��ƽ��14641����������

��������Ǳ�дһ������������д��ڵ���1С�ڵ���300��������

Input
�����������������ݣ��봦��EOF������
ÿ��������ݣ���һ����ɣ�Ϊһ������������B(B��ʮ���Ʊ�ʾ)��

Output
��ÿ�����������ÿ���������֣��ڶ������ǵ�һ������ƽ�����ҵ�һ������������(ע��:����������Ӧ����B�Ǹ�������)

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
 
