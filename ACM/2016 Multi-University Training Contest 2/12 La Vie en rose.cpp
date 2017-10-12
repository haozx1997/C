#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>

int isfit(char *ss,char *pp ,int len)
{
	int f = 1;
//	printf("!!!!%s %s %d\n",ss,pp,len);
	for(int i = 0;i < len;i++)
	{
		
			if(ss[i] == pp[i])
			 {
			 	continue;
			 }
			 else
			 {
			 	if((ss[i]==pp[i+1])&&(ss[i+1]==pp[i]))
			 	 {
			 	 	f = 0;i++;
			 	 	continue;
				  }
				 else 
				 {
				 	return 0;
				  } 
			 }
		
	}
	return 1;
}

int main()
{
	int T ;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		char s[100100];
		char p[5050];
		scanf("%d%d",&n,&m);
		scanf("%s",s);
		scanf("%s",p);
		int slen = strlen(s);
		int plen = strlen(p);
		
		for(int i = 0;i < slen-plen+1;i++)
		{
			printf("%d",isfit(s+i,p,plen));
		}
		for(int i = 0;i < plen-1;i++)
		{
			printf("0");
		}
		printf("\n");
		
		
		
	}
}
