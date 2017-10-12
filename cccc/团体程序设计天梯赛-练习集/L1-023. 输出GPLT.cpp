#include<string.h>
#include<stdio.h>
int main()
{
	char s[100100];
	char c[] = {"GPLTgplt"};
	int g[10] ;
	
	gets(s);
	memset(g,0,sizeof(g));
	for(int i = 0;i < strlen(s);i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(s[i] == c[j])
			{
				g[j%4]++;
				
			}
		}
	}
//	for(int i = 0 ;i<4;i++)
//	{
//		printf("%d \n",g[i]);(g[0]+g[1]+g[2]+g[3]+4);
//	}
	for(int i = 0;g[0]||g[1]||g[2]||g[3];i++)
	{
		if(g[i%4]>0)
		{
			printf("%c",c[i%4]);
			g[i%4]--;
		}
		
	}
	printf("\n");
}
