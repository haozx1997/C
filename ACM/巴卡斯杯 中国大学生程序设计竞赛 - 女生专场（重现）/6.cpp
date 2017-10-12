/*
abc
def
adebcf

qqq
www
qqqwww

asd
asf
asdasf

asd
asf
asfasd


*/


#include<stdio.h>
#include<string.h>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

char c1[2005],c2[2005],c3[2005];
int d[2005][2005];

void mdzz()
{
        int i,j,s,t,k;
        memset(d,0,sizeof(d));
        for(i=0;i<=strlen(c1);i++)
            d[i][0]=0;
        for(j=0;j<=strlen(c2);j++)
            d[0][j]=0;
        for(i=1;i<=strlen(c1);i++)
            for(j=1;j<=strlen(c2);j++)
        {
            if(c1[i-1]==c2[j-1])
                    d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
       


        
        s=strlen(c1);t=strlen(c2);
        k=d[s][t];
        c3[k]={'\0'};
        while(i&&j)
        {
            if(c1[i-1]==c2[j-1]&&d[i][j]==d[i-1][j-1]+1)
            {
                c3[--k]=c1[i-1];
                --i;
                --j;
            }
            else if(c1[i-1]!=c2[j-1]&&d[i-1][j]>d[i][j-1])
                --i;
            else
                --j;
        }
       
    }

int main()
{
	char a[2020];
	int az[30];
	int cz[30];
	memset(a,0,sizeof(a));
	while(~scanf("%s",a))
	{
		char b[2020];
		char c[2020];
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		
		scanf("%s",b);
		scanf("%s",c);
		if((strlen(a)+strlen(b))!=strlen(c))
		{
			printf("No\n");memset(a,0,sizeof(a));
			continue;
		}
		strcpy(c1,a);
		strcpy(c2,c);
		mdzz();
		if(strcmp(c3,a))
		{
			printf("No\n");memset(a,0,sizeof(a));
			continue;
		}
		strcpy(c1,b);
		strcpy(c2,c);
		mdzz();
		if(strcmp(c3,b))
		{
			printf("No\n");memset(a,0,sizeof(a));
			continue;
		}
		
		strcat(a,b);
		memset(az,0,sizeof(az));
		memset(cz,0,sizeof(cz));
		for(int i = 0;i<strlen(a);i++)
		{
			az[a[i]-'a']++;
			cz[c[i]-'a']++;
		}
		int f = 0;
		
		
		for(int i = 0;i<27;i++)
		{
			printf("%d %d\n",az[i],cz[i]);
			if(az[i]!=cz[i])
			 f=1;
		}
		if(f)
		{
			printf("No\n");memset(a,0,sizeof(a));
			continue;
		}
		
		printf("Yes\n");
		memset(a,0,sizeof(a));

		
	}
}
