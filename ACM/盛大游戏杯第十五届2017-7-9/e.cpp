#include<bits/stdc++.h>

using namespace std;
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
	puts(num);
}
int main()
{
	int m;
	char a[100];
	while(~scanf("%s%d",a,&m))
	{
		long long org =0;
		int len = strlen(a);
		for(int i = 0;i < len;i++)
		{
			org += (a[i]-'a');
			if(i != len-1)
			{
				org *= 26;
			}
		}
	//	printf("%d\n",org);
		ttt(org,m);
	}




 return 0;
}


