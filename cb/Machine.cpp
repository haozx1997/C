#include<stdio.h>
#include<string.h> 
char c[3] = {'R','G','B'};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		int i = 0;
		int m,mm[100]; 
		memset(mm,0,sizeof(mm));
		scanf("%d%I64d",&m,&n);
		while(n)
		{
			mm[i] = n%3;
			n/=3;
			i++;
		}
		int j;
		for(j = m-1;j>=0;j--)
		 {
		 	printf("%c",c[mm[j]]);
		 }

		  printf("\n");
	}
 } 
