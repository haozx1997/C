#include<stdio.h>
#include<string.h>

char num[10];
char boom[] = {"0123456789ABCDEFGHIJK"};

int moob(char c)
{
	if(c>'9')
	 return c-'A'+10;
	return c - '0';
}
int issym(char *n)
{
	for(int i = 0;i < strlen(n);i++)
	{
		if(n[i] != n[(strlen(n)-i-1)])
		 return 0;
	}
	return 1;
}
void ttt(int n,int to)//¦Ì?to???? 
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

int xy(int x ,int y)//x¦Ì?y¡ä? 
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

int ttten(char *n,int to)//¦Ì?¨º????? 
{
	int ans = 0;
	for(int i = 0;i < strlen(n);i++)
	{
	//	printf("¨º?????%d %d\n",ans,xy(to,i));
		
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
//		printf("¨º????? %d\n",ttten(num,to));
	
		
	}
}
